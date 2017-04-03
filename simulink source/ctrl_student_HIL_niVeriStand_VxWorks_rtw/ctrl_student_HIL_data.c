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
 * Model version              : 1.301
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Apr 03 12:48:03 2017
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
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S10>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Gain3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/x_pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/x_pos'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/x_pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/x_pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/x_pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/x_pos'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/y_pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/y_pos'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/y_pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/y_pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/y_pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/y_pos'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/psi_pos'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/psi_pos'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/psi_pos'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/psi_pos'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/psi_pos'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/psi_pos'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/Drop-out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/Drop-out'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/Drop-out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/Drop-out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/Drop-out'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/Drop-out'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S8>/Memory'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0]
   * Referenced by: '<S38>/Memory'
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
                                        * Referenced by: '<Root>/eta_mx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_mx'
                                        */
  7.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S12>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/N_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/X_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/Y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/integrator reset model'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/x_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/y_0'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_my'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_my'
                                        */
  8.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_mpsi'
                                        */
  9.0,                                 /* Expression: portnum
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

  /*  Expression: [7;0;0]
   * Referenced by: '<S5>/Integrator'
   */
  { 7.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/ pathNumber'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/ pathNumber'
                                        */
  40.0,                                /* Expression: portnum
                                        * Referenced by: '<S17>/ pathNumber'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/ pathNumber'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/ pathNumber'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/ pathNumber'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/ U_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/ U_ref'
                                        */
  41.0,                                /* Expression: portnum
                                        * Referenced by: '<S17>/ U_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/ U_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/ U_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/ U_ref'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Constant1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S17>/Gain'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S18>/IC'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0.00001;0.00001;0.00001]
   * Referenced by: '<S18>/IC1'
   */
  { 1.0E-5, 1.0E-5, 1.0E-5 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S21>/my'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S21>/my'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S21>/my'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S21>/my'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S21>/my'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S21>/my'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S21>/Gain'
                                        */
  1.0E-7,                              /* Expression: 0.0000001
                                        * Referenced by: '<S21>/Memory'
                                        */
  1.0E-7,                              /* Expression: 0.0000001
                                        * Referenced by: '<S18>/IC3'
                                        */

  /*  Expression: [0.0000001;0.0000001;0.0000001]
   * Referenced by: '<S18>/IC2'
   */
  { 1.0E-7, 1.0E-7, 1.0E-7 },

  /*  Expression: [0.2 0 0;0 0.2 0;0 0 0.1]
   * Referenced by: '<S17>/Constant'
   */
  { 0.2, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.1 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/K_p2_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/K_p2_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/K_p2_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/K_p2_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/K_p2_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/K_p2_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/K_p2_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/K_p2_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/K_p2_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/K_p2_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/K_p2_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/K_p2_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/K_p2_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/K_p2_3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/K_p2_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/K_p2_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/K_p2_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/K_p2_3'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S7>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/Integrator'
                                        */

  /*  Expression: [0; 0; 0]
   * Referenced by: '<S1>/Constant'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/ArrowRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_d_psi'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_d_psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_d_x'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_d_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/eta_d_PSI'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/eta_d_PSI'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/eta_d_PSI'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/eta_d_PSI'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/eta_d_PSI'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/eta_d_PSI'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/eta_d_X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/eta_d_X'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/eta_d_X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/eta_d_X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/eta_d_X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/eta_d_X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/eta_d_Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/eta_d_Y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/eta_d_Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/eta_d_Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/eta_d_Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/eta_d_Y'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S52>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S52>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S52>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S52>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S52>/control input u exceeds bounds'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S52>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S54>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S54>/alpha_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S54>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S54>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S54>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S54>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S54>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S54>/alpha_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S54>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S54>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S54>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S54>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S54>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S54>/omega_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S54>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S54>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S54>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S54>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S54>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S54>/omega_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S54>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S54>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S54>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S54>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S54>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S54>/u_BT'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S54>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S54>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S54>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S54>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S54>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S54>/u_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S54>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S54>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S54>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S54>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S54>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S54>/u_VSP2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S54>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S54>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S54>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S54>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_d_y'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_d_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/z1_psi'
                                        */
  1.0,                                 /* Expression: portnum
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
  2.0,                                 /* Expression: portnum
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
  3.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S5>/s'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/s'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/s'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/s'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/s'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/s'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/s_dot'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/s_dot'
                                        */
  30.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/s_dot'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/s_dot'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/s_dot'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/s_dot'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/bias_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/bias_x'
                                        */
  35.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/bias_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/bias_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/bias_x'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/bias_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/bias_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/bias_y'
                                        */
  36.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/bias_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/bias_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/bias_y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/bias_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/bias_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/bias_psi'
                                        */
  37.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/bias_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/bias_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/bias_psi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/bias_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S36>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S36>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S36>/ nu_x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S36>/ nu_x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S36>/ nu_x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S36>/ nu_x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S36>/ nu_y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S36>/ nu_y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S36>/ nu_y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S36>/ nu_y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S36>/ nu_y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S36>/ nu_y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S36>/nu_psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S36>/nu_psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S36>/nu_psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S36>/nu_psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S36>/nu_psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S36>/nu_psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L1_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L1_11'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/L1_11'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L1_11'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L1_11'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L1_11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L1_22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L1_22'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/L1_22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L1_22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L1_22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L1_22'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L1_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L1_33'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/L1_33'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L1_33'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L1_33'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L1_33'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L2_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L2_11'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/L2_11'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L2_11'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L2_11'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L2_11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L2_22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L2_22'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/L2_22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L2_22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L2_22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L2_22'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L2_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L2_33'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/L2_33'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L2_33'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L2_33'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L2_33'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L3_11'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L3_11'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/L3_11'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L3_11'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L3_11'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L3_11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L3_22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L3_22'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/L3_22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L3_22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L3_22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L3_22'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L3_33'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L3_33'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/L3_33'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L3_33'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L3_33'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L3_33'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/eta_mpsi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/eta_mpsi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/eta_mpsi'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/eta_mpsi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/eta_mx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/eta_mx'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/eta_mx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/eta_mx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/eta_mx'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/eta_mx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/eta_my'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/eta_my'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/eta_my'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/eta_my'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/eta_my'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/eta_my'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/y_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/y_in'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/y_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/y_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/y_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/y_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/psi_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/psi_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/psi_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/psi_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/psi_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/x_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/x_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/x_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/x_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/x_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/r_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/r_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/r_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/r_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/r_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_in'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/v_in'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/v_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/v_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/v_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/v_in'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S1>/Manual Switch'
                                        */
  0U                                   /* Computed Parameter: ManualSwitch_CurrentSetting_b
                                        * Referenced by: '<Root>/Manual Switch'
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
