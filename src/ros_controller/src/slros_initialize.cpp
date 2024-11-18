#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ros_controller";

// For Block ros_controller/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ros_controller_std_msgs_Float64> Sub_ros_controller_13;

// For Block ros_controller/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ros_controller_std_msgs_Float64> Sub_ros_controller_16;

// For Block ros_controller/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ros_controller_std_msgs_Float64> Sub_ros_controller_17;

// For Block ros_controller/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_ros_controller_std_msgs_Float64> Pub_ros_controller_11;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

