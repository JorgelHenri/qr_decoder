#pragma once

/* includes //{ */

/* each ROS nodelet must have these */
#include <nodelet/nodelet.h>
#include <ros/package.h>
#include <ros/ros.h>

#include <zbar.h>
#include <zbar/Exception.h>
#include <zbar/Image.h>
#include <zbar/ImageScanner.h>
#include <zbar/Processor.h>
#include <zbar/Scanner.h>
#include <zbar/Symbol.h>
#include <zbar/Window.h>

/* custom helper functions from our library */
#include <mrs_lib/param_loader.h>

/* ROS includes for Odometry*/
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <cv_bridge/cv_bridge.h>
#include <image_geometry/pinhole_camera_model.h>
#include <image_transport/image_transport.h>

using namespace zbar;

typedef struct
{
    std::string data;
}decodedObject;

namespace qr_decode {


    /* class QRDecode //{ */
    class QRDecode : public nodelet::Nodelet {
        public:
          /* onInit() is called when nodelet is launched (similar to main() in regular
        * node) */
        virtual void onInit();
        
        // Find and decode barcodes and QR codes
        void decode(cv::Mat &im, std::vector<decodedObject>&decodedObjects);
        decodedObject obj;

        private:
        bool is_initialized_;
        
        /* ros parameters */
        bool _gui_;

        /* variables*/
        std::string _uav_name_;

        /* scribers */
        image_transport::Subscriber QrcodeSubscriber;
        ros::Subscriber cameraInfoSubscriber;
       
        ros::Time time_last_image_;  // time stamp of the last received image message
        ros::Time time_last_camera_info_;  // time stamp of the last received camera
                                           // info message

        image_geometry::PinholeCameraModel camera_model_;

        uint64_t image_counter_ = 0;       // counts the number of images received
        bool got_image_ =
            false;  // indicates whether at least one image message was received
        bool got_camera_info_ =
            false;  // indicates whether at least one camera info message was received

        // | ---------------------- msg callbacks --------------------- |
        void QrcodeCallback(const sensor_msgs::ImageConstPtr& msg);
        void cameraInfoCallback(const sensor_msgs::CameraInfoConstPtr& msg);
   
        // | ------------------- helper functions --------------------- |
        int getInterval(cv::Mat image, int L2);
        int counter = 0;
       
    };
}  // namespace fase_4
