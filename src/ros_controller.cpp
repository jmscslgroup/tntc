/*
 * ros_controller.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ros_controller".
 *
 * Model version              : 1.8
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Mon Nov 18 14:34:32 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ros_controller.h"
#include "rtwtypes.h"
#include "ros_controller_types.h"
#include "ros_controller_private.h"
#include <string.h>

/* Block signals (default storage) */
B_ros_controller_T ros_controller_B;

/* Block states (default storage) */
DW_ros_controller_T ros_controller_DW;

/* Real-time model */
RT_MODEL_ros_controller_T ros_controller_M_ = RT_MODEL_ros_controller_T();
RT_MODEL_ros_controller_T *const ros_controller_M = &ros_controller_M_;

/*
 * System initialize for enable system:
 *    '<S6>/Enabled Subsystem'
 *    '<S7>/Enabled Subsystem'
 *    '<S8>/Enabled Subsystem'
 */
void ros_contr_EnabledSubsystem_Init(B_EnabledSubsystem_ros_contro_T *localB,
  P_EnabledSubsystem_ros_contro_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S9>/In1' incorporates:
   *  Outport: '<S9>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for enable system:
 *    '<S6>/Enabled Subsystem'
 *    '<S7>/Enabled Subsystem'
 *    '<S8>/Enabled Subsystem'
 */
void ros_controller_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_ros_controller_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_ros_contro_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S9>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
}

/* Model step function */
void ros_controller_step(void)
{
  SL_Bus_ros_controller_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_ros_controller_std_msgs_Float64 tmp;
  real_T rtb_TSamp;
  real_T rtb_TSamp_l;
  real_T rtb_cmd_accel;
  boolean_T b_varargout_1;

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
  /* MATLABSystem: '<S6>/SourceBlock' */
  b_varargout_1 = Sub_ros_controller_13.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S6>/SourceBlock' */
  ros_controller_EnabledSubsystem(b_varargout_1, &tmp,
    &ros_controller_B.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe' */

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe1' */
  /* MATLABSystem: '<S7>/SourceBlock' */
  b_varargout_1 = Sub_ros_controller_16.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S7>/SourceBlock' */
  ros_controller_EnabledSubsystem(b_varargout_1, &tmp,
    &ros_controller_B.EnabledSubsystem_o);

  /* End of Outputs for SubSystem: '<S7>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe1' */

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe2' */
  /* MATLABSystem: '<S8>/SourceBlock' */
  b_varargout_1 = Sub_ros_controller_17.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S8>/SourceBlock' */
  ros_controller_EnabledSubsystem(b_varargout_1, &tmp,
    &ros_controller_B.EnabledSubsystem_l);

  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe2' */

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = ros_controller_B.EnabledSubsystem_l.In1.Data *
    ros_controller_P.TSamp_WtEt;

  /* SampleTimeMath: '<S3>/TSamp' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Product: '<Root>/Product1'
   *  Sum: '<Root>/Sum3'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_l = (ros_controller_B.EnabledSubsystem.In1.Data -
                 ros_controller_B.EnabledSubsystem_o.In1.Data *
                 ros_controller_P.Constant5_Value) *
    ros_controller_P.TSamp_WtEt_e;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Sum: '<S2>/Diff'
   *  Sum: '<S3>/Diff'
   *  UnitDelay: '<S2>/UD'
   *  UnitDelay: '<S3>/UD'
   */
  rtb_cmd_accel = (((-ros_controller_B.EnabledSubsystem_o.In1.Data *
                     ros_controller_P.Constant5_Value +
                     ros_controller_B.EnabledSubsystem.In1.Data) * 0.4 +
                    (rtb_TSamp - ros_controller_DW.UD_DSTATE)) + (rtb_TSamp_l -
    ros_controller_DW.UD_DSTATE_h) * 0.0) * 0.4;
  if (rtb_cmd_accel > 1.5) {
    rtb_cmd_accel = 1.5;
  } else if (rtb_cmd_accel < -3.0) {
    rtb_cmd_accel = -3.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* BusAssignment: '<Root>/Bus Assignment' */
  rtb_BusAssignment.Data = rtb_cmd_accel;

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S5>/SinkBlock' */
  Pub_ros_controller_11.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */

  /* Update for UnitDelay: '<S2>/UD' */
  ros_controller_DW.UD_DSTATE = rtb_TSamp;

  /* Update for UnitDelay: '<S3>/UD' */
  ros_controller_DW.UD_DSTATE_h = rtb_TSamp_l;
}

/* Model initialize function */
void ros_controller_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset((static_cast<void *>(&ros_controller_B)), 0,
                sizeof(B_ros_controller_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(&ros_controller_DW), 0,
                sizeof(DW_ros_controller_T));

  {
    char_T b_zeroDelimTopic_1[15];
    char_T b_zeroDelimTopic_0[14];
    char_T b_zeroDelimTopic[11];
    static const char_T b_zeroDelimTopic_2[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_3[14] = "/egocar/vel_x";
    static const char_T b_zeroDelimTopic_4[15] = "/leadcar/vel_x";
    static const char_T b_zeroDelimTopic_5[11] = "/cmd_accel";

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S6>/SourceBlock' */
    ros_controller_DW.obj_l.matlabCodegenIsDeleted = false;
    ros_controller_DW.objisempty_i = true;
    ros_controller_DW.obj_l.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_ros_controller_13.createSubscriber(&b_zeroDelimTopic[0], 1);
    ros_controller_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S6>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe1' */
    /* Start for MATLABSystem: '<S7>/SourceBlock' */
    ros_controller_DW.obj_p.matlabCodegenIsDeleted = false;
    ros_controller_DW.objisempty_o = true;
    ros_controller_DW.obj_p.isInitialized = 1;
    for (int32_T i = 0; i < 14; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_ros_controller_16.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    ros_controller_DW.obj_p.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S7>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe1' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe2' */
    /* Start for MATLABSystem: '<S8>/SourceBlock' */
    ros_controller_DW.obj_j.matlabCodegenIsDeleted = false;
    ros_controller_DW.objisempty = true;
    ros_controller_DW.obj_j.isInitialized = 1;
    for (int32_T i = 0; i < 15; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Sub_ros_controller_17.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    ros_controller_DW.obj_j.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S8>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe2' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S5>/SinkBlock' */
    ros_controller_DW.obj.matlabCodegenIsDeleted = false;
    ros_controller_DW.objisempty_i5 = true;
    ros_controller_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_5[i];
    }

    Pub_ros_controller_11.createPublisher(&b_zeroDelimTopic[0], 1);
    ros_controller_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */
  }

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  ros_controller_DW.UD_DSTATE = ros_controller_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S3>/UD' */
  ros_controller_DW.UD_DSTATE_h =
    ros_controller_P.DiscreteDerivative1_ICPrevScale;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  ros_contr_EnabledSubsystem_Init(&ros_controller_B.EnabledSubsystem,
    &ros_controller_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1' */
  /* SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem' */
  ros_contr_EnabledSubsystem_Init(&ros_controller_B.EnabledSubsystem_o,
    &ros_controller_P.EnabledSubsystem_o);

  /* End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe1' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2' */
  /* SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem' */
  ros_contr_EnabledSubsystem_Init(&ros_controller_B.EnabledSubsystem_l,
    &ros_controller_P.EnabledSubsystem_l);

  /* End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe2' */
}

/* Model terminate function */
void ros_controller_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S6>/SourceBlock' */
  if (!ros_controller_DW.obj_l.matlabCodegenIsDeleted) {
    ros_controller_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe1' */
  /* Terminate for MATLABSystem: '<S7>/SourceBlock' */
  if (!ros_controller_DW.obj_p.matlabCodegenIsDeleted) {
    ros_controller_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe1' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe2' */
  /* Terminate for MATLABSystem: '<S8>/SourceBlock' */
  if (!ros_controller_DW.obj_j.matlabCodegenIsDeleted) {
    ros_controller_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe2' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S5>/SinkBlock' */
  if (!ros_controller_DW.obj.matlabCodegenIsDeleted) {
    ros_controller_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */
}
