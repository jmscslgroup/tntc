#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "tntc_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block tntc/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_tntc_std_msgs_Float64> Sub_tntc_13;

// For Block tntc/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_tntc_std_msgs_Float64> Sub_tntc_16;

// For Block tntc/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_tntc_std_msgs_Float64> Sub_tntc_17;

// For Block tntc/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_tntc_std_msgs_Float64> Pub_tntc_11;

void slros_node_init(int argc, char** argv);

#endif
