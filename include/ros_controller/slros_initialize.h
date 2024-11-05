#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "ros_controller_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ros_controller/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ros_controller_std_msgs_Float64> Sub_ros_controller_13;

// For Block ros_controller/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ros_controller_std_msgs_Float64> Pub_ros_controller_11;

void slros_node_init(int argc, char** argv);

#endif
