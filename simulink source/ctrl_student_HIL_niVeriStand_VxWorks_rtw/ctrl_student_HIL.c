/*
 * ctrl_student_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.330
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Apr 04 12:46:08 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

const real_T ctrl_student_HIL_RGND = 0.0;/* real_T ground */

/* Block signals (auto storage) */
B_ctrl_student_HIL_T ctrl_student_HIL_B;

/* Continuous states */
X_ctrl_student_HIL_T ctrl_student_HIL_X;

/* Block states (auto storage) */
DW_ctrl_student_HIL_T ctrl_student_HIL_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_student_HIL_T ctrl_student_HIL_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_student_HIL_T ctrl_student_HIL_M_;
RT_MODEL_ctrl_student_HIL_T *const ctrl_student_HIL_M = &ctrl_student_HIL_M_;

/* Forward declaration for local functions */
static void ctrl_student_HIL_inv(const real_T x[9], real_T y[9]);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 13;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_HIL_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S35>/MATLAB Function1' */
static void ctrl_student_HIL_inv(const real_T x[9], real_T y[9])
{
  real_T b_x[9];
  int32_T p1;
  int32_T p2;
  int32_T p3;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
  real_T b_y;
  memcpy(&b_x[0], &x[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = fabs(x[0]);
  absx21 = fabs(x[1]);
  absx31 = fabs(x[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    b_x[0] = x[1];
    b_x[1] = x[0];
    b_x[3] = x[4];
    b_x[4] = x[3];
    b_x[6] = x[7];
    b_x[7] = x[6];
  } else {
    if (absx31 > absx11) {
      p1 = 6;
      p3 = 0;
      b_x[0] = x[2];
      b_x[2] = x[0];
      b_x[3] = x[5];
      b_x[5] = x[3];
      b_x[6] = x[8];
      b_x[8] = x[6];
    }
  }

  absx11 = b_x[1] / b_x[0];
  b_x[1] /= b_x[0];
  absx21 = b_x[2] / b_x[0];
  b_x[2] /= b_x[0];
  b_x[4] -= absx11 * b_x[3];
  b_x[5] -= absx21 * b_x[3];
  b_x[7] -= absx11 * b_x[6];
  b_x[8] -= absx21 * b_x[6];
  if (fabs(b_x[5]) > fabs(b_x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    b_x[1] = absx21;
    b_x[2] = absx11;
    absx11 = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = absx11;
    absx11 = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = absx11;
  }

  absx31 = b_x[5];
  b_y = b_x[4];
  absx11 = b_x[5] / b_x[4];
  b_x[8] -= absx11 * b_x[7];
  absx11 = (absx11 * b_x[1] - b_x[2]) / b_x[8];
  absx21 = -(b_x[7] * absx11 + b_x[1]) / b_x[4];
  y[p1] = ((1.0 - b_x[3] * absx21) - b_x[6] * absx11) / b_x[0];
  y[p1 + 1] = absx21;
  y[p1 + 2] = absx11;
  absx11 = -(absx31 / b_y) / b_x[8];
  absx21 = (1.0 - b_x[7] * absx11) / b_x[4];
  y[p2] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
  y[p2 + 1] = absx21;
  y[p2 + 2] = absx11;
  absx11 = 1.0 / b_x[8];
  absx21 = -b_x[7] * absx11 / b_x[4];
  y[p3] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
  y[p3 + 1] = absx21;
  y[p3 + 2] = absx11;
}

/* Model output function */
void ctrl_student_HIL_output(void)
{
  /* local block i/o variables */
  real_T rtb_MatrixMultiply[3];
  real_T xd;
  real_T yd;
  real_T xds;
  real_T yds;
  real_T b_a;
  real_T x;
  real_T c_a;
  real_T c_x;
  real_T d_x;
  real_T c_13;
  real_T S_r[9];
  real_T z1[3];
  real_T alpha1[3];
  real_T z2[3];
  real_T u[4];
  static const real_T a[12] = { 0.42918454935622313, 0.0, 0.42918454935622313,
    0.0, 3.740036787247087, 0.42918454935622796, -3.7400367872470879,
    0.4291845493562183, 8.1749437972613919, 1.04638520070921E-14,
    -8.1749437972613936, -1.0519363158323358E-14 };

  real_T rtb_Gain;
  real_T rtb_Sum3;
  int32_T rtb_bool;
  real_T rtb_K_p2[9];
  real_T rtb_D[9];
  real_T rtb_C[9];
  real_T rtb_M[9];
  real_T rtb_R[9];
  real_T rtb_R_T[9];
  static const int8_T tmp[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T tmp_0[9] = { 16.79, 0.0, 0.0, 0.0, 24.79,
    0.55462499999999992, 0.0, 0.55462499999999992, 2.76 };

  int32_T i;
  real_T tmp_1[9];
  real_T rtb_R_T_0[3];
  real_T rtb_K_p2_0[9];
  real_T rtb_K_p2_1[3];
  real_T rtb_D_0[3];
  real_T S_r_0[3];
  real_T S_r_1[3];
  int32_T i_0;
  real_T tmp_2[3];
  boolean_T tmp_3;
  real_T tmp_4[9];
  real_T tmp_5[9];
  real_T tmp_6[9];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* set solver stop time */
    if (!(ctrl_student_HIL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTickH0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTick0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 +
        ctrl_student_HIL_M->Timing.clockTickH0 *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_student_HIL_M)) {
    ctrl_student_HIL_M->Timing.t[0] = rtsiGetT(&ctrl_student_HIL_M->solverInfo);
  }

  /* Gain: '<Root>/Gain3' */
  ctrl_student_HIL_B.Gain3 = ctrl_student_HIL_P.Gain3_Gain_n *
    ctrl_student_HIL_B.x_pos;

  /* Gain: '<Root>/Gain2' */
  ctrl_student_HIL_B.Gain2 = ctrl_student_HIL_P.Gain2_Gain_d *
    ctrl_student_HIL_B.y_pos;

  /* Gain: '<Root>/Gain1' */
  ctrl_student_HIL_B.Gain1 = ctrl_student_HIL_P.Gain1_Gain_h *
    ctrl_student_HIL_B.psi_pos;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S8>/Memory' */
    ctrl_student_HIL_B.Memory[0] = ctrl_student_HIL_DW.Memory_PreviousInput[0];
    ctrl_student_HIL_B.Memory[1] = ctrl_student_HIL_DW.Memory_PreviousInput[1];
    ctrl_student_HIL_B.Memory[2] = ctrl_student_HIL_DW.Memory_PreviousInput[2];
  }

  /* MATLAB Function: '<S8>/Signal drop-out simulation' incorporates:
   *  SignalConversion: '<S39>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Signal Drop-out/Signal drop-out simulation': '<S39>:1' */
  if (ctrl_student_HIL_B.Dropout == 1.0) {
    /* '<S39>:1:3' */
    /* '<S39>:1:4' */
    ctrl_student_HIL_B.eta_m_out[0] = ctrl_student_HIL_B.Memory[0];
    ctrl_student_HIL_B.eta_m_out[1] = ctrl_student_HIL_B.Memory[1];
    ctrl_student_HIL_B.eta_m_out[2] = ctrl_student_HIL_B.Memory[2];
  } else {
    /* '<S39>:1:7' */
    ctrl_student_HIL_B.eta_m_out[0] = ctrl_student_HIL_B.Gain3;
    ctrl_student_HIL_B.eta_m_out[1] = ctrl_student_HIL_B.Gain2;
    ctrl_student_HIL_B.eta_m_out[2] = ctrl_student_HIL_B.Gain1;
  }

  /* End of MATLAB Function: '<S8>/Signal drop-out simulation' */
  /* if */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S38>/Memory' */
    ctrl_student_HIL_B.Memory_a[0] = ctrl_student_HIL_DW.Memory_PreviousInput_n
      [0];
    ctrl_student_HIL_B.Memory_a[1] = ctrl_student_HIL_DW.Memory_PreviousInput_n
      [1];
    ctrl_student_HIL_B.Memory_a[2] = ctrl_student_HIL_DW.Memory_PreviousInput_n
      [2];
  }

  /* MATLAB Function: '<S38>/MATLAB Function' */
  /* MATLAB Function 'Signal Drop-out/Detection/MATLAB Function': '<S40>:1' */
  if ((ctrl_student_HIL_B.eta_m_out[0] - ctrl_student_HIL_B.Memory_a[0] == 0.0) &&
      (ctrl_student_HIL_B.eta_m_out[1] - ctrl_student_HIL_B.Memory_a[1] == 0.0) &&
      (ctrl_student_HIL_B.eta_m_out[2] - ctrl_student_HIL_B.Memory_a[2] == 0.0))
  {
    /* '<S40>:1:3' */
    /* '<S40>:1:4' */
    rtb_bool = 0;
  } else {
    /* '<S40>:1:6' */
    rtb_bool = 1;
  }

  /* '<S40>:1:9' */
  ctrl_student_HIL_B.eta_m_c1[0] = ctrl_student_HIL_B.eta_m_out[0];
  ctrl_student_HIL_B.eta_m_c1[1] = ctrl_student_HIL_B.eta_m_out[1];
  ctrl_student_HIL_B.eta_m_c1[2] = ctrl_student_HIL_B.eta_m_out[2];

  /* End of MATLAB Function: '<S38>/MATLAB Function' */

  /* Integrator: '<S7>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator2_Reset_ZCE,
                       ctrl_student_HIL_B.SystemReset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading) {
      ctrl_student_HIL_X.Integrator2_CSTATE[0] = ctrl_student_HIL_B.eta_m_c1[0];
      ctrl_student_HIL_X.Integrator2_CSTATE[1] = ctrl_student_HIL_B.eta_m_c1[1];
      ctrl_student_HIL_X.Integrator2_CSTATE[2] = ctrl_student_HIL_B.eta_m_c1[2];
    }
  }

  rtb_MatrixMultiply[0] = ctrl_student_HIL_X.Integrator2_CSTATE[0];
  rtb_MatrixMultiply[1] = ctrl_student_HIL_X.Integrator2_CSTATE[1];
  rtb_MatrixMultiply[2] = ctrl_student_HIL_X.Integrator2_CSTATE[2];

  /* InitialCondition: '<S7>/IC' */
  if ((ctrl_student_HIL_DW.IC_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC_FirstOutputTime == ctrl_student_HIL_M->Timing.t[0]))
  {
    ctrl_student_HIL_DW.IC_FirstOutputTime = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC[0] = ctrl_student_HIL_P.IC_Value[0];
    ctrl_student_HIL_B.IC[1] = ctrl_student_HIL_P.IC_Value[1];
    ctrl_student_HIL_B.IC[2] = ctrl_student_HIL_P.IC_Value[2];
  } else {
    ctrl_student_HIL_B.IC[0] = rtb_MatrixMultiply[0];
    ctrl_student_HIL_B.IC[1] = rtb_MatrixMultiply[1];
    ctrl_student_HIL_B.IC[2] = rtb_MatrixMultiply[2];
  }

  /* End of InitialCondition: '<S7>/IC' */

  /* Sum: '<Root>/Sum' */
  ctrl_student_HIL_B.Sum[0] = ctrl_student_HIL_B.eta_m_c1[0] -
    ctrl_student_HIL_B.IC[0];
  ctrl_student_HIL_B.Sum[1] = ctrl_student_HIL_B.eta_m_c1[1] -
    ctrl_student_HIL_B.IC[1];
  ctrl_student_HIL_B.Sum[2] = ctrl_student_HIL_B.eta_m_c1[2] -
    ctrl_student_HIL_B.IC[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Integrator: '<S5>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_student_HIL_B.SystemReset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator_CSTATE[0] =
        (ctrl_student_HIL_P.Integrator_IC[0]);
      ctrl_student_HIL_X.Integrator_CSTATE[1] =
        (ctrl_student_HIL_P.Integrator_IC[1]);
      ctrl_student_HIL_X.Integrator_CSTATE[2] =
        (ctrl_student_HIL_P.Integrator_IC[2]);
    }
  }

  ctrl_student_HIL_B.Integrator[0] = ctrl_student_HIL_X.Integrator_CSTATE[0];
  ctrl_student_HIL_B.Integrator[1] = ctrl_student_HIL_X.Integrator_CSTATE[1];
  ctrl_student_HIL_B.Integrator[2] = ctrl_student_HIL_X.Integrator_CSTATE[2];

  /* Integrator: '<S5>/Integrator1' */
  ctrl_student_HIL_B.Integrator1 = ctrl_student_HIL_X.Integrator1_CSTATE;

  /* Gain: '<S17>/Gain' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Sum: '<S17>/Sum'
   */
  rtb_Gain = (ctrl_student_HIL_P.Constant1_Value_e - ctrl_student_HIL_B.U_ref) *
    ctrl_student_HIL_P.Gain_Gain_l;

  /* MATLAB Function: '<S18>/Ellipsoid' */
  /* MATLAB Function 'Guidance/Path generation/Ellipsoid': '<S22>:1' */
  /* U_ref */
  /* U_ref = 0.1; */
  /* Path variables */
  /* '<S22>:1:8' */
  /* '<S22>:1:9' */
  /* eta_d */
  /* '<S22>:1:12' */
  xd = 5.0 * cos(ctrl_student_HIL_B.Integrator1) + 6.0;

  /* '<S22>:1:13' */
  yd = 3.0 * sin(ctrl_student_HIL_B.Integrator1);

  /* '<S22>:1:14' */
  /* eta_ds */
  /* '<S22>:1:17' */
  xds = -5.0 * sin(ctrl_student_HIL_B.Integrator1);

  /* '<S22>:1:18' */
  yds = 3.0 * cos(ctrl_student_HIL_B.Integrator1);

  /* '<S22>:1:19' */
  rtb_Sum3 = 5.0 * sin(ctrl_student_HIL_B.Integrator1);
  b_a = 3.0 * cos(ctrl_student_HIL_B.Integrator1);

  /* eta_ds2 */
  /* '<S22>:1:22' */
  /* '<S22>:1:23' */
  /* '<S22>:1:24' */
  x = 1.0 / sin(ctrl_student_HIL_B.Integrator1);
  c_13 = 1.0 / tan(ctrl_student_HIL_B.Integrator1);
  c_a = c_13 * c_13 * 9.0 + 25.0;

  /* eta_d_vectors */
  /* '<S22>:1:27' */
  /* '<S22>:1:28' */
  /* '<S22>:1:29' */
  /* U_s */
  /* '<S22>:1:32' */
  /* '<S22>:1:33' */
  c_x = sin(ctrl_student_HIL_B.Integrator1);
  d_x = cos(ctrl_student_HIL_B.Integrator1);

  /* Sum: '<S18>/Sum2' incorporates:
   *  MATLAB Function: '<S18>/Ellipsoid'
   *  MATLAB Function: '<S18>/straight line'
   */
  /* MATLAB Function 'Guidance/Path generation/straight line': '<S23>:1' */
  /* U_ref */
  /* U_ref = 0.1; */
  /* U_ref = 0.2*(1.01+sin(2*pi*s-(pi/2))); */
  /*  %Path variables */
  /* '<S23>:1:7' */
  /* '<S23>:1:8' */
  /* Slope */
  /* eta_d */
  /* '<S23>:1:17' */
  /* '<S23>:1:18' */
  /* '<S23>:1:19' */
  /*  psi_d = atan2(yd,xd); */
  /* eta_d_vectors */
  /* '<S23>:1:23' */
  /* '<S23>:1:24' */
  /* '<S23>:1:25' */
  /* U_s */
  /* '<S23>:1:28' */
  /* '<S23>:1:29' */
  /* U_ss=U_ref*2*pi*sin(2*pi*s)/(sqrt(a1^2+a2^2))*(1-path); */
  rtb_MatrixMultiply[0] = 5.0 * ctrl_student_HIL_B.Integrator1 * (1.0 -
    ctrl_student_HIL_B.pathNumber) + xd * ctrl_student_HIL_B.pathNumber;
  rtb_MatrixMultiply[1] = 0.0 * ctrl_student_HIL_B.Integrator1 * (1.0 -
    ctrl_student_HIL_B.pathNumber) + yd * ctrl_student_HIL_B.pathNumber;
  rtb_MatrixMultiply[2] = (1.0 - ctrl_student_HIL_B.pathNumber) * 0.0 +
    rt_atan2d_snf(yd, xd) * ctrl_student_HIL_B.pathNumber;

  /* InitialCondition: '<S18>/IC' */
  if ((ctrl_student_HIL_DW.IC_FirstOutputTime_h == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC_FirstOutputTime_h == ctrl_student_HIL_M->Timing.t
       [0])) {
    ctrl_student_HIL_DW.IC_FirstOutputTime_h = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC_d[0] = ctrl_student_HIL_P.IC_Value_o[0];
    ctrl_student_HIL_B.IC_d[1] = ctrl_student_HIL_P.IC_Value_o[1];
    ctrl_student_HIL_B.IC_d[2] = ctrl_student_HIL_P.IC_Value_o[2];
  } else {
    ctrl_student_HIL_B.IC_d[0] = rtb_MatrixMultiply[0];
    ctrl_student_HIL_B.IC_d[1] = rtb_MatrixMultiply[1];
    ctrl_student_HIL_B.IC_d[2] = rtb_MatrixMultiply[2];
  }

  /* End of InitialCondition: '<S18>/IC' */

  /* Sum: '<S18>/Sum4' incorporates:
   *  MATLAB Function: '<S18>/Ellipsoid'
   *  MATLAB Function: '<S18>/straight line'
   */
  rtb_MatrixMultiply[0] = (1.0 - ctrl_student_HIL_B.pathNumber) * 5.0 + xds *
    ctrl_student_HIL_B.pathNumber;
  rtb_MatrixMultiply[1] = (1.0 - ctrl_student_HIL_B.pathNumber) * 0.0 + yds *
    ctrl_student_HIL_B.pathNumber;
  rtb_MatrixMultiply[2] = 15.0 / (rtb_Sum3 * rtb_Sum3 + b_a * b_a) *
    ctrl_student_HIL_B.pathNumber + (1.0 - ctrl_student_HIL_B.pathNumber) * 0.0;

  /* InitialCondition: '<S18>/IC1' */
  if ((ctrl_student_HIL_DW.IC1_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC1_FirstOutputTime == ctrl_student_HIL_M->Timing.t[0]))
  {
    ctrl_student_HIL_DW.IC1_FirstOutputTime = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC1[0] = ctrl_student_HIL_P.IC1_Value[0];
    ctrl_student_HIL_B.IC1[1] = ctrl_student_HIL_P.IC1_Value[1];
    ctrl_student_HIL_B.IC1[2] = ctrl_student_HIL_P.IC1_Value[2];
  } else {
    ctrl_student_HIL_B.IC1[0] = rtb_MatrixMultiply[0];
    ctrl_student_HIL_B.IC1[1] = rtb_MatrixMultiply[1];
    ctrl_student_HIL_B.IC1[2] = rtb_MatrixMultiply[2];
  }

  /* End of InitialCondition: '<S18>/IC1' */

  /* Sum: '<S18>/Sum3' incorporates:
   *  MATLAB Function: '<S18>/Ellipsoid'
   *  MATLAB Function: '<S18>/straight line'
   */
  rtb_Sum3 = rtb_Gain / sqrt(xds * xds + yds * yds) *
    ctrl_student_HIL_B.pathNumber + rtb_Gain / 5.0 * (1.0 -
    ctrl_student_HIL_B.pathNumber);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S21>/Memory' */
    ctrl_student_HIL_B.Memory_p = ctrl_student_HIL_DW.Memory_PreviousInput_g;
  }

  /* MATLAB Function: '<S21>/s calculation' incorporates:
   *  Gain: '<S21>/Gain'
   */
  c_13 = ctrl_student_HIL_B.Memory_p;

  /* MATLAB Function 'Guidance/s_dot generation/s calculation': '<S24>:1' */
  /* V_1s = -0.5*(eta_ds.')*(eta-eta_d)-0.5*((eta-eta_d).')*eta_ds; */
  /* '<S24>:1:5' */
  /* '<S24>:1:7' */
  yd = 2.2250738585072014E-308;
  xds = fabs(ctrl_student_HIL_B.IC1[0]);
  if (xds > 2.2250738585072014E-308) {
    xd = 1.0;
    yd = xds;
  } else {
    yds = xds / 2.2250738585072014E-308;
    xd = yds * yds;
  }

  xds = fabs(ctrl_student_HIL_B.IC1[1]);
  if (xds > yd) {
    yds = yd / xds;
    xd = xd * yds * yds + 1.0;
    yd = xds;
  } else {
    yds = xds / yd;
    xd += yds * yds;
  }

  xds = fabs(ctrl_student_HIL_B.IC1[2]);
  if (xds > yd) {
    yds = yd / xds;
    xd = xd * yds * yds + 1.0;
    yd = xds;
  } else {
    yds = xds / yd;
    xd += yds * yds;
  }

  xd = yd * sqrt(xd);
  ctrl_student_HIL_B.s_dot = rtb_Sum3 - ((-(ctrl_student_HIL_B.Integrator[0] -
    ctrl_student_HIL_B.IC_d[0]) * ctrl_student_HIL_B.IC1[0] +
    -(ctrl_student_HIL_B.Integrator[1] - ctrl_student_HIL_B.IC_d[1]) *
    ctrl_student_HIL_B.IC1[1]) + -(ctrl_student_HIL_B.Integrator[2] -
    ctrl_student_HIL_B.IC_d[2]) * ctrl_student_HIL_B.IC1[2]) *
    (ctrl_student_HIL_P.Gain_Gain_f * ctrl_student_HIL_B.my / xd);
  if (ctrl_student_HIL_B.Memory_p == 0.0) {
    /* '<S24>:1:9' */
    /* '<S24>:1:10' */
    c_13 = 4.94065645841247E-324;
  }

  if (ctrl_student_HIL_B.pathNumber == 0.0) {
    /* '<S24>:1:13' */
    if ((ctrl_student_HIL_B.Integrator1 < 1.0) &&
        (ctrl_student_HIL_B.Integrator1 > 0.0)) {
      /* '<S24>:1:14' */
      if (ctrl_student_HIL_B.Integrator1 < 0.0) {
        xd = -1.0;
      } else if (ctrl_student_HIL_B.Integrator1 > 0.0) {
        xd = 1.0;
      } else if (ctrl_student_HIL_B.Integrator1 == 0.0) {
        xd = 0.0;
      } else {
        xd = ctrl_student_HIL_B.Integrator1;
      }

      if (c_13 < 0.0) {
        xds = -1.0;
      } else if (c_13 > 0.0) {
        xds = 1.0;
      } else if (c_13 == 0.0) {
        xds = 0.0;
      } else {
        xds = c_13;
      }

      if (!(xd == xds)) {
        /* '<S24>:1:18' */
        if (c_13 < 0.0) {
          c_13 = -1.0;
        } else if (c_13 > 0.0) {
          c_13 = 1.0;
        } else {
          if (c_13 == 0.0) {
            c_13 = 0.0;
          }
        }

        ctrl_student_HIL_B.s_dot *= c_13;
      } else {
        /* '<S24>:1:15' */
        /* '<S24>:1:16' */
      }
    } else if (ctrl_student_HIL_B.Integrator1 >= 1.0) {
      /* '<S24>:1:20' */
      if (ctrl_student_HIL_B.Integrator1 < 0.0) {
        xd = -1.0;
      } else if (ctrl_student_HIL_B.Integrator1 > 0.0) {
        xd = 1.0;
      } else if (ctrl_student_HIL_B.Integrator1 == 0.0) {
        xd = 0.0;
      } else {
        xd = ctrl_student_HIL_B.Integrator1;
      }

      if (c_13 < 0.0) {
        xds = -1.0;
      } else if (c_13 > 0.0) {
        xds = 1.0;
      } else if (c_13 == 0.0) {
        xds = 0.0;
      } else {
        xds = c_13;
      }

      if (xd == xds) {
        /* '<S24>:1:21' */
        /* '<S24>:1:22' */
        ctrl_student_HIL_B.s_dot = -ctrl_student_HIL_B.s_dot;
      } else {
        /* '<S24>:1:24' */
        if (c_13 < 0.0) {
          c_13 = -1.0;
        } else if (c_13 > 0.0) {
          c_13 = 1.0;
        } else {
          if (c_13 == 0.0) {
            c_13 = 0.0;
          }
        }

        ctrl_student_HIL_B.s_dot *= c_13;
      }
    } else {
      if (ctrl_student_HIL_B.Integrator1 < 0.0) {
        xd = -1.0;
      } else if (ctrl_student_HIL_B.Integrator1 > 0.0) {
        xd = 1.0;
      } else if (ctrl_student_HIL_B.Integrator1 == 0.0) {
        xd = 0.0;
      } else {
        xd = ctrl_student_HIL_B.Integrator1;
      }

      if (c_13 < 0.0) {
        xds = -1.0;
      } else if (c_13 > 0.0) {
        xds = 1.0;
      } else if (c_13 == 0.0) {
        xds = 0.0;
      } else {
        xds = c_13;
      }

      if ((ctrl_student_HIL_B.Integrator1 <= 0.0) && (!(xd == xds))) {
        /* '<S24>:1:27' */
        /* '<S24>:1:31' */
        if (c_13 < 0.0) {
          c_13 = -1.0;
        } else if (c_13 > 0.0) {
          c_13 = 1.0;
        } else {
          if (c_13 == 0.0) {
            c_13 = 0.0;
          }
        }

        ctrl_student_HIL_B.s_dot *= c_13;
      } else {
        /* '<S24>:1:28' */
        /* '<S24>:1:29' */
      }
    }
  }

  /* End of MATLAB Function: '<S21>/s calculation' */

  /* InitialCondition: '<S18>/IC3' incorporates:
   *  MATLAB Function: '<S18>/Ellipsoid'
   */
  if ((ctrl_student_HIL_DW.IC3_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC3_FirstOutputTime == ctrl_student_HIL_M->Timing.t[0]))
  {
    ctrl_student_HIL_DW.IC3_FirstOutputTime = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC3 = ctrl_student_HIL_P.IC3_Value;
  } else {
    ctrl_student_HIL_B.IC3 = -rtb_Gain * 16.0 * sin
      (ctrl_student_HIL_B.Integrator1) * cos(ctrl_student_HIL_B.Integrator1) /
      rt_powd_snf(c_x * c_x * 25.0 + d_x * d_x * 9.0, 1.5) *
      ctrl_student_HIL_B.pathNumber;
  }

  /* End of InitialCondition: '<S18>/IC3' */

  /* Sum: '<S18>/Sum' incorporates:
   *  MATLAB Function: '<S18>/Ellipsoid'
   */
  rtb_MatrixMultiply[0] = -5.0 * cos(ctrl_student_HIL_B.Integrator1) *
    ctrl_student_HIL_B.pathNumber;
  rtb_MatrixMultiply[1] = -3.0 * sin(ctrl_student_HIL_B.Integrator1) *
    ctrl_student_HIL_B.pathNumber;
  rtb_MatrixMultiply[2] = 1.0 / tan(ctrl_student_HIL_B.Integrator1) * -480.0 *
    (x * x) / (c_a * c_a) * ctrl_student_HIL_B.pathNumber;

  /* InitialCondition: '<S18>/IC2' */
  if ((ctrl_student_HIL_DW.IC2_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC2_FirstOutputTime == ctrl_student_HIL_M->Timing.t[0]))
  {
    ctrl_student_HIL_DW.IC2_FirstOutputTime = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC2[0] = ctrl_student_HIL_P.IC2_Value[0];
    ctrl_student_HIL_B.IC2[1] = ctrl_student_HIL_P.IC2_Value[1];
    ctrl_student_HIL_B.IC2[2] = ctrl_student_HIL_P.IC2_Value[2];
  } else {
    ctrl_student_HIL_B.IC2[0] = rtb_MatrixMultiply[0];
    ctrl_student_HIL_B.IC2[1] = rtb_MatrixMultiply[1];
    ctrl_student_HIL_B.IC2[2] = rtb_MatrixMultiply[2];
  }

  /* End of InitialCondition: '<S18>/IC2' */

  /* MATLAB Function: '<S4>/Controller gain matrix k_p2' */
  /* MATLAB Function 'Gain Matrices/Controller gain matrix k_p2': '<S15>:1' */
  /* Gain matrix for controller gain values k_p2 */
  /* '<S15>:1:3' */
  rtb_K_p2[0] = ctrl_student_HIL_B.K_p2_1 * 0.01;
  rtb_K_p2[3] = 0.0;
  rtb_K_p2[6] = 0.0;
  rtb_K_p2[1] = 0.0;
  rtb_K_p2[4] = ctrl_student_HIL_B.K_p2_2 * 0.01;
  rtb_K_p2[7] = 0.0;
  rtb_K_p2[2] = 0.0;
  rtb_K_p2[5] = 0.0;
  rtb_K_p2[8] = ctrl_student_HIL_B.K_p2_3 * 0.01;

  /*  K_p2 = [1 0 0; 0 2 0; 0 0 3]; */

  /* Integrator: '<S7>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_student_HIL_B.Dropout);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator1_CSTATE_b[0] =
        (ctrl_student_HIL_P.Integrator1_IC_m[0]);
      ctrl_student_HIL_X.Integrator1_CSTATE_b[1] =
        (ctrl_student_HIL_P.Integrator1_IC_m[1]);
      ctrl_student_HIL_X.Integrator1_CSTATE_b[2] =
        (ctrl_student_HIL_P.Integrator1_IC_m[2]);
    }
  }

  ctrl_student_HIL_B.Integrator1_k[0] = ctrl_student_HIL_X.Integrator1_CSTATE_b
    [0];
  ctrl_student_HIL_B.Integrator1_k[1] = ctrl_student_HIL_X.Integrator1_CSTATE_b
    [1];
  ctrl_student_HIL_B.Integrator1_k[2] = ctrl_student_HIL_X.Integrator1_CSTATE_b
    [2];

  /* MATLAB Function: '<S35>/MATLAB Function1' */
  memcpy(&rtb_M[0], &tmp_0[0], 9U * sizeof(real_T));

  /* MATLAB Function 'Observer/kinematics/MATLAB Function1': '<S37>:1' */
  /* '<S37>:1:2' */
  /* '<S37>:1:3' */
  /* '<S37>:1:4' */
  /*  u   = 1; */
  /*  v   = 1; */
  /*  r   = 1; */
  /* % MATRICES */
  /*  x_g  =  0.0460; % Table B.1 */
  /* % Added mass */
  /*  Table B.1 */
  /*  Table B.1 guestimate */
  /*  Table B.1 */
  /* % Total mass matrix */
  /* '<S37>:1:26' */
  /* '<S37>:1:30' */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S37>:1:33' */
  /* '<S37>:1:37' */
  /*  Y_r */
  /*  Y_rrzx */
  /*  Y_rv, Y_vr */
  /* '<S37>:1:43' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* % Correolis matrix */
  /* '<S37>:1:50' */
  /* '<S37>:1:51' */
  c_13 = -10.0 * ctrl_student_HIL_B.Integrator1_k[1] + -0.55462499999999992 *
    ctrl_student_HIL_B.Integrator1_k[2];

  /* '<S37>:1:52' */
  /* '<S37>:1:53' */
  xd = 2.0 * ctrl_student_HIL_B.Integrator1_k[0];

  /* '<S37>:1:54' */
  /* '<S37>:1:55' */
  /* '<S37>:1:56' */
  /* % Assembly of the damping matrix */
  /* '<S37>:1:61' */
  /* '<S37>:1:62' */
  /* '<S37>:1:63' */
  /* '<S37>:1:64' */
  /* '<S37>:1:65' */
  /*  using abs(r) */
  /* '<S37>:1:67' */
  rtb_D[0] = (0.6555 - 0.3545 * fabs(ctrl_student_HIL_B.Integrator1_k[0])) -
    ctrl_student_HIL_B.Integrator1_k[0] * ctrl_student_HIL_B.Integrator1_k[0] *
    -3.787;
  rtb_D[3] = 0.0;
  rtb_D[6] = 0.0;
  rtb_D[1] = 0.0;
  rtb_D[4] = ((1.33 - -2.776 * fabs(ctrl_student_HIL_B.Integrator1_k[1])) -
              ctrl_student_HIL_B.Integrator1_k[1] *
              ctrl_student_HIL_B.Integrator1_k[1] * -64.91) - -0.805 * fabs
    (ctrl_student_HIL_B.Integrator1_k[2]);
  rtb_D[7] = ((7.25 - -0.845 * fabs(ctrl_student_HIL_B.Integrator1_k[1])) -
              -3.45 * fabs(ctrl_student_HIL_B.Integrator1_k[2])) -
    ctrl_student_HIL_B.Integrator1_k[2] * ctrl_student_HIL_B.Integrator1_k[2] *
    0.0;
  rtb_D[2] = 0.0;
  rtb_D[5] = ((-0.0 - -0.2088 * fabs(ctrl_student_HIL_B.Integrator1_k[1])) -
              ctrl_student_HIL_B.Integrator1_k[1] *
              ctrl_student_HIL_B.Integrator1_k[1] * 0.0) - 0.13 * fabs
    (ctrl_student_HIL_B.Integrator1_k[2]);
  rtb_D[8] = ((1.9 - 0.08 * fabs(ctrl_student_HIL_B.Integrator1_k[1])) - -0.75 *
              fabs(ctrl_student_HIL_B.Integrator1_k[2])) -
    ctrl_student_HIL_B.Integrator1_k[2] * ctrl_student_HIL_B.Integrator1_k[2] *
    0.0;
  rtb_C[0] = 0.0;
  rtb_C[3] = -14.79 * ctrl_student_HIL_B.Integrator1_k[2];
  rtb_C[6] = c_13;
  rtb_C[1] = 14.79 * ctrl_student_HIL_B.Integrator1_k[2];
  rtb_C[4] = 0.0;
  rtb_C[7] = xd;
  rtb_C[2] = -c_13;
  rtb_C[5] = -xd;
  rtb_C[8] = 0.0;

  /* MATLAB Function: '<S7>/MATLAB Function' */
  /* MATLAB Function 'Observer/MATLAB Function': '<S34>:1' */
  /* '<S34>:1:3' */
  /* '<S34>:1:5' */
  rtb_R[0] = cos(ctrl_student_HIL_B.IC[2]);
  rtb_R[3] = -sin(ctrl_student_HIL_B.IC[2]);
  rtb_R[6] = 0.0;
  rtb_R[1] = sin(ctrl_student_HIL_B.IC[2]);
  rtb_R[4] = cos(ctrl_student_HIL_B.IC[2]);
  rtb_R[7] = 0.0;
  rtb_R[2] = 0.0;
  rtb_R[5] = 0.0;
  rtb_R[8] = 1.0;

  /* Rotation matrix */
  /* '<S34>:1:7' */
  for (i = 0; i < 3; i++) {
    rtb_R_T[3 * i] = rtb_R[i];
    rtb_R_T[1 + 3 * i] = rtb_R[i + 3];
    rtb_R_T[2 + 3 * i] = rtb_R[i + 6];
  }

  /* End of MATLAB Function: '<S7>/MATLAB Function' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S17>/Constant'
   */
  /* Transpose rotation matrix */
  /* MATLAB Function 'Controller/MATLAB Function': '<S14>:1' */
  /* Rotation rate matrix */
  /* '<S14>:1:4' */
  S_r[0] = 0.0;
  S_r[3] = -ctrl_student_HIL_B.Integrator1_k[2];
  S_r[6] = 0.0;
  S_r[1] = ctrl_student_HIL_B.Integrator1_k[2];
  S_r[4] = 0.0;
  S_r[7] = 0.0;
  S_r[2] = 0.0;
  S_r[5] = 0.0;
  S_r[8] = 0.0;

  /* Error states */
  /* '<S14>:1:7' */
  ctrl_student_HIL_B.z1_inertial[0] = ctrl_student_HIL_B.IC[0] -
    ctrl_student_HIL_B.Integrator[0];
  ctrl_student_HIL_B.z1_inertial[1] = ctrl_student_HIL_B.IC[1] -
    ctrl_student_HIL_B.Integrator[1];
  ctrl_student_HIL_B.z1_inertial[2] = ctrl_student_HIL_B.IC[2] -
    ctrl_student_HIL_B.Integrator[2];

  /* '<S14>:1:8' */
  xd = ctrl_student_HIL_B.IC[0] - ctrl_student_HIL_B.Integrator[0];
  xds = ctrl_student_HIL_B.IC[1] - ctrl_student_HIL_B.Integrator[1];
  yd = ctrl_student_HIL_B.IC[2] - ctrl_student_HIL_B.Integrator[2];
  for (i = 0; i < 3; i++) {
    z1[i] = rtb_R_T[i + 6] * yd + (rtb_R_T[i + 3] * xds + rtb_R_T[i] * xd);
  }

  /* Virtual Controller */
  /* '<S14>:1:11' */
  for (i = 0; i < 3; i++) {
    tmp_1[3 * i] = -ctrl_student_HIL_P.Constant_Value_n[3 * i];
    tmp_1[1 + 3 * i] = -ctrl_student_HIL_P.Constant_Value_n[3 * i + 1];
    tmp_1[2 + 3 * i] = -ctrl_student_HIL_P.Constant_Value_n[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    rtb_R_T_0[i] = rtb_R_T[i + 6] * ctrl_student_HIL_B.IC1[2] + (rtb_R_T[i + 3] *
      ctrl_student_HIL_B.IC1[1] + rtb_R_T[i] * ctrl_student_HIL_B.IC1[0]);
  }

  for (i = 0; i < 3; i++) {
    alpha1[i] = ((tmp_1[i + 3] * z1[1] + tmp_1[i] * z1[0]) + tmp_1[i + 6] * z1[2])
      + rtb_R_T_0[i] * rtb_Sum3;
  }

  /* Error states */
  /* '<S14>:1:14' */
  z2[0] = ctrl_student_HIL_B.Integrator1_k[0] - alpha1[0];
  z2[1] = ctrl_student_HIL_B.Integrator1_k[1] - alpha1[1];
  z2[2] = ctrl_student_HIL_B.Integrator1_k[2] - alpha1[2];

  /* Integrator: '<S33>/Integrator' */
  /* Error state derivatives */
  /* '<S14>:1:17' */
  /* Alpha1_dot */
  /* '<S14>:1:20' */
  /* '<S14>:1:21' */
  /* '<S14>:1:22' */
  /* Tau (Is the nu_hat correctly used here?) */
  /* '<S14>:1:25' */
  rtb_MatrixMultiply[0] = ctrl_student_HIL_X.Integrator_CSTATE_n[0];
  rtb_MatrixMultiply[1] = ctrl_student_HIL_X.Integrator_CSTATE_n[1];
  rtb_MatrixMultiply[2] = ctrl_student_HIL_X.Integrator_CSTATE_n[2];

  /* Product: '<S33>/Matrix Multiply2' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.MatrixMultiply2[i] = 0.0;
    ctrl_student_HIL_B.MatrixMultiply2[i] += rtb_R_T[i] * rtb_MatrixMultiply[0];
    ctrl_student_HIL_B.MatrixMultiply2[i] += rtb_R_T[i + 3] *
      rtb_MatrixMultiply[1];
    ctrl_student_HIL_B.MatrixMultiply2[i] += rtb_R_T[i + 6] *
      rtb_MatrixMultiply[2];
  }

  /* End of Product: '<S33>/Matrix Multiply2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Gain: '<S10>/Gain'
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Gain3'
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S1>/Sum1'
   */
  if (ctrl_student_HIL_P.ManualSwitch_CurrentSetting_b == 1) {
    /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
     *  Constant: '<S17>/Constant'
     */
    for (i = 0; i < 3; i++) {
      rtb_K_p2_0[3 * i] = -rtb_K_p2[3 * i];
      rtb_K_p2_0[1 + 3 * i] = -rtb_K_p2[3 * i + 1];
      rtb_K_p2_0[2 + 3 * i] = -rtb_K_p2[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      rtb_K_p2_1[i] = ((rtb_K_p2_0[i + 3] * z2[1] + rtb_K_p2_0[i] * z2[0]) +
                       rtb_K_p2_0[i + 6] * z2[2]) - z1[i];
    }

    for (i = 0; i < 3; i++) {
      rtb_D_0[i] = rtb_D[i + 6] * ctrl_student_HIL_B.Integrator1_k[2] + (rtb_D[i
        + 3] * ctrl_student_HIL_B.Integrator1_k[1] + rtb_D[i] *
        ctrl_student_HIL_B.Integrator1_k[0]);
    }

    for (i = 0; i < 3; i++) {
      rtb_K_p2_0[3 * i] = -S_r[3 * i];
      rtb_K_p2_0[1 + 3 * i] = -S_r[3 * i + 1];
      rtb_K_p2_0[2 + 3 * i] = -S_r[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      rtb_R_T_0[i] = rtb_R_T[i + 6] * ctrl_student_HIL_B.IC1[2] + (rtb_R_T[i + 3]
        * ctrl_student_HIL_B.IC1[1] + rtb_R_T[i] * ctrl_student_HIL_B.IC1[0]);
    }

    for (i = 0; i < 3; i++) {
      tmp_1[3 * i] = -ctrl_student_HIL_P.Constant_Value_n[3 * i];
      tmp_1[1 + 3 * i] = -ctrl_student_HIL_P.Constant_Value_n[3 * i + 1];
      tmp_1[2 + 3 * i] = -ctrl_student_HIL_P.Constant_Value_n[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      S_r_0[i] = ((((rtb_K_p2_0[i + 3] * z1[1] + rtb_K_p2_0[i] * z1[0]) +
                    rtb_K_p2_0[i + 6] * z1[2]) + z2[i]) + alpha1[i]) -
        rtb_R_T_0[i] * ctrl_student_HIL_B.s_dot;
    }

    for (i = 0; i < 3; i++) {
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_K_p2_0[i + 3 * i_0] = 0.0;
        rtb_K_p2_0[i + 3 * i_0] += rtb_R_T[3 * i_0] * S_r[i];
        rtb_K_p2_0[i + 3 * i_0] += rtb_R_T[3 * i_0 + 1] * S_r[i + 3];
        rtb_K_p2_0[i + 3 * i_0] += rtb_R_T[3 * i_0 + 2] * 0.0;
      }
    }

    for (i = 0; i < 3; i++) {
      S_r_1[i] = rtb_K_p2_0[i + 6] * ctrl_student_HIL_B.IC1[2] + (rtb_K_p2_0[i +
        3] * ctrl_student_HIL_B.IC1[1] + rtb_K_p2_0[i] * ctrl_student_HIL_B.IC1
        [0]);
    }

    for (i = 0; i < 3; i++) {
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_K_p2_0[i + 3 * i_0] = 0.0;
        rtb_K_p2_0[i + 3 * i_0] += rtb_R_T[3 * i_0] *
          ctrl_student_HIL_P.Constant_Value_n[i];
        rtb_K_p2_0[i + 3 * i_0] += rtb_R_T[3 * i_0 + 1] *
          ctrl_student_HIL_P.Constant_Value_n[i + 3];
        rtb_K_p2_0[i + 3 * i_0] += rtb_R_T[3 * i_0 + 2] *
          ctrl_student_HIL_P.Constant_Value_n[i + 6];
      }
    }

    for (i = 0; i < 3; i++) {
      rtb_R_T_0[i] = rtb_R_T[i + 6] * ctrl_student_HIL_B.IC2[2] + (rtb_R_T[i + 3]
        * ctrl_student_HIL_B.IC2[1] + rtb_R_T[i] * ctrl_student_HIL_B.IC2[0]);
    }

    for (i = 0; i < 3; i++) {
      alpha1[i] = rtb_R_T[i + 6] * ctrl_student_HIL_B.IC1[2] + (rtb_R_T[i + 3] *
        ctrl_student_HIL_B.IC1[1] + rtb_R_T[i] * ctrl_student_HIL_B.IC1[0]);
    }

    for (i = 0; i < 3; i++) {
      tmp_2[i] = (((rtb_K_p2_0[i + 3] * ctrl_student_HIL_B.IC1[1] + rtb_K_p2_0[i]
                    * ctrl_student_HIL_B.IC1[0]) + rtb_K_p2_0[i + 6] *
                   ctrl_student_HIL_B.IC1[2]) + rtb_R_T_0[i] * rtb_Sum3) +
        alpha1[i] * ctrl_student_HIL_B.IC3;
    }

    for (i = 0; i < 3; i++) {
      z2[i] = (((tmp_1[i + 3] * S_r_0[1] + tmp_1[i] * S_r_0[0]) + tmp_1[i + 6] *
                S_r_0[2]) - S_r_1[i] * rtb_Sum3) + tmp_2[i] *
        ctrl_student_HIL_B.s_dot;
    }

    /* ManualSwitch: '<S1>/Manual Switch' */
    tmp_3 = (ctrl_student_HIL_P.ManualSwitch_CurrentSetting == 1);
    for (i = 0; i < 3; i++) {
      /* Sum: '<S1>/Sum1' incorporates:
       *  Constant: '<S1>/Constant'
       *  MATLAB Function: '<S1>/MATLAB Function'
       *  ManualSwitch: '<S1>/Manual Switch'
       */
      if (tmp_3) {
        xd = ctrl_student_HIL_B.MatrixMultiply2[i];
      } else {
        xd = ctrl_student_HIL_P.Constant_Value_m[i];
      }

      ctrl_student_HIL_B.ManualSwitch[i] = (((rtb_M[i + 3] * z2[1] + rtb_M[i] *
        z2[0]) + rtb_M[i + 6] * z2[2]) + (rtb_K_p2_1[i] + rtb_D_0[i])) + xd;
    }
  } else {
    ctrl_student_HIL_B.ManualSwitch[0] = ctrl_student_HIL_P.Gain1_Gain *
      ctrl_student_HIL_B.PosYRight;
    ctrl_student_HIL_B.ManualSwitch[1] = ctrl_student_HIL_P.Gain2_Gain *
      ctrl_student_HIL_B.PosXRight;
    ctrl_student_HIL_B.ManualSwitch[2] = (ctrl_student_HIL_B.L2_continuous -
      ctrl_student_HIL_B.R2_continuous) * ctrl_student_HIL_P.Gain_Gain *
      ctrl_student_HIL_P.Gain3_Gain;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  ctrl_student_HIL_B.Sum1 = ctrl_student_HIL_B.ManualSwitch[2] +
    ctrl_student_HIL_P.Constant_Value_k;

  /* Gain: '<Root>/Gain7' */
  ctrl_student_HIL_B.Gain7 = ctrl_student_HIL_P.Gain7_Gain *
    ctrl_student_HIL_B.ManualSwitch[0];

  /* Gain: '<Root>/Gain6' */
  ctrl_student_HIL_B.Gain6 = ctrl_student_HIL_P.Gain6_Gain *
    ctrl_student_HIL_B.ManualSwitch[1];

  /* MATLAB Function: '<S13>/Thrust Allocation 2x VSP' incorporates:
   *  Constant: '<S13>/Constant'
   */
  /* MATLAB Function 'tau to real ship (only use in MCLab)/Thrust Allocation 2x VSP': '<S51>:1' */
  /* Omega: Voith Scnheider rotational speed [rad/s] */
  if (ctrl_student_HIL_P.Constant_Value_g != 0.0) {
    /* '<S51>:1:5' */
    ctrl_student_HIL_B.omega = 0.3;
  } else {
    /* '<S51>:1:7' */
    ctrl_student_HIL_B.omega = 0.0;
  }

  /* Maximum forces, VS */
  /*  [N] */
  /* Moment arm vsp x-direction */
  /* [m] */
  /* Moment arm vsp y-direction */
  /* T-matrix thrust allocation */
  /* K-matrix, saturation limits for thrusters */
  /* Solving the thrust allocation relation for the decomposed thrust */
  /* '<S51>:1:28' */
  for (i = 0; i < 4; i++) {
    u[i] = a[i + 8] * ctrl_student_HIL_B.Sum1 + (a[i + 4] *
      ctrl_student_HIL_B.Gain6 + a[i] * ctrl_student_HIL_B.Gain7);
  }

  /* Assigning the decomposed thrust */
  /* '<S51>:1:31' */
  /* '<S51>:1:32' */
  /* '<S51>:1:33' */
  /* '<S51>:1:34' */
  /* Calculating total VSP thrust */
  /* '<S51>:1:37' */
  c_13 = sqrt(u[0] * u[0] + u[1] * u[1]);

  /* '<S51>:1:38' */
  xd = sqrt(u[2] * u[2] + u[3] * u[3]);

  /* Calculating thrust angle for VSP */
  /* '<S51>:1:41' */
  ctrl_student_HIL_B.alpha1 = rt_atan2d_snf(u[1], u[0]);

  /* '<S51>:1:42' */
  ctrl_student_HIL_B.alpha2 = rt_atan2d_snf(u[3], u[2]);

  /* Saturation U_vsp1 */
  if (fabs(c_13) > 1.0) {
    /* '<S51>:1:45' */
    /* '<S51>:1:46' */
    c_13 = 1.0;
  }

  /* Saturation U_vsp2 */
  if (fabs(xd) > 1.0) {
    /* '<S51>:1:50' */
    /* '<S51>:1:51' */
    xd = 1.0;
  }

  /* end of function */
  ctrl_student_HIL_B.U_vsp1 = c_13;
  ctrl_student_HIL_B.U_vsp2 = xd;

  /* End of MATLAB Function: '<S13>/Thrust Allocation 2x VSP' */

  /* MATLAB Function: '<S52>/control limit checking' incorporates:
   *  Constant: '<S13>/Constant1'
   *  SignalConversion: '<S53>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking': '<S53>:1' */
  /* '<S53>:1:2' */
  /* '<S53>:1:3' */
  /* '<S53>:1:4' */
  /* '<S53>:1:5' */
  /* '<S53>:1:6' */
  /* '<S53>:1:7' */
  /* '<S53>:1:8' */
  /* '<S53>:1:10' */
  /* '<S53>:1:18' */
  ctrl_student_HIL_B.fault = !((-1.0 <= ctrl_student_HIL_P.Constant1_Value_l) &&
    (ctrl_student_HIL_P.Constant1_Value_l <= 1.0) && (0.0 <=
    ctrl_student_HIL_B.U_vsp1) && (ctrl_student_HIL_B.U_vsp1 <= 1.0) && (0.0 <=
    ctrl_student_HIL_B.U_vsp2) && (ctrl_student_HIL_B.U_vsp2 <= 1.0) &&
    (-3.1415926535897931 <= ctrl_student_HIL_B.alpha1) &&
    (ctrl_student_HIL_B.alpha1 <= 3.1415926535897931) && (-3.1415926535897931 <=
    ctrl_student_HIL_B.alpha2) && (ctrl_student_HIL_B.alpha2 <=
    3.1415926535897931) && (-1.0 <= ctrl_student_HIL_B.omega) &&
    (ctrl_student_HIL_B.omega <= 1.0) && (-1.0 <= ctrl_student_HIL_B.omega) &&
    (ctrl_student_HIL_B.omega <= 1.0));
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* MATLAB Function: '<S5>/Rotation matrix' */
  /* MATLAB Function 'Guidance/Rotation matrix': '<S19>:1' */
  /* '<S19>:1:3' */
  /* '<S19>:1:5' */
  rtb_K_p2[0] = cos(ctrl_student_HIL_B.Integrator[2]);
  rtb_K_p2[3] = -sin(ctrl_student_HIL_B.Integrator[2]);
  rtb_K_p2[6] = 0.0;
  rtb_K_p2[1] = sin(ctrl_student_HIL_B.Integrator[2]);
  rtb_K_p2[4] = cos(ctrl_student_HIL_B.Integrator[2]);
  rtb_K_p2[7] = 0.0;
  rtb_K_p2[2] = 0.0;
  rtb_K_p2[5] = 0.0;
  rtb_K_p2[8] = 1.0;

  /* Sum: '<S5>/Sum' */
  /* '<S19>:1:6' */
  rtb_MatrixMultiply[0] = ctrl_student_HIL_B.Integrator[0] -
    ctrl_student_HIL_B.IC_d[0];
  rtb_MatrixMultiply[1] = ctrl_student_HIL_B.Integrator[1] -
    ctrl_student_HIL_B.IC_d[1];
  rtb_MatrixMultiply[2] = ctrl_student_HIL_B.Integrator[2] -
    ctrl_student_HIL_B.IC_d[2];

  /* Product: '<S5>/Matrix Multiply1' incorporates:
   *  MATLAB Function: '<S5>/Rotation matrix'
   *  Product: '<S5>/Matrix Multiply2'
   */
  for (i = 0; i < 3; i++) {
    rtb_K_p2_1[i] = rtb_K_p2[3 * i + 2] * rtb_MatrixMultiply[2] + (rtb_K_p2[3 *
      i + 1] * rtb_MatrixMultiply[1] + rtb_K_p2[3 * i] * rtb_MatrixMultiply[0]);
  }

  /* End of Product: '<S5>/Matrix Multiply1' */

  /* Product: '<S5>/Matrix Multiply2' incorporates:
   *  Constant: '<S17>/Constant'
   */
  for (i = 0; i < 3; i++) {
    rtb_MatrixMultiply[i] = 0.0;
    rtb_MatrixMultiply[i] += ctrl_student_HIL_P.Constant_Value_n[i] *
      rtb_K_p2_1[0];
    rtb_MatrixMultiply[i] += ctrl_student_HIL_P.Constant_Value_n[i + 3] *
      rtb_K_p2_1[1];
    rtb_MatrixMultiply[i] += ctrl_student_HIL_P.Constant_Value_n[i + 6] *
      rtb_K_p2_1[2];
  }

  /* Sum: '<S5>/Sum1' incorporates:
   *  Product: '<S5>/Matrix Multiply3'
   */
  rtb_MatrixMultiply[0] = rtb_Sum3 * ctrl_student_HIL_B.IC1[0] -
    rtb_MatrixMultiply[0];
  rtb_MatrixMultiply[1] = rtb_Sum3 * ctrl_student_HIL_B.IC1[1] -
    rtb_MatrixMultiply[1];
  rtb_MatrixMultiply[2] = rtb_Sum3 * ctrl_student_HIL_B.IC1[2] -
    rtb_MatrixMultiply[2];

  /* Product: '<S5>/Matrix Multiply' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.MatrixMultiply[i] = 0.0;
    ctrl_student_HIL_B.MatrixMultiply[i] += rtb_K_p2[i] * rtb_MatrixMultiply[0];
    ctrl_student_HIL_B.MatrixMultiply[i] += rtb_K_p2[i + 3] *
      rtb_MatrixMultiply[1];
    ctrl_student_HIL_B.MatrixMultiply[i] += rtb_K_p2[i + 6] *
      rtb_MatrixMultiply[2];
  }

  /* End of Product: '<S5>/Matrix Multiply' */

  /* Sum: '<S7>/Sum' */
  /* MATLAB Function 'Gain Matrices/MATLAB Function': '<S16>:1' */
  /*  L1_11 = 10; */
  /*  L2_11 = 30; */
  /*  L3_11 = 8; */
  /*  L1_22 = 10; */
  /*  L2_22 = 30; */
  /*  L3_22 = 8; */
  /*  L1_33 = 5; */
  /*  L2_33 = 10; */
  /*  L3_33 = 4; */
  /* '<S16>:1:13' */
  /* '<S16>:1:15' */
  /* '<S16>:1:17' */
  /* '<S16>:1:19' */
  z1[0] = ctrl_student_HIL_B.eta_m_c1[0] - ctrl_student_HIL_B.IC[0];
  z1[1] = ctrl_student_HIL_B.eta_m_c1[1] - ctrl_student_HIL_B.IC[1];
  z1[2] = ctrl_student_HIL_B.eta_m_c1[2] - ctrl_student_HIL_B.IC[2];

  /* MATLAB Function: '<S4>/MATLAB Function' */
  tmp_4[0] = ctrl_student_HIL_B.L3_11 + 8.0;
  tmp_4[3] = 0.0;
  tmp_4[6] = 0.0;
  tmp_4[1] = 0.0;
  tmp_4[4] = ctrl_student_HIL_B.L3_22 + 8.0;
  tmp_4[7] = 0.0;
  tmp_4[2] = 0.0;
  tmp_4[5] = 0.0;
  tmp_4[8] = ctrl_student_HIL_B.L3_33 + 4.0;

  /* Product: '<S33>/Matrix Multiply1' */
  for (i = 0; i < 3; i++) {
    rtb_MatrixMultiply[i] = 0.0;
    rtb_MatrixMultiply[i] += tmp_4[i] * z1[0];
    rtb_MatrixMultiply[i] += tmp_4[i + 3] * z1[1];
    rtb_MatrixMultiply[i] += tmp_4[i + 6] * z1[2];
  }

  /* End of Product: '<S33>/Matrix Multiply1' */

  /* Product: '<S33>/Matrix Multiply9' */
  ctrl_student_HIL_B.MatrixMultiply9[0] = rtb_MatrixMultiply[0] * (real_T)
    rtb_bool;
  ctrl_student_HIL_B.MatrixMultiply9[1] = rtb_MatrixMultiply[1] * (real_T)
    rtb_bool;
  ctrl_student_HIL_B.MatrixMultiply9[2] = rtb_MatrixMultiply[2] * (real_T)
    rtb_bool;

  /* MATLAB Function: '<S4>/MATLAB Function' */
  tmp_5[0] = ctrl_student_HIL_B.L1_11 + 10.0;
  tmp_5[3] = 0.0;
  tmp_5[6] = 0.0;
  tmp_5[1] = 0.0;
  tmp_5[4] = ctrl_student_HIL_B.L1_22 + 10.0;
  tmp_5[7] = 0.0;
  tmp_5[2] = 0.0;
  tmp_5[5] = 0.0;
  tmp_5[8] = ctrl_student_HIL_B.L1_33 + 5.0;

  /* Product: '<S7>/Matrix Multiply' */
  for (i = 0; i < 3; i++) {
    rtb_MatrixMultiply[i] = 0.0;
    rtb_MatrixMultiply[i] += tmp_5[i] * z1[0];
    rtb_MatrixMultiply[i] += tmp_5[i + 3] * z1[1];
    rtb_MatrixMultiply[i] += tmp_5[i + 6] * z1[2];
  }

  /* End of Product: '<S7>/Matrix Multiply' */

  /* MATLAB Function: '<S35>/MATLAB Function1' */
  ctrl_student_HIL_inv(rtb_M, tmp_1);

  /* MATLAB Function: '<S4>/MATLAB Function' */
  tmp_6[0] = ctrl_student_HIL_B.L2_11 + 30.0;
  tmp_6[3] = 0.0;
  tmp_6[6] = 0.0;
  tmp_6[1] = 0.0;
  tmp_6[4] = ctrl_student_HIL_B.L2_22 + 30.0;
  tmp_6[7] = 0.0;
  tmp_6[2] = 0.0;
  tmp_6[5] = 0.0;
  tmp_6[8] = ctrl_student_HIL_B.L2_33 + 10.0;

  /* Product: '<S7>/Matrix Multiply7' incorporates:
   *  Product: '<S7>/Matrix Multiply9'
   */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = tmp_6[i + 6] * z1[2] + (tmp_6[i + 3] * z1[1] + tmp_6[i] * z1[0]);
  }

  /* End of Product: '<S7>/Matrix Multiply7' */

  /* Product: '<S7>/Matrix Multiply9' incorporates:
   *  Product: '<S7>/Matrix Multiply2'
   */
  xd = tmp_2[0] * (real_T)rtb_bool;
  xds = tmp_2[1] * (real_T)rtb_bool;
  yd = tmp_2[2] * (real_T)rtb_bool;

  /* Product: '<S7>/Matrix Multiply2' incorporates:
   *  Product: '<S7>/Matrix Multiply3'
   */
  for (i = 0; i < 3; i++) {
    rtb_R_T_0[i] = rtb_R_T[i + 6] * yd + (rtb_R_T[i + 3] * xds + rtb_R_T[i] * xd);
  }

  /* Sum: '<S7>/Sum2' incorporates:
   *  MATLAB Function: '<S4>/MATLAB Function'
   *  Product: '<S7>/Matrix Multiply3'
   */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = (((real_T)tmp[i + 3] * rtb_R_T_0[1] + (real_T)tmp[i] * rtb_R_T_0
                 [0]) + (real_T)tmp[i + 6] * rtb_R_T_0[2]) +
      ctrl_student_HIL_B.ManualSwitch[i];
  }

  /* Product: '<S7>/Matrix Multiply1' incorporates:
   *  Sum: '<S7>/Sum2'
   */
  for (i = 0; i < 3; i++) {
    alpha1[i] = rtb_C[i + 6] * ctrl_student_HIL_B.Integrator1_k[2] + (rtb_C[i +
      3] * ctrl_student_HIL_B.Integrator1_k[1] + rtb_C[i] *
      ctrl_student_HIL_B.Integrator1_k[0]);
  }

  /* End of Product: '<S7>/Matrix Multiply1' */

  /* Sum: '<S7>/Sum3' incorporates:
   *  Product: '<S7>/Matrix Multiply4'
   *  Product: '<S7>/Matrix Multiply5'
   *  Sum: '<S7>/Sum2'
   */
  for (i = 0; i < 3; i++) {
    z2[i] = ((tmp_2[i] - alpha1[i]) + ctrl_student_HIL_B.MatrixMultiply2[i]) -
      ((rtb_D[i + 3] * ctrl_student_HIL_B.Integrator1_k[1] + rtb_D[i] *
        ctrl_student_HIL_B.Integrator1_k[0]) + rtb_D[i + 6] *
       ctrl_student_HIL_B.Integrator1_k[2]);
  }

  /* End of Sum: '<S7>/Sum3' */

  /* Product: '<S7>/Matrix Multiply4' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.MatrixMultiply4[i] = 0.0;
    ctrl_student_HIL_B.MatrixMultiply4[i] += tmp_1[i] * z2[0];
    ctrl_student_HIL_B.MatrixMultiply4[i] += tmp_1[i + 3] * z2[1];
    ctrl_student_HIL_B.MatrixMultiply4[i] += tmp_1[i + 6] * z2[2];
  }

  /* Sum: '<S7>/Sum1' incorporates:
   *  Product: '<S7>/Matrix Multiply6'
   *  Product: '<S7>/Matrix Multiply8'
   */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Sum1_n[i] = ((rtb_R[i + 3] *
      ctrl_student_HIL_B.Integrator1_k[1] + rtb_R[i] *
      ctrl_student_HIL_B.Integrator1_k[0]) + rtb_R[i + 6] *
      ctrl_student_HIL_B.Integrator1_k[2]) + rtb_MatrixMultiply[i] * (real_T)
      rtb_bool;
  }

  /* End of Sum: '<S7>/Sum1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S8>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput[0] = ctrl_student_HIL_B.eta_m_out[0];
    ctrl_student_HIL_DW.Memory_PreviousInput[1] = ctrl_student_HIL_B.eta_m_out[1];
    ctrl_student_HIL_DW.Memory_PreviousInput[2] = ctrl_student_HIL_B.eta_m_out[2];

    /* Update for Memory: '<S38>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_n[0] = ctrl_student_HIL_B.eta_m_c1
      [0];
    ctrl_student_HIL_DW.Memory_PreviousInput_n[1] = ctrl_student_HIL_B.eta_m_c1
      [1];
    ctrl_student_HIL_DW.Memory_PreviousInput_n[2] = ctrl_student_HIL_B.eta_m_c1
      [2];
  }

  /* Update for Integrator: '<S7>/Integrator2' */
  ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S21>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_g = ctrl_student_HIL_B.s_dot;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_student_HIL_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_student_HIL_M->Timing.clockTick0)) {
    ++ctrl_student_HIL_M->Timing.clockTickH0;
  }

  ctrl_student_HIL_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_student_HIL_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_student_HIL_M->Timing.clockTick1)) {
      ++ctrl_student_HIL_M->Timing.clockTickH1;
    }

    ctrl_student_HIL_M->Timing.t[1] = ctrl_student_HIL_M->Timing.clockTick1 *
      ctrl_student_HIL_M->Timing.stepSize1 +
      ctrl_student_HIL_M->Timing.clockTickH1 *
      ctrl_student_HIL_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_student_HIL_derivatives(void)
{
  XDot_ctrl_student_HIL_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator2_CSTATE[0] = ctrl_student_HIL_B.Sum1_n[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator2_CSTATE[1] = ctrl_student_HIL_B.Sum1_n[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator2_CSTATE[2] = ctrl_student_HIL_B.Sum1_n[2];
  }

  /* Derivatives for Integrator: '<S5>/Integrator' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE[0] = ctrl_student_HIL_B.MatrixMultiply[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE[1] = ctrl_student_HIL_B.MatrixMultiply[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator_CSTATE[2] = ctrl_student_HIL_B.MatrixMultiply[2];
  }

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = ctrl_student_HIL_B.s_dot;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE_b[0] = ctrl_student_HIL_B.MatrixMultiply4[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE_b[1] = ctrl_student_HIL_B.MatrixMultiply4[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE_b[2] = ctrl_student_HIL_B.MatrixMultiply4[2];
  }

  /* Derivatives for Integrator: '<S33>/Integrator' */
  _rtXdot->Integrator_CSTATE_n[0] = ctrl_student_HIL_B.MatrixMultiply9[0];
  _rtXdot->Integrator_CSTATE_n[1] = ctrl_student_HIL_B.MatrixMultiply9[1];
  _rtXdot->Integrator_CSTATE_n[2] = ctrl_student_HIL_B.MatrixMultiply9[2];
}

/* Model initialize function */
void ctrl_student_HIL_initialize(void)
{
  /* Start for InitialCondition: '<S7>/IC' */
  ctrl_student_HIL_B.IC[0] = ctrl_student_HIL_P.IC_Value[0];
  ctrl_student_HIL_B.IC[1] = ctrl_student_HIL_P.IC_Value[1];
  ctrl_student_HIL_B.IC[2] = ctrl_student_HIL_P.IC_Value[2];
  ctrl_student_HIL_DW.IC_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S18>/IC' */
  ctrl_student_HIL_B.IC_d[0] = ctrl_student_HIL_P.IC_Value_o[0];
  ctrl_student_HIL_B.IC_d[1] = ctrl_student_HIL_P.IC_Value_o[1];
  ctrl_student_HIL_B.IC_d[2] = ctrl_student_HIL_P.IC_Value_o[2];
  ctrl_student_HIL_DW.IC_FirstOutputTime_h = (rtMinusInf);

  /* Start for InitialCondition: '<S18>/IC1' */
  ctrl_student_HIL_B.IC1[0] = ctrl_student_HIL_P.IC1_Value[0];
  ctrl_student_HIL_B.IC1[1] = ctrl_student_HIL_P.IC1_Value[1];
  ctrl_student_HIL_B.IC1[2] = ctrl_student_HIL_P.IC1_Value[2];
  ctrl_student_HIL_DW.IC1_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S18>/IC3' */
  ctrl_student_HIL_B.IC3 = ctrl_student_HIL_P.IC3_Value;
  ctrl_student_HIL_DW.IC3_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S18>/IC2' */
  ctrl_student_HIL_B.IC2[0] = ctrl_student_HIL_P.IC2_Value[0];
  ctrl_student_HIL_B.IC2[1] = ctrl_student_HIL_P.IC2_Value[1];
  ctrl_student_HIL_B.IC2[2] = ctrl_student_HIL_P.IC2_Value[2];
  ctrl_student_HIL_DW.IC2_FirstOutputTime = (rtMinusInf);
  ctrl_student_HIL_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Memory: '<S8>/Memory' */
  ctrl_student_HIL_DW.Memory_PreviousInput[0] = ctrl_student_HIL_P.Memory_X0[0];
  ctrl_student_HIL_DW.Memory_PreviousInput[1] = ctrl_student_HIL_P.Memory_X0[1];
  ctrl_student_HIL_DW.Memory_PreviousInput[2] = ctrl_student_HIL_P.Memory_X0[2];

  /* InitializeConditions for Memory: '<S38>/Memory' */
  ctrl_student_HIL_DW.Memory_PreviousInput_n[0] =
    ctrl_student_HIL_P.Memory_X0_e[0];
  ctrl_student_HIL_DW.Memory_PreviousInput_n[1] =
    ctrl_student_HIL_P.Memory_X0_e[1];
  ctrl_student_HIL_DW.Memory_PreviousInput_n[2] =
    ctrl_student_HIL_P.Memory_X0_e[2];

  /* InitializeConditions for Integrator: '<S7>/Integrator2' */
  if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
    ctrl_student_HIL_X.Integrator2_CSTATE[0] = 0.0;
    ctrl_student_HIL_X.Integrator2_CSTATE[1] = 0.0;
    ctrl_student_HIL_X.Integrator2_CSTATE[2] = 0.0;
  }

  ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  ctrl_student_HIL_X.Integrator_CSTATE[0] = (ctrl_student_HIL_P.Integrator_IC[0]);
  ctrl_student_HIL_X.Integrator_CSTATE[1] = (ctrl_student_HIL_P.Integrator_IC[1]);
  ctrl_student_HIL_X.Integrator_CSTATE[2] = (ctrl_student_HIL_P.Integrator_IC[2]);

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  ctrl_student_HIL_X.Integrator1_CSTATE = ctrl_student_HIL_P.Integrator1_IC;

  /* InitializeConditions for Memory: '<S21>/Memory' */
  ctrl_student_HIL_DW.Memory_PreviousInput_g = ctrl_student_HIL_P.Memory_X0_b;

  /* InitializeConditions for Integrator: '<S7>/Integrator1' */
  ctrl_student_HIL_X.Integrator1_CSTATE_b[0] =
    (ctrl_student_HIL_P.Integrator1_IC_m[0]);
  ctrl_student_HIL_X.Integrator1_CSTATE_b[1] =
    (ctrl_student_HIL_P.Integrator1_IC_m[1]);
  ctrl_student_HIL_X.Integrator1_CSTATE_b[2] =
    (ctrl_student_HIL_P.Integrator1_IC_m[2]);

  /* InitializeConditions for Integrator: '<S33>/Integrator' */
  ctrl_student_HIL_X.Integrator_CSTATE_n[0] = ctrl_student_HIL_P.Integrator_IC_a;
  ctrl_student_HIL_X.Integrator_CSTATE_n[1] = ctrl_student_HIL_P.Integrator_IC_a;
  ctrl_student_HIL_X.Integrator_CSTATE_n[2] = ctrl_student_HIL_P.Integrator_IC_a;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
    rtmSetFirstInitCond(ctrl_student_HIL_M, 0);
  }
}

/* Model terminate function */
void ctrl_student_HIL_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_student_HIL_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_student_HIL_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_student_HIL_initialize();
}

void MdlTerminate(void)
{
  ctrl_student_HIL_terminate();
}

/* Registration function */
RT_MODEL_ctrl_student_HIL_T *ctrl_student_HIL(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_student_HIL_M, 0,
                sizeof(RT_MODEL_ctrl_student_HIL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_student_HIL_M->solverInfo,
                          &ctrl_student_HIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_student_HIL_M->solverInfo, &rtmGetTPtr(ctrl_student_HIL_M));
    rtsiSetStepSizePtr(&ctrl_student_HIL_M->solverInfo,
                       &ctrl_student_HIL_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_student_HIL_M->solverInfo,
                 &ctrl_student_HIL_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_student_HIL_M->solverInfo, (real_T **)
                         &ctrl_student_HIL_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_student_HIL_M->solverInfo,
      &ctrl_student_HIL_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_student_HIL_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_student_HIL_M)));
    rtsiSetRTModelPtr(&ctrl_student_HIL_M->solverInfo, ctrl_student_HIL_M);
  }

  rtsiSetSimTimeStep(&ctrl_student_HIL_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_student_HIL_M->ModelData.intgData.y = ctrl_student_HIL_M->ModelData.odeY;
  ctrl_student_HIL_M->ModelData.intgData.f[0] =
    ctrl_student_HIL_M->ModelData.odeF[0];
  ctrl_student_HIL_M->ModelData.intgData.f[1] =
    ctrl_student_HIL_M->ModelData.odeF[1];
  ctrl_student_HIL_M->ModelData.intgData.f[2] =
    ctrl_student_HIL_M->ModelData.odeF[2];
  ctrl_student_HIL_M->ModelData.contStates = ((real_T *) &ctrl_student_HIL_X);
  rtsiSetSolverData(&ctrl_student_HIL_M->solverInfo, (void *)
                    &ctrl_student_HIL_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_HIL_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_student_HIL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_student_HIL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_student_HIL_M->Timing.sampleTimes =
      (&ctrl_student_HIL_M->Timing.sampleTimesArray[0]);
    ctrl_student_HIL_M->Timing.offsetTimes =
      (&ctrl_student_HIL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_student_HIL_M->Timing.sampleTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_student_HIL_M->Timing.offsetTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_student_HIL_M, &ctrl_student_HIL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_student_HIL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_student_HIL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_student_HIL_M, -1);
  ctrl_student_HIL_M->Timing.stepSize0 = 0.01;
  ctrl_student_HIL_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_student_HIL_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_student_HIL_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_student_HIL_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_student_HIL_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_student_HIL_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_student_HIL_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_student_HIL_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
  }

  ctrl_student_HIL_M->solverInfoPtr = (&ctrl_student_HIL_M->solverInfo);
  ctrl_student_HIL_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_student_HIL_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_student_HIL_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_student_HIL_M->ModelData.blockIO = ((void *) &ctrl_student_HIL_B);
  (void) memset(((void *) &ctrl_student_HIL_B), 0,
                sizeof(B_ctrl_student_HIL_T));

  /* parameters */
  ctrl_student_HIL_M->ModelData.defaultParam = ((real_T *)&ctrl_student_HIL_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_student_HIL_X;
    ctrl_student_HIL_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_student_HIL_X, 0,
                  sizeof(X_ctrl_student_HIL_T));
  }

  /* states (dwork) */
  ctrl_student_HIL_M->ModelData.dwork = ((void *) &ctrl_student_HIL_DW);
  (void) memset((void *)&ctrl_student_HIL_DW, 0,
                sizeof(DW_ctrl_student_HIL_T));

  /* Initialize Sizes */
  ctrl_student_HIL_M->Sizes.numContStates = (13);/* Number of continuous states */
  ctrl_student_HIL_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_M->Sizes.numBlocks = (191);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (76);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (606);/* Sum of parameter "widths" */
  return ctrl_student_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================*
 * This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_student_HIL
#include "model_info.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;
double NIRT_GetValueByDataType(void* ptr,int subindex, int type, int Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 35:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

long NIRT_SetValueByDataType(void* ptr,int subindex, double value, int type, int
  Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 35:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 36:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_student_HIL_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // From Lab/x_pos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_pos, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // From Lab/y_pos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y_pos, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // From Lab/psi_pos
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.psi_pos, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Signal Drop-out/Drop-out
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Dropout, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // System Reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.SystemReset, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Guidance/Control inputs/ pathNumber
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.pathNumber, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Guidance/Control inputs/ U_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.U_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Guidance/Path generation/x0
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x0, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Guidance/Path generation/y0
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y0, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Guidance/Path generation/x1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Guidance/Path generation/y1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Guidance/s_dot generation/my
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.my, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/K_p2_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.K_p2_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/K_p2_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.K_p2_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/K_p2_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.K_p2_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowDown
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowDown, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowUp, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowLeft, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Gain Matrices/L1_11
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1_11, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/L1_22
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1_22, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/L1_33
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1_33, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/L2_11
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_11, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/L2_22
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_22, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/L2_33
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_33, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/L3_11
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L3_11, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/L3_22
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L3_22, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/L3_33
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L3_33, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // From model/y_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // From model/psi_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.psi_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // From model/x_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // From model/r_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.r_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // From model/u_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // From model/v_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.v_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 42;
}

double ni_extout[49];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  //  eta_tilde_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,2,18,0);
  } else {
    index += 1;
  }

  //  eta_tilde_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,0,18,0);
  } else {
    index += 1;
  }

  //  eta_tilde_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,1,18,0);
  } else {
    index += 1;
  }

  // eta_hat_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.IC,2,18,0);
  } else {
    index += 1;
  }

  // eta_hat_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.IC,0,18,0);
  } else {
    index += 1;
  }

  // eta_hat_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.IC,1,18,0);
  } else {
    index += 1;
  }

  // eta_mx: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain3,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.SystemReset,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant2_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant1_Value,0,0,0);
  } else {
    index += 1;
  }

  // eta_my: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain2,0,0,0);
  } else {
    index += 1;
  }

  // eta_mpsi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,0,0,0);
  } else {
    index += 1;
  }

  // tau_d_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.ManualSwitch,2,18,0);
  } else {
    index += 1;
  }

  // tau_d_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.ManualSwitch,0,18,0);
  } else {
    index += 1;
  }

  // tau_d_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.ManualSwitch,1,18,0);
  } else {
    index += 1;
  }

  // tau_psi_rev: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,0,0);
  } else {
    index += 1;
  }

  // tau_x_rev: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain7,0,0,0);
  } else {
    index += 1;
  }

  // eta_d to veristand/eta_d_PSI: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,
      2,18,0);
  } else {
    index += 1;
  }

  // eta_d to veristand/eta_d_X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,
      0,18,0);
  } else {
    index += 1;
  }

  // eta_d to veristand/eta_d_Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,
      1,18,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/ U_vsp1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.U_vsp1,0,0,
      0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.fault,0,8,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha1,0,0,
      0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha2,0,0,
      0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant1_Value_l,0,0,0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.U_vsp1,0,0,
      0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.U_vsp2,0,0,
      0);
  } else {
    index += 1;
  }

  // tau to real ship (only use in MCLab)/U_vsp2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.U_vsp2,0,0,
      0);
  } else {
    index += 1;
  }

  // tau_y_rev: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain6,0,0,0);
  } else {
    index += 1;
  }

  // Controller/z1_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z1_inertial,
      2,18,0);
  } else {
    index += 1;
  }

  // Controller/z1_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z1_inertial,
      0,18,0);
  } else {
    index += 1;
  }

  // Controller/z1_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z1_inertial,
      1,18,0);
  } else {
    index += 1;
  }

  // Guidance/s: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,
      0,0,0);
  } else {
    index += 1;
  }

  // Guidance/s_dot: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.s_dot,0,0,0);
  } else {
    index += 1;
  }

  // Observer/bias_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.MatrixMultiply2,0,18,0);
  } else {
    index += 1;
  }

  // Observer/bias_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.MatrixMultiply2,1,18,0);
  } else {
    index += 1;
  }

  // Observer/bias_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.MatrixMultiply2,2,18,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_out/ nu_x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Integrator1_k,0,18,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_out/ nu_y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Integrator1_k,1,18,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_out/nu_psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.Integrator1_k,2,18,0);
  } else {
    index += 1;
  }

  // Signal Drop-out/eta_mpsi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_m_c1,2,
      18,0);
  } else {
    index += 1;
  }

  // Signal Drop-out/eta_mx: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_m_c1,0,
      18,0);
  } else {
    index += 1;
  }

  // Signal Drop-out/eta_my: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_m_c1,1,
      18,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 49;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  //  eta_tilde_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,2,18,0);

  //  eta_tilde_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,0,18,0);

  //  eta_tilde_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,1,18,0);

  // eta_hat_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.IC,2,18,0);

  // eta_hat_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.IC,0,18,0);

  // eta_hat_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.IC,1,18,0);

  // eta_mx: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain3,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.SystemReset,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value,0,0,0);

  // eta_my: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain2,0,0,0);

  // eta_mpsi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain1,0,0,0);

  // tau_d_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ManualSwitch,
    2,18,0);

  // tau_d_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ManualSwitch,
    0,18,0);

  // tau_d_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ManualSwitch,
    1,18,0);

  // tau_psi_rev: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,0,0);

  // tau_x_rev: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain7,0,0,0);

  // eta_d to veristand/eta_d_PSI: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,2,
    18,0);

  // eta_d to veristand/eta_d_X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,0,
    18,0);

  // eta_d to veristand/eta_d_Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator,1,
    18,0);

  // tau to real ship (only use in MCLab)/ U_vsp1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.U_vsp1,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.fault,0,8,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha1,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.alpha2,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.omega,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value_l,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.U_vsp1,0,0,0);

  // tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.U_vsp2,0,0,0);

  // tau to real ship (only use in MCLab)/U_vsp2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.U_vsp2,0,0,0);

  // tau_y_rev: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Gain6,0,0,0);

  // Controller/z1_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z1_inertial,2,
    18,0);

  // Controller/z1_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z1_inertial,0,
    18,0);

  // Controller/z1_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.z1_inertial,1,
    18,0);

  // Guidance/s: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,0,
    0,0);

  // Guidance/s_dot: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.s_dot,0,0,0);

  // Observer/bias_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.MatrixMultiply2,0,18,0);

  // Observer/bias_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.MatrixMultiply2,1,18,0);

  // Observer/bias_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_B.MatrixMultiply2,2,18,0);

  // Observer/nu_hat_out/ nu_x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1_k,
    0,18,0);

  // Observer/nu_hat_out/ nu_y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1_k,
    1,18,0);

  // Observer/nu_hat_out/nu_psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1_k,
    2,18,0);

  // Signal Drop-out/eta_mpsi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_m_c1,2,18,
    0);

  // Signal Drop-out/eta_mx: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_m_c1,0,18,
    0);

  // Signal Drop-out/eta_my: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_m_c1,1,18,
    0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil/joystick/Gain1/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain1_Gain), 33, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil/joystick/Gain2/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain2_Gain), 33, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil/joystick/Gain/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain_Gain), 33, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/joystick/Gain3/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain3_Gain), 33, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/Gain3/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain3_Gain_n), 33, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/Gain2/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain2_Gain_d), 33, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/Gain1/Gain", offsetof(P_ctrl_student_HIL_T,
    Gain1_Gain_h), 33, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/Signal Drop-out/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0), 23, 3, 2, 14, 0 },

  { 8, "ctrl_student_hil/Signal Drop-out/Detection/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0_e), 23, 3, 2, 16, 0 },

  { 9, "ctrl_student_hil/Observer/IC/Value", offsetof(P_ctrl_student_HIL_T,
    IC_Value), 24, 3, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value), 33, 1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value), 33, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value), 33, 1, 2, 24, 0 },

  { 13, "ctrl_student_hil/Guidance/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC), 24, 3, 2, 26, 0 },

  { 14, "ctrl_student_hil/Guidance/Integrator1/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator1_IC), 33, 1, 2, 28, 0 },

  { 15, "ctrl_student_hil/Guidance/Control inputs/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, Constant1_Value_e), 33, 1, 2, 30, 0 },

  { 16, "ctrl_student_hil/Guidance/Control inputs/Gain/Gain", offsetof
    (P_ctrl_student_HIL_T, Gain_Gain_l), 33, 1, 2, 32, 0 },

  { 17, "ctrl_student_hil/Guidance/Path generation/IC/Value", offsetof
    (P_ctrl_student_HIL_T, IC_Value_o), 24, 3, 2, 34, 0 },

  { 18, "ctrl_student_hil/Guidance/Path generation/IC1/Value", offsetof
    (P_ctrl_student_HIL_T, IC1_Value), 24, 3, 2, 36, 0 },

  { 19, "ctrl_student_hil/Guidance/s_dot generation/Gain/Gain", offsetof
    (P_ctrl_student_HIL_T, Gain_Gain_f), 33, 1, 2, 38, 0 },

  { 20, "ctrl_student_hil/Guidance/s_dot generation/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0_b), 33, 1, 2, 40, 0 },

  { 21, "ctrl_student_hil/Guidance/Path generation/IC3/Value", offsetof
    (P_ctrl_student_HIL_T, IC3_Value), 33, 1, 2, 42, 0 },

  { 22, "ctrl_student_hil/Guidance/Path generation/IC2/Value", offsetof
    (P_ctrl_student_HIL_T, IC2_Value), 24, 3, 2, 44, 0 },

  { 23, "ctrl_student_hil/Guidance/Control inputs/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_n), 19, 9, 2, 46, 0 },

  { 24, "ctrl_student_hil/Observer/Integrator1/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator1_IC_m), 24, 3, 2, 48, 0 },

  { 25, "ctrl_student_hil/Observer/Bias estimator/Integrator/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, Integrator_IC_a), 33, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil/Controller/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_m), 24, 3, 2, 52, 0 },

  { 27, "ctrl_student_hil/Constant/Value", offsetof(P_ctrl_student_HIL_T,
    Constant_Value_k), 33, 1, 2, 54, 0 },

  { 28, "ctrl_student_hil/Gain7/Gain", offsetof(P_ctrl_student_HIL_T, Gain7_Gain),
    33, 1, 2, 56, 0 },

  { 29, "ctrl_student_hil/tau to real ship (only use in MCLab)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_g), 33, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil/Gain6/Gain", offsetof(P_ctrl_student_HIL_T, Gain6_Gain),
    33, 1, 2, 60, 0 },

  { 31, "ctrl_student_hil/tau to real ship (only use in MCLab)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value_l), 33, 1, 2, 62, 0 },

  { 32, "ctrl_student_hil/Controller/Manual Switch/CurrentSetting", offsetof
    (P_ctrl_student_HIL_T, ManualSwitch_CurrentSetting), 34, 1, 2, 64, 0 },

  { 33, "ctrl_student_hil/Manual Switch/CurrentSetting", offsetof
    (P_ctrl_student_HIL_T, ManualSwitch_CurrentSetting_b), 34, 1, 2, 66, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 34;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 3,                                /* Parameter at index 7 */
  1, 3,                                /* Parameter at index 8 */
  3, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  3, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  3, 1,                                /* Parameter at index 17 */
  3, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  3, 1,                                /* Parameter at index 22 */
  3, 3,                                /* Parameter at index 23 */
  3, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  3, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil/From Lab/x_pos", 0, "", offsetof(B_ctrl_student_HIL_T,
    x_pos)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil/Gain3", 0, "", offsetof(B_ctrl_student_HIL_T, Gain3)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil/From Lab/y_pos", 0, "", offsetof(B_ctrl_student_HIL_T,
    y_pos)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/Gain2", 0, "", offsetof(B_ctrl_student_HIL_T, Gain2)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/From Lab/psi_pos", 0, "", offsetof(B_ctrl_student_HIL_T,
    psi_pos)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/Gain1", 0, "", offsetof(B_ctrl_student_HIL_T, Gain1)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/Signal Drop-out/Drop-out", 0, "", offsetof
    (B_ctrl_student_HIL_T, Dropout)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12,
    0 },

  { 7, "ctrl_student_hil/Signal Drop-out/Memory", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 14,
    0 },

  { 8, "ctrl_student_hil/Signal Drop-out/Memory", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 16,
    0 },

  { 9, "ctrl_student_hil/Signal Drop-out/Memory", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 18,
    0 },

  { 10, "ctrl_student_hil/Signal Drop-out/Detection/Memory", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Memory_a)+0*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 20, 0 },

  { 11, "ctrl_student_hil/Signal Drop-out/Detection/Memory", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Memory_a)+1*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 22, 0 },

  { 12, "ctrl_student_hil/Signal Drop-out/Detection/Memory", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Memory_a)+2*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 24, 0 },

  { 13, "ctrl_student_hil/System Reset", 0, "", offsetof(B_ctrl_student_HIL_T,
    SystemReset)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 26, 0 },

  { 14, "ctrl_student_hil/Observer/IC", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, IC)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 28, 0 },

  { 15, "ctrl_student_hil/Observer/IC", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, IC)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 30, 0 },

  { 16, "ctrl_student_hil/Observer/IC", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, IC)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 32, 0 },

  { 17, "ctrl_student_hil/Sum", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum)+
    0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil/Sum", 0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Sum)+
    1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 36, 0 },

  { 19, "ctrl_student_hil/Sum", 0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Sum)+
    2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 38, 0 },

  { 20, "ctrl_student_hil/Guidance/Integrator", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    40, 0 },

  { 21, "ctrl_student_hil/Guidance/Integrator", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    42, 0 },

  { 22, "ctrl_student_hil/Guidance/Integrator", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    44, 0 },

  { 23, "ctrl_student_hil/Guidance/Integrator1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    46, 0 },

  { 24, "ctrl_student_hil/Guidance/Control inputs/ pathNumber", 0, "", offsetof
    (B_ctrl_student_HIL_T, pathNumber)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    48, 0 },

  { 25, "ctrl_student_hil/Guidance/Control inputs/ U_ref", 0, "", offsetof
    (B_ctrl_student_HIL_T, U_ref)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 50, 0
  },

  { 26, "ctrl_student_hil/Guidance/Path generation/x0", 0, "", offsetof
    (B_ctrl_student_HIL_T, x0)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil/Guidance/Path generation/y0", 0, "", offsetof
    (B_ctrl_student_HIL_T, y0)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 54, 0 },

  { 28, "ctrl_student_hil/Guidance/Path generation/x1", 0, "", offsetof
    (B_ctrl_student_HIL_T, x1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 56, 0 },

  { 29, "ctrl_student_hil/Guidance/Path generation/y1", 0, "", offsetof
    (B_ctrl_student_HIL_T, y1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil/Guidance/Path generation/IC", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, IC_d)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 60, 0
  },

  { 31, "ctrl_student_hil/Guidance/Path generation/IC", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, IC_d)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 62, 0
  },

  { 32, "ctrl_student_hil/Guidance/Path generation/IC", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, IC_d)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 64, 0
  },

  { 33, "ctrl_student_hil/Guidance/Path generation/IC1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, IC1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 66, 0 },

  { 34, "ctrl_student_hil/Guidance/Path generation/IC1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, IC1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/Guidance/Path generation/IC1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, IC1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 70, 0 },

  { 36, "ctrl_student_hil/Guidance/s_dot generation/my", 0, "", offsetof
    (B_ctrl_student_HIL_T, my)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 72, 0 },

  { 37, "ctrl_student_hil/Guidance/s_dot generation/Memory", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory_p)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 74,
    0 },

  { 38, "ctrl_student_hil/Guidance/Path generation/IC3", 0, "", offsetof
    (B_ctrl_student_HIL_T, IC3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 76, 0 },

  { 39, "ctrl_student_hil/Guidance/Path generation/IC2", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, IC2)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 78, 0 },

  { 40, "ctrl_student_hil/Guidance/Path generation/IC2", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, IC2)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 80, 0 },

  { 41, "ctrl_student_hil/Guidance/Path generation/IC2", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, IC2)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 82, 0 },

  { 42, "ctrl_student_hil/Gain Matrices/K_p2_1", 0, "", offsetof
    (B_ctrl_student_HIL_T, K_p2_1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 84, 0
  },

  { 43, "ctrl_student_hil/Gain Matrices/K_p2_2", 0, "", offsetof
    (B_ctrl_student_HIL_T, K_p2_2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 86, 0
  },

  { 44, "ctrl_student_hil/Gain Matrices/K_p2_3", 0, "", offsetof
    (B_ctrl_student_HIL_T, K_p2_3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 88, 0
  },

  { 45, "ctrl_student_hil/Observer/Integrator1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Integrator1_k)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 90, 0 },

  { 46, "ctrl_student_hil/Observer/Integrator1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Integrator1_k)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 92, 0 },

  { 47, "ctrl_student_hil/Observer/Integrator1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Integrator1_k)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 94, 0 },

  { 48, "ctrl_student_hil/Observer/Bias estimator/Matrix Multiply2", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, MatrixMultiply2)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 96, 0 },

  { 49, "ctrl_student_hil/Observer/Bias estimator/Matrix Multiply2", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, MatrixMultiply2)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 98, 0 },

  { 50, "ctrl_student_hil/Observer/Bias estimator/Matrix Multiply2", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, MatrixMultiply2)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 100, 0 },

  { 51, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    102, 0 },

  { 52, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    104, 0 },

  { 53, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    106, 0 },

  { 54, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    108, 0 },

  { 55, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 110,
    0 },

  { 56, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 112,
    0 },

  { 57, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T, L1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 114, 0 },

  { 58, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 116, 0 },

  { 59, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    118, 0 },

  { 60, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 120,
    0 },

  { 61, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    122, 0 },

  { 62, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    124, 0 },

  { 63, "ctrl_student_hil/Manual Switch", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, ManualSwitch)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    126, 0 },

  { 64, "ctrl_student_hil/Manual Switch", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, ManualSwitch)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    128, 0 },

  { 65, "ctrl_student_hil/Manual Switch", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, ManualSwitch)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    130, 0 },

  { 66, "ctrl_student_hil/Sum1", 0, "", offsetof(B_ctrl_student_HIL_T, Sum1)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 132, 0 },

  { 67, "ctrl_student_hil/Gain7", 0, "", offsetof(B_ctrl_student_HIL_T, Gain7)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 134, 0 },

  { 68, "ctrl_student_hil/Gain6", 0, "", offsetof(B_ctrl_student_HIL_T, Gain6)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 136, 0 },

  { 69, "ctrl_student_hil/Guidance/Matrix Multiply", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 138, 0 },

  { 70, "ctrl_student_hil/Guidance/Matrix Multiply", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 140, 0 },

  { 71, "ctrl_student_hil/Guidance/Matrix Multiply", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 142, 0 },

  { 72, "ctrl_student_hil/Gain Matrices/L1_11", 0, "", offsetof
    (B_ctrl_student_HIL_T, L1_11)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 144, 0
  },

  { 73, "ctrl_student_hil/Gain Matrices/L1_22", 0, "", offsetof
    (B_ctrl_student_HIL_T, L1_22)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 146, 0
  },

  { 74, "ctrl_student_hil/Gain Matrices/L1_33", 0, "", offsetof
    (B_ctrl_student_HIL_T, L1_33)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 148, 0
  },

  { 75, "ctrl_student_hil/Gain Matrices/L2_11", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_11)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 150, 0
  },

  { 76, "ctrl_student_hil/Gain Matrices/L2_22", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_22)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 152, 0
  },

  { 77, "ctrl_student_hil/Gain Matrices/L2_33", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_33)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 154, 0
  },

  { 78, "ctrl_student_hil/Gain Matrices/L3_11", 0, "", offsetof
    (B_ctrl_student_HIL_T, L3_11)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 156, 0
  },

  { 79, "ctrl_student_hil/Gain Matrices/L3_22", 0, "", offsetof
    (B_ctrl_student_HIL_T, L3_22)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 158, 0
  },

  { 80, "ctrl_student_hil/Gain Matrices/L3_33", 0, "", offsetof
    (B_ctrl_student_HIL_T, L3_33)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 160, 0
  },

  { 81, "ctrl_student_hil/Observer/Bias estimator/Matrix Multiply9", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, MatrixMultiply9)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 162, 0 },

  { 82, "ctrl_student_hil/Observer/Bias estimator/Matrix Multiply9", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, MatrixMultiply9)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 164, 0 },

  { 83, "ctrl_student_hil/Observer/Bias estimator/Matrix Multiply9", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, MatrixMultiply9)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 166, 0 },

  { 84, "ctrl_student_hil/Observer/Matrix Multiply4", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply4)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 168, 0 },

  { 85, "ctrl_student_hil/Observer/Matrix Multiply4", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply4)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 170, 0 },

  { 86, "ctrl_student_hil/Observer/Matrix Multiply4", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply4)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 172, 0 },

  { 87, "ctrl_student_hil/Observer/Sum1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Sum1_n)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 174,
    0 },

  { 88, "ctrl_student_hil/Observer/Sum1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Sum1_n)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 176,
    0 },

  { 89, "ctrl_student_hil/Observer/Sum1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Sum1_n)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 178,
    0 },

  { 90, "ctrl_student_hil/From model/y_in", 0, "", offsetof(B_ctrl_student_HIL_T,
    y_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 180, 0 },

  { 91, "ctrl_student_hil/From model/psi_in", 0, "", offsetof
    (B_ctrl_student_HIL_T, psi_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 182,
    0 },

  { 92, "ctrl_student_hil/From model/x_in", 0, "", offsetof(B_ctrl_student_HIL_T,
    x_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 184, 0 },

  { 93, "ctrl_student_hil/From model/r_in", 0, "", offsetof(B_ctrl_student_HIL_T,
    r_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 186, 0 },

  { 94, "ctrl_student_hil/From model/u_in", 0, "", offsetof(B_ctrl_student_HIL_T,
    u_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 188, 0 },

  { 95, "ctrl_student_hil/From model/v_in", 0, "", offsetof(B_ctrl_student_HIL_T,
    v_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 190, 0 },

  { 96,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Thrust Allocation 2x VSP",
    0, "U_vsp1", offsetof(B_ctrl_student_HIL_T, U_vsp1)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 192, 0 },

  { 97,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Thrust Allocation 2x VSP",
    1, "U_vsp2", offsetof(B_ctrl_student_HIL_T, U_vsp2)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 194, 0 },

  { 98,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Thrust Allocation 2x VSP",
    2, "alpha1", offsetof(B_ctrl_student_HIL_T, alpha1)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 196, 0 },

  { 99,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Thrust Allocation 2x VSP",
    3, "alpha2", offsetof(B_ctrl_student_HIL_T, alpha2)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 198, 0 },

  { 100,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/Thrust Allocation 2x VSP",
    4, "omega", offsetof(B_ctrl_student_HIL_T, omega)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 200, 0 },

  { 101, "ctrl_student_hil/Signal Drop-out/Signal drop-out simulation", 0,
    "eta_m_out(1,1)", offsetof(B_ctrl_student_HIL_T, eta_m_out)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 202, 0 },

  { 102, "ctrl_student_hil/Signal Drop-out/Signal drop-out simulation", 0,
    "eta_m_out(1,2)", offsetof(B_ctrl_student_HIL_T, eta_m_out)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 204, 0 },

  { 103, "ctrl_student_hil/Signal Drop-out/Signal drop-out simulation", 0,
    "eta_m_out(1,3)", offsetof(B_ctrl_student_HIL_T, eta_m_out)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 206, 0 },

  { 104, "ctrl_student_hil/Signal Drop-out/Detection/MATLAB Function", 1,
    "eta_m_c1(1,1)", offsetof(B_ctrl_student_HIL_T, eta_m_c1)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 208, 0 },

  { 105, "ctrl_student_hil/Signal Drop-out/Detection/MATLAB Function", 1,
    "eta_m_c1(1,2)", offsetof(B_ctrl_student_HIL_T, eta_m_c1)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 210, 0 },

  { 106, "ctrl_student_hil/Signal Drop-out/Detection/MATLAB Function", 1,
    "eta_m_c1(1,3)", offsetof(B_ctrl_student_HIL_T, eta_m_c1)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 212, 0 },

  { 107, "ctrl_student_hil/Guidance/s_dot generation/s calculation", 0, "s_dot",
    offsetof(B_ctrl_student_HIL_T, s_dot)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    214, 0 },

  { 108, "ctrl_student_hil/Controller/MATLAB Function", 1, "z1_inertial(1,1)",
    offsetof(B_ctrl_student_HIL_T, z1_inertial)+0*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 216, 0 },

  { 109, "ctrl_student_hil/Controller/MATLAB Function", 1, "z1_inertial(1,2)",
    offsetof(B_ctrl_student_HIL_T, z1_inertial)+1*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 218, 0 },

  { 110, "ctrl_student_hil/Controller/MATLAB Function", 1, "z1_inertial(1,3)",
    offsetof(B_ctrl_student_HIL_T, z1_inertial)+2*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 220, 0 },

  { 111,
    "ctrl_student_hil/tau to real ship (only use in MCLab)/To thruster of real ship/control limit checking",
    0, "fault", offsetof(B_ctrl_student_HIL_T, fault)+0*sizeof(boolean_T),
    BLOCKIO_SIG, 8, 1, 2, 222, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 112;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 91;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "From Lab/x_pos", 0, EXT_IN, 1, 1, 1 },

  { 1, "From Lab/y_pos", 0, EXT_IN, 1, 1, 1 },

  { 2, "From Lab/psi_pos", 0, EXT_IN, 1, 1, 1 },

  { 3, "Signal Drop-out/Drop-out", 0, EXT_IN, 1, 1, 1 },

  { 4, "System Reset", 0, EXT_IN, 1, 1, 1 },

  { 5, "Guidance/Control inputs/ pathNumber", 0, EXT_IN, 1, 1, 1 },

  { 6, "Guidance/Control inputs/ U_ref", 0, EXT_IN, 1, 1, 1 },

  { 7, "Guidance/Path generation/x0", 0, EXT_IN, 1, 1, 1 },

  { 8, "Guidance/Path generation/y0", 0, EXT_IN, 1, 1, 1 },

  { 9, "Guidance/Path generation/x1", 0, EXT_IN, 1, 1, 1 },

  { 10, "Guidance/Path generation/y1", 0, EXT_IN, 1, 1, 1 },

  { 11, "Guidance/s_dot generation/my", 0, EXT_IN, 1, 1, 1 },

  { 12, "Gain Matrices/K_p2_1", 0, EXT_IN, 1, 1, 1 },

  { 13, "Gain Matrices/K_p2_2", 0, EXT_IN, 1, 1, 1 },

  { 14, "Gain Matrices/K_p2_3", 0, EXT_IN, 1, 1, 1 },

  { 15, "joystick/L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 16, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 17, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 18, "joystick/R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 19, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 20, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 21, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 22, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 23, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 24, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 25, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 26, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 27, "Gain Matrices/L1_11", 0, EXT_IN, 1, 1, 1 },

  { 28, "Gain Matrices/L1_22", 0, EXT_IN, 1, 1, 1 },

  { 29, "Gain Matrices/L1_33", 0, EXT_IN, 1, 1, 1 },

  { 30, "Gain Matrices/L2_11", 0, EXT_IN, 1, 1, 1 },

  { 31, "Gain Matrices/L2_22", 0, EXT_IN, 1, 1, 1 },

  { 32, "Gain Matrices/L2_33", 0, EXT_IN, 1, 1, 1 },

  { 33, "Gain Matrices/L3_11", 0, EXT_IN, 1, 1, 1 },

  { 34, "Gain Matrices/L3_22", 0, EXT_IN, 1, 1, 1 },

  { 35, "Gain Matrices/L3_33", 0, EXT_IN, 1, 1, 1 },

  { 36, "From model/y_in", 1, EXT_IN, 1, 1, 1 },

  { 37, "From model/psi_in", 1, EXT_IN, 1, 1, 1 },

  { 38, "From model/x_in", 1, EXT_IN, 1, 1, 1 },

  { 39, "From model/r_in", 1, EXT_IN, 1, 1, 1 },

  { 40, "From model/u_in", 1, EXT_IN, 1, 1, 1 },

  { 41, "From model/v_in", 1, EXT_IN, 1, 1, 1 },

  { 0, " eta_tilde_psi", 0, EXT_OUT, 1, 1, 1 },

  { 1, " eta_tilde_x", 0, EXT_OUT, 1, 1, 1 },

  { 2, " eta_tilde_y", 0, EXT_OUT, 1, 1, 1 },

  { 3, "eta_hat_psi", 0, EXT_OUT, 1, 1, 1 },

  { 4, "eta_hat_x", 0, EXT_OUT, 1, 1, 1 },

  { 5, "eta_hat_y", 0, EXT_OUT, 1, 1, 1 },

  { 6, "eta_mx", 0, EXT_OUT, 1, 1, 1 },

  { 7, "tau to CSE mocell (only use for HIL testing)/N_d", 1, EXT_OUT, 1, 1, 1 },

  { 8, "tau to CSE mocell (only use for HIL testing)/X_d", 1, EXT_OUT, 1, 1, 1 },

  { 9, "tau to CSE mocell (only use for HIL testing)/Y_d", 1, EXT_OUT, 1, 1, 1 },

  { 10, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 0,
    EXT_OUT, 1, 1, 1 },

  { 11, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 12, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 13, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 14, "eta_my", 0, EXT_OUT, 1, 1, 1 },

  { 15, "eta_mpsi", 0, EXT_OUT, 1, 1, 1 },

  { 16, "tau_d_psi", 0, EXT_OUT, 1, 1, 1 },

  { 17, "tau_d_x", 0, EXT_OUT, 1, 1, 1 },

  { 18, "tau_d_y", 0, EXT_OUT, 1, 1, 1 },

  { 19, "tau_psi_rev", 0, EXT_OUT, 1, 1, 1 },

  { 20, "tau_x_rev", 0, EXT_OUT, 1, 1, 1 },

  { 21, "eta_d to veristand/eta_d_PSI", 0, EXT_OUT, 1, 1, 1 },

  { 22, "eta_d to veristand/eta_d_X", 0, EXT_OUT, 1, 1, 1 },

  { 23, "eta_d to veristand/eta_d_Y", 0, EXT_OUT, 1, 1, 1 },

  { 24, "tau to real ship (only use in MCLab)/ U_vsp1", 0, EXT_OUT, 1, 1, 1 },

  { 25,
    "tau to real ship (only use in MCLab)/To thruster of real ship/control input u exceeds bounds",
    0, EXT_OUT, 1, 1, 1 },

  { 26,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP1",
    0, EXT_OUT, 1, 1, 1 },

  { 27,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/alpha_VSP2",
    0, EXT_OUT, 1, 1, 1 },

  { 28,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP1",
    0, EXT_OUT, 1, 1, 1 },

  { 29,
    "tau to real ship (only use in MCLab)/To thruster of real ship/u/omega_VSP2",
    0, EXT_OUT, 1, 1, 1 },

  { 30, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_BT",
    1, EXT_OUT, 1, 1, 1 },

  { 31, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP1",
    0, EXT_OUT, 1, 1, 1 },

  { 32, "tau to real ship (only use in MCLab)/To thruster of real ship/u/u_VSP2",
    0, EXT_OUT, 1, 1, 1 },

  { 33, "tau to real ship (only use in MCLab)/U_vsp2", 0, EXT_OUT, 1, 1, 1 },

  { 34, "tau_y_rev", 0, EXT_OUT, 1, 1, 1 },

  { 35, "Controller/z1_psi", 0, EXT_OUT, 1, 1, 1 },

  { 36, "Controller/z1_x", 0, EXT_OUT, 1, 1, 1 },

  { 37, "Controller/z1_y", 0, EXT_OUT, 1, 1, 1 },

  { 38, "Guidance/s", 0, EXT_OUT, 1, 1, 1 },

  { 39, "Guidance/s_dot", 0, EXT_OUT, 1, 1, 1 },

  { 40, "Observer/bias_x", 0, EXT_OUT, 1, 1, 1 },

  { 41, "Observer/bias_y", 0, EXT_OUT, 1, 1, 1 },

  { 42, "Observer/bias_psi", 0, EXT_OUT, 1, 1, 1 },

  { 43, "Observer/nu_hat_out/ nu_x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 44, "Observer/nu_hat_out/ nu_y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 45, "Observer/nu_hat_out/nu_psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 46, "Signal Drop-out/eta_mpsi", 0, EXT_OUT, 1, 1, 1 },

  { 47, "Signal Drop-out/eta_mx", 0, EXT_OUT, 1, 1, 1 },

  { 48, "Signal Drop-out/eta_my", 0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_student_hil";
static char* NI_CompiledModelVersion = "1.330";
static char* NI_CompiledModelDateTime = "Tue Apr 04 12:46:08 2017";
static char* NI_builder DataSection(".NIVS.builder") =
  "NI VeriStand 2014.0.0.82 (2014) RTW Build";
static char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2014.0.0.82";

/* Model Information Query fucntions for MATLAB
 */
/* dll information
 * Returns 1 for RTW DLL
 *		   2 for AutoCode DLL
 */
DLL_EXPORT long NIRT_GetBuildInfo(char* detail, long* len)
{
  // There are no console properties to set for VxWorks, because the console is simply serial output data.
  // Just do printf for VxWorks and ignore all console properties.
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  printf("\n*******************************************************************************\n");
  printf("%s\nModel Name: %s\nModel Version: %s\nCompiled On: %s",
         NI_builder, NI_CompiledModelName, NI_CompiledModelVersion,
         NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len>=(long)strlen(NI_builder))
    *len = strlen(NI_builder)+1;
  strncpy(detail,NI_builder,*len);
  return 1;
}

/*
 * Distinction between Index and ID:
 * Index is a long datatype (used to set parameter/probe signals).
 * ID on the other hand is a string (tag "2-3-2-12" for MatrixX/ Full path "f14/Gain/Gain" for Matlab).
 * If Bus support is added then signal path from the block name is added to the end of the port number (Model/subsystem1:1/X/A)
 * where X/A is the path from the block
 * NOTE: ID may not be the same as Paramname or signal name.
 */

/* signal information
   NOTE: signal ID == the blockname and port that feeds it extended with /sinalname.

   The port number in Simulation Environment is 1 indexed.. but on RT is 0 indexed.
 */
DLL_EXPORT long NIRT_GetSignalSpec(long* sidx, char* ID, long* ID_len, char
  * blkname, long *bnlen,
  long *portnum, char* signame, long *snlen, long *dattype, long* dims, long
  * numdim)
{
  long sigidx = *sidx;
  int i = 0;
  char *IDblk = 0;
  int IDport = 0;
  if (sigidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // parse ID into blkname and port
      i = strrchr(ID, ':') - ID;

      // malformed ID
      if (i<=0)
        return NI_SigListSize;

      //ID[i] = 0;
      IDblk = ID;
      IDport = atoi(ID+i+1);

      // lookup the table for matching ID
      // Bus support
      for (i=0;i<NI_SigListSize;i++) {
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname)+ 11, sizeof(char));

        //sprintf(tempID,"%s%s%s",NI_SigList[i].blockname,"/",NI_SigList[i].signalname);
        if (strlen(NI_SigList[i].signalname)>0)
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        else
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1))
          break;
        free(tempID);
      }

      if (i<NI_SigListSize)
        sigidx = *sidx = i;
      else
        return NI_SigListSize;
    } else                             // no index or ID specified.
      return NI_SigListSize;
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID) {
      // no need for return string to be null terminated!
      // 11 to accomodate ':','/', port number and null character
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0)
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      else
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      if ((long)strlen(tempID)<*ID_len)
        *ID_len = strlen(tempID);
      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].blockname)<*bnlen)
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].signalname)<*snlen)
        *snlen = strlen(NI_SigList[sigidx].signalname);
      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum)
      *portnum = NI_SigList[sigidx].portno;
    if (dattype)
      *dattype = NI_SigList[sigidx].datatype;
    if (dims && *numdim>=NI_SigList[sigidx].numofdims) {
      *numdim = NI_SigList[sigidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_SigListSize;
}

/*
 * Get parameter indices
 */
DLL_EXPORT long NIRT_GetParameterIndices(long* indices, long* len)
{
  long i;
  for (i=0;i<NI_ParamListSize && i<*len;i++)
    indices[i] = NI_ParamList[i].idx;
  *len = i;
  return NI_OK;
}

/*
 * parameter information
 *
 * if *pidx < 0, Lookup parameter by ID if ID != NULL.
 * if ID == NULL or no matching ID found, return number of parameters.
 *
 * plen  -> size of path
 * pnlen -> size of paramname
 * numdim -> size of dims array
 */
DLL_EXPORT long NIRT_GetParameterSpec(long* pidx, char* ID, long* ID_len, char
  * paramname, long *pnlen,
  long *dattype, long* dims, long* numdim)
{
  int i= 0;
  int paramidx = *pidx;
  if (paramidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // lookup the table for matching ID
      for (i=0;i<NI_ParamListSize;i++) {
        if (!strcmp(ID,NI_ParamList[i].paramname))
          break;
      }

      if (i<NI_ParamListSize)
        paramidx = *pidx = i;
      else
        return NI_ParamListSize;
    } else                             // no index or ID specified.
      return NI_ParamListSize;
  }

  if (paramidx>=0 && paramidx<NI_ParamListSize) {
    if (ID) {
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*ID_len)
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*pnlen)
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype)
      *dattype = NI_ParamList[paramidx].datatype;
    if (!numdim)
      return 0;
    if (*numdim>=NI_ParamList[paramidx].numofdims) {
      *numdim = NI_ParamList[paramidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_ParamListSize;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetParameterExpression(long paramidx, char* expression,
  long *exp_len)
{
  return 0;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetVariableName(long varidx, char* variable_name, long
  *var_len)
{
  return 0;
}

/*
 * NIRT_GetExtIOSpec
 *
 * Inputs:
 *		index: index of the task
 * Outputs:
 *		idx:  idx of the IO.
 *		name: Name of the IO block
 *		tid: task id
 *		type: EXT_IN or EXT_OUT
 *		dimX: size of 0th dimension
 *		dimY: size of 1th dimension
 * Return value: 0 if no error. (if index == -1, return number of tasks in the model)
 */
DLL_EXPORT long NIRT_GetExtIOSpec(long index, long *idx, char* name, long* tid,
  long *type, long *dims, long* numdims)
{
  if (index==-1)
    return NI_ExtListSize;
  if (idx)
    *idx = NI_ExtList[index].idx;
  if (name) {
    int sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid)
    *tid = NI_ExtList[index].TID;
  if (type)
    *type = NI_ExtList[index].type;
  if (numdims && dims) {
    if (*numdims>=2) {
      *numdims= 2;
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    } else
      *numdims= 0;
  }

  return 0;
}

/* Helper function to probe one	signal. baseaddr must NOT be VIRTUAL_SIG */
static long NI_ProbeOneSignal(long idx, double *value, long len, long *count,
  long vOffset, long vLength)
{
  char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                      S->ModelData.blockIO : S->ModelData.inputs) + (int)
    NI_SigList[idx].addr;
  long subindex = (vLength == -1) ? 0 : vOffset;
  long sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength + vOffset);
  while ((subindex < sublength) && (*count < len))
    value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++, NI_SigList[idx]
      .datatype, NI_SigList[idx].IsComplex);
  return *count;
}

/*
 * NIRT_ProbeSignals
 *
 * Inputs:
 *		sigindices: indeces of signals
 *		numsigs: number of signals
 *		len: total length of all signals
 * Outputs:
 *		value: probed signal data
 *		len: length of data (may vary from input)
 * Return value: equal to len
 */
DLL_EXPORT long NIRT_ProbeSignals(long* sigindices, long numsigs,
  double* value, long* len)
{
  int i, j, idx;
  long count = 0;
  if (!SITexportglobals.inCriticalSection)
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0)
      break;
    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        for (j = 0; j < 2; j++) {
          long vidx = NI_VirtualBlockSources[NI_SigList[idx].addr][j];
          long voff = NI_VirtualBlockOffsets[NI_SigList[idx].addr][j];
          long vlen = NI_VirtualBlockLengths[NI_SigList[idx].addr][j];
          if (vidx == -1)
            break;
          NI_ProbeOneSignal(vidx, value, *len, &count, voff, vlen);
        }
      } else
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
    }
  }

  *len = count;
  return count;
}

/* Copy the	statically initialized params into our copy of the param struct
   The undef allows us to access the real ctrl_student_HIL_P
   In the rest of the code ctrl_student_HIL_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_student_HIL_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_student_HIL_P, sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_student_HIL_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

static int NI_SetParamTxStatus = NI_OK;

// This function is called by the BGL to set parameters.  When a commit is requested (index < 0),
// the code enters a critical section shared with the TCL. This ensures that the flip occurs only
// when safe, and acts as a messaging scheme for us to copy back the parameters.
DLL_EXPORT long NIRT_SetParameter(long index, long subindex, double value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_student_HIL_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0)
        return NI_OK;
      SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                         1);
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    if (NI_SetParamTxStatus==NI_ERROR) {
      // fail the transaction.
      // copy old	list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1)
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_student_HIL_T));

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /*Do nothing if no new parameters were written after last commit*/
    if (WriteSideDirtyFlag == 0)
      return NI_OK;

    // commit changes
    S->ModelData.defaultParam = (double *)&rtParameter[1-READSIDE];
    WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
    READSIDE = 1 - READSIDE;
    SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
    ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

    // Copy back the newly set parameters to the writeside.
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,value,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_SetVectorParameter( unsigned long index, const double
  * paramvalues, unsigned long paramlength)
{
  unsigned int i = 0;
  long retval= NI_OK, temp_retval;
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    if (temp_retval = NIRT_SetValueByDataType(ptr, i, paramvalues[i],
         NI_ParamList[index].datatype, NI_ParamList[index].IsComplex))//assignment intended in if condition
      retval= temp_retval;
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

DLL_EXPORT long NIRT_SetScalarParameterInline( unsigned long index, unsigned
  long subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,paramvalue,NI_ParamList[index].
    datatype,NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_GetParameter(long index, long subindex, double *value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  *value = NIRT_GetValueByDataType(ptr,subindex,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

DLL_EXPORT long NIRT_GetVectorParameter(unsigned long index, double* paramvalues,
  unsigned long paramlength)
{
  char* ptr = NULL;
  unsigned int i = 0;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_GetSimState(long* numContStates, char* contStatesNames,
  double* contStates, long* numDiscStates, char* discStatesNames, double
  * discStates, long* numClockTicks, char* clockTicksNames, long* clockTicks)
{
  long count, idx;
  if (numContStates && numDiscStates && numClockTicks) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 13;
      *numDiscStates = 1651;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator2_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator2_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator2_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE_b[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_b");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE_b[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_b");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE_b[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_b");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_n[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_n[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_n[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_pos_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_pos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_pos_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_pos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_pos_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_pos_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Dropout_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Dropout_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_n, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_n, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_n, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.SystemReset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.SystemReset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_tilde_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_tilde_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_tilde_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_tilde_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_tilde_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_tilde_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_mx_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_mx_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_my_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_my_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_mpsi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_mpsi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.pathNumber_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.pathNumber_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.U_ref_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.U_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC_FirstOutputTime_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC_FirstOutputTime_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC1_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC1_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.my_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.my_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_g, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC3_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC3_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC2_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC2_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.K_p2_1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.K_p2_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.K_p2_2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.K_p2_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.K_p2_3_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.K_p2_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_d_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_d_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_d_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_psi_rev_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_psi_rev_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_x_rev_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_x_rev_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_d_PSI_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_d_PSI_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_d_X_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_d_X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_d_Y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_d_Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.U_vsp1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.U_vsp1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.U_vsp2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.U_vsp2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.tau_y_rev_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.tau_y_rev_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z1_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z1_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z1_x_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z1_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z1_y_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z1_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.s_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.s_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.s_dot_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.s_dot_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.bias_x_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.bias_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.bias_y_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.bias_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.bias_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.bias_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.nu_x_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.nu_x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.nu_y_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.nu_y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.nu_psi_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.nu_psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_11_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_11_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_22_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_22_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_33_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_33_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L2_11_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L2_11_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L2_22_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L2_22_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L2_33_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L2_33_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L3_11_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L3_11_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L3_22_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L3_22_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L3_33_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L3_33_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_mpsi_DWORK1_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_mpsi_DWORK1_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_mx_DWORK1_g, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_mx_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_my_DWORK1_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_my_DWORK1_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading");
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_pos_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_pos_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.y_pos_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.y_pos_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_pos_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_pos_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Dropout_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Dropout_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.SystemReset_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.SystemReset_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_tilde_psi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_tilde_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_tilde_x_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_tilde_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_tilde_y_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_tilde_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_hat_psi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_hat_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_hat_x_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_hat_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_hat_y_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_hat_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_mx_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_mx_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.integratorresetmodel_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_0_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_my_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_my_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_mpsi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_mpsi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.pathNumber_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.pathNumber_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.U_ref_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.U_ref_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x0_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y0_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x1_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y1_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.my_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.my_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.K_p2_1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.K_p2_1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.K_p2_2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.K_p2_2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.K_p2_3_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.K_p2_3_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_continuous_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXRight_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYRight_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.R2_continuous_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowDown_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowUp_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowRight_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_d_psi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_d_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_d_x_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_d_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_d_y_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_d_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_psi_rev_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_psi_rev_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_x_rev_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_x_rev_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_d_PSI_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_d_PSI_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_d_X_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_d_X_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_d_Y_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_d_Y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.U_vsp1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.U_vsp1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_l, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_l");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.U_vsp2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.U_vsp2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.tau_y_rev_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.tau_y_rev_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.z1_psi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.z1_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z1_x_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z1_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.z1_y_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.z1_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.s_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.s_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.s_dot_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.s_dot_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.bias_x_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.bias_x_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.bias_y_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.bias_y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.bias_psi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.bias_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.nu_x_hat_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.nu_x_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.nu_y_hat_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.nu_y_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.nu_psi_hat_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.nu_psi_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L1_11_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L1_11_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L1_22_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L1_22_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L1_33_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L1_33_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_11_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_11_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_22_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_22_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_33_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_33_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L3_11_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L3_11_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L3_22_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L3_22_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L3_33_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L3_33_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_mpsi_DWORK2_f, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_mpsi_DWORK2_f");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_mx_DWORK2_c, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_mx_DWORK2_c");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_my_DWORK2_g, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_my_DWORK2_g");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_in_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK2");
    }
  }

  if (clockTicks && clockTicksNames) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_SetSimState(double* contStates, double* discStates, long
  * clockTicks)
{
  long count, idx;
  if (contStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator2_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator2_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator2_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE_b[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE_b[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE_b[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_n[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_n[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_n[0], 2,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_pos_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_pos_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_pos_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_n, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_n, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_n, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SystemReset_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mx_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_my_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mpsi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.pathNumber_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.U_ref_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC_FirstOutputTime_h, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC1_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.my_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_g, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC3_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC2_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p2_1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p2_2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p2_3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_d_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_d_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_d_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_psi_rev_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_x_rev_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_PSI_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_X_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_Y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.U_vsp1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.controlinputuexceedsbounds_DWOR,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.U_vsp2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_y_rev_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z1_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z1_x_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z1_y_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_dot_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bias_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bias_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bias_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_x_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_y_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_psi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_11_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_22_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_33_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_11_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_22_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_33_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_11_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_22_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_33_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mpsi_DWORK1_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mx_DWORK1_g, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_my_DWORK1_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading, 0, discStates[idx
       ++], 10, 0);
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_pos_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_pos_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_pos_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SystemReset_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_psi_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_x_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_y_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_psi_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_x_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_y_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mx_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_my_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mpsi_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.pathNumber_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.U_ref_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.my_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p2_1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p2_2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p2_3_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_d_psi_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_d_x_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_d_y_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_psi_rev_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_x_rev_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_PSI_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_X_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_Y_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.U_vsp1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_DW.controlinputuexceedsbounds_DW_l, count,
         discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.U_vsp2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.tau_y_rev_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z1_psi_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z1_x_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.z1_y_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_dot_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bias_x_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bias_y_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bias_psi_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_x_hat_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_y_hat_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_psi_hat_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_11_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_22_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_33_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_11_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_22_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_33_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_11_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_22_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_33_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mpsi_DWORK2_f, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mx_DWORK2_c, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_my_DWORK2_g, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL
