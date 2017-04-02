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
 * Model version              : 1.283
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun Apr 02 13:52:02 2017
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
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S8>/Gain'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/Constant4'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S4>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/counter'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/niose_power'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/niose_power'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/niose_power'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/niose_power'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/niose_power'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/niose_power'
                                        */
  0.0001,                              /* Expression: 0.0001
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S28>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S28>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S29>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S29>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S29>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S27>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S27>/White Noise'
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
                                        * Referenced by: '<S23>/Hold'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Drop-out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Drop-out'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Drop-out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Drop-out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Drop-out'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Drop-out'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S6>/Memory'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0]
   * Referenced by: '<S35>/Memory'
   */
  { 0.0, 0.0, 0.0 },
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ eta_tilde_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat_psi'
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
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat_x'
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
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat_y'
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

  /*  Expression: [7;0;0]
   * Referenced by: '<S3>/Integrator'
   */
  { 7.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/eta_d_PSI'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/eta_d_PSI'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/eta_d_PSI'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/eta_d_PSI'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/eta_d_PSI'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/eta_d_PSI'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/eta_d_X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/eta_d_X'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/eta_d_X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/eta_d_X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/eta_d_X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/eta_d_X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/eta_d_Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/eta_d_Y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/eta_d_Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/eta_d_Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/eta_d_Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/eta_d_Y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  40.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ pathNumber'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  41.0,                                /* Expression: portnum
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/ U_ref'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Constant1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S14>/Gain'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S15>/IC'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0.00001;0.00001;0.00001]
   * Referenced by: '<S15>/IC1'
   */
  { 1.0E-5, 1.0E-5, 1.0E-5 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/my'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/my'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/my'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/my'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/my'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/my'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S18>/Gain'
                                        */
  1.0E-7,                              /* Expression: 0.0000001
                                        * Referenced by: '<S18>/Memory'
                                        */
  1.0E-7,                              /* Expression: 0.0000001
                                        * Referenced by: '<S15>/IC3'
                                        */

  /*  Expression: [0.0000001;0.0000001;0.0000001]
   * Referenced by: '<S15>/IC2'
   */
  { 1.0E-7, 1.0E-7, 1.0E-7 },

  /*  Expression: [0.2 0 0;0 0.2 0;0 0 0.1]
   * Referenced by: '<S14>/Constant'
   */
  { 0.2, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.1 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/K_p2_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/K_p2_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/K_p2_3'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S5>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S30>/Integrator'
                                        */

  /*  Expression: [0; 0; 0]
   * Referenced by: '<S1>/Constant'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/X_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/x_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/y_0'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/tau_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/tau_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/tau_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/z1_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/z1_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/z1_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/z1_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/z1_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/z1_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/z1_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/z1_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/z1_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/z1_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/z1_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/z1_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/s'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/s'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/s'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/s'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/s'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/s'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/s_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/s_dot'
                                        */
  30.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/s_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/s_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/s_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/s_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/bias_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/bias_x'
                                        */
  35.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/bias_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/bias_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/bias_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/bias_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/bias_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/bias_y'
                                        */
  36.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/bias_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/bias_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/bias_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/bias_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  37.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/bias_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S33>/ nu_x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S33>/ nu_y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S33>/nu_psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L1_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L1_11'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L1_11'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L1_11'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L1_11'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L1_11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L1_22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L1_22'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L1_22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L1_22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L1_22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L1_22'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L1_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L1_33'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L1_33'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L1_33'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L1_33'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L1_33'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L2_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L2_11'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L2_11'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L2_11'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L2_11'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L2_11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L2_22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L2_22'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L2_22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L2_22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L2_22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L2_22'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L2_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L2_33'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/L2_33'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L2_33'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L2_33'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L2_33'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L3_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L3_11'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S2>/L3_11'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L3_11'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L3_11'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L3_11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L3_22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L3_22'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S2>/L3_22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L3_22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L3_22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L3_22'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L3_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L3_33'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S2>/L3_33'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/L3_33'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/L3_33'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/L3_33'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/eta_mpsi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/eta_mpsi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/eta_mpsi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/eta_mx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/eta_mx'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/eta_mx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/eta_mx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/eta_mx'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/eta_mx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/eta_my'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/eta_my'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/eta_my'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/eta_my'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/eta_my'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/eta_my'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  1U                                   /* Computed Parameter: ManualSwitch_CurrentSetting_f
                                        * Referenced by: '<S1>/Manual Switch'
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 9, 0 },

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

  { sizeof(uint8_T), 1, 3 },

  { sizeof(uint8_T), 1, 3 },
};

#endif
