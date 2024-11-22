#ifndef TNTC__VISIBILITY_CONTROL_H_
#define TNTC__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define TNTC_EXPORT __attribute__ ((dllexport))
    #define TNTC_IMPORT __attribute__ ((dllimport))
  #else
    #define TNTC_EXPORT __declspec(dllexport)
    #define TNTC_IMPORT __declspec(dllimport)
  #endif
  #ifdef TNTC_BUILDING_LIBRARY
    #define TNTC_PUBLIC TNTC_EXPORT
  #else
    #define TNTC_PUBLIC TNTC_IMPORT
  #endif
  #define TNTC_PUBLIC_TYPE TNTC_PUBLIC
  #define TNTC_LOCAL
#else
  #define TNTC_EXPORT __attribute__ ((visibility("default")))
  #define TNTC_IMPORT
  #if __GNUC__ >= 4
    #define TNTC_PUBLIC __attribute__ ((visibility("default")))
    #define TNTC_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define TNTC_PUBLIC
    #define TNTC_LOCAL
  #endif
  #define TNTC_PUBLIC_TYPE
#endif
#endif  // TNTC__VISIBILITY_CONTROL_H_
// Generated 21-Nov-2024 22:22:17
// Copyright 2019-2020 The MathWorks, Inc.
