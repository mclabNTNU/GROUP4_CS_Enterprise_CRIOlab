/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_student_HIL_caseC_P      ctrl_student_HIL_caseC_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_student_HIL_caseC_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL_caseC".
 *
 * Model version              : 1.209
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Mar 31 14:51:31 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_student_HIL_caseC.h"
#include "ctrl_student_HIL_caseC_private.h"

/* Block parameters (auto storage) */
P_ctrl_student_HIL_caseC_T ctrl_student_HIL_caseC_P = {
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S3>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/counter'
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
                                        * Referenced by: '<Root>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_mpsi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_mpsi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_mpsi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_mpsi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_mx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_mx'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_mx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_mx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_mx'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_mx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_my'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_my'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/eta_my'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_my'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_my'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_my'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/integrator reset model'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S4>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/ nu_x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/ nu_x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/ nu_x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/ nu_y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/ nu_y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/ nu_y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/ nu_y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/ nu_y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/ nu_y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/nu_psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/nu_psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/nu_psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/nu_psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/nu_psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/nu_psi_hat'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L1_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L1_11'
                                        */
  6.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S2>/L3_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L3_11'
                                        */
  7.0,                                 /* Expression: portnum
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
  8.0,                                 /* Expression: portnum
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
  9.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S2>/L2_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L2_33'
                                        */
  10.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S2>/L1_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L1_33'
                                        */
  11.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S2>/L1_22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L1_22'
                                        */
  12.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S2>/L2_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L2_11'
                                        */
  13.0,                                /* Expression: portnum
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
  14.0,                                /* Expression: portnum
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

NI_ParamSizeWidth P_ctrl_student_HIL_caseC_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_student_HIL_caseC_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
