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
 * Model version              : 1.214
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun Mar 19 16:32:00 2017
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
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S2>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/counter'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/Constant4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/niose_power'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/niose_power'
                                        */
  9.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S15>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S15>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S15>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S16>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S16>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S14>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S14>/White Noise'
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
                                        * Referenced by: '<S10>/Hold'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S22>/Memory'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Drop-out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Drop-out'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Drop-out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Drop-out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Drop-out'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Drop-out'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S4>/Memory'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/eta_mpsi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/eta_mpsi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/eta_mpsi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/eta_mpsi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/eta_mx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/eta_mx'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/eta_mx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/eta_mx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/eta_mx'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/eta_mx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/eta_my'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/eta_my'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/eta_my'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/eta_my'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/eta_my'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/eta_my'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  1.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ eta_tilde_psi'
                                        */
  4.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  5.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  6.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S5>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/integrator reset model'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S3>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S20>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S20>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S20>/ nu_x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S20>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S20>/ nu_x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S20>/ nu_x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S20>/ nu_y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S20>/ nu_y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S20>/ nu_y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S20>/ nu_y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S20>/ nu_y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S20>/ nu_y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S20>/nu_psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S20>/nu_psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S20>/nu_psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S20>/nu_psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S20>/nu_psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S20>/nu_psi_hat'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/L1_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L1_11'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/L1_11'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L1_11'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L1_11'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L1_11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/L3_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L3_11'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/L3_11'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L3_11'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L3_11'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L3_11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/L3_22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L3_22'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/L3_22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L3_22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L3_22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L3_22'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/L3_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L3_33'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/L3_33'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L3_33'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L3_33'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L3_33'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/L2_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L2_33'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S1>/L2_33'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L2_33'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L2_33'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L2_33'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/L1_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L1_33'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S1>/L1_33'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L1_33'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L1_33'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L1_33'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/L1_22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L1_22'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S1>/L1_22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L1_22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L1_22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L1_22'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/L2_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L2_11'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S1>/L2_11'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L2_11'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L2_11'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L2_11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/L2_22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/L2_22'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S1>/L2_22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/L2_22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/L2_22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/L2_22'
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
};

#endif
