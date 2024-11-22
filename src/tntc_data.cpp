/*
 * tntc_data.cpp
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

/* Block parameters (default storage) */
P_tntc_T tntc_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S2>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S3>/UD'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S6>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S7>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_h2
   * Referenced by: '<S8>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Expression: 2.5
   * Referenced by: '<Root>/Constant5'
   */
  2.5,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S2>/TSamp'
   */
  5.0,

  /* Computed Parameter: TSamp_WtEt_e
   * Referenced by: '<S3>/TSamp'
   */
  5.0,

  /* Start of '<S8>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S11>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  ,

  /* End of '<S8>/Enabled Subsystem' */

  /* Start of '<S7>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S10>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  ,

  /* End of '<S7>/Enabled Subsystem' */

  /* Start of '<S6>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S9>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  /* End of '<S6>/Enabled Subsystem' */
};
