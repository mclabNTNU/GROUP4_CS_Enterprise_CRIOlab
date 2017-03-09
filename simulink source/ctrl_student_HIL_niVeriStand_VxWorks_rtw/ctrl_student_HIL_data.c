/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_student_HIL_P            ctrl_student_HIL_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_student_HIL_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.158
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Mar 09 14:31:40 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

/* Block parameters (auto storage) */
P_ctrl_student_HIL_T ctrl_student_HIL_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_psi'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/K_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_psi'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Constant4'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S2>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/counter'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S17>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S17>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S18>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S18>/White Noise'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S16>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S16>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Hold'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S1>/Memory'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Drop-out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Drop-out'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Drop-out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Drop-out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Drop-out'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Drop-out'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<Root>/Memory'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ u_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ u_tilde'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/ u_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ u_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ u_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ u_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/r_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/v_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/v_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/System Reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/System Reset'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/System Reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/System Reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/System Reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/System Reset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  0.059559261465157838,                /* Expression: 1/(14.79+2)
                                        * Referenced by: '<S3>/1//m_1'
                                        */
  0.059559261465157838,                /* Expression: 1/(14.79+2)
                                        * Referenced by: '<S3>/1//m_11'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_student_HIL_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_student_HIL_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
