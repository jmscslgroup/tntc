#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "tntc";

// For Block tntc/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_tntc_std_msgs_Float64> Sub_tntc_13;

// For Block tntc/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_tntc_std_msgs_Float64> Sub_tntc_16;

// For Block tntc/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_tntc_std_msgs_Float64> Sub_tntc_17;

// For Block tntc/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_tntc_std_msgs_Float64> Pub_tntc_11;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

