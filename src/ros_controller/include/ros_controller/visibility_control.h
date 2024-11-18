#ifndef ROS_CONTROLLER__VISIBILITY_CONTROL_H_
#define ROS_CONTROLLER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROS_CONTROLLER_EXPORT __attribute__ ((dllexport))
    #define ROS_CONTROLLER_IMPORT __attribute__ ((dllimport))
  #else
    #define ROS_CONTROLLER_EXPORT __declspec(dllexport)
    #define ROS_CONTROLLER_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROS_CONTROLLER_BUILDING_LIBRARY
    #define ROS_CONTROLLER_PUBLIC ROS_CONTROLLER_EXPORT
  #else
    #define ROS_CONTROLLER_PUBLIC ROS_CONTROLLER_IMPORT
  #endif
  #define ROS_CONTROLLER_PUBLIC_TYPE ROS_CONTROLLER_PUBLIC
  #define ROS_CONTROLLER_LOCAL
#else
  #define ROS_CONTROLLER_EXPORT __attribute__ ((visibility("default")))
  #define ROS_CONTROLLER_IMPORT
  #if __GNUC__ >= 4
    #define ROS_CONTROLLER_PUBLIC __attribute__ ((visibility("default")))
    #define ROS_CONTROLLER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROS_CONTROLLER_PUBLIC
    #define ROS_CONTROLLER_LOCAL
  #endif
  #define ROS_CONTROLLER_PUBLIC_TYPE
#endif
#endif  // ROS_CONTROLLER__VISIBILITY_CONTROL_H_
// Generated 18-Nov-2024 14:34:52
// Copyright 2019-2020 The MathWorks, Inc.
