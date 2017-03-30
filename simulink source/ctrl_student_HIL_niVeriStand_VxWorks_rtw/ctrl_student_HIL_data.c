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
 * Model version              : 1.278
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Mar 30 17:50:23 2017
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
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S5>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/counter'
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
                                        * Referenced by: '<S30>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S30>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S30>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S31>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_d
                                        * Referenced by: '<S31>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S31>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S29>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_g
                                        * Referenced by: '<S29>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S29>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S25>/Hold'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S37>/Memory'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/Drop-out'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/Drop-out'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S7>/Memory'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/eta_mpsi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/eta_mx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/eta_my'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/eta_my'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/eta_my'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/eta_my'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/eta_my'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/eta_my'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ eta_tilde_x'
                                        */
  8.0,                                 /* Expression: portnum
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
  9.0,                                 /* Expression: portnum
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
  10.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_x'
                                        */
  11.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_y'
                                        */
  12.0,                                /* Expression: portnum
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

  /*  Expression: [7;0;0]
   * Referenced by: '<S3>/Integrator'
   */
  { 7.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/eta_d_X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/eta_d_Y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  16.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/eta_d_PSI'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat_psi'
                                        */
  13.0,                                /* Expression: portnum
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

  /*  Expression: [0;0;0]
   * Referenced by: '<S6>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/ pathNumber'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/ pathNumber'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/ pathNumber'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/ pathNumber'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/ pathNumber'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/ pathNumber'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S16>/IC'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0.00001;0.00001;0.00001]
   * Referenced by: '<S16>/IC1'
   */
  { 1.0E-5, 1.0E-5, 1.0E-5 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S19>/my'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S19>/my'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S19>/my'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S19>/my'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S19>/my'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S19>/my'
                                        */
  1.0E-7,                              /* Expression: 0.0000001
                                        * Referenced by: '<S19>/Memory'
                                        */

  /*  Expression: [0.2 0 0;0 0.2 0;0 0 0.1]
   * Referenced by: '<S15>/Constant'
   */
  { 0.2, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.1 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/L1_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L1_11'
                                        */
  11.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S2>/L1_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/L1_33'
                                        */
  13.0,                                /* Expression: portnum
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
  14.0,                                /* Expression: portnum
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
  15.0,                                /* Expression: portnum
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
  16.0,                                /* Expression: portnum
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
  17.0,                                /* Expression: portnum
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
  18.0,                                /* Expression: portnum
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
  19.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/K_p2_1'
                                        */
  20.0,                                /* Expression: portnum
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
  21.0,                                /* Expression: portnum
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
  22.0,                                /* Expression: portnum
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
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
  5.0,                                 /* Expression: portnum
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
  6.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/Controller output X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/Controller output X'
                                        */
  17.0,                                /* Expression: portnum
                                        * Referenced by: '<S12>/Controller output X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/Controller output X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/Controller output X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/Controller output X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/Controller output Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/Controller output Y'
                                        */
  18.0,                                /* Expression: portnum
                                        * Referenced by: '<S12>/Controller output Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/Controller output Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/Controller output Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/Controller output Y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/Controller output PSI'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/Controller output PSI'
                                        */
  19.0,                                /* Expression: portnum
                                        * Referenced by: '<S12>/Controller output PSI'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/Controller output PSI'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/Controller output PSI'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/Controller output PSI'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S35>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S35>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S35>/ nu_x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S35>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S35>/ nu_x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S35>/ nu_x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S35>/ nu_y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S35>/ nu_y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S35>/ nu_y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S35>/ nu_y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S35>/ nu_y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S35>/ nu_y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S35>/nu_psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S35>/nu_psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S35>/nu_psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S35>/nu_psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S35>/nu_psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S35>/nu_psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S23>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S23>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S23>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/ArrowRight'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
  1U                                   /* Computed Parameter: ManualSwitch_CurrentSetting
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
};

#endif
