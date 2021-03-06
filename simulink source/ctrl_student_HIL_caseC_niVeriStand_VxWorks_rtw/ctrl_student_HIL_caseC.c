/*
 * ctrl_student_HIL_caseC.c
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

/* Block signals (auto storage) */
B_ctrl_student_HIL_caseC_T ctrl_student_HIL_caseC_B;

/* Continuous states */
X_ctrl_student_HIL_caseC_T ctrl_student_HIL_caseC_X;

/* Block states (auto storage) */
DW_ctrl_student_HIL_caseC_T ctrl_student_HIL_caseC_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_student_HIL_case_T ctrl_student_HIL_caseC_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_student_HIL_cas_T ctrl_student_HIL_caseC_M_;
RT_MODEL_ctrl_student_HIL_cas_T *const ctrl_student_HIL_caseC_M =
  &ctrl_student_HIL_caseC_M_;

/* Forward declaration for local functions */
static void ctrl_student_HIL_caseC_inv(const real_T x[9], real_T y[9]);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_HIL_caseC_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_student_HIL_caseC_output();
  ctrl_student_HIL_caseC_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_student_HIL_caseC_output();
  ctrl_student_HIL_caseC_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_student_HIL_caseC_output();
  ctrl_student_HIL_caseC_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Function for MATLAB Function: '<S21>/MATLAB Function1' */
static void ctrl_student_HIL_caseC_inv(const real_T x[9], real_T y[9])
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
void ctrl_student_HIL_caseC_output(void)
{
  real_T rtb_Product_a;
  real_T rtb_Product;
  real_T rtb_Product_f;
  real_T rtb_MatrixMultiply[3];
  real_T rtb_MatrixMultiply2[3];
  real_T rtb_D[9];
  real_T rtb_C[9];
  real_T rtb_R[9];
  real_T rtb_R_T[9];
  static const real_T tmp[9] = { 16.79, 0.0, 0.0, 0.0, 24.79,
    0.55462499999999992, 0.0, 0.55462499999999992, 2.76 };

  static const int8_T tmp_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T tmp_1[9];
  int32_T i;
  real_T tmp_2[9];
  real_T tmp_3[9];
  real_T tmp_4[3];
  real_T tmp_5[3];
  real_T rtb_R_T_0[3];
  real_T tmp_6[3];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
    /* set solver stop time */
    if (!(ctrl_student_HIL_caseC_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_student_HIL_caseC_M->solverInfo,
                            ((ctrl_student_HIL_caseC_M->Timing.clockTickH0 + 1) *
        ctrl_student_HIL_caseC_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_student_HIL_caseC_M->solverInfo,
                            ((ctrl_student_HIL_caseC_M->Timing.clockTick0 + 1) *
        ctrl_student_HIL_caseC_M->Timing.stepSize0 +
        ctrl_student_HIL_caseC_M->Timing.clockTickH0 *
        ctrl_student_HIL_caseC_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_student_HIL_caseC_M)) {
    ctrl_student_HIL_caseC_M->Timing.t[0] = rtsiGetT
      (&ctrl_student_HIL_caseC_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
    /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Constant: '<S3>/Step size'
     *  Memory: '<S11>/counter'
     */
    /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S14>:1' */
    /* '<S14>:1:3' */
    if ((ctrl_student_HIL_caseC_DW.counter_PreviousInput + 1.0) *
        ctrl_student_HIL_caseC_P.Stepsize_Value >= 1.0 /
        ctrl_student_HIL_caseC_P.Constant4_Value) {
      /* '<S14>:1:4' */
      /* '<S14>:1:5' */
      ctrl_student_HIL_caseC_B.count = 0.0;
    } else {
      /* '<S14>:1:7' */
      ctrl_student_HIL_caseC_B.count =
        ctrl_student_HIL_caseC_DW.counter_PreviousInput + 1.0;
    }

    /* End of MATLAB Function: '<S11>/MATLAB Function' */
  }

  /* Gain: '<Root>/Gain' */
  rtb_Product_a = ctrl_student_HIL_caseC_P.Gain_Gain *
    ctrl_student_HIL_caseC_B.niose_power;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
    /* RandomNumber: '<S17>/White Noise' */
    ctrl_student_HIL_caseC_B.WhiteNoise = ctrl_student_HIL_caseC_DW.NextOutput;
  }

  /* Product: '<S17>/Product' incorporates:
   *  Constant: '<S3>/Step size'
   *  Product: '<S17>/Divide'
   *  Sqrt: '<S17>/Sqrt'
   */
  rtb_Product = sqrt(rtb_Product_a / ctrl_student_HIL_caseC_P.Stepsize_Value) *
    ctrl_student_HIL_caseC_B.WhiteNoise;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
    /* RandomNumber: '<S18>/White Noise' */
    ctrl_student_HIL_caseC_B.WhiteNoise_e =
      ctrl_student_HIL_caseC_DW.NextOutput_c;
  }

  /* Product: '<S18>/Product' incorporates:
   *  Constant: '<S3>/Step size'
   *  Product: '<S18>/Divide'
   *  Sqrt: '<S18>/Sqrt'
   */
  rtb_Product_f = sqrt(rtb_Product_a / ctrl_student_HIL_caseC_P.Stepsize_Value) *
    ctrl_student_HIL_caseC_B.WhiteNoise_e;

  /* Product: '<S16>/Divide' incorporates:
   *  Constant: '<S3>/Step size'
   */
  rtb_Product_a /= ctrl_student_HIL_caseC_P.Stepsize_Value;

  /* Sqrt: '<S16>/Sqrt' */
  rtb_Product_a = sqrt(rtb_Product_a);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
    /* RandomNumber: '<S16>/White Noise' */
    ctrl_student_HIL_caseC_B.WhiteNoise_m =
      ctrl_student_HIL_caseC_DW.NextOutput_p;
  }

  /* Product: '<S16>/Product' */
  rtb_Product_a *= ctrl_student_HIL_caseC_B.WhiteNoise_m;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
    /* Memory: '<S12>/Hold' */
    ctrl_student_HIL_caseC_B.Hold[0] =
      ctrl_student_HIL_caseC_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_caseC_B.Hold[1] =
      ctrl_student_HIL_caseC_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_caseC_B.Hold[2] =
      ctrl_student_HIL_caseC_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S12>/MATLAB Function1' incorporates:
   *  Sum: '<S3>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S15>:1' */
  if (ctrl_student_HIL_caseC_B.count == 0.0) {
    /* '<S15>:1:4' */
    /* '<S15>:1:5' */
    ctrl_student_HIL_caseC_B.output[0] = rtb_Product +
      ctrl_student_HIL_caseC_B.x_in;
    ctrl_student_HIL_caseC_B.output[1] = rtb_Product_f +
      ctrl_student_HIL_caseC_B.y_in;
    ctrl_student_HIL_caseC_B.output[2] = rtb_Product_a +
      ctrl_student_HIL_caseC_B.psi_in;
  } else {
    /* '<S15>:1:7' */
    ctrl_student_HIL_caseC_B.output[0] = ctrl_student_HIL_caseC_B.Hold[0];
    ctrl_student_HIL_caseC_B.output[1] = ctrl_student_HIL_caseC_B.Hold[1];
    ctrl_student_HIL_caseC_B.output[2] = ctrl_student_HIL_caseC_B.Hold[2];
  }

  /* End of MATLAB Function: '<S12>/MATLAB Function1' */

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if (ctrl_student_HIL_caseC_P.Constant2_Value != 0.0) {
    ctrl_student_HIL_caseC_B.Switch[0] = ctrl_student_HIL_caseC_B.output[0];
    ctrl_student_HIL_caseC_B.Switch[1] = ctrl_student_HIL_caseC_B.output[1];
    ctrl_student_HIL_caseC_B.Switch[2] = ctrl_student_HIL_caseC_B.output[2];
  } else {
    ctrl_student_HIL_caseC_B.Switch[0] = ctrl_student_HIL_caseC_B.x_in;
    ctrl_student_HIL_caseC_B.Switch[1] = ctrl_student_HIL_caseC_B.y_in;
    ctrl_student_HIL_caseC_B.Switch[2] = ctrl_student_HIL_caseC_B.psi_in;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Integrator: '<S4>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_caseC_PrevZCX.Integrator2_Reset_ZCE,
                       ctrl_student_HIL_caseC_B.SystemReset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_student_HIL_caseC_DW.Integrator2_IWORK.IcNeedsLoading) {
      ctrl_student_HIL_caseC_X.Integrator2_CSTATE[0] =
        ctrl_student_HIL_caseC_B.Switch[0];
      ctrl_student_HIL_caseC_X.Integrator2_CSTATE[1] =
        ctrl_student_HIL_caseC_B.Switch[1];
      ctrl_student_HIL_caseC_X.Integrator2_CSTATE[2] =
        ctrl_student_HIL_caseC_B.Switch[2];
    }
  }

  ctrl_student_HIL_caseC_B.Integrator2[0] =
    ctrl_student_HIL_caseC_X.Integrator2_CSTATE[0];
  ctrl_student_HIL_caseC_B.Integrator2[1] =
    ctrl_student_HIL_caseC_X.Integrator2_CSTATE[1];
  ctrl_student_HIL_caseC_B.Integrator2[2] =
    ctrl_student_HIL_caseC_X.Integrator2_CSTATE[2];

  /* Sum: '<Root>/Sum' */
  ctrl_student_HIL_caseC_B.Sum[0] = ctrl_student_HIL_caseC_B.Switch[0] -
    ctrl_student_HIL_caseC_B.Integrator2[0];
  ctrl_student_HIL_caseC_B.Sum[1] = ctrl_student_HIL_caseC_B.Switch[1] -
    ctrl_student_HIL_caseC_B.Integrator2[1];
  ctrl_student_HIL_caseC_B.Sum[2] = ctrl_student_HIL_caseC_B.Switch[2] -
    ctrl_student_HIL_caseC_B.Integrator2[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
  }

  /* Sum: '<Root>/Subtract1' */
  ctrl_student_HIL_caseC_B.Subtract1 = ctrl_student_HIL_caseC_B.R2_continuous -
    ctrl_student_HIL_caseC_B.L2_continuous;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
  }

  /* Integrator: '<S4>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_caseC_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_student_HIL_caseC_B.SystemReset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_caseC_X.Integrator1_CSTATE[0] =
        (ctrl_student_HIL_caseC_P.Integrator1_IC[0]);
      ctrl_student_HIL_caseC_X.Integrator1_CSTATE[1] =
        (ctrl_student_HIL_caseC_P.Integrator1_IC[1]);
      ctrl_student_HIL_caseC_X.Integrator1_CSTATE[2] =
        (ctrl_student_HIL_caseC_P.Integrator1_IC[2]);
    }
  }

  ctrl_student_HIL_caseC_B.Integrator1[0] =
    ctrl_student_HIL_caseC_X.Integrator1_CSTATE[0];
  ctrl_student_HIL_caseC_B.Integrator1[1] =
    ctrl_student_HIL_caseC_X.Integrator1_CSTATE[1];
  ctrl_student_HIL_caseC_B.Integrator1[2] =
    ctrl_student_HIL_caseC_X.Integrator1_CSTATE[2];

  /* MATLAB Function: '<S21>/MATLAB Function1' */
  /* MATLAB Function 'Observer/kinematics/MATLAB Function1': '<S23>:1' */
  /* '<S23>:1:2' */
  /* '<S23>:1:3' */
  /* '<S23>:1:4' */
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
  /* '<S23>:1:26' */
  /* '<S23>:1:30' */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S23>:1:33' */
  /* '<S23>:1:37' */
  /*  Y_r */
  /*  Y_rrzx */
  /*  Y_rv, Y_vr */
  /* '<S23>:1:43' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* % Correolis matrix */
  /* '<S23>:1:50' */
  /* '<S23>:1:51' */
  rtb_Product_a = -10.0 * ctrl_student_HIL_caseC_B.Integrator1[1] +
    -0.55462499999999992 * ctrl_student_HIL_caseC_B.Integrator1[2];

  /* '<S23>:1:52' */
  /* '<S23>:1:53' */
  rtb_Product = 2.0 * ctrl_student_HIL_caseC_B.Integrator1[0];

  /* '<S23>:1:54' */
  /* '<S23>:1:55' */
  /* '<S23>:1:56' */
  /* % Assembly of the damping matrix */
  /* '<S23>:1:61' */
  /* '<S23>:1:62' */
  /* '<S23>:1:63' */
  /* '<S23>:1:64' */
  /* '<S23>:1:65' */
  /*  using abs(r) */
  /* '<S23>:1:67' */
  rtb_D[0] = (0.6555 - 0.3545 * fabs(ctrl_student_HIL_caseC_B.Integrator1[0])) -
    ctrl_student_HIL_caseC_B.Integrator1[0] *
    ctrl_student_HIL_caseC_B.Integrator1[0] * -3.787;
  rtb_D[3] = 0.0;
  rtb_D[6] = 0.0;
  rtb_D[1] = 0.0;
  rtb_D[4] = ((1.33 - -2.776 * fabs(ctrl_student_HIL_caseC_B.Integrator1[1])) -
              ctrl_student_HIL_caseC_B.Integrator1[1] *
              ctrl_student_HIL_caseC_B.Integrator1[1] * -64.91) - -0.805 * fabs
    (ctrl_student_HIL_caseC_B.Integrator1[2]);
  rtb_D[7] = ((7.25 - -0.845 * fabs(ctrl_student_HIL_caseC_B.Integrator1[1])) -
              -3.45 * fabs(ctrl_student_HIL_caseC_B.Integrator1[2])) -
    ctrl_student_HIL_caseC_B.Integrator1[2] *
    ctrl_student_HIL_caseC_B.Integrator1[2] * 0.0;
  rtb_D[2] = 0.0;
  rtb_D[5] = ((-0.0 - -0.2088 * fabs(ctrl_student_HIL_caseC_B.Integrator1[1])) -
              ctrl_student_HIL_caseC_B.Integrator1[1] *
              ctrl_student_HIL_caseC_B.Integrator1[1] * 0.0) - 0.13 * fabs
    (ctrl_student_HIL_caseC_B.Integrator1[2]);
  rtb_D[8] = ((1.9 - 0.08 * fabs(ctrl_student_HIL_caseC_B.Integrator1[1])) -
              -0.75 * fabs(ctrl_student_HIL_caseC_B.Integrator1[2])) -
    ctrl_student_HIL_caseC_B.Integrator1[2] *
    ctrl_student_HIL_caseC_B.Integrator1[2] * 0.0;
  rtb_C[0] = 0.0;
  rtb_C[3] = -14.79 * ctrl_student_HIL_caseC_B.Integrator1[2];
  rtb_C[6] = rtb_Product_a;
  rtb_C[1] = 14.79 * ctrl_student_HIL_caseC_B.Integrator1[2];
  rtb_C[4] = 0.0;
  rtb_C[7] = rtb_Product;
  rtb_C[2] = -rtb_Product_a;
  rtb_C[5] = -rtb_Product;
  rtb_C[8] = 0.0;

  /* Sum: '<S4>/Sum' */
  /* MATLAB Function 'Gain Matrices/MATLAB Function': '<S10>:1' */
  /*  L1_11 = 10; */
  /*  L2_11 = 30; */
  /*  L3_11 = 8; */
  /*  L1_22 = 10; */
  /*  L2_22 = 30; */
  /*  L3_22 = 8; */
  /*  L1_33 = 5; */
  /*  L2_33 = 10; */
  /*  L3_33 = 4; */
  /* '<S10>:1:13' */
  /* '<S10>:1:15' */
  /* '<S10>:1:17' */
  /* '<S10>:1:19' */
  rtb_MatrixMultiply2[0] = ctrl_student_HIL_caseC_B.Switch[0] -
    ctrl_student_HIL_caseC_B.Integrator2[0];
  rtb_MatrixMultiply2[1] = ctrl_student_HIL_caseC_B.Switch[1] -
    ctrl_student_HIL_caseC_B.Integrator2[1];
  rtb_MatrixMultiply2[2] = ctrl_student_HIL_caseC_B.Switch[2] -
    ctrl_student_HIL_caseC_B.Integrator2[2];

  /* MATLAB Function: '<S2>/MATLAB Function' */
  tmp_1[0] = ctrl_student_HIL_caseC_B.L3_11 + 8.0;
  tmp_1[3] = 0.0;
  tmp_1[6] = 0.0;
  tmp_1[1] = 0.0;
  tmp_1[4] = ctrl_student_HIL_caseC_B.L3_22 + 8.0;
  tmp_1[7] = 0.0;
  tmp_1[2] = 0.0;
  tmp_1[5] = 0.0;
  tmp_1[8] = ctrl_student_HIL_caseC_B.L3_33 + 4.0;

  /* Product: '<S19>/Matrix Multiply1' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_caseC_B.MatrixMultiply1[i] = 0.0;
    ctrl_student_HIL_caseC_B.MatrixMultiply1[i] += tmp_1[i] *
      rtb_MatrixMultiply2[0];
    ctrl_student_HIL_caseC_B.MatrixMultiply1[i] += tmp_1[i + 3] *
      rtb_MatrixMultiply2[1];
    ctrl_student_HIL_caseC_B.MatrixMultiply1[i] += tmp_1[i + 6] *
      rtb_MatrixMultiply2[2];
  }

  /* End of Product: '<S19>/Matrix Multiply1' */

  /* MATLAB Function: '<S4>/MATLAB Function' */
  /* MATLAB Function 'Observer/MATLAB Function': '<S20>:1' */
  /* '<S20>:1:3' */
  /* '<S20>:1:5' */
  rtb_R[0] = cos(ctrl_student_HIL_caseC_B.Switch[2]);
  rtb_R[3] = -sin(ctrl_student_HIL_caseC_B.Switch[2]);
  rtb_R[6] = 0.0;
  rtb_R[1] = sin(ctrl_student_HIL_caseC_B.Switch[2]);
  rtb_R[4] = cos(ctrl_student_HIL_caseC_B.Switch[2]);
  rtb_R[7] = 0.0;
  rtb_R[2] = 0.0;
  rtb_R[5] = 0.0;
  rtb_R[8] = 1.0;

  /* Rotation matrix */
  /* '<S20>:1:7' */
  for (i = 0; i < 3; i++) {
    rtb_R_T[3 * i] = rtb_R[i];
    rtb_R_T[1 + 3 * i] = rtb_R[i + 3];
    rtb_R_T[2 + 3 * i] = rtb_R[i + 6];
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function' */

  /* MATLAB Function: '<S2>/MATLAB Function' */
  /* Transpose rotation matrix */
  tmp_2[0] = ctrl_student_HIL_caseC_B.L1_11 + 10.0;
  tmp_2[3] = 0.0;
  tmp_2[6] = 0.0;
  tmp_2[1] = 0.0;
  tmp_2[4] = ctrl_student_HIL_caseC_B.L1_22 + 10.0;
  tmp_2[7] = 0.0;
  tmp_2[2] = 0.0;
  tmp_2[5] = 0.0;
  tmp_2[8] = ctrl_student_HIL_caseC_B.L1_33 + 5.0;

  /* Product: '<S4>/Matrix Multiply' */
  for (i = 0; i < 3; i++) {
    rtb_MatrixMultiply[i] = tmp_2[i + 6] * rtb_MatrixMultiply2[2] + (tmp_2[i + 3]
      * rtb_MatrixMultiply2[1] + tmp_2[i] * rtb_MatrixMultiply2[0]);
  }

  /* End of Product: '<S4>/Matrix Multiply' */

  /* MATLAB Function: '<S2>/MATLAB Function' */
  tmp_3[0] = ctrl_student_HIL_caseC_B.L2_11 + 30.0;
  tmp_3[3] = 0.0;
  tmp_3[6] = 0.0;
  tmp_3[1] = 0.0;
  tmp_3[4] = ctrl_student_HIL_caseC_B.L2_22 + 30.0;
  tmp_3[7] = 0.0;
  tmp_3[2] = 0.0;
  tmp_3[5] = 0.0;
  tmp_3[8] = ctrl_student_HIL_caseC_B.L2_33 + 10.0;

  /* Product: '<S4>/Matrix Multiply7' incorporates:
   *  Product: '<S4>/Matrix Multiply2'
   */
  for (i = 0; i < 3; i++) {
    tmp_4[i] = tmp_3[i + 6] * rtb_MatrixMultiply2[2] + (tmp_3[i + 3] *
      rtb_MatrixMultiply2[1] + tmp_3[i] * rtb_MatrixMultiply2[0]);
  }

  /* End of Product: '<S4>/Matrix Multiply7' */

  /* Product: '<S4>/Matrix Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_MatrixMultiply2[i] = rtb_R_T[i + 6] * tmp_4[2] + (rtb_R_T[i + 3] *
      tmp_4[1] + rtb_R_T[i] * tmp_4[0]);
  }

  /* MATLAB Function: '<S21>/MATLAB Function1' */
  ctrl_student_HIL_caseC_inv(tmp, tmp_1);

  /* Product: '<S4>/Matrix Multiply3' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function'
   *  Sum: '<S4>/Sum2'
   */
  for (i = 0; i < 3; i++) {
    tmp_4[i] = (real_T)tmp_0[i + 6] * rtb_MatrixMultiply2[2] + ((real_T)tmp_0[i
      + 3] * rtb_MatrixMultiply2[1] + (real_T)tmp_0[i] * rtb_MatrixMultiply2[0]);
  }

  /* End of Product: '<S4>/Matrix Multiply3' */

  /* Sum: '<S4>/Sum2' */
  tmp_5[0] = ctrl_student_HIL_caseC_B.PosYRight;
  tmp_5[1] = ctrl_student_HIL_caseC_B.PosXRight;
  tmp_5[2] = ctrl_student_HIL_caseC_B.Subtract1;

  /* Product: '<S19>/Matrix Multiply2' incorporates:
   *  Integrator: '<S19>/Integrator'
   *  Sum: '<S4>/Sum3'
   */
  for (i = 0; i < 3; i++) {
    rtb_R_T_0[i] = rtb_R_T[i + 6] * ctrl_student_HIL_caseC_X.Integrator_CSTATE[2]
      + (rtb_R_T[i + 3] * ctrl_student_HIL_caseC_X.Integrator_CSTATE[1] +
         rtb_R_T[i] * ctrl_student_HIL_caseC_X.Integrator_CSTATE[0]);
  }

  /* End of Product: '<S19>/Matrix Multiply2' */

  /* Sum: '<S4>/Sum2' incorporates:
   *  Product: '<S4>/Matrix Multiply1'
   *  Sum: '<S4>/Sum3'
   */
  for (i = 0; i < 3; i++) {
    tmp_6[i] = (tmp_4[i] + tmp_5[i]) - ((rtb_C[i + 3] *
      ctrl_student_HIL_caseC_B.Integrator1[1] + rtb_C[i] *
      ctrl_student_HIL_caseC_B.Integrator1[0]) + rtb_C[i + 6] *
      ctrl_student_HIL_caseC_B.Integrator1[2]);
  }

  /* Sum: '<S4>/Sum3' incorporates:
   *  Product: '<S4>/Matrix Multiply4'
   *  Product: '<S4>/Matrix Multiply5'
   */
  for (i = 0; i < 3; i++) {
    rtb_MatrixMultiply2[i] = (rtb_R_T_0[i] + tmp_6[i]) - ((rtb_D[i + 3] *
      ctrl_student_HIL_caseC_B.Integrator1[1] + rtb_D[i] *
      ctrl_student_HIL_caseC_B.Integrator1[0]) + rtb_D[i + 6] *
      ctrl_student_HIL_caseC_B.Integrator1[2]);
  }

  /* Product: '<S4>/Matrix Multiply4' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_caseC_B.MatrixMultiply4[i] = 0.0;
    ctrl_student_HIL_caseC_B.MatrixMultiply4[i] += tmp_1[i] *
      rtb_MatrixMultiply2[0];
    ctrl_student_HIL_caseC_B.MatrixMultiply4[i] += tmp_1[i + 3] *
      rtb_MatrixMultiply2[1];
    ctrl_student_HIL_caseC_B.MatrixMultiply4[i] += tmp_1[i + 6] *
      rtb_MatrixMultiply2[2];
  }

  /* Sum: '<S4>/Sum1' incorporates:
   *  Product: '<S4>/Matrix Multiply6'
   */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_caseC_B.Sum1[i] = ((rtb_R[i + 3] *
      ctrl_student_HIL_caseC_B.Integrator1[1] + rtb_R[i] *
      ctrl_student_HIL_caseC_B.Integrator1[0]) + rtb_R[i + 6] *
      ctrl_student_HIL_caseC_B.Integrator1[2]) + rtb_MatrixMultiply[i];
  }

  /* End of Sum: '<S4>/Sum1' */
  /* MATLAB Function 'op_space': '<S7>:1' */
  /* parameters */
  /* '<S7>:1:4' */
  /* '<S7>:1:5' */
  /* '<S7>:1:6' */
  /* '<S7>:1:7' */
  /* if */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_caseC_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
    /* Update for Memory: '<S11>/counter' */
    ctrl_student_HIL_caseC_DW.counter_PreviousInput =
      ctrl_student_HIL_caseC_B.count;

    /* Update for RandomNumber: '<S17>/White Noise' */
    ctrl_student_HIL_caseC_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_caseC_DW.RandSeed) *
      ctrl_student_HIL_caseC_P.WhiteNoise_StdDev +
      ctrl_student_HIL_caseC_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S18>/White Noise' */
    ctrl_student_HIL_caseC_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_caseC_DW.RandSeed_j) *
      ctrl_student_HIL_caseC_P.WhiteNoise_StdDev_d +
      ctrl_student_HIL_caseC_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S16>/White Noise' */
    ctrl_student_HIL_caseC_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_caseC_DW.RandSeed_c) *
      ctrl_student_HIL_caseC_P.WhiteNoise_StdDev_g +
      ctrl_student_HIL_caseC_P.WhiteNoise_Mean_f;

    /* Update for Memory: '<S12>/Hold' */
    ctrl_student_HIL_caseC_DW.Hold_PreviousInput[0] =
      ctrl_student_HIL_caseC_B.output[0];
    ctrl_student_HIL_caseC_DW.Hold_PreviousInput[1] =
      ctrl_student_HIL_caseC_B.output[1];
    ctrl_student_HIL_caseC_DW.Hold_PreviousInput[2] =
      ctrl_student_HIL_caseC_B.output[2];
  }

  /* Update for Integrator: '<S4>/Integrator2' */
  ctrl_student_HIL_caseC_DW.Integrator2_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_caseC_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_student_HIL_caseC_M->solverInfo);
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
  if (!(++ctrl_student_HIL_caseC_M->Timing.clockTick0)) {
    ++ctrl_student_HIL_caseC_M->Timing.clockTickH0;
  }

  ctrl_student_HIL_caseC_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_student_HIL_caseC_M->solverInfo);

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
    if (!(++ctrl_student_HIL_caseC_M->Timing.clockTick1)) {
      ++ctrl_student_HIL_caseC_M->Timing.clockTickH1;
    }

    ctrl_student_HIL_caseC_M->Timing.t[1] =
      ctrl_student_HIL_caseC_M->Timing.clockTick1 *
      ctrl_student_HIL_caseC_M->Timing.stepSize1 +
      ctrl_student_HIL_caseC_M->Timing.clockTickH1 *
      ctrl_student_HIL_caseC_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_student_HIL_caseC_derivatives(void)
{
  XDot_ctrl_student_HIL_caseC_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_student_HIL_caseC_T *)
             ctrl_student_HIL_caseC_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  {
    ((XDot_ctrl_student_HIL_caseC_T *)
      ctrl_student_HIL_caseC_M->ModelData.derivs)->Integrator2_CSTATE[0] =
      ctrl_student_HIL_caseC_B.Sum1[0];
    ((XDot_ctrl_student_HIL_caseC_T *)
      ctrl_student_HIL_caseC_M->ModelData.derivs)->Integrator2_CSTATE[1] =
      ctrl_student_HIL_caseC_B.Sum1[1];
    ((XDot_ctrl_student_HIL_caseC_T *)
      ctrl_student_HIL_caseC_M->ModelData.derivs)->Integrator2_CSTATE[2] =
      ctrl_student_HIL_caseC_B.Sum1[2];
  }

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  {
    ((XDot_ctrl_student_HIL_caseC_T *)
      ctrl_student_HIL_caseC_M->ModelData.derivs)->Integrator1_CSTATE[0] =
      ctrl_student_HIL_caseC_B.MatrixMultiply4[0];
    ((XDot_ctrl_student_HIL_caseC_T *)
      ctrl_student_HIL_caseC_M->ModelData.derivs)->Integrator1_CSTATE[1] =
      ctrl_student_HIL_caseC_B.MatrixMultiply4[1];
    ((XDot_ctrl_student_HIL_caseC_T *)
      ctrl_student_HIL_caseC_M->ModelData.derivs)->Integrator1_CSTATE[2] =
      ctrl_student_HIL_caseC_B.MatrixMultiply4[2];
  }

  /* Derivatives for Integrator: '<S19>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_student_HIL_caseC_B.MatrixMultiply1[0];
  _rtXdot->Integrator_CSTATE[1] = ctrl_student_HIL_caseC_B.MatrixMultiply1[1];
  _rtXdot->Integrator_CSTATE[2] = ctrl_student_HIL_caseC_B.MatrixMultiply1[2];
}

/* Model initialize function */
void ctrl_student_HIL_caseC_initialize(void)
{
  ctrl_student_HIL_caseC_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_caseC_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Memory: '<S11>/counter' */
    ctrl_student_HIL_caseC_DW.counter_PreviousInput =
      ctrl_student_HIL_caseC_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S17>/White Noise' */
    tmp = floor(ctrl_student_HIL_caseC_P.WhiteNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_caseC_DW.RandSeed = tseed;
    ctrl_student_HIL_caseC_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_caseC_DW.RandSeed) *
      ctrl_student_HIL_caseC_P.WhiteNoise_StdDev +
      ctrl_student_HIL_caseC_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S17>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S18>/White Noise' */
    tmp = floor(ctrl_student_HIL_caseC_P.WhiteNoise_Seed_b);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_caseC_DW.RandSeed_j = tseed;
    ctrl_student_HIL_caseC_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_caseC_DW.RandSeed_j) *
      ctrl_student_HIL_caseC_P.WhiteNoise_StdDev_d +
      ctrl_student_HIL_caseC_P.WhiteNoise_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S18>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S16>/White Noise' */
    tmp = floor(ctrl_student_HIL_caseC_P.WhiteNoise_Seed_l);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_caseC_DW.RandSeed_c = tseed;
    ctrl_student_HIL_caseC_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_caseC_DW.RandSeed_c) *
      ctrl_student_HIL_caseC_P.WhiteNoise_StdDev_g +
      ctrl_student_HIL_caseC_P.WhiteNoise_Mean_f;

    /* End of InitializeConditions for RandomNumber: '<S16>/White Noise' */

    /* InitializeConditions for Memory: '<S12>/Hold' */
    ctrl_student_HIL_caseC_DW.Hold_PreviousInput[0] =
      ctrl_student_HIL_caseC_P.Hold_X0;
    ctrl_student_HIL_caseC_DW.Hold_PreviousInput[1] =
      ctrl_student_HIL_caseC_P.Hold_X0;
    ctrl_student_HIL_caseC_DW.Hold_PreviousInput[2] =
      ctrl_student_HIL_caseC_P.Hold_X0;

    /* InitializeConditions for Integrator: '<S4>/Integrator2' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_caseC_M)) {
      ctrl_student_HIL_caseC_X.Integrator2_CSTATE[0] = 0.0;
      ctrl_student_HIL_caseC_X.Integrator2_CSTATE[1] = 0.0;
      ctrl_student_HIL_caseC_X.Integrator2_CSTATE[2] = 0.0;
    }

    ctrl_student_HIL_caseC_DW.Integrator2_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S4>/Integrator1' */
    ctrl_student_HIL_caseC_X.Integrator1_CSTATE[0] =
      (ctrl_student_HIL_caseC_P.Integrator1_IC[0]);
    ctrl_student_HIL_caseC_X.Integrator1_CSTATE[1] =
      (ctrl_student_HIL_caseC_P.Integrator1_IC[1]);
    ctrl_student_HIL_caseC_X.Integrator1_CSTATE[2] =
      (ctrl_student_HIL_caseC_P.Integrator1_IC[2]);

    /* InitializeConditions for Integrator: '<S19>/Integrator' */
    ctrl_student_HIL_caseC_X.Integrator_CSTATE[0] =
      ctrl_student_HIL_caseC_P.Integrator_IC;
    ctrl_student_HIL_caseC_X.Integrator_CSTATE[1] =
      ctrl_student_HIL_caseC_P.Integrator_IC;
    ctrl_student_HIL_caseC_X.Integrator_CSTATE[2] =
      ctrl_student_HIL_caseC_P.Integrator_IC;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_student_HIL_caseC_M)) {
      rtmSetFirstInitCond(ctrl_student_HIL_caseC_M, 0);
    }
  }
}

/* Model terminate function */
void ctrl_student_HIL_caseC_terminate(void)
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
  ctrl_student_HIL_caseC_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_student_HIL_caseC_update();
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
  ctrl_student_HIL_caseC_initialize();
}

void MdlTerminate(void)
{
  ctrl_student_HIL_caseC_terminate();
}

/* Registration function */
RT_MODEL_ctrl_student_HIL_cas_T *ctrl_student_HIL_caseC(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_student_HIL_caseC_M, 0,
                sizeof(RT_MODEL_ctrl_student_HIL_cas_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_student_HIL_caseC_M->solverInfo,
                          &ctrl_student_HIL_caseC_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_student_HIL_caseC_M->solverInfo, &rtmGetTPtr
                (ctrl_student_HIL_caseC_M));
    rtsiSetStepSizePtr(&ctrl_student_HIL_caseC_M->solverInfo,
                       &ctrl_student_HIL_caseC_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_student_HIL_caseC_M->solverInfo,
                 &ctrl_student_HIL_caseC_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_student_HIL_caseC_M->solverInfo, (real_T **)
                         &ctrl_student_HIL_caseC_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_student_HIL_caseC_M->solverInfo,
      &ctrl_student_HIL_caseC_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_student_HIL_caseC_M->solverInfo,
                          (&rtmGetErrorStatus(ctrl_student_HIL_caseC_M)));
    rtsiSetRTModelPtr(&ctrl_student_HIL_caseC_M->solverInfo,
                      ctrl_student_HIL_caseC_M);
  }

  rtsiSetSimTimeStep(&ctrl_student_HIL_caseC_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_student_HIL_caseC_M->ModelData.intgData.y =
    ctrl_student_HIL_caseC_M->ModelData.odeY;
  ctrl_student_HIL_caseC_M->ModelData.intgData.f[0] =
    ctrl_student_HIL_caseC_M->ModelData.odeF[0];
  ctrl_student_HIL_caseC_M->ModelData.intgData.f[1] =
    ctrl_student_HIL_caseC_M->ModelData.odeF[1];
  ctrl_student_HIL_caseC_M->ModelData.intgData.f[2] =
    ctrl_student_HIL_caseC_M->ModelData.odeF[2];
  ctrl_student_HIL_caseC_M->ModelData.intgData.f[3] =
    ctrl_student_HIL_caseC_M->ModelData.odeF[3];
  ctrl_student_HIL_caseC_M->ModelData.contStates = ((real_T *)
    &ctrl_student_HIL_caseC_X);
  rtsiSetSolverData(&ctrl_student_HIL_caseC_M->solverInfo, (void *)
                    &ctrl_student_HIL_caseC_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_HIL_caseC_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_student_HIL_caseC_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_student_HIL_caseC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_student_HIL_caseC_M->Timing.sampleTimes =
      (&ctrl_student_HIL_caseC_M->Timing.sampleTimesArray[0]);
    ctrl_student_HIL_caseC_M->Timing.offsetTimes =
      (&ctrl_student_HIL_caseC_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_student_HIL_caseC_M->Timing.sampleTimes[0] = (0.0);
    ctrl_student_HIL_caseC_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_student_HIL_caseC_M->Timing.offsetTimes[0] = (0.0);
    ctrl_student_HIL_caseC_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_student_HIL_caseC_M, &ctrl_student_HIL_caseC_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = ctrl_student_HIL_caseC_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_student_HIL_caseC_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_student_HIL_caseC_M, -1);
  ctrl_student_HIL_caseC_M->Timing.stepSize0 = 0.01;
  ctrl_student_HIL_caseC_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_student_HIL_caseC_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_student_HIL_caseC_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_student_HIL_caseC_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_student_HIL_caseC_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_student_HIL_caseC_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_student_HIL_caseC_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_student_HIL_caseC_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_student_HIL_caseC_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_student_HIL_caseC_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_student_HIL_caseC_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_student_HIL_caseC_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_student_HIL_caseC_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_student_HIL_caseC_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_student_HIL_caseC_M->rtwLogInfo, (NULL));
  }

  ctrl_student_HIL_caseC_M->solverInfoPtr =
    (&ctrl_student_HIL_caseC_M->solverInfo);
  ctrl_student_HIL_caseC_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_student_HIL_caseC_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_student_HIL_caseC_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_student_HIL_caseC_M->ModelData.blockIO = ((void *)
    &ctrl_student_HIL_caseC_B);
  (void) memset(((void *) &ctrl_student_HIL_caseC_B), 0,
                sizeof(B_ctrl_student_HIL_caseC_T));

  /* parameters */
  ctrl_student_HIL_caseC_M->ModelData.defaultParam = ((real_T *)
    &ctrl_student_HIL_caseC_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_student_HIL_caseC_X;
    ctrl_student_HIL_caseC_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_student_HIL_caseC_X, 0,
                  sizeof(X_ctrl_student_HIL_caseC_T));
  }

  /* states (dwork) */
  ctrl_student_HIL_caseC_M->ModelData.dwork = ((void *)
    &ctrl_student_HIL_caseC_DW);
  (void) memset((void *)&ctrl_student_HIL_caseC_DW, 0,
                sizeof(DW_ctrl_student_HIL_caseC_T));

  /* Initialize Sizes */
  ctrl_student_HIL_caseC_M->Sizes.numContStates = (9);/* Number of continuous states */
  ctrl_student_HIL_caseC_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_caseC_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_caseC_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_caseC_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_caseC_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_caseC_M->Sizes.numBlocks = (103);/* Number of blocks */
  ctrl_student_HIL_caseC_M->Sizes.numBlockIO = (43);/* Number of block outputs */
  ctrl_student_HIL_caseC_M->Sizes.numBlockPrms = (311);/* Sum of parameter "widths" */
  return ctrl_student_HIL_caseC_M;
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
#ifdef NI_ROOTMODEL_ctrl_student_HIL_caseC
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_student_HIL_caseC_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // niose_power
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.niose_power, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // y_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.y_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.x_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.psi_in, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // System Reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.SystemReset, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.r_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // u_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.u_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // v_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.v_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/L2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L2_continuous, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.PosXRight, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.PosYRight, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.R2_continuous, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.PosXLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.PosYLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/L1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.R1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowDown
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.ArrowDown, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.ArrowUp, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.ArrowLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.ArrowRight, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // Gain Matrices/L1_11
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L1_11, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Gain Matrices/L3_11
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L3_11, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Gain Matrices/L3_22
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L3_22, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Gain Matrices/L3_33
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L3_33, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Gain Matrices/L2_33
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L2_33, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Gain Matrices/L1_33
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L1_33, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Gain Matrices/L1_22
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L1_22, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Gain Matrices/L2_11
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L2_11, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Gain Matrices/L2_22
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_B.L2_22, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 29;
}

double ni_extout[19];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // eta_hat_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.Integrator2,0,18,0);
  } else {
    index += 1;
  }

  //  eta_tilde_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_caseC_B.Sum,0,
      18,0);
  } else {
    index += 1;
  }

  //  eta_tilde_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_caseC_B.Sum,1,
      18,0);
  } else {
    index += 1;
  }

  //  eta_tilde_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_caseC_B.Sum,2,
      18,0);
  } else {
    index += 1;
  }

  // eta_hat_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.Integrator2,1,18,0);
  } else {
    index += 1;
  }

  // eta_hat_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.Integrator2,2,18,0);
  } else {
    index += 1;
  }

  // eta_mpsi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.Switch,2,18,0);
  } else {
    index += 1;
  }

  // eta_mx: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.Switch,0,18,0);
  } else {
    index += 1;
  }

  // eta_my: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.Switch,1,18,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.PosYRight,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.Subtract1,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.PosXRight,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_P.Constant2_Value_e,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_P.Constant_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_P.Constant1_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.SystemReset,0,0,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_out/ nu_x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.Integrator1,0,18,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_out/ nu_y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.Integrator1,1,18,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_out/nu_psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_B.Integrator1,2,18,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 19;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // eta_hat_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_B.Integrator2,0,18,0);

  //  eta_tilde_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_caseC_B.Sum,0,
    18,0);

  //  eta_tilde_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_caseC_B.Sum,1,
    18,0);

  //  eta_tilde_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_caseC_B.Sum,2,
    18,0);

  // eta_hat_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_B.Integrator2,1,18,0);

  // eta_hat_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_B.Integrator2,2,18,0);

  // eta_mpsi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_caseC_B.Switch,
    2,18,0);

  // eta_mx: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_caseC_B.Switch,
    0,18,0);

  // eta_my: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_caseC_B.Switch,
    1,18,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_B.PosYRight,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_B.Subtract1,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_B.PosXRight,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_P.Constant2_Value_e,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_P.Constant_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_P.Constant1_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_B.SystemReset,0,0,0);

  // Observer/nu_hat_out/ nu_x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_B.Integrator1,0,18,0);

  // Observer/nu_hat_out/ nu_y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_B.Integrator1,1,18,0);

  // Observer/nu_hat_out/nu_psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_caseC_B.Integrator1,2,18,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil_casec/Noise generator/Step size/Value", offsetof
    (P_ctrl_student_HIL_caseC_T, Stepsize_Value), 32, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil_casec/Noise generator/Downsamplesignal/counter/X0",
    offsetof(P_ctrl_student_HIL_caseC_T, counter_X0), 32, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil_casec/Constant4/Value", offsetof
    (P_ctrl_student_HIL_caseC_T, Constant4_Value), 32, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil_casec/Gain/Gain", offsetof(P_ctrl_student_HIL_caseC_T,
    Gain_Gain), 32, 1, 2, 6, 0 },

  { 4,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_caseC_T, WhiteNoise_Mean), 32, 1, 2, 8, 0 },

  { 5,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_caseC_T, WhiteNoise_StdDev), 32, 1, 2, 10, 0 },

  { 6,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_caseC_T, WhiteNoise_Seed), 32, 1, 2, 12, 0 },

  { 7,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_caseC_T, WhiteNoise_Mean_h), 32, 1, 2, 14, 0 },

  { 8,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_caseC_T, WhiteNoise_StdDev_d), 32, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_caseC_T, WhiteNoise_Seed_b), 32, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_caseC_T, WhiteNoise_Mean_f), 32, 1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_caseC_T, WhiteNoise_StdDev_g), 32, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_caseC_T, WhiteNoise_Seed_l), 32, 1, 2, 24, 0 },

  { 13, "ctrl_student_hil_casec/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_student_HIL_caseC_T, Hold_X0), 32, 1, 2, 26, 0 },

  { 14, "ctrl_student_hil_casec/Constant2/Value", offsetof
    (P_ctrl_student_HIL_caseC_T, Constant2_Value), 32, 1, 2, 28, 0 },

  { 15,
    "ctrl_student_hil_casec/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_caseC_T, Constant2_Value_e), 32, 1, 2, 30, 0 },

  { 16,
    "ctrl_student_hil_casec/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_caseC_T, Constant_Value), 32, 1, 2, 32, 0 },

  { 17,
    "ctrl_student_hil_casec/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_caseC_T, Constant1_Value), 32, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil_casec/Observer/Integrator1/InitialCondition", offsetof
    (P_ctrl_student_HIL_caseC_T, Integrator1_IC), 22, 3, 2, 36, 0 },

  { 19,
    "ctrl_student_hil_casec/Observer/Bias estimator/Integrator/InitialCondition",
    offsetof(P_ctrl_student_HIL_caseC_T, Integrator_IC), 32, 1, 2, 38, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 20;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  3, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil_casec/niose_power", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, niose_power)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 1,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_caseC_T, WhiteNoise)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_caseC_T, WhiteNoise_e)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3,
    "ctrl_student_hil_casec/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_caseC_T, WhiteNoise_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil_casec/y_in", 0, "", offsetof(B_ctrl_student_HIL_caseC_T,
    y_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil_casec/x_in", 0, "", offsetof(B_ctrl_student_HIL_caseC_T,
    x_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil_casec/psi_in", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, psi_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    12, 0 },

  { 7, "ctrl_student_hil_casec/Noise generator/Sample & hold/Hold", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_caseC_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 14, 0 },

  { 8, "ctrl_student_hil_casec/Noise generator/Sample & hold/Hold", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_caseC_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 16, 0 },

  { 9, "ctrl_student_hil_casec/Noise generator/Sample & hold/Hold", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_caseC_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 18, 0 },

  { 10, "ctrl_student_hil_casec/Noise generator/Switch", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_caseC_T, Switch)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    20, 0 },

  { 11, "ctrl_student_hil_casec/Noise generator/Switch", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_caseC_T, Switch)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    22, 0 },

  { 12, "ctrl_student_hil_casec/Noise generator/Switch", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_caseC_T, Switch)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    24, 0 },

  { 13, "ctrl_student_hil_casec/System Reset", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, SystemReset)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 26, 0 },

  { 14, "ctrl_student_hil_casec/Observer/Integrator2", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_caseC_T, Integrator2)+0*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 28, 0 },

  { 15, "ctrl_student_hil_casec/Observer/Integrator2", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_caseC_T, Integrator2)+1*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 30, 0 },

  { 16, "ctrl_student_hil_casec/Observer/Integrator2", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_caseC_T, Integrator2)+2*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 32, 0 },

  { 17, "ctrl_student_hil_casec/Sum", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_caseC_T, Sum)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    34, 0 },

  { 18, "ctrl_student_hil_casec/Sum", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_caseC_T, Sum)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    36, 0 },

  { 19, "ctrl_student_hil_casec/Sum", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_caseC_T, Sum)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    38, 0 },

  { 20, "ctrl_student_hil_casec/r_in", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, r_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    40, 0 },

  { 21, "ctrl_student_hil_casec/u_in", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, u_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    42, 0 },

  { 22, "ctrl_student_hil_casec/v_in", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, v_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    44, 0 },

  { 23, "ctrl_student_hil_casec/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 46, 0 },

  { 24, "ctrl_student_hil_casec/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 48, 0 },

  { 25, "ctrl_student_hil_casec/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 50, 0 },

  { 26, "ctrl_student_hil_casec/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 52, 0 },

  { 27, "ctrl_student_hil_casec/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 54, 0 },

  { 28, "ctrl_student_hil_casec/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 56, 0 },

  { 29, "ctrl_student_hil_casec/joystick/L1", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 58,
    0 },

  { 30, "ctrl_student_hil_casec/joystick/R1", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, R1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 60,
    0 },

  { 31, "ctrl_student_hil_casec/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 62, 0 },

  { 32, "ctrl_student_hil_casec/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    64, 0 },

  { 33, "ctrl_student_hil_casec/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 66, 0 },

  { 34, "ctrl_student_hil_casec/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 68, 0 },

  { 35, "ctrl_student_hil_casec/Subtract1", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, Subtract1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 70, 0 },

  { 36, "ctrl_student_hil_casec/Observer/Integrator1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_caseC_T, Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 72, 0 },

  { 37, "ctrl_student_hil_casec/Observer/Integrator1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_caseC_T, Integrator1)+1*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 74, 0 },

  { 38, "ctrl_student_hil_casec/Observer/Integrator1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_caseC_T, Integrator1)+2*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 76, 0 },

  { 39, "ctrl_student_hil_casec/Gain Matrices/L1_11", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L1_11)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    78, 0 },

  { 40, "ctrl_student_hil_casec/Gain Matrices/L3_11", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L3_11)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    80, 0 },

  { 41, "ctrl_student_hil_casec/Gain Matrices/L3_22", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L3_22)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    82, 0 },

  { 42, "ctrl_student_hil_casec/Gain Matrices/L3_33", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L3_33)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    84, 0 },

  { 43, "ctrl_student_hil_casec/Gain Matrices/L2_33", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L2_33)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    86, 0 },

  { 44, "ctrl_student_hil_casec/Gain Matrices/L1_33", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L1_33)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    88, 0 },

  { 45, "ctrl_student_hil_casec/Gain Matrices/L1_22", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L1_22)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    90, 0 },

  { 46, "ctrl_student_hil_casec/Gain Matrices/L2_11", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L2_11)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    92, 0 },

  { 47, "ctrl_student_hil_casec/Gain Matrices/L2_22", 0, "", offsetof
    (B_ctrl_student_HIL_caseC_T, L2_22)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    94, 0 },

  { 48, "ctrl_student_hil_casec/Observer/Bias estimator/Matrix Multiply1", 0,
    "(1,1)", offsetof(B_ctrl_student_HIL_caseC_T, MatrixMultiply1)+0*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 96, 0 },

  { 49, "ctrl_student_hil_casec/Observer/Bias estimator/Matrix Multiply1", 0,
    "(1,2)", offsetof(B_ctrl_student_HIL_caseC_T, MatrixMultiply1)+1*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 98, 0 },

  { 50, "ctrl_student_hil_casec/Observer/Bias estimator/Matrix Multiply1", 0,
    "(1,3)", offsetof(B_ctrl_student_HIL_caseC_T, MatrixMultiply1)+2*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 100, 0 },

  { 51, "ctrl_student_hil_casec/Observer/Matrix Multiply4", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_caseC_T, MatrixMultiply4)+0*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 102, 0 },

  { 52, "ctrl_student_hil_casec/Observer/Matrix Multiply4", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_caseC_T, MatrixMultiply4)+1*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 104, 0 },

  { 53, "ctrl_student_hil_casec/Observer/Matrix Multiply4", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_caseC_T, MatrixMultiply4)+2*sizeof(real_T), BLOCKIO_SIG,
    18, 1, 2, 106, 0 },

  { 54, "ctrl_student_hil_casec/Observer/Sum1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_caseC_T, Sum1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    108, 0 },

  { 55, "ctrl_student_hil_casec/Observer/Sum1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_caseC_T, Sum1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    110, 0 },

  { 56, "ctrl_student_hil_casec/Observer/Sum1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_caseC_T, Sum1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    112, 0 },

  { 57, "ctrl_student_hil_casec/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,1)", offsetof(B_ctrl_student_HIL_caseC_T, output)+0*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 114, 0 },

  { 58, "ctrl_student_hil_casec/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,2)", offsetof(B_ctrl_student_HIL_caseC_T, output)+1*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 116, 0 },

  { 59, "ctrl_student_hil_casec/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,3)", offsetof(B_ctrl_student_HIL_caseC_T, output)+2*sizeof
    (real_T), BLOCKIO_SIG, 18, 1, 2, 118, 0 },

  { 60,
    "ctrl_student_hil_casec/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_student_HIL_caseC_T, count)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 120, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 61;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 48;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "niose_power", 0, EXT_IN, 1, 1, 1 },

  { 1, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 2, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 3, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 4, "System Reset", 0, EXT_IN, 1, 1, 1 },

  { 5, "r_in", 1, EXT_IN, 1, 1, 1 },

  { 6, "u_in", 1, EXT_IN, 1, 1, 1 },

  { 7, "v_in", 1, EXT_IN, 1, 1, 1 },

  { 8, "joystick/L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 9, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 10, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 11, "joystick/R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 12, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 13, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 14, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 15, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 16, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 17, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 18, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 19, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 20, "Gain Matrices/L1_11", 0, EXT_IN, 1, 1, 1 },

  { 21, "Gain Matrices/L3_11", 0, EXT_IN, 1, 1, 1 },

  { 22, "Gain Matrices/L3_22", 0, EXT_IN, 1, 1, 1 },

  { 23, "Gain Matrices/L3_33", 0, EXT_IN, 1, 1, 1 },

  { 24, "Gain Matrices/L2_33", 0, EXT_IN, 1, 1, 1 },

  { 25, "Gain Matrices/L1_33", 0, EXT_IN, 1, 1, 1 },

  { 26, "Gain Matrices/L1_22", 0, EXT_IN, 1, 1, 1 },

  { 27, "Gain Matrices/L2_11", 0, EXT_IN, 1, 1, 1 },

  { 28, "Gain Matrices/L2_22", 0, EXT_IN, 1, 1, 1 },

  { 0, "eta_hat_x", 0, EXT_OUT, 1, 1, 1 },

  { 1, " eta_tilde_x", 0, EXT_OUT, 1, 1, 1 },

  { 2, " eta_tilde_y", 0, EXT_OUT, 1, 1, 1 },

  { 3, " eta_tilde_psi", 0, EXT_OUT, 1, 1, 1 },

  { 4, "eta_hat_y", 0, EXT_OUT, 1, 1, 1 },

  { 5, "eta_hat_psi", 0, EXT_OUT, 1, 1, 1 },

  { 6, "eta_mpsi", 0, EXT_OUT, 1, 1, 1 },

  { 7, "eta_mx", 0, EXT_OUT, 1, 1, 1 },

  { 8, "eta_my", 0, EXT_OUT, 1, 1, 1 },

  { 9, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1 },

  { 10, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 11, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 12, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 13, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 14, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 15, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 0,
    EXT_OUT, 1, 1, 1 },

  { 16, "Observer/nu_hat_out/ nu_x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 17, "Observer/nu_hat_out/ nu_y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 18, "Observer/nu_hat_out/nu_psi_hat", 0, EXT_OUT, 1, 1, 1 },

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
  "ctrl_student_hil_casec";
static char* NI_CompiledModelVersion = "1.209";
static char* NI_CompiledModelDateTime = "Fri Mar 31 14:51:31 2017";
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
   The undef allows us to access the real ctrl_student_HIL_caseC_P
   In the rest of the code ctrl_student_HIL_caseC_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_student_HIL_caseC_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_student_HIL_caseC_P, sizeof
         (P_ctrl_student_HIL_caseC_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_student_HIL_caseC_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_student_HIL_caseC_T));
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
             (P_ctrl_student_HIL_caseC_T));
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
               (P_ctrl_student_HIL_caseC_T));

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
           (P_ctrl_student_HIL_caseC_T));
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
           (P_ctrl_student_HIL_caseC_T));
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
           (P_ctrl_student_HIL_caseC_T));
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
      *numContStates = 9;
      *numDiscStates = 1253;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_X.Integrator2_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_X.Integrator2_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_X.Integrator2_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_X.Integrator1_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_X.Integrator1_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_X.Integrator1_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_X.Integrator_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_X.Integrator_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_X.Integrator_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.niose_power_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.niose_power_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.NextOutput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.NextOutput_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.NextOutput_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.NextOutput_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.NextOutput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.y_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.x_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.psi_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.Hold_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.Hold_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.Hold_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.SystemReset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.SystemReset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.eta_hat_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.eta_hat_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.eta_tilde_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.eta_tilde_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.eta_tilde_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.eta_tilde_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.eta_tilde_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.eta_tilde_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.r_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.eta_hat_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.eta_hat_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.u_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.eta_hat_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.eta_hat_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.v_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.v_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.eta_mpsi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.eta_mpsi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.eta_mx_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.eta_mx_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.eta_my_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.eta_my_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.PosXRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.PosYRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.R1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.R1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.ArrowLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.ArrowLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.ArrowRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.ArrowRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.X_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.N_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.Y_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.psi_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.x_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.y_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.nu_x_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.nu_x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.nu_y_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.nu_y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.nu_psi_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.nu_psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L1_11_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L1_11_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L3_11_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L3_11_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L3_22_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L3_22_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L3_33_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L3_33_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L2_33_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L2_33_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L1_33_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L1_33_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L1_22_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L1_22_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L2_11_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L2_11_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.L2_22_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.L2_22_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.RandSeed, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.RandSeed_j, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.RandSeed_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.RandSeed_c, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.RandSeed_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_caseC_DW.Integrator2_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_caseC_DW.Integrator2_IWORK.IcNeedsLoading");
    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.niose_power_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.niose_power_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.y_in_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.y_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.x_in_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.x_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.psi_in_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.SystemReset_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.SystemReset_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.eta_hat_x_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.eta_hat_x_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.eta_tilde_x_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.eta_tilde_x_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.eta_tilde_y_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.eta_tilde_y_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.eta_tilde_psi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.eta_tilde_psi_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.r_in_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.r_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.eta_hat_y_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.eta_hat_y_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.u_in_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.u_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.eta_hat_psi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.eta_hat_psi_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.v_in_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.v_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.eta_mpsi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.eta_mpsi_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.eta_mx_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.eta_mx_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.eta_my_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.eta_my_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L2_continuous_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.PosXRight_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.PosYRight_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.R2_continuous_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.PosXLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.PosYLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.R1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.R1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.ArrowDown_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.ArrowUp_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.ArrowLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.ArrowRight_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.X_d_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.X_d_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.N_d_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.N_d_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.Y_d_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.psi_0_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.x_0_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.x_0_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.y_0_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.y_0_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.integratorresetmodel_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.nu_x_hat_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.nu_x_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.nu_y_hat_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.nu_y_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.nu_psi_hat_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.nu_psi_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L1_11_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L1_11_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L3_11_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L3_11_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L3_22_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L3_22_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L3_33_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L3_33_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L2_33_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L2_33_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L1_33_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L1_33_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L1_22_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L1_22_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L2_11_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L2_11_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.L2_22_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.L2_22_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.NIVeriStandSignalProbe_DWORK1, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 66; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_caseC_DW.NIVeriStandSignalProbe_DWORK3, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_caseC_DW.NIVeriStandSignalProbe_DWORK3");
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_X.Integrator2_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_X.Integrator2_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_X.Integrator2_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_X.Integrator1_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_X.Integrator1_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_X.Integrator1_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_X.Integrator_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_X.Integrator_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_X.Integrator_CSTATE[0], 2,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.niose_power_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.NextOutput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.NextOutput_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.NextOutput_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.y_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.x_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.Hold_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.Hold_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.Hold_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.SystemReset_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_hat_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_tilde_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_tilde_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_tilde_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.r_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_hat_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.u_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_hat_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.v_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_mpsi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_mx_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_my_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.PosXRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.PosYRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.R1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.ArrowLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.ArrowRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.X_d_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.N_d_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.Y_d_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.psi_0_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.x_0_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.y_0_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_caseC_DW.integratorresetmodel_DWORK1, 0, discStates[idx
       ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.nu_x_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.nu_y_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.nu_psi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L1_11_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L3_11_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L3_22_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L3_33_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L2_33_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L1_33_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L1_22_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L2_11_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L2_22_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_caseC_DW.NIVeriStandSignalProbe_DWORK2, 0,
       discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.RandSeed, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.RandSeed_j, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.RandSeed_c, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_caseC_DW.Integrator2_IWORK.IcNeedsLoading, 0,
       discStates[idx++], 10, 0);
    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.niose_power_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.y_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.x_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.psi_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.SystemReset_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_hat_x_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_tilde_x_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_tilde_y_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_tilde_psi_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.r_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_hat_y_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.u_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_hat_psi_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.v_in_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_mpsi_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_mx_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.eta_my_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L2_continuous_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.PosXRight_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.PosYRight_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.R2_continuous_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.R1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.ArrowRight_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.X_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.N_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.Y_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.psi_0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.x_0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.y_0_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_caseC_DW.integratorresetmodel_DWORK2, count,
         discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.nu_x_hat_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.nu_y_hat_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.nu_psi_hat_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L1_11_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L3_11_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L3_22_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L3_33_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L2_33_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L1_33_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L1_22_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L2_11_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_caseC_DW.L2_22_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_caseC_DW.NIVeriStandSignalProbe_DWORK1, count,
         discStates[idx++], 17, 0);
    }

    for (count = 0; count < 66; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_caseC_DW.NIVeriStandSignalProbe_DWORK3, count,
         discStates[idx++], 20, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL_caseC
