/*
 * ros_controller.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ros_controller".
 *
 * Model version              : 1.6
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Thu Oct 24 12:21:30 2024
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
#include <string.h>

/* Block signals (default storage) */
B_ros_controller_T ros_controller_B;

/* Block states (default storage) */
DW_ros_controller_T ros_controller_DW;

/* Real-time model */
RT_MODEL_ros_controller_T ros_controller_M_ = RT_MODEL_ros_controller_T();
RT_MODEL_ros_controller_T *const ros_controller_M = &ros_controller_M_;

/* Model step function */
void ros_controller_step(void)
{
  SL_Bus_ros_controller_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_ros_controller_std_msgs_Float64 rtb_SourceBlock_o2_0;
  boolean_T b_varargout_1;

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
  /* MATLABSystem: '<S4>/SourceBlock' */
  b_varargout_1 = Sub_ros_controller_13.getLatestMessage(&rtb_SourceBlock_o2_0);

  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* Start for MATLABSystem: '<S4>/SourceBlock' */
  if (b_varargout_1) {
    /* SignalConversion generated from: '<S5>/In1' */
    ros_controller_B.In1 = rtb_SourceBlock_o2_0;
  }

  /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe' */

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  rtb_BusAssignment.Data = (ros_controller_B.In1.Data - 5.0) * 0.1;

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S3>/SinkBlock' */
  Pub_ros_controller_11.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
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
    char_T b_zeroDelimTopic[11];
    static const char_T b_zeroDelimTopic_0[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_1[11] = "/cmd_accel";

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    ros_controller_DW.obj_l.matlabCodegenIsDeleted = false;
    ros_controller_DW.objisempty = true;
    ros_controller_DW.obj_l.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
    }

    Sub_ros_controller_13.createSubscriber(&b_zeroDelimTopic[0], 1);
    ros_controller_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S3>/SinkBlock' */
    ros_controller_DW.obj.matlabCodegenIsDeleted = false;
    ros_controller_DW.objisempty_i = true;
    ros_controller_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Pub_ros_controller_11.createPublisher(&b_zeroDelimTopic[0], 1);
    ros_controller_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S5>/In1' incorporates:
   *  Outport: '<S5>/Out1'
   */
  ros_controller_B.In1 = ros_controller_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */
}

/* Model terminate function */
void ros_controller_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!ros_controller_DW.obj_l.matlabCodegenIsDeleted) {
    ros_controller_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S3>/SinkBlock' */
  if (!ros_controller_DW.obj.matlabCodegenIsDeleted) {
    ros_controller_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */
}
