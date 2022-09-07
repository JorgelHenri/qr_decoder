#include <QRDecode.h>

/* every nodelet must include macros which export the class as a nodelet plugin
 */
#include <pluginlib/class_list_macros.h>

using namespace zbar;

namespace qr_decode
{

    /* onInit() method //{ */
    void QRDecode::onInit() {
        got_image_ = false;
        got_camera_info_ = false;

        /* obtain node handle */
        ros::NodeHandle nh("~");

        /* waits for the ROS to publish clock */
        ros::Time::waitForValid();

       // new nodehandle for goto calls
        ros::NodeHandle n;

        // | ------------------- load ros parameters ------------------ |
        /* (mrs_lib implementation checks whether the parameter was loaded or not) */

        mrs_lib::ParamLoader param_loader(nh, "QRDecode");

        param_loader.loadParam("UAV_NAME", _uav_name_);
        param_loader.loadParam("gui", _gui_);

        if (!param_loader.loadedSuccessfully()) {
            ROS_ERROR("[FASE4]: failed to load non-optional parameters!");
            ros::shutdown();
        }

        // // | --------------------------- gui -------------------------- |

        if (_gui_) {
            int flags =
                cv::WINDOW_NORMAL | cv::WINDOW_FREERATIO | cv::WINDOW_GUI_EXPANDED;
            cv::namedWindow("original", flags);
        }

        /* initialize the image transport, needs node handle */
        image_transport::ImageTransport it(nh);
        
        // // | ----------------- initialize subscribers ----------------- |
        QrcodeSubscriber = it.subscribe("image_in", 1, &QRDecode::QrcodeCallback, this);

        cameraInfoSubscriber =
            nh.subscribe("camera_info_in", 1, &QRDecode::cameraInfoCallback, this,
                        ros::TransportHints().tcpNoDelay());

        // | -------------------- initialize timers ------------------- |
        
        ROS_INFO_ONCE("[QRcode decoder]: initialized");
        is_initialized_ = true;
        ros::AsyncSpinner spinner(0);  // Use all threads avaliable
        spinner.start();
        ros::waitForShutdown();
    }
    //}

    // | ---------------------- msg callbacks --------------------- |

    /* cameraInfoCallback() method //{ */

    void QRDecode::cameraInfoCallback(const sensor_msgs::CameraInfoConstPtr& msg){
        if (!is_initialized_)
        return;

        got_camera_info_ = true;
        time_last_camera_info_ = ros::Time::now();

        // update the camera model using the latest camera info message
        camera_model_.fromCameraInfo(*msg);
    }
    //}

    void QRDecode::QrcodeCallback(const sensor_msgs::ImageConstPtr& msg){

        std::time_t timeBegin = std::time(0);
        const std::string color_encoding = "bgr8";
        const cv_bridge::CvImagePtr bridge_image_ptr =
            cv_bridge::toCvCopy(msg, color_encoding);
        const std_msgs::Header msg_header = msg->header;

        if (_gui_) cv::imshow("original", bridge_image_ptr->image);

        // Read image
        cv::Mat gray;
        cv::cvtColor(bridge_image_ptr->image, gray, cv::COLOR_BGR2GRAY);

        if( gray.empty() )                      // Check for invalid input
        {

            ROS_WARN("Could not open or find the image");
            ros::shutdown();

        }
 
        // Variable for decoded objects
        std::vector<decodedObject> decodedObjects;

        // Find and decode barcodes and QR codes
        decode(gray, decodedObjects);

        cv::waitKey(1);
    }

    void QRDecode::decode(cv::Mat &im, std::vector<decodedObject>&decodedObjects){

        // Create zbar scanner

        ImageScanner scanner;

        // Configure scanner
        // disable all

        scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 0);

        // enable qr
        scanner.set_config(ZBAR_QRCODE, ZBAR_CFG_ENABLE, 1);

        // Convert image to grayscale

        // cv::Mat imGray;
        // cv::cvtColor( im, imGray, cv::COLOR_RGB2GRAY );



        // Wrap image data in a zbar image
        Image image(im.cols, im.rows, "Y800", (uchar *)im.data, im.cols * im.rows);

        // Scan the image for barcodes and QRCodes
        int n = scanner.scan(image);

        // Print results

        for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
        {
            

            obj.data = symbol->get_data();

            // Print type and data
             ROS_INFO("[QRcode decoder]: Qrcode Data: %s ", obj.data.c_str() );
            decodedObjects.push_back(obj);
        }
       
        obj.data.clear();

    }
    
} // namespace qr_decode
/* every nodelet must export its class as nodelet plugin */
PLUGINLIB_EXPORT_CLASS(qr_decode::QRDecode, nodelet::Nodelet);
