cmake_minimum_required(VERSION 3.0)
project(qr_code_decode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fno-diagnostics-color")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  image_transport
  roscpp
  std_msgs
  cv_bridge
  image_geometry
  mrs_lib
  mrs_msgs
)


find_package(OpenCV REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES QRDecode 
  CATKIN_DEPENDS roscpp mrs_lib image_transport std_msgs mrs_msgs
)

include_directories(include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

# Necessario pra fase quatro
add_library(QRDecode src/QRDecode.cpp)
add_dependencies(QRDecode ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
find_package(PkgConfig REQUIRED)
pkg_check_modules(ZBar REQUIRED IMPORTED_TARGET zbar)
target_link_libraries(QRDecode ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} PkgConfig::ZBar )


