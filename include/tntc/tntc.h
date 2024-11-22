/*
 * tntc.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "tntc".
 *
 * Model version              : 1.9
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Thu Nov 21 22:21:58 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef tntc_h_
#define tntc_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "tntc_types.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S6>/Enabled Subsystem' */
struct B_EnabledSubsystem_tntc_T {
  SL_Bus_tntc_std_msgs_Float64 In1;    /* '<S9>/In1' */
};

/* Block signals (default storage) */
struct B_tntc_T {
  B_EnabledSubsystem_tntc_T EnabledSubsystem_l;/* '<S8>/Enabled Subsystem' */
  B_EnabledSubsystem_tntc_T EnabledSubsystem_o;/* '<S7>/Enabled Subsystem' */
  B_EnabledSubsystem_tntc_T EnabledSubsystem;/* '<S6>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_tntc_T {
  ros_slroscpp_internal_block_P_T obj; /* '<S5>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_j;/* '<S8>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_p;/* '<S7>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_l;/* '<S6>/SourceBlock' */
  real_T UD_DSTATE;                    /* '<S2>/UD' */
  real_T UD_DSTATE_h;                  /* '<S3>/UD' */
  boolean_T objisempty;                /* '<S8>/SourceBlock' */
  boolean_T objisempty_o;              /* '<S7>/SourceBlock' */
  boolean_T objisempty_i;              /* '<S6>/SourceBlock' */
  boolean_T objisempty_i5;             /* '<S5>/SinkBlock' */
};

/* Parameters for system: '<S6>/Enabled Subsystem' */
struct P_EnabledSubsystem_tntc_T_ {
  SL_Bus_tntc_std_msgs_Float64 Out1_Y0;/* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S9>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_tntc_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S2>/UD'
                               */
  real_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S3>/UD'
                               */
  SL_Bus_tntc_std_msgs_Float64 Constant_Value;/* Computed Parameter: Constant_Value
                                               * Referenced by: '<S1>/Constant'
                                               */
  SL_Bus_tntc_std_msgs_Float64 Constant_Value_e;/* Computed Parameter: Constant_Value_e
                                                 * Referenced by: '<S6>/Constant'
                                                 */
  SL_Bus_tntc_std_msgs_Float64 Constant_Value_h;/* Computed Parameter: Constant_Value_h
                                                 * Referenced by: '<S7>/Constant'
                                                 */
  SL_Bus_tntc_std_msgs_Float64 Constant_Value_h2;/* Computed Parameter: Constant_Value_h2
                                                  * Referenced by: '<S8>/Constant'
                                                  */
  real_T Constant5_Value;              /* Expression: 2.5
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S2>/TSamp'
                                        */
  real_T TSamp_WtEt_e;                 /* Computed Parameter: TSamp_WtEt_e
                                        * Referenced by: '<S3>/TSamp'
                                        */
  P_EnabledSubsystem_tntc_T EnabledSubsystem_l;/* '<S8>/Enabled Subsystem' */
  P_EnabledSubsystem_tntc_T EnabledSubsystem_o;/* '<S7>/Enabled Subsystem' */
  P_EnabledSubsystem_tntc_T EnabledSubsystem;/* '<S6>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_tntc_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_tntc_T tntc_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_tntc_T tntc_B;

#ifdef __cplusplus

}

#endif

/* Block states (default storage) */
extern struct DW_tntc_T tntc_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void tntc_initialize(void);
  extern void tntc_step(void);
  extern void tntc_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_tntc_T *const tntc_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'tntc'
 * '<S1>'   : 'tntc/Blank Message1'
 * '<S2>'   : 'tntc/Discrete Derivative'
 * '<S3>'   : 'tntc/Discrete Derivative1'
 * '<S4>'   : 'tntc/MATLAB Function1'
 * '<S5>'   : 'tntc/Publish'
 * '<S6>'   : 'tntc/Subscribe'
 * '<S7>'   : 'tntc/Subscribe1'
 * '<S8>'   : 'tntc/Subscribe2'
 * '<S9>'   : 'tntc/Subscribe/Enabled Subsystem'
 * '<S10>'  : 'tntc/Subscribe1/Enabled Subsystem'
 * '<S11>'  : 'tntc/Subscribe2/Enabled Subsystem'
 */
#endif                                 /* tntc_h_ */
