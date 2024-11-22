/*
 * tntc.cpp
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

#include "tntc.h"
#include "rtwtypes.h"
#include "tntc_types.h"
#include "tntc_private.h"
#include <string.h>

/* Block signals (default storage) */
B_tntc_T tntc_B;

/* Block states (default storage) */
DW_tntc_T tntc_DW;

/* Real-time model */
RT_MODEL_tntc_T tntc_M_ = RT_MODEL_tntc_T();
RT_MODEL_tntc_T *const tntc_M = &tntc_M_;

/*
 * System initialize for enable system:
 *    '<S6>/Enabled Subsystem'
 *    '<S7>/Enabled Subsystem'
 *    '<S8>/Enabled Subsystem'
 */
void tntc_EnabledSubsystem_Init(B_EnabledSubsystem_tntc_T *localB,
  P_EnabledSubsystem_tntc_T *localP)
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
void tntc_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_tntc_std_msgs_Float64 *rtu_In1, B_EnabledSubsystem_tntc_T *localB)
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
void tntc_step(void)
{
  SL_Bus_tntc_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_tntc_std_msgs_Float64 tmp;
  real_T rtb_TSamp;
  real_T rtb_TSamp_l;
  real_T rtb_cmd_accel;
  boolean_T b_varargout_1;

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
  /* MATLABSystem: '<S6>/SourceBlock' */
  b_varargout_1 = Sub_tntc_13.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S6>/SourceBlock' */
  tntc_EnabledSubsystem(b_varargout_1, &tmp, &tntc_B.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe' */

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe1' */
  /* MATLABSystem: '<S7>/SourceBlock' */
  b_varargout_1 = Sub_tntc_16.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S7>/SourceBlock' */
  tntc_EnabledSubsystem(b_varargout_1, &tmp, &tntc_B.EnabledSubsystem_o);

  /* End of Outputs for SubSystem: '<S7>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe1' */

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe2' */
  /* MATLABSystem: '<S8>/SourceBlock' */
  b_varargout_1 = Sub_tntc_17.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S8>/SourceBlock' */
  tntc_EnabledSubsystem(b_varargout_1, &tmp, &tntc_B.EnabledSubsystem_l);

  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe2' */

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = tntc_B.EnabledSubsystem_l.In1.Data * tntc_P.TSamp_WtEt;

  /* SampleTimeMath: '<S3>/TSamp' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Product: '<Root>/Product1'
   *  Sum: '<Root>/Sum3'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp_l = (tntc_B.EnabledSubsystem.In1.Data -
                 tntc_B.EnabledSubsystem_o.In1.Data * tntc_P.Constant5_Value) *
    tntc_P.TSamp_WtEt_e;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Sum: '<S2>/Diff'
   *  Sum: '<S3>/Diff'
   *  UnitDelay: '<S2>/UD'
   *  UnitDelay: '<S3>/UD'
   */
  rtb_cmd_accel = (((-tntc_B.EnabledSubsystem_o.In1.Data *
                     tntc_P.Constant5_Value + tntc_B.EnabledSubsystem.In1.Data) *
                    0.4 + (rtb_TSamp - tntc_DW.UD_DSTATE)) + (rtb_TSamp_l -
    tntc_DW.UD_DSTATE_h) * 0.2) * 0.4;
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
  Pub_tntc_11.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */

  /* Update for UnitDelay: '<S2>/UD' */
  tntc_DW.UD_DSTATE = rtb_TSamp;

  /* Update for UnitDelay: '<S3>/UD' */
  tntc_DW.UD_DSTATE_h = rtb_TSamp_l;
}

/* Model initialize function */
void tntc_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset((static_cast<void *>(&tntc_B)), 0,
                sizeof(B_tntc_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(&tntc_DW), 0,
                sizeof(DW_tntc_T));

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
    tntc_DW.obj_l.matlabCodegenIsDeleted = false;
    tntc_DW.objisempty_i = true;
    tntc_DW.obj_l.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_tntc_13.createSubscriber(&b_zeroDelimTopic[0], 1);
    tntc_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S6>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe1' */
    /* Start for MATLABSystem: '<S7>/SourceBlock' */
    tntc_DW.obj_p.matlabCodegenIsDeleted = false;
    tntc_DW.objisempty_o = true;
    tntc_DW.obj_p.isInitialized = 1;
    for (int32_T i = 0; i < 14; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_tntc_16.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    tntc_DW.obj_p.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S7>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe1' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe2' */
    /* Start for MATLABSystem: '<S8>/SourceBlock' */
    tntc_DW.obj_j.matlabCodegenIsDeleted = false;
    tntc_DW.objisempty = true;
    tntc_DW.obj_j.isInitialized = 1;
    for (int32_T i = 0; i < 15; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Sub_tntc_17.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    tntc_DW.obj_j.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S8>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe2' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S5>/SinkBlock' */
    tntc_DW.obj.matlabCodegenIsDeleted = false;
    tntc_DW.objisempty_i5 = true;
    tntc_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_5[i];
    }

    Pub_tntc_11.createPublisher(&b_zeroDelimTopic[0], 1);
    tntc_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */
  }

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  tntc_DW.UD_DSTATE = tntc_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S3>/UD' */
  tntc_DW.UD_DSTATE_h = tntc_P.DiscreteDerivative1_ICPrevScale;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  tntc_EnabledSubsystem_Init(&tntc_B.EnabledSubsystem, &tntc_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1' */
  /* SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem' */
  tntc_EnabledSubsystem_Init(&tntc_B.EnabledSubsystem_o,
    &tntc_P.EnabledSubsystem_o);

  /* End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe1' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2' */
  /* SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem' */
  tntc_EnabledSubsystem_Init(&tntc_B.EnabledSubsystem_l,
    &tntc_P.EnabledSubsystem_l);

  /* End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe2' */
}

/* Model terminate function */
void tntc_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S6>/SourceBlock' */
  if (!tntc_DW.obj_l.matlabCodegenIsDeleted) {
    tntc_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe1' */
  /* Terminate for MATLABSystem: '<S7>/SourceBlock' */
  if (!tntc_DW.obj_p.matlabCodegenIsDeleted) {
    tntc_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe1' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe2' */
  /* Terminate for MATLABSystem: '<S8>/SourceBlock' */
  if (!tntc_DW.obj_j.matlabCodegenIsDeleted) {
    tntc_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe2' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S5>/SinkBlock' */
  if (!tntc_DW.obj.matlabCodegenIsDeleted) {
    tntc_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */
}
