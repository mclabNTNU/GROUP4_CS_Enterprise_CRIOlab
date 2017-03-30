/*
 * ctrl_student_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.277
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Mar 30 17:34:51 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

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
  int_T nXc = 13;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_HIL_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

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

/* Function for MATLAB Function: '<S33>/MATLAB Function1' */
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
  real_T yd;
  real_T xds;
  real_T yds;
  real_T a;
  real_T b_a;
  real_T x;
  real_T c_a;
  real_T c_x;
  real_T d_x;
  real_T S_r[9];
  real_T z1[3];
  real_T alpha1[3];
  real_T z2[3];
  real_T rtb_Product_a;
  real_T rtb_Product;
  real_T rtb_Product_f;
  real_T rtb_Integrator[3];
  real_T rtb_Sum3_l[3];
  int32_T rtb_bool;
  real_T rtb_R[9];
  real_T rtb_R_T[9];
  real_T rtb_D[9];
  real_T rtb_C[9];
  real_T rtb_M[9];
  real_T rtb_R_c[9];
  static const int8_T tmp[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T tmp_0[9] = { 16.79, 0.0, 0.0, 0.0, 24.79,
    0.55462499999999992, 0.0, 0.55462499999999992, 2.76 };

  int32_T i;
  real_T tmp_1[9];
  real_T tmp_2[3];
  real_T rtb_D_0[3];
  real_T S_r_0[9];
  real_T rtb_R_T_0[3];
  real_T S_r_1[3];
  int32_T i_0;
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

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* MATLAB Function: '<S23>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Constant: '<S4>/Step size'
     *  Memory: '<S23>/counter'
     */
    /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S26>:1' */
    /* '<S26>:1:3' */
    if ((ctrl_student_HIL_DW.counter_PreviousInput + 1.0) *
        ctrl_student_HIL_P.Stepsize_Value >= 1.0 /
        ctrl_student_HIL_P.Constant4_Value) {
      /* '<S26>:1:4' */
      /* '<S26>:1:5' */
      ctrl_student_HIL_B.count = 0.0;
    } else {
      /* '<S26>:1:7' */
      ctrl_student_HIL_B.count = ctrl_student_HIL_DW.counter_PreviousInput + 1.0;
    }

    /* End of MATLAB Function: '<S23>/MATLAB Function' */
  }

  /* Gain: '<Root>/Gain' */
  rtb_Product_a = ctrl_student_HIL_P.Gain_Gain * ctrl_student_HIL_B.niose_power;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S29>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise = ctrl_student_HIL_DW.NextOutput;
  }

  /* Product: '<S29>/Product' incorporates:
   *  Constant: '<S4>/Step size'
   *  Product: '<S29>/Divide'
   *  Sqrt: '<S29>/Sqrt'
   */
  rtb_Product = sqrt(rtb_Product_a / ctrl_student_HIL_P.Stepsize_Value) *
    ctrl_student_HIL_B.WhiteNoise;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S30>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_e = ctrl_student_HIL_DW.NextOutput_c;
  }

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S4>/Step size'
   *  Product: '<S30>/Divide'
   *  Sqrt: '<S30>/Sqrt'
   */
  rtb_Product_f = sqrt(rtb_Product_a / ctrl_student_HIL_P.Stepsize_Value) *
    ctrl_student_HIL_B.WhiteNoise_e;

  /* Product: '<S28>/Divide' incorporates:
   *  Constant: '<S4>/Step size'
   */
  rtb_Product_a /= ctrl_student_HIL_P.Stepsize_Value;

  /* Sqrt: '<S28>/Sqrt' */
  rtb_Product_a = sqrt(rtb_Product_a);
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S28>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_m = ctrl_student_HIL_DW.NextOutput_p;
  }

  /* Product: '<S28>/Product' */
  rtb_Product_a *= ctrl_student_HIL_B.WhiteNoise_m;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S24>/Hold' */
    ctrl_student_HIL_B.Hold[0] = ctrl_student_HIL_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_B.Hold[1] = ctrl_student_HIL_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_B.Hold[2] = ctrl_student_HIL_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S24>/MATLAB Function1' incorporates:
   *  Sum: '<S4>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S27>:1' */
  if (ctrl_student_HIL_B.count == 0.0) {
    /* '<S27>:1:4' */
    /* '<S27>:1:5' */
    ctrl_student_HIL_B.output[0] = rtb_Product + ctrl_student_HIL_B.x_in;
    ctrl_student_HIL_B.output[1] = rtb_Product_f + ctrl_student_HIL_B.y_in;
    ctrl_student_HIL_B.output[2] = rtb_Product_a + ctrl_student_HIL_B.psi_in;
  } else {
    /* '<S27>:1:7' */
    ctrl_student_HIL_B.output[0] = ctrl_student_HIL_B.Hold[0];
    ctrl_student_HIL_B.output[1] = ctrl_student_HIL_B.Hold[1];
    ctrl_student_HIL_B.output[2] = ctrl_student_HIL_B.Hold[2];
  }

  /* End of MATLAB Function: '<S24>/MATLAB Function1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S36>/Memory' */
    ctrl_student_HIL_B.Memory[0] = ctrl_student_HIL_DW.Memory_PreviousInput[0];
    ctrl_student_HIL_B.Memory[1] = ctrl_student_HIL_DW.Memory_PreviousInput[1];
    ctrl_student_HIL_B.Memory[2] = ctrl_student_HIL_DW.Memory_PreviousInput[2];
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S6>/Memory' */
    ctrl_student_HIL_B.Memory_c[0] = ctrl_student_HIL_DW.Memory_PreviousInput_l
      [0];
    ctrl_student_HIL_B.Memory_c[1] = ctrl_student_HIL_DW.Memory_PreviousInput_l
      [1];
    ctrl_student_HIL_B.Memory_c[2] = ctrl_student_HIL_DW.Memory_PreviousInput_l
      [2];
  }

  /* MATLAB Function: '<S6>/Signal drop-out simulation' */
  /* MATLAB Function 'Signal Drop-out/Signal drop-out simulation': '<S37>:1' */
  if (ctrl_student_HIL_B.Dropout == 1.0) {
    /* '<S37>:1:3' */
    /* '<S37>:1:4' */
    ctrl_student_HIL_B.eta_m_out[0] = ctrl_student_HIL_B.Memory_c[0];
    ctrl_student_HIL_B.eta_m_out[1] = ctrl_student_HIL_B.Memory_c[1];
    ctrl_student_HIL_B.eta_m_out[2] = ctrl_student_HIL_B.Memory_c[2];
  } else {
    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    /* '<S37>:1:7' */
    if (ctrl_student_HIL_P.Constant2_Value != 0.0) {
      ctrl_student_HIL_B.eta_m_out[0] = ctrl_student_HIL_B.output[0];
      ctrl_student_HIL_B.eta_m_out[1] = ctrl_student_HIL_B.output[1];
      ctrl_student_HIL_B.eta_m_out[2] = ctrl_student_HIL_B.output[2];
    } else {
      ctrl_student_HIL_B.eta_m_out[0] = ctrl_student_HIL_B.x_in;
      ctrl_student_HIL_B.eta_m_out[1] = ctrl_student_HIL_B.y_in;
      ctrl_student_HIL_B.eta_m_out[2] = ctrl_student_HIL_B.psi_in;
    }

    /* End of Switch: '<S4>/Switch' */
  }

  /* End of MATLAB Function: '<S6>/Signal drop-out simulation' */

  /* MATLAB Function: '<S36>/MATLAB Function' */
  /* if */
  /* MATLAB Function 'Signal Drop-out/Detection/MATLAB Function': '<S38>:1' */
  if ((ctrl_student_HIL_B.eta_m_out[0] - ctrl_student_HIL_B.Memory[0] == 0.0) &&
      (ctrl_student_HIL_B.eta_m_out[1] - ctrl_student_HIL_B.Memory[1] == 0.0) &&
      (ctrl_student_HIL_B.eta_m_out[2] - ctrl_student_HIL_B.Memory[2] == 0.0)) {
    /* '<S38>:1:3' */
    /* '<S38>:1:4' */
    rtb_bool = 0;
  } else {
    /* '<S38>:1:6' */
    rtb_bool = 1;
  }

  /* '<S38>:1:9' */
  ctrl_student_HIL_B.eta_m_c1[0] = ctrl_student_HIL_B.eta_m_out[0];
  ctrl_student_HIL_B.eta_m_c1[1] = ctrl_student_HIL_B.eta_m_out[1];
  ctrl_student_HIL_B.eta_m_c1[2] = ctrl_student_HIL_B.eta_m_out[2];

  /* End of MATLAB Function: '<S36>/MATLAB Function' */

  /* Integrator: '<S5>/Integrator2' */
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

  ctrl_student_HIL_B.Integrator2[0] = ctrl_student_HIL_X.Integrator2_CSTATE[0];
  ctrl_student_HIL_B.Integrator2[1] = ctrl_student_HIL_X.Integrator2_CSTATE[1];
  ctrl_student_HIL_B.Integrator2[2] = ctrl_student_HIL_X.Integrator2_CSTATE[2];

  /* Sum: '<Root>/Sum' */
  ctrl_student_HIL_B.Sum[0] = ctrl_student_HIL_B.eta_m_c1[0] -
    ctrl_student_HIL_B.Integrator2[0];
  ctrl_student_HIL_B.Sum[1] = ctrl_student_HIL_B.eta_m_c1[1] -
    ctrl_student_HIL_B.Integrator2[1];
  ctrl_student_HIL_B.Sum[2] = ctrl_student_HIL_B.eta_m_c1[2] -
    ctrl_student_HIL_B.Integrator2[2];

  /* Integrator: '<S3>/Integrator' */
  rtb_Integrator[0] = ctrl_student_HIL_X.Integrator_CSTATE[0];
  rtb_Integrator[1] = ctrl_student_HIL_X.Integrator_CSTATE[1];
  rtb_Integrator[2] = ctrl_student_HIL_X.Integrator_CSTATE[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Integrator: '<S3>/Integrator'
   *  Sum: '<Root>/Subtract1'
   */
  if (ctrl_student_HIL_P.ManualSwitch_CurrentSetting == 1) {
    ctrl_student_HIL_B.ManualSwitch[0] = ctrl_student_HIL_X.Integrator_CSTATE[0];
    ctrl_student_HIL_B.ManualSwitch[1] = ctrl_student_HIL_X.Integrator_CSTATE[1];
    ctrl_student_HIL_B.ManualSwitch[2] = ctrl_student_HIL_X.Integrator_CSTATE[2];
  } else {
    ctrl_student_HIL_B.ManualSwitch[0] = ctrl_student_HIL_B.PosYRight;
    ctrl_student_HIL_B.ManualSwitch[1] = ctrl_student_HIL_B.PosXRight;
    ctrl_student_HIL_B.ManualSwitch[2] = ctrl_student_HIL_B.R2_continuous -
      ctrl_student_HIL_B.L2_continuous;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* MATLAB Function: '<S5>/MATLAB Function' */
  /* MATLAB Function 'Observer/MATLAB Function': '<S32>:1' */
  /* '<S32>:1:3' */
  /* '<S32>:1:5' */
  rtb_R[0] = cos(ctrl_student_HIL_B.eta_m_c1[2]);
  rtb_R[3] = -sin(ctrl_student_HIL_B.eta_m_c1[2]);
  rtb_R[6] = 0.0;
  rtb_R[1] = sin(ctrl_student_HIL_B.eta_m_c1[2]);
  rtb_R[4] = cos(ctrl_student_HIL_B.eta_m_c1[2]);
  rtb_R[7] = 0.0;
  rtb_R[2] = 0.0;
  rtb_R[5] = 0.0;
  rtb_R[8] = 1.0;

  /* Rotation matrix */
  /* '<S32>:1:7' */
  for (i = 0; i < 3; i++) {
    rtb_R_T[3 * i] = rtb_R[i];
    rtb_R_T[1 + 3 * i] = rtb_R[i + 3];
    rtb_R_T[2 + 3 * i] = rtb_R[i + 6];
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */
  /* Transpose rotation matrix */

  /* Integrator: '<S5>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_student_HIL_B.SystemReset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_student_HIL_X.Integrator1_CSTATE[0] =
        (ctrl_student_HIL_P.Integrator1_IC[0]);
      ctrl_student_HIL_X.Integrator1_CSTATE[1] =
        (ctrl_student_HIL_P.Integrator1_IC[1]);
      ctrl_student_HIL_X.Integrator1_CSTATE[2] =
        (ctrl_student_HIL_P.Integrator1_IC[2]);
    }
  }

  ctrl_student_HIL_B.Integrator1[0] = ctrl_student_HIL_X.Integrator1_CSTATE[0];
  ctrl_student_HIL_B.Integrator1[1] = ctrl_student_HIL_X.Integrator1_CSTATE[1];
  ctrl_student_HIL_B.Integrator1[2] = ctrl_student_HIL_X.Integrator1_CSTATE[2];

  /* MATLAB Function: '<S33>/MATLAB Function1' */
  memcpy(&rtb_M[0], &tmp_0[0], 9U * sizeof(real_T));

  /* MATLAB Function 'Observer/kinematics/MATLAB Function1': '<S35>:1' */
  /* '<S35>:1:2' */
  /* '<S35>:1:3' */
  /* '<S35>:1:4' */
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
  /* '<S35>:1:26' */
  /* '<S35>:1:30' */
  /* % Damping coefficients */
  /*  Comments at the end of the lines indicate the old values used. */
  /* '<S35>:1:33' */
  /* '<S35>:1:37' */
  /*  Y_r */
  /*  Y_rrzx */
  /*  Y_rv, Y_vr */
  /* '<S35>:1:43' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /* % Correolis matrix */
  /* '<S35>:1:50' */
  /* '<S35>:1:51' */
  rtb_Product_a = -10.0 * ctrl_student_HIL_B.Integrator1[1] +
    -0.55462499999999992 * ctrl_student_HIL_B.Integrator1[2];

  /* '<S35>:1:52' */
  /* '<S35>:1:53' */
  rtb_Product = 2.0 * ctrl_student_HIL_B.Integrator1[0];

  /* '<S35>:1:54' */
  /* '<S35>:1:55' */
  /* '<S35>:1:56' */
  /* % Assembly of the damping matrix */
  /* '<S35>:1:61' */
  /* '<S35>:1:62' */
  /* '<S35>:1:63' */
  /* '<S35>:1:64' */
  /* '<S35>:1:65' */
  /*  using abs(r) */
  /* '<S35>:1:67' */
  rtb_D[0] = (0.6555 - 0.3545 * fabs(ctrl_student_HIL_B.Integrator1[0])) -
    ctrl_student_HIL_B.Integrator1[0] * ctrl_student_HIL_B.Integrator1[0] *
    -3.787;
  rtb_D[3] = 0.0;
  rtb_D[6] = 0.0;
  rtb_D[1] = 0.0;
  rtb_D[4] = ((1.33 - -2.776 * fabs(ctrl_student_HIL_B.Integrator1[1])) -
              ctrl_student_HIL_B.Integrator1[1] *
              ctrl_student_HIL_B.Integrator1[1] * -64.91) - -0.805 * fabs
    (ctrl_student_HIL_B.Integrator1[2]);
  rtb_D[7] = ((7.25 - -0.845 * fabs(ctrl_student_HIL_B.Integrator1[1])) - -3.45 *
              fabs(ctrl_student_HIL_B.Integrator1[2])) -
    ctrl_student_HIL_B.Integrator1[2] * ctrl_student_HIL_B.Integrator1[2] * 0.0;
  rtb_D[2] = 0.0;
  rtb_D[5] = ((-0.0 - -0.2088 * fabs(ctrl_student_HIL_B.Integrator1[1])) -
              ctrl_student_HIL_B.Integrator1[1] *
              ctrl_student_HIL_B.Integrator1[1] * 0.0) - 0.13 * fabs
    (ctrl_student_HIL_B.Integrator1[2]);
  rtb_D[8] = ((1.9 - 0.08 * fabs(ctrl_student_HIL_B.Integrator1[1])) - -0.75 *
              fabs(ctrl_student_HIL_B.Integrator1[2])) -
    ctrl_student_HIL_B.Integrator1[2] * ctrl_student_HIL_B.Integrator1[2] * 0.0;
  rtb_C[0] = 0.0;
  rtb_C[3] = -14.79 * ctrl_student_HIL_B.Integrator1[2];
  rtb_C[6] = rtb_Product_a;
  rtb_C[1] = 14.79 * ctrl_student_HIL_B.Integrator1[2];
  rtb_C[4] = 0.0;
  rtb_C[7] = rtb_Product;
  rtb_C[2] = -rtb_Product_a;
  rtb_C[5] = -rtb_Product;
  rtb_C[8] = 0.0;

  /* Integrator: '<S3>/Integrator1' */
  ctrl_student_HIL_B.Integrator1_k = ctrl_student_HIL_X.Integrator1_CSTATE_e;

  /* MATLAB Function: '<S16>/Ellipsoid' */
  /* MATLAB Function 'Guidance/Path generation/Ellipsoid': '<S20>:1' */
  /* U_ref */
  /* Path variables */
  /* '<S20>:1:8' */
  /* '<S20>:1:9' */
  /* eta_d */
  /* '<S20>:1:12' */
  rtb_Product_f = 5.0 * cos(ctrl_student_HIL_B.Integrator1_k) + 6.0;

  /* '<S20>:1:13' */
  yd = 3.0 * sin(ctrl_student_HIL_B.Integrator1_k);

  /* '<S20>:1:14' */
  /* eta_ds */
  /* '<S20>:1:17' */
  xds = -5.0 * sin(ctrl_student_HIL_B.Integrator1_k);

  /* '<S20>:1:18' */
  yds = 3.0 * cos(ctrl_student_HIL_B.Integrator1_k);

  /* '<S20>:1:19' */
  a = 5.0 * sin(ctrl_student_HIL_B.Integrator1_k);
  b_a = 3.0 * cos(ctrl_student_HIL_B.Integrator1_k);

  /* eta_ds2 */
  /* '<S20>:1:22' */
  /* '<S20>:1:23' */
  /* '<S20>:1:24' */
  x = 1.0 / sin(ctrl_student_HIL_B.Integrator1_k);
  rtb_Product_a = 1.0 / tan(ctrl_student_HIL_B.Integrator1_k);
  c_a = rtb_Product_a * rtb_Product_a * 9.0 + 25.0;

  /* eta_d_vectors */
  /* '<S20>:1:27' */
  /* '<S20>:1:28' */
  /* '<S20>:1:29' */
  /* U_s */
  /* '<S20>:1:32' */
  /* '<S20>:1:33' */
  c_x = sin(ctrl_student_HIL_B.Integrator1_k);
  d_x = cos(ctrl_student_HIL_B.Integrator1_k);

  /* MATLAB Function: '<S16>/straight line' */
  /* MATLAB Function 'Guidance/Path generation/straight line': '<S21>:1' */
  /* U_ref */
  /* U_ref = 0.1*(1.01+sin(2*pi*s-(pi/2))); */
  /* Path variables */
  /* '<S21>:1:7' */
  /* '<S21>:1:8' */
  /* Slope */
  /* eta_d */
  /* '<S21>:1:17' */
  rtb_Product_a = 8.0 * ctrl_student_HIL_B.Integrator1_k + 2.0;

  /* '<S21>:1:18' */
  rtb_Product = 4.0 * ctrl_student_HIL_B.Integrator1_k;

  /* InitialCondition: '<S16>/IC' incorporates:
   *  MATLAB Function: '<S16>/Ellipsoid'
   *  MATLAB Function: '<S16>/straight line'
   *  Sum: '<S16>/Sum2'
   */
  /* '<S21>:1:19' */
  /* eta_d_vectors */
  /* '<S21>:1:22' */
  /* '<S21>:1:23' */
  /* '<S21>:1:24' */
  /* U_s */
  /* '<S21>:1:27' */
  /* '<S21>:1:28' */
  /* U_ss=U_ref*2*pi*sin(2*pi*s)/(sqrt(a1^2+a2^2))*(1-path); */
  if ((ctrl_student_HIL_DW.IC_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC_FirstOutputTime == ctrl_student_HIL_M->Timing.t[0]))
  {
    ctrl_student_HIL_DW.IC_FirstOutputTime = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC[0] = ctrl_student_HIL_P.IC_Value[0];
    ctrl_student_HIL_B.IC[1] = ctrl_student_HIL_P.IC_Value[1];
    ctrl_student_HIL_B.IC[2] = ctrl_student_HIL_P.IC_Value[2];
  } else {
    ctrl_student_HIL_B.IC[0] = (1.0 - ctrl_student_HIL_B.pathNumber) *
      rtb_Product_a + rtb_Product_f * ctrl_student_HIL_B.pathNumber;
    ctrl_student_HIL_B.IC[1] = (1.0 - ctrl_student_HIL_B.pathNumber) *
      rtb_Product + yd * ctrl_student_HIL_B.pathNumber;
    ctrl_student_HIL_B.IC[2] = (1.0 - ctrl_student_HIL_B.pathNumber) *
      rt_atan2d_snf(rtb_Product, rtb_Product_a) + rt_atan2d_snf(yd,
      rtb_Product_f) * ctrl_student_HIL_B.pathNumber;
  }

  /* End of InitialCondition: '<S16>/IC' */

  /* InitialCondition: '<S16>/IC1' incorporates:
   *  MATLAB Function: '<S16>/Ellipsoid'
   *  MATLAB Function: '<S16>/straight line'
   *  Sum: '<S16>/Sum4'
   */
  if ((ctrl_student_HIL_DW.IC1_FirstOutputTime == (rtMinusInf)) ||
      (ctrl_student_HIL_DW.IC1_FirstOutputTime == ctrl_student_HIL_M->Timing.t[0]))
  {
    ctrl_student_HIL_DW.IC1_FirstOutputTime = ctrl_student_HIL_M->Timing.t[0];
    ctrl_student_HIL_B.IC1[0] = ctrl_student_HIL_P.IC1_Value[0];
    ctrl_student_HIL_B.IC1[1] = ctrl_student_HIL_P.IC1_Value[1];
    ctrl_student_HIL_B.IC1[2] = ctrl_student_HIL_P.IC1_Value[2];
  } else {
    ctrl_student_HIL_B.IC1[0] = (1.0 - ctrl_student_HIL_B.pathNumber) * 8.0 +
      xds * ctrl_student_HIL_B.pathNumber;
    ctrl_student_HIL_B.IC1[1] = (1.0 - ctrl_student_HIL_B.pathNumber) * 4.0 +
      yds * ctrl_student_HIL_B.pathNumber;
    ctrl_student_HIL_B.IC1[2] = 15.0 / (a * a + b_a * b_a) *
      ctrl_student_HIL_B.pathNumber + (1.0 - ctrl_student_HIL_B.pathNumber) *
      0.0;
  }

  /* End of InitialCondition: '<S16>/IC1' */

  /* Sum: '<S16>/Sum3' incorporates:
   *  MATLAB Function: '<S16>/Ellipsoid'
   *  MATLAB Function: '<S16>/straight line'
   */
  xds = 0.1 / sqrt(xds * xds + yds * yds) * ctrl_student_HIL_B.pathNumber + (1.0
    - ctrl_student_HIL_B.pathNumber) * 0.011180339887498949;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S19>/Memory' */
    ctrl_student_HIL_B.Memory_a = ctrl_student_HIL_DW.Memory_PreviousInput_la;
  }

  /* MATLAB Function: '<S19>/s calculation' */
  /* MATLAB Function 'Guidance/s_dot generation/s calculation': '<S22>:1' */
  /* V_1s = -0.5*(eta_ds.')*(eta-eta_d)-0.5*((eta-eta_d).')*eta_ds; */
  /* '<S22>:1:5' */
  /* '<S22>:1:7' */
  rtb_Product = 2.2250738585072014E-308;
  rtb_Product_f = fabs(ctrl_student_HIL_B.IC1[0]);
  if (rtb_Product_f > 2.2250738585072014E-308) {
    rtb_Product_a = 1.0;
    rtb_Product = rtb_Product_f;
  } else {
    yd = rtb_Product_f / 2.2250738585072014E-308;
    rtb_Product_a = yd * yd;
  }

  rtb_Product_f = fabs(ctrl_student_HIL_B.IC1[1]);
  if (rtb_Product_f > rtb_Product) {
    yd = rtb_Product / rtb_Product_f;
    rtb_Product_a = rtb_Product_a * yd * yd + 1.0;
    rtb_Product = rtb_Product_f;
  } else {
    yd = rtb_Product_f / rtb_Product;
    rtb_Product_a += yd * yd;
  }

  rtb_Product_f = fabs(ctrl_student_HIL_B.IC1[2]);
  if (rtb_Product_f > rtb_Product) {
    yd = rtb_Product / rtb_Product_f;
    rtb_Product_a = rtb_Product_a * yd * yd + 1.0;
    rtb_Product = rtb_Product_f;
  } else {
    yd = rtb_Product_f / rtb_Product;
    rtb_Product_a += yd * yd;
  }

  rtb_Product_a = rtb_Product * sqrt(rtb_Product_a);
  ctrl_student_HIL_B.s_dot = xds - ((-(rtb_Integrator[0] -
    ctrl_student_HIL_B.IC[0]) * ctrl_student_HIL_B.IC1[0] + -(rtb_Integrator[1]
    - ctrl_student_HIL_B.IC[1]) * ctrl_student_HIL_B.IC1[1]) + -(rtb_Integrator
    [2] - ctrl_student_HIL_B.IC[2]) * ctrl_student_HIL_B.IC1[2]) *
    (ctrl_student_HIL_B.my / rtb_Product_a);
  if (ctrl_student_HIL_B.pathNumber == 0.0) {
    /* '<S22>:1:9' */
    if ((ctrl_student_HIL_B.Integrator1_k < 1.0) &&
        (ctrl_student_HIL_B.Integrator1_k > 0.0)) {
      /* '<S22>:1:10' */
      if (ctrl_student_HIL_B.Integrator1_k < 0.0) {
        rtb_Product = -1.0;
      } else if (ctrl_student_HIL_B.Integrator1_k > 0.0) {
        rtb_Product = 1.0;
      } else if (ctrl_student_HIL_B.Integrator1_k == 0.0) {
        rtb_Product = 0.0;
      } else {
        rtb_Product = ctrl_student_HIL_B.Integrator1_k;
      }

      if (ctrl_student_HIL_B.Memory_a < 0.0) {
        rtb_Product_f = -1.0;
      } else if (ctrl_student_HIL_B.Memory_a > 0.0) {
        rtb_Product_f = 1.0;
      } else if (ctrl_student_HIL_B.Memory_a == 0.0) {
        rtb_Product_f = 0.0;
      } else {
        rtb_Product_f = ctrl_student_HIL_B.Memory_a;
      }

      if (!(rtb_Product == rtb_Product_f)) {
        /* '<S22>:1:14' */
        if (ctrl_student_HIL_B.Memory_a < 0.0) {
          rtb_Product = -1.0;
        } else if (ctrl_student_HIL_B.Memory_a > 0.0) {
          rtb_Product = 1.0;
        } else if (ctrl_student_HIL_B.Memory_a == 0.0) {
          rtb_Product = 0.0;
        } else {
          rtb_Product = ctrl_student_HIL_B.Memory_a;
        }

        ctrl_student_HIL_B.s_dot *= rtb_Product;
      } else {
        /* '<S22>:1:11' */
        /* '<S22>:1:12' */
      }
    } else if (ctrl_student_HIL_B.Integrator1_k >= 1.0) {
      /* '<S22>:1:16' */
      if (ctrl_student_HIL_B.Integrator1_k < 0.0) {
        rtb_Product = -1.0;
      } else if (ctrl_student_HIL_B.Integrator1_k > 0.0) {
        rtb_Product = 1.0;
      } else if (ctrl_student_HIL_B.Integrator1_k == 0.0) {
        rtb_Product = 0.0;
      } else {
        rtb_Product = ctrl_student_HIL_B.Integrator1_k;
      }

      if (ctrl_student_HIL_B.Memory_a < 0.0) {
        rtb_Product_f = -1.0;
      } else if (ctrl_student_HIL_B.Memory_a > 0.0) {
        rtb_Product_f = 1.0;
      } else if (ctrl_student_HIL_B.Memory_a == 0.0) {
        rtb_Product_f = 0.0;
      } else {
        rtb_Product_f = ctrl_student_HIL_B.Memory_a;
      }

      if (rtb_Product == rtb_Product_f) {
        /* '<S22>:1:17' */
        /* '<S22>:1:18' */
        ctrl_student_HIL_B.s_dot = -ctrl_student_HIL_B.s_dot;
      } else {
        /* '<S22>:1:20' */
        if (ctrl_student_HIL_B.Memory_a < 0.0) {
          rtb_Product = -1.0;
        } else if (ctrl_student_HIL_B.Memory_a > 0.0) {
          rtb_Product = 1.0;
        } else if (ctrl_student_HIL_B.Memory_a == 0.0) {
          rtb_Product = 0.0;
        } else {
          rtb_Product = ctrl_student_HIL_B.Memory_a;
        }

        ctrl_student_HIL_B.s_dot *= rtb_Product;
      }
    } else {
      if (ctrl_student_HIL_B.Integrator1_k < 0.0) {
        rtb_Product = -1.0;
      } else if (ctrl_student_HIL_B.Integrator1_k > 0.0) {
        rtb_Product = 1.0;
      } else if (ctrl_student_HIL_B.Integrator1_k == 0.0) {
        rtb_Product = 0.0;
      } else {
        rtb_Product = ctrl_student_HIL_B.Integrator1_k;
      }

      if (ctrl_student_HIL_B.Memory_a < 0.0) {
        rtb_Product_f = -1.0;
      } else if (ctrl_student_HIL_B.Memory_a > 0.0) {
        rtb_Product_f = 1.0;
      } else if (ctrl_student_HIL_B.Memory_a == 0.0) {
        rtb_Product_f = 0.0;
      } else {
        rtb_Product_f = ctrl_student_HIL_B.Memory_a;
      }

      if ((ctrl_student_HIL_B.Integrator1_k <= 0.0) && (!(rtb_Product ==
            rtb_Product_f))) {
        /* '<S22>:1:23' */
        /* '<S22>:1:27' */
        if (ctrl_student_HIL_B.Memory_a < 0.0) {
          rtb_Product = -1.0;
        } else if (ctrl_student_HIL_B.Memory_a > 0.0) {
          rtb_Product = 1.0;
        } else if (ctrl_student_HIL_B.Memory_a == 0.0) {
          rtb_Product = 0.0;
        } else {
          rtb_Product = ctrl_student_HIL_B.Memory_a;
        }

        ctrl_student_HIL_B.s_dot *= rtb_Product;
      } else {
        /* '<S22>:1:24' */
        /* '<S22>:1:25' */
      }
    }
  }

  /* End of MATLAB Function: '<S19>/s calculation' */

  /* Sum: '<S16>/Sum1' incorporates:
   *  MATLAB Function: '<S16>/Ellipsoid'
   */
  rtb_Product_a = -1.6 * sin(ctrl_student_HIL_B.Integrator1_k) * cos
    (ctrl_student_HIL_B.Integrator1_k) / rt_powd_snf(c_x * c_x * 25.0 + d_x *
    d_x * 9.0, 1.5) * ctrl_student_HIL_B.pathNumber;

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S15>/Constant'
   *  SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Gain Matrices/Controller gain matrix k_p2': '<S13>:1' */
  /* Gain matrix for controller gain values k_p2 */
  /* '<S13>:1:3' */
  /* MATLAB Function 'Controller/MATLAB Function': '<S11>:1' */
  /* Rotation rate matrix */
  /* '<S11>:1:3' */
  S_r[0] = 0.0;
  S_r[3] = -ctrl_student_HIL_B.Integrator1[2];
  S_r[6] = 0.0;
  S_r[1] = ctrl_student_HIL_B.Integrator1[2];
  S_r[4] = 0.0;
  S_r[7] = 0.0;
  S_r[2] = 0.0;
  S_r[5] = 0.0;
  S_r[8] = 0.0;

  /* Error states */
  /* '<S11>:1:6' */
  rtb_Product = ctrl_student_HIL_B.x_in - ctrl_student_HIL_B.ManualSwitch[0];
  rtb_Product_f = ctrl_student_HIL_B.y_in - ctrl_student_HIL_B.ManualSwitch[1];
  yd = ctrl_student_HIL_B.psi_in - ctrl_student_HIL_B.ManualSwitch[2];
  for (i = 0; i < 3; i++) {
    z1[i] = rtb_R_T[i + 6] * yd + (rtb_R_T[i + 3] * rtb_Product_f + rtb_R_T[i] *
      rtb_Product);
  }

  /* Virtual Controller */
  /* '<S11>:1:9' */
  for (i = 0; i < 3; i++) {
    tmp_1[3 * i] = -ctrl_student_HIL_P.Constant_Value[3 * i];
    tmp_1[1 + 3 * i] = -ctrl_student_HIL_P.Constant_Value[3 * i + 1];
    tmp_1[2 + 3 * i] = -ctrl_student_HIL_P.Constant_Value[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    alpha1[i] = ((tmp_1[i + 3] * z1[1] + tmp_1[i] * z1[0]) + tmp_1[i + 6] * z1[2])
      + ctrl_student_HIL_B.IC1[i] * xds;
  }

  /* Error states */
  /* '<S11>:1:12' */
  z2[0] = ctrl_student_HIL_B.Integrator1[0] - alpha1[0];
  z2[1] = ctrl_student_HIL_B.Integrator1[1] - alpha1[1];
  z2[2] = ctrl_student_HIL_B.Integrator1[2] - alpha1[2];

  /* Product: '<S31>/Matrix Multiply2' incorporates:
   *  Integrator: '<S31>/Integrator'
   */
  /* Error state derivatives */
  /* '<S11>:1:15' */
  /* Alpha1_dot */
  /* '<S11>:1:18' */
  /* '<S11>:1:19' */
  /* '<S11>:1:20' */
  /* Tau (Is the nu_hat correctly used here?) */
  /* '<S11>:1:23' */
  for (i = 0; i < 3; i++) {
    rtb_Sum3_l[i] = rtb_R_T[i + 6] * ctrl_student_HIL_X.Integrator_CSTATE_b[2] +
      (rtb_R_T[i + 3] * ctrl_student_HIL_X.Integrator_CSTATE_b[1] + rtb_R_T[i] *
       ctrl_student_HIL_X.Integrator_CSTATE_b[0]);
  }

  /* End of Product: '<S31>/Matrix Multiply2' */

  /* MATLAB Function: '<S2>/Controller gain matrix k_p2' */
  S_r_0[0] = ctrl_student_HIL_B.K_p2_1;
  S_r_0[3] = 0.0;
  S_r_0[6] = 0.0;
  S_r_0[1] = 0.0;
  S_r_0[4] = ctrl_student_HIL_B.K_p2_2;
  S_r_0[7] = 0.0;
  S_r_0[2] = 0.0;
  S_r_0[5] = 0.0;
  S_r_0[8] = ctrl_student_HIL_B.K_p2_3;

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S15>/Constant'
   */
  for (i = 0; i < 3; i++) {
    tmp_1[3 * i] = -S_r_0[3 * i];
    tmp_1[1 + 3 * i] = -S_r_0[3 * i + 1];
    tmp_1[2 + 3 * i] = -S_r_0[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    tmp_2[i] = ((tmp_1[i + 3] * z2[1] + tmp_1[i] * z2[0]) + tmp_1[i + 6] * z2[2])
      - z1[i];
  }

  for (i = 0; i < 3; i++) {
    rtb_D_0[i] = rtb_D[i + 6] * ctrl_student_HIL_B.Integrator1[2] + (rtb_D[i + 3]
      * ctrl_student_HIL_B.Integrator1[1] + rtb_D[i] *
      ctrl_student_HIL_B.Integrator1[0]);
  }

  for (i = 0; i < 3; i++) {
    S_r_0[3 * i] = -S_r[3 * i];
    S_r_0[1 + 3 * i] = -S_r[3 * i + 1];
    S_r_0[2 + 3 * i] = -S_r[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    rtb_R_T_0[i] = rtb_R_T[i + 6] * ctrl_student_HIL_B.IC1[2] + (rtb_R_T[i + 3] *
      ctrl_student_HIL_B.IC1[1] + rtb_R_T[i] * ctrl_student_HIL_B.IC1[0]);
  }

  for (i = 0; i < 3; i++) {
    tmp_1[3 * i] = -ctrl_student_HIL_P.Constant_Value[3 * i];
    tmp_1[1 + 3 * i] = -ctrl_student_HIL_P.Constant_Value[3 * i + 1];
    tmp_1[2 + 3 * i] = -ctrl_student_HIL_P.Constant_Value[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    S_r_1[i] = ((((S_r_0[i + 3] * z1[1] + S_r_0[i] * z1[0]) + S_r_0[i + 6] * z1
                  [2]) + z2[i]) + alpha1[i]) - rtb_R_T_0[i] *
      ctrl_student_HIL_B.s_dot;
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      S_r_0[i + 3 * i_0] = 0.0;
      S_r_0[i + 3 * i_0] += rtb_R_T[3 * i_0] * S_r[i];
      S_r_0[i + 3 * i_0] += rtb_R_T[3 * i_0 + 1] * S_r[i + 3];
      S_r_0[i + 3 * i_0] += rtb_R_T[3 * i_0 + 2] * 0.0;
    }
  }

  for (i = 0; i < 3; i++) {
    z2[i] = S_r_0[i + 6] * ctrl_student_HIL_B.IC1[2] + (S_r_0[i + 3] *
      ctrl_student_HIL_B.IC1[1] + S_r_0[i] * ctrl_student_HIL_B.IC1[0]);
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      S_r_0[i + 3 * i_0] = 0.0;
      S_r_0[i + 3 * i_0] += rtb_R_T[3 * i_0] *
        ctrl_student_HIL_P.Constant_Value[i];
      S_r_0[i + 3 * i_0] += rtb_R_T[3 * i_0 + 1] *
        ctrl_student_HIL_P.Constant_Value[i + 3];
      S_r_0[i + 3 * i_0] += rtb_R_T[3 * i_0 + 2] *
        ctrl_student_HIL_P.Constant_Value[i + 6];
    }
  }

  /* Sum: '<S16>/Sum' incorporates:
   *  MATLAB Function: '<S16>/Ellipsoid'
   */
  rtb_Product = -5.0 * cos(ctrl_student_HIL_B.Integrator1_k) *
    ctrl_student_HIL_B.pathNumber;
  rtb_Product_f = -3.0 * sin(ctrl_student_HIL_B.Integrator1_k) *
    ctrl_student_HIL_B.pathNumber;
  yd = 1.0 / tan(ctrl_student_HIL_B.Integrator1_k) * -480.0 * (x * x) / (c_a *
    c_a) * ctrl_student_HIL_B.pathNumber;

  /* MATLAB Function: '<S1>/MATLAB Function' */
  for (i = 0; i < 3; i++) {
    rtb_R_T_0[i] = rtb_R_T[i + 6] * yd + (rtb_R_T[i + 3] * rtb_Product_f +
      rtb_R_T[i] * rtb_Product);
  }

  for (i = 0; i < 3; i++) {
    alpha1[i] = rtb_R_T[i + 6] * ctrl_student_HIL_B.IC1[2] + (rtb_R_T[i + 3] *
      ctrl_student_HIL_B.IC1[1] + rtb_R_T[i] * ctrl_student_HIL_B.IC1[0]);
  }

  for (i = 0; i < 3; i++) {
    z1[i] = (((S_r_0[i + 3] * ctrl_student_HIL_B.IC1[1] + S_r_0[i] *
               ctrl_student_HIL_B.IC1[0]) + S_r_0[i + 6] *
              ctrl_student_HIL_B.IC1[2]) + rtb_R_T_0[i] * xds) + alpha1[i] *
      rtb_Product_a;
  }

  for (i = 0; i < 3; i++) {
    alpha1[i] = (((tmp_1[i + 3] * S_r_1[1] + tmp_1[i] * S_r_1[0]) + tmp_1[i + 6]
                  * S_r_1[2]) - z2[i] * xds) + z1[i] * ctrl_student_HIL_B.s_dot;
  }

  /* ManualSwitch: '<S1>/Manual Switch' */
  tmp_3 = (ctrl_student_HIL_P.ManualSwitch_CurrentSetting_f == 1);

  /* Sum: '<S1>/Sum1' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  for (i = 0; i < 3; i++) {
    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  MATLAB Function: '<S1>/MATLAB Function'
     */
    if (tmp_3) {
      rtb_Product = rtb_Sum3_l[i];
    } else {
      rtb_Product = ctrl_student_HIL_P.Constant_Value_h;
    }

    ctrl_student_HIL_B.Sum1[i] = (((rtb_M[i + 3] * alpha1[1] + rtb_M[i] *
      alpha1[0]) + rtb_M[i + 6] * alpha1[2]) + (tmp_2[i] + rtb_D_0[i])) +
      rtb_Product;
  }

  /* End of Sum: '<S1>/Sum1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* MATLAB Function: '<S3>/Rotation matrix' */
  /* MATLAB Function 'Guidance/Rotation matrix': '<S17>:1' */
  /* '<S17>:1:3' */
  /* '<S17>:1:5' */
  rtb_R_c[0] = cos(rtb_Integrator[2]);
  rtb_R_c[3] = -sin(rtb_Integrator[2]);
  rtb_R_c[6] = 0.0;
  rtb_R_c[1] = sin(rtb_Integrator[2]);
  rtb_R_c[4] = cos(rtb_Integrator[2]);
  rtb_R_c[7] = 0.0;
  rtb_R_c[2] = 0.0;
  rtb_R_c[5] = 0.0;
  rtb_R_c[8] = 1.0;

  /* Sum: '<S3>/Sum' incorporates:
   *  Product: '<S3>/Matrix Multiply1'
   */
  /* '<S17>:1:6' */
  rtb_Product = rtb_Integrator[0] - ctrl_student_HIL_B.IC[0];
  rtb_Product_f = rtb_Integrator[1] - ctrl_student_HIL_B.IC[1];
  yd = rtb_Integrator[2] - ctrl_student_HIL_B.IC[2];

  /* Product: '<S3>/Matrix Multiply1' incorporates:
   *  MATLAB Function: '<S3>/Rotation matrix'
   *  Product: '<S3>/Matrix Multiply2'
   */
  for (i = 0; i < 3; i++) {
    alpha1[i] = rtb_R_c[3 * i + 2] * yd + (rtb_R_c[3 * i + 1] * rtb_Product_f +
      rtb_R_c[3 * i] * rtb_Product);
  }

  /* Sum: '<S3>/Sum1' incorporates:
   *  Constant: '<S15>/Constant'
   *  Product: '<S3>/Matrix Multiply'
   *  Product: '<S3>/Matrix Multiply2'
   *  Product: '<S3>/Matrix Multiply3'
   */
  for (i = 0; i < 3; i++) {
    z2[i] = xds * ctrl_student_HIL_B.IC1[i] -
      ((ctrl_student_HIL_P.Constant_Value[i + 3] * alpha1[1] +
        ctrl_student_HIL_P.Constant_Value[i] * alpha1[0]) +
       ctrl_student_HIL_P.Constant_Value[i + 6] * alpha1[2]);
  }

  /* End of Sum: '<S3>/Sum1' */

  /* Product: '<S3>/Matrix Multiply' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.MatrixMultiply[i] = 0.0;
    ctrl_student_HIL_B.MatrixMultiply[i] += rtb_R_c[i] * z2[0];
    ctrl_student_HIL_B.MatrixMultiply[i] += rtb_R_c[i + 3] * z2[1];
    ctrl_student_HIL_B.MatrixMultiply[i] += rtb_R_c[i + 6] * z2[2];
  }

  /* Sum: '<S5>/Sum' */
  /* MATLAB Function 'Gain Matrices/MATLAB Function': '<S14>:1' */
  /*  L1_11 = 10; */
  /*  L2_11 = 30; */
  /*  L3_11 = 8; */
  /*  L1_22 = 10; */
  /*  L2_22 = 30; */
  /*  L3_22 = 8; */
  /*  L1_33 = 5; */
  /*  L2_33 = 10; */
  /*  L3_33 = 4; */
  /* '<S14>:1:13' */
  /* '<S14>:1:15' */
  /* '<S14>:1:17' */
  /* '<S14>:1:19' */
  rtb_Integrator[0] = ctrl_student_HIL_B.eta_m_c1[0] -
    ctrl_student_HIL_B.Integrator2[0];
  rtb_Integrator[1] = ctrl_student_HIL_B.eta_m_c1[1] -
    ctrl_student_HIL_B.Integrator2[1];
  rtb_Integrator[2] = ctrl_student_HIL_B.eta_m_c1[2] -
    ctrl_student_HIL_B.Integrator2[2];

  /* MATLAB Function: '<S2>/MATLAB Function' */
  tmp_4[0] = ctrl_student_HIL_B.L3_11 + 8.0;
  tmp_4[3] = 0.0;
  tmp_4[6] = 0.0;
  tmp_4[1] = 0.0;
  tmp_4[4] = ctrl_student_HIL_B.L3_22 + 8.0;
  tmp_4[7] = 0.0;
  tmp_4[2] = 0.0;
  tmp_4[5] = 0.0;
  tmp_4[8] = ctrl_student_HIL_B.L3_33 + 4.0;

  /* Product: '<S31>/Matrix Multiply1' incorporates:
   *  Product: '<S31>/Matrix Multiply9'
   */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = tmp_4[i + 6] * rtb_Integrator[2] + (tmp_4[i + 3] *
      rtb_Integrator[1] + tmp_4[i] * rtb_Integrator[0]);
  }

  /* End of Product: '<S31>/Matrix Multiply1' */

  /* Product: '<S31>/Matrix Multiply9' */
  ctrl_student_HIL_B.MatrixMultiply9[0] = tmp_2[0] * (real_T)rtb_bool;
  ctrl_student_HIL_B.MatrixMultiply9[1] = tmp_2[1] * (real_T)rtb_bool;
  ctrl_student_HIL_B.MatrixMultiply9[2] = tmp_2[2] * (real_T)rtb_bool;

  /* MATLAB Function: '<S2>/MATLAB Function' */
  tmp_5[0] = ctrl_student_HIL_B.L1_11 + 10.0;
  tmp_5[3] = 0.0;
  tmp_5[6] = 0.0;
  tmp_5[1] = 0.0;
  tmp_5[4] = ctrl_student_HIL_B.L1_22 + 10.0;
  tmp_5[7] = 0.0;
  tmp_5[2] = 0.0;
  tmp_5[5] = 0.0;
  tmp_5[8] = ctrl_student_HIL_B.L1_33 + 5.0;

  /* Product: '<S5>/Matrix Multiply' */
  for (i = 0; i < 3; i++) {
    z1[i] = tmp_5[i + 6] * rtb_Integrator[2] + (tmp_5[i + 3] * rtb_Integrator[1]
      + tmp_5[i] * rtb_Integrator[0]);
  }

  /* End of Product: '<S5>/Matrix Multiply' */

  /* MATLAB Function: '<S2>/MATLAB Function' */
  tmp_6[0] = ctrl_student_HIL_B.L2_11 + 30.0;
  tmp_6[3] = 0.0;
  tmp_6[6] = 0.0;
  tmp_6[1] = 0.0;
  tmp_6[4] = ctrl_student_HIL_B.L2_22 + 30.0;
  tmp_6[7] = 0.0;
  tmp_6[2] = 0.0;
  tmp_6[5] = 0.0;
  tmp_6[8] = ctrl_student_HIL_B.L2_33 + 10.0;

  /* Product: '<S5>/Matrix Multiply7' incorporates:
   *  Product: '<S5>/Matrix Multiply9'
   */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = tmp_6[i + 6] * rtb_Integrator[2] + (tmp_6[i + 3] *
      rtb_Integrator[1] + tmp_6[i] * rtb_Integrator[0]);
  }

  /* End of Product: '<S5>/Matrix Multiply7' */

  /* Product: '<S5>/Matrix Multiply9' incorporates:
   *  Product: '<S5>/Matrix Multiply2'
   */
  rtb_Product = tmp_2[0] * (real_T)rtb_bool;
  rtb_Product_f = tmp_2[1] * (real_T)rtb_bool;
  yd = tmp_2[2] * (real_T)rtb_bool;

  /* Product: '<S5>/Matrix Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_Integrator[i] = rtb_R_T[i + 6] * yd + (rtb_R_T[i + 3] * rtb_Product_f +
      rtb_R_T[i] * rtb_Product);
  }

  /* Sum: '<S5>/Sum2' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function'
   *  Product: '<S5>/Matrix Multiply3'
   */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = (((real_T)tmp[i + 3] * rtb_Integrator[1] + (real_T)tmp[i] *
                 rtb_Integrator[0]) + (real_T)tmp[i + 6] * rtb_Integrator[2]) +
      ctrl_student_HIL_B.Sum1[i];
  }

  /* Product: '<S5>/Matrix Multiply1' incorporates:
   *  Sum: '<S5>/Sum2'
   */
  for (i = 0; i < 3; i++) {
    alpha1[i] = rtb_C[i + 6] * ctrl_student_HIL_B.Integrator1[2] + (rtb_C[i + 3]
      * ctrl_student_HIL_B.Integrator1[1] + rtb_C[i] *
      ctrl_student_HIL_B.Integrator1[0]);
  }

  /* End of Product: '<S5>/Matrix Multiply1' */

  /* Sum: '<S5>/Sum3' incorporates:
   *  Product: '<S5>/Matrix Multiply5'
   *  Sum: '<S5>/Sum2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum3_l[i] = ((tmp_2[i] - alpha1[i]) + rtb_Sum3_l[i]) - ((rtb_D[i + 3] *
      ctrl_student_HIL_B.Integrator1[1] + rtb_D[i] *
      ctrl_student_HIL_B.Integrator1[0]) + rtb_D[i + 6] *
      ctrl_student_HIL_B.Integrator1[2]);
  }

  /* End of Sum: '<S5>/Sum3' */

  /* MATLAB Function: '<S33>/MATLAB Function1' */
  ctrl_student_HIL_inv(rtb_M, tmp_1);

  /* Product: '<S5>/Matrix Multiply4' */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.MatrixMultiply4[i] = 0.0;
    ctrl_student_HIL_B.MatrixMultiply4[i] += tmp_1[i] * rtb_Sum3_l[0];
    ctrl_student_HIL_B.MatrixMultiply4[i] += tmp_1[i + 3] * rtb_Sum3_l[1];
    ctrl_student_HIL_B.MatrixMultiply4[i] += tmp_1[i + 6] * rtb_Sum3_l[2];
  }

  /* End of Product: '<S5>/Matrix Multiply4' */

  /* Sum: '<S5>/Sum1' incorporates:
   *  Product: '<S5>/Matrix Multiply6'
   *  Product: '<S5>/Matrix Multiply8'
   */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Sum1_g[i] = ((rtb_R[i + 3] *
      ctrl_student_HIL_B.Integrator1[1] + rtb_R[i] *
      ctrl_student_HIL_B.Integrator1[0]) + rtb_R[i + 6] *
      ctrl_student_HIL_B.Integrator1[2]) + z1[i] * (real_T)rtb_bool;
  }

  /* End of Sum: '<S5>/Sum1' */
  /* MATLAB Function 'op_space': '<S9>:1' */
  /* parameters */
  /* '<S9>:1:4' */
  /* '<S9>:1:5' */
  /* '<S9>:1:6' */
  /* '<S9>:1:7' */
  /* if */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S23>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_B.count;

    /* Update for RandomNumber: '<S29>/White Noise' */
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S30>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_j) * ctrl_student_HIL_P.WhiteNoise_StdDev_d
      + ctrl_student_HIL_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S28>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_c) * ctrl_student_HIL_P.WhiteNoise_StdDev_g
      + ctrl_student_HIL_P.WhiteNoise_Mean_f;

    /* Update for Memory: '<S24>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_B.output[2];

    /* Update for Memory: '<S36>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput[0] = ctrl_student_HIL_B.eta_m_c1[0];
    ctrl_student_HIL_DW.Memory_PreviousInput[1] = ctrl_student_HIL_B.eta_m_c1[1];
    ctrl_student_HIL_DW.Memory_PreviousInput[2] = ctrl_student_HIL_B.eta_m_c1[2];

    /* Update for Memory: '<S6>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_l[0] =
      ctrl_student_HIL_B.eta_m_out[0];
    ctrl_student_HIL_DW.Memory_PreviousInput_l[1] =
      ctrl_student_HIL_B.eta_m_out[1];
    ctrl_student_HIL_DW.Memory_PreviousInput_l[2] =
      ctrl_student_HIL_B.eta_m_out[2];
  }

  /* Update for Integrator: '<S5>/Integrator2' */
  ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S19>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_la = ctrl_student_HIL_B.s_dot;
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

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator2_CSTATE[0] = ctrl_student_HIL_B.Sum1_g[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator2_CSTATE[1] = ctrl_student_HIL_B.Sum1_g[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator2_CSTATE[2] = ctrl_student_HIL_B.Sum1_g[2];
  }

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_student_HIL_B.MatrixMultiply[0];
  _rtXdot->Integrator_CSTATE[1] = ctrl_student_HIL_B.MatrixMultiply[1];
  _rtXdot->Integrator_CSTATE[2] = ctrl_student_HIL_B.MatrixMultiply[2];

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  {
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE[0] = ctrl_student_HIL_B.MatrixMultiply4[0];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE[1] = ctrl_student_HIL_B.MatrixMultiply4[1];
    ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs)
      ->Integrator1_CSTATE[2] = ctrl_student_HIL_B.MatrixMultiply4[2];
  }

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_e = ctrl_student_HIL_B.s_dot;

  /* Derivatives for Integrator: '<S31>/Integrator' */
  _rtXdot->Integrator_CSTATE_b[0] = ctrl_student_HIL_B.MatrixMultiply9[0];
  _rtXdot->Integrator_CSTATE_b[1] = ctrl_student_HIL_B.MatrixMultiply9[1];
  _rtXdot->Integrator_CSTATE_b[2] = ctrl_student_HIL_B.MatrixMultiply9[2];
}

/* Model initialize function */
void ctrl_student_HIL_initialize(void)
{
  /* Start for InitialCondition: '<S16>/IC' */
  ctrl_student_HIL_B.IC[0] = ctrl_student_HIL_P.IC_Value[0];
  ctrl_student_HIL_B.IC[1] = ctrl_student_HIL_P.IC_Value[1];
  ctrl_student_HIL_B.IC[2] = ctrl_student_HIL_P.IC_Value[2];
  ctrl_student_HIL_DW.IC_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S16>/IC1' */
  ctrl_student_HIL_B.IC1[0] = ctrl_student_HIL_P.IC1_Value[0];
  ctrl_student_HIL_B.IC1[1] = ctrl_student_HIL_P.IC1_Value[1];
  ctrl_student_HIL_B.IC1[2] = ctrl_student_HIL_P.IC1_Value[2];
  ctrl_student_HIL_DW.IC1_FirstOutputTime = (rtMinusInf);
  ctrl_student_HIL_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_student_HIL_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Memory: '<S23>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S29>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed);
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

    ctrl_student_HIL_DW.RandSeed = tseed;
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S29>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S30>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_b);
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

    ctrl_student_HIL_DW.RandSeed_j = tseed;
    ctrl_student_HIL_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_j) * ctrl_student_HIL_P.WhiteNoise_StdDev_d
      + ctrl_student_HIL_P.WhiteNoise_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S30>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S28>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_l);
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

    ctrl_student_HIL_DW.RandSeed_c = tseed;
    ctrl_student_HIL_DW.NextOutput_p = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_c) * ctrl_student_HIL_P.WhiteNoise_StdDev_g
      + ctrl_student_HIL_P.WhiteNoise_Mean_f;

    /* End of InitializeConditions for RandomNumber: '<S28>/White Noise' */

    /* InitializeConditions for Memory: '<S24>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_P.Hold_X0;

    /* InitializeConditions for Memory: '<S36>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput[0] = ctrl_student_HIL_P.Memory_X0[0];
    ctrl_student_HIL_DW.Memory_PreviousInput[1] = ctrl_student_HIL_P.Memory_X0[1];
    ctrl_student_HIL_DW.Memory_PreviousInput[2] = ctrl_student_HIL_P.Memory_X0[2];

    /* InitializeConditions for Memory: '<S6>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_l[0] =
      ctrl_student_HIL_P.Memory_X0_l[0];
    ctrl_student_HIL_DW.Memory_PreviousInput_l[1] =
      ctrl_student_HIL_P.Memory_X0_l[1];
    ctrl_student_HIL_DW.Memory_PreviousInput_l[2] =
      ctrl_student_HIL_P.Memory_X0_l[2];

    /* InitializeConditions for Integrator: '<S5>/Integrator2' */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      ctrl_student_HIL_X.Integrator2_CSTATE[0] = 0.0;
      ctrl_student_HIL_X.Integrator2_CSTATE[1] = 0.0;
      ctrl_student_HIL_X.Integrator2_CSTATE[2] = 0.0;
    }

    ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S3>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE[0] = ctrl_student_HIL_P.Integrator_IC[0];
    ctrl_student_HIL_X.Integrator_CSTATE[1] = ctrl_student_HIL_P.Integrator_IC[1];
    ctrl_student_HIL_X.Integrator_CSTATE[2] = ctrl_student_HIL_P.Integrator_IC[2];

    /* InitializeConditions for Integrator: '<S5>/Integrator1' */
    ctrl_student_HIL_X.Integrator1_CSTATE[0] =
      (ctrl_student_HIL_P.Integrator1_IC[0]);
    ctrl_student_HIL_X.Integrator1_CSTATE[1] =
      (ctrl_student_HIL_P.Integrator1_IC[1]);
    ctrl_student_HIL_X.Integrator1_CSTATE[2] =
      (ctrl_student_HIL_P.Integrator1_IC[2]);

    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    ctrl_student_HIL_X.Integrator1_CSTATE_e =
      ctrl_student_HIL_P.Integrator1_IC_m;

    /* InitializeConditions for Memory: '<S19>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_la = ctrl_student_HIL_P.Memory_X0_e;

    /* InitializeConditions for Integrator: '<S31>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_b[0] =
      ctrl_student_HIL_P.Integrator_IC_l;
    ctrl_student_HIL_X.Integrator_CSTATE_b[1] =
      ctrl_student_HIL_P.Integrator_IC_l;
    ctrl_student_HIL_X.Integrator_CSTATE_b[2] =
      ctrl_student_HIL_P.Integrator_IC_l;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_student_HIL_M)) {
      rtmSetFirstInitCond(ctrl_student_HIL_M, 0);
    }
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
  ctrl_student_HIL_M->ModelData.intgData.f[3] =
    ctrl_student_HIL_M->ModelData.odeF[3];
  ctrl_student_HIL_M->ModelData.contStates = ((real_T *) &ctrl_student_HIL_X);
  rtsiSetSolverData(&ctrl_student_HIL_M->solverInfo, (void *)
                    &ctrl_student_HIL_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_HIL_M->solverInfo,"ode4");

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
  ctrl_student_HIL_M->Sizes.numBlocks = (160);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (59);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (412);/* Sum of parameter "widths" */
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 35:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 37:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

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

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 35:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 36:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 37:
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

  // y_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.psi_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.r_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // v_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.v_in, 0, data[index++], 0, 0);
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

  // niose_power
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.niose_power, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Signal Drop-out/Drop-out
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Dropout, 0, data[index++], 0, 0);
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

  // Guidance/Control inputs/ pathNumber
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.pathNumber, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Guidance/s_dot generation/my
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.my, 0, data[index++], 0, 0);
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
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 35;
}

double ni_extout[25];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

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

  //  eta_tilde_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,2,18,0);
  } else {
    index += 1;
  }

  // eta_hat_x: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator2,
      0,18,0);
  } else {
    index += 1;
  }

  // eta_hat_y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator2,
      1,18,0);
  } else {
    index += 1;
  }

  // eta_d to veristand/eta_d_X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.ManualSwitch,0,18,0);
  } else {
    index += 1;
  }

  // eta_d to veristand/eta_d_Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.ManualSwitch,1,18,0);
  } else {
    index += 1;
  }

  // eta_d to veristand/eta_d_PSI: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_B.ManualSwitch,2,18,0);
  } else {
    index += 1;
  }

  // eta_hat_psi: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator2,
      2,18,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,18,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,2,18,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,1,18,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant2_Value_e,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant_Value_i,0,0,0);
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

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.SystemReset,
      0,0,0);
  } else {
    index += 1;
  }

  // Controller/VeriStand Output/Controller output X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,18,0);
  } else {
    index += 1;
  }

  // Controller/VeriStand Output/Controller output Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,1,18,0);
  } else {
    index += 1;
  }

  // Controller/VeriStand Output/Controller output PSI: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,2,18,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_out/ nu_x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,
      0,18,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_out/ nu_y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,
      1,18,0);
  } else {
    index += 1;
  }

  // Observer/nu_hat_out/nu_psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,
      2,18,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 25;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // Signal Drop-out/eta_mpsi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_m_c1,2,18,
    0);

  // Signal Drop-out/eta_mx: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_m_c1,0,18,
    0);

  // Signal Drop-out/eta_my: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.eta_m_c1,1,18,
    0);

  //  eta_tilde_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,0,18,0);

  //  eta_tilde_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,1,18,0);

  //  eta_tilde_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum,2,18,0);

  // eta_hat_x: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator2,0,
    18,0);

  // eta_hat_y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator2,1,
    18,0);

  // eta_d to veristand/eta_d_X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ManualSwitch,
    0,18,0);

  // eta_d to veristand/eta_d_Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ManualSwitch,
    1,18,0);

  // eta_d to veristand/eta_d_PSI: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.ManualSwitch,
    2,18,0);

  // eta_hat_psi: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator2,2,
    18,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,18,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,2,18,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,1,18,0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value_e,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value_i,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.SystemReset,0,
    0,0);

  // Controller/VeriStand Output/Controller output X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,0,18,0);

  // Controller/VeriStand Output/Controller output Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,1,18,0);

  // Controller/VeriStand Output/Controller output PSI: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Sum1,2,18,0);

  // Observer/nu_hat_out/ nu_x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,0,
    18,0);

  // Observer/nu_hat_out/ nu_y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,1,
    18,0);

  // Observer/nu_hat_out/nu_psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Integrator1,2,
    18,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil/Noise generator/Step size/Value", offsetof
    (P_ctrl_student_HIL_T, Stepsize_Value), 34, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil/Noise generator/Downsamplesignal/counter/X0", offsetof
    (P_ctrl_student_HIL_T, counter_X0), 34, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil/Constant4/Value", offsetof(P_ctrl_student_HIL_T,
    Constant4_Value), 34, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/Gain/Gain", offsetof(P_ctrl_student_HIL_T, Gain_Gain),
    34, 1, 2, 6, 0 },

  { 4,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean), 34, 1, 2, 8, 0 },

  { 5,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev), 34, 1, 2, 10, 0 },

  { 6,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed), 34, 1, 2, 12, 0 },

  { 7,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_h), 34, 1, 2, 14, 0 },

  { 8,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_d), 34, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_b), 34, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_f), 34, 1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_g), 34, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_l), 34, 1, 2, 24, 0 },

  { 13, "ctrl_student_hil/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_student_HIL_T, Hold_X0), 34, 1, 2, 26, 0 },

  { 14, "ctrl_student_hil/Constant2/Value", offsetof(P_ctrl_student_HIL_T,
    Constant2_Value), 34, 1, 2, 28, 0 },

  { 15, "ctrl_student_hil/Signal Drop-out/Detection/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0), 23, 3, 2, 30, 0 },

  { 16, "ctrl_student_hil/Signal Drop-out/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0_l), 23, 3, 2, 32, 0 },

  { 17, "ctrl_student_hil/Guidance/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC), 24, 3, 2, 34, 0 },

  { 18, "ctrl_student_hil/Observer/Integrator1/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator1_IC), 24, 3, 2, 36, 0 },

  { 19, "ctrl_student_hil/Guidance/Integrator1/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator1_IC_m), 34, 1, 2, 38, 0 },

  { 20, "ctrl_student_hil/Guidance/Path generation/IC/Value", offsetof
    (P_ctrl_student_HIL_T, IC_Value), 24, 3, 2, 40, 0 },

  { 21, "ctrl_student_hil/Guidance/Path generation/IC1/Value", offsetof
    (P_ctrl_student_HIL_T, IC1_Value), 24, 3, 2, 42, 0 },

  { 22, "ctrl_student_hil/Guidance/s_dot generation/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0_e), 34, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/Guidance/Control inputs/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value), 19, 9, 2, 46, 0 },

  { 24, "ctrl_student_hil/Observer/Bias estimator/Integrator/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, Integrator_IC_l), 34, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/Controller/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_h), 34, 1, 2, 50, 0 },

  { 26,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value_e), 34, 1, 2, 52, 0 },

  { 27,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value_i), 34, 1, 2, 54, 0 },

  { 28,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value), 34, 1, 2, 56, 0 },

  { 29, "ctrl_student_hil/Manual Switch/CurrentSetting", offsetof
    (P_ctrl_student_HIL_T, ManualSwitch_CurrentSetting), 35, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil/Controller/Manual Switch/CurrentSetting", offsetof
    (P_ctrl_student_HIL_T, ManualSwitch_CurrentSetting_f), 35, 1, 2, 60, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 31;
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
  1, 3,                                /* Parameter at index 15 */
  1, 3,                                /* Parameter at index 16 */
  3, 1,                                /* Parameter at index 17 */
  3, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  3, 1,                                /* Parameter at index 20 */
  3, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  3, 3,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil/y_in", 0, "", offsetof(B_ctrl_student_HIL_T, y_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil/psi_in", 0, "", offsetof(B_ctrl_student_HIL_T, psi_in)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil/x_in", 0, "", offsetof(B_ctrl_student_HIL_T, x_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/r_in", 0, "", offsetof(B_ctrl_student_HIL_T, r_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/u_in", 0, "", offsetof(B_ctrl_student_HIL_T, u_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/v_in", 0, "", offsetof(B_ctrl_student_HIL_T, v_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/System Reset", 0, "", offsetof(B_ctrl_student_HIL_T,
    SystemReset)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 12, 0 },

  { 7, "ctrl_student_hil/niose_power", 0, "", offsetof(B_ctrl_student_HIL_T,
    niose_power)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_e)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_m)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 20, 0 },

  { 11, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    22, 0 },

  { 12, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    24, 0 },

  { 13, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    26, 0 },

  { 14, "ctrl_student_hil/Signal Drop-out/Detection/Memory", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Memory)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 28, 0 },

  { 15, "ctrl_student_hil/Signal Drop-out/Detection/Memory", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Memory)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 30, 0 },

  { 16, "ctrl_student_hil/Signal Drop-out/Detection/Memory", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Memory)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 32, 0 },

  { 17, "ctrl_student_hil/Signal Drop-out/Drop-out", 0, "", offsetof
    (B_ctrl_student_HIL_T, Dropout)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 34,
    0 },

  { 18, "ctrl_student_hil/Signal Drop-out/Memory", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory_c)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 36,
    0 },

  { 19, "ctrl_student_hil/Signal Drop-out/Memory", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory_c)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 38,
    0 },

  { 20, "ctrl_student_hil/Signal Drop-out/Memory", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory_c)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 40,
    0 },

  { 21, "ctrl_student_hil/Observer/Integrator2", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Integrator2)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    42, 0 },

  { 22, "ctrl_student_hil/Observer/Integrator2", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Integrator2)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    44, 0 },

  { 23, "ctrl_student_hil/Observer/Integrator2", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Integrator2)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    46, 0 },

  { 24, "ctrl_student_hil/Sum", 0, "(1,1)", offsetof(B_ctrl_student_HIL_T, Sum)+
    0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/Sum", 0, "(1,2)", offsetof(B_ctrl_student_HIL_T, Sum)+
    1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil/Sum", 0, "(1,3)", offsetof(B_ctrl_student_HIL_T, Sum)+
    2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    54, 0 },

  { 28, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 56,
    0 },

  { 29, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 58,
    0 },

  { 30, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    60, 0 },

  { 31, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 62,
    0 },

  { 32, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 64,
    0 },

  { 33, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T, L1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 66, 0 },

  { 34, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 70,
    0 },

  { 36, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 72,
    0 },

  { 37, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 74,
    0 },

  { 38, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    76, 0 },

  { 39, "ctrl_student_hil/Manual Switch", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, ManualSwitch)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    78, 0 },

  { 40, "ctrl_student_hil/Manual Switch", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, ManualSwitch)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    80, 0 },

  { 41, "ctrl_student_hil/Manual Switch", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, ManualSwitch)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    82, 0 },

  { 42, "ctrl_student_hil/Observer/Integrator1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Integrator1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    84, 0 },

  { 43, "ctrl_student_hil/Observer/Integrator1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Integrator1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    86, 0 },

  { 44, "ctrl_student_hil/Observer/Integrator1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Integrator1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    88, 0 },

  { 45, "ctrl_student_hil/Guidance/Integrator1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Integrator1_k)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    90, 0 },

  { 46, "ctrl_student_hil/Guidance/Control inputs/ pathNumber", 0, "", offsetof
    (B_ctrl_student_HIL_T, pathNumber)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    92, 0 },

  { 47, "ctrl_student_hil/Guidance/Path generation/IC", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, IC)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 94, 0 },

  { 48, "ctrl_student_hil/Guidance/Path generation/IC", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, IC)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 96, 0 },

  { 49, "ctrl_student_hil/Guidance/Path generation/IC", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, IC)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 98, 0 },

  { 50, "ctrl_student_hil/Guidance/Path generation/IC1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, IC1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 100, 0
  },

  { 51, "ctrl_student_hil/Guidance/Path generation/IC1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, IC1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 102, 0
  },

  { 52, "ctrl_student_hil/Guidance/Path generation/IC1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, IC1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 104, 0
  },

  { 53, "ctrl_student_hil/Guidance/s_dot generation/my", 0, "", offsetof
    (B_ctrl_student_HIL_T, my)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 106, 0 },

  { 54, "ctrl_student_hil/Guidance/s_dot generation/Memory", 0, "", offsetof
    (B_ctrl_student_HIL_T, Memory_a)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 108,
    0 },

  { 55, "ctrl_student_hil/Gain Matrices/L1_11", 0, "", offsetof
    (B_ctrl_student_HIL_T, L1_11)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 110, 0
  },

  { 56, "ctrl_student_hil/Gain Matrices/L1_22", 0, "", offsetof
    (B_ctrl_student_HIL_T, L1_22)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 112, 0
  },

  { 57, "ctrl_student_hil/Gain Matrices/L1_33", 0, "", offsetof
    (B_ctrl_student_HIL_T, L1_33)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 114, 0
  },

  { 58, "ctrl_student_hil/Gain Matrices/L2_11", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_11)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 116, 0
  },

  { 59, "ctrl_student_hil/Gain Matrices/L2_22", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_22)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 118, 0
  },

  { 60, "ctrl_student_hil/Gain Matrices/L2_33", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_33)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 120, 0
  },

  { 61, "ctrl_student_hil/Gain Matrices/L3_11", 0, "", offsetof
    (B_ctrl_student_HIL_T, L3_11)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 122, 0
  },

  { 62, "ctrl_student_hil/Gain Matrices/L3_22", 0, "", offsetof
    (B_ctrl_student_HIL_T, L3_22)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 124, 0
  },

  { 63, "ctrl_student_hil/Gain Matrices/L3_33", 0, "", offsetof
    (B_ctrl_student_HIL_T, L3_33)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 126, 0
  },

  { 64, "ctrl_student_hil/Gain Matrices/K_p2_1", 0, "", offsetof
    (B_ctrl_student_HIL_T, K_p2_1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 128,
    0 },

  { 65, "ctrl_student_hil/Gain Matrices/K_p2_2", 0, "", offsetof
    (B_ctrl_student_HIL_T, K_p2_2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 130,
    0 },

  { 66, "ctrl_student_hil/Gain Matrices/K_p2_3", 0, "", offsetof
    (B_ctrl_student_HIL_T, K_p2_3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 132,
    0 },

  { 67, "ctrl_student_hil/Controller/Sum1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Sum1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 134, 0
  },

  { 68, "ctrl_student_hil/Controller/Sum1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Sum1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 136, 0
  },

  { 69, "ctrl_student_hil/Controller/Sum1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Sum1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 138, 0
  },

  { 70, "ctrl_student_hil/Guidance/Matrix Multiply", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 140, 0 },

  { 71, "ctrl_student_hil/Guidance/Matrix Multiply", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 142, 0 },

  { 72, "ctrl_student_hil/Guidance/Matrix Multiply", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 144, 0 },

  { 73, "ctrl_student_hil/Observer/Bias estimator/Matrix Multiply9", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, MatrixMultiply9)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 146, 0 },

  { 74, "ctrl_student_hil/Observer/Bias estimator/Matrix Multiply9", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, MatrixMultiply9)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 148, 0 },

  { 75, "ctrl_student_hil/Observer/Bias estimator/Matrix Multiply9", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, MatrixMultiply9)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 150, 0 },

  { 76, "ctrl_student_hil/Observer/Matrix Multiply4", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply4)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 152, 0 },

  { 77, "ctrl_student_hil/Observer/Matrix Multiply4", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply4)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 154, 0 },

  { 78, "ctrl_student_hil/Observer/Matrix Multiply4", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, MatrixMultiply4)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1,
    2, 156, 0 },

  { 79, "ctrl_student_hil/Observer/Sum1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Sum1_g)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 158,
    0 },

  { 80, "ctrl_student_hil/Observer/Sum1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Sum1_g)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 160,
    0 },

  { 81, "ctrl_student_hil/Observer/Sum1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Sum1_g)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 162,
    0 },

  { 82, "ctrl_student_hil/Signal Drop-out/Signal drop-out simulation", 0,
    "eta_m_out(1,1)", offsetof(B_ctrl_student_HIL_T, eta_m_out)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 164, 0 },

  { 83, "ctrl_student_hil/Signal Drop-out/Signal drop-out simulation", 0,
    "eta_m_out(1,2)", offsetof(B_ctrl_student_HIL_T, eta_m_out)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 166, 0 },

  { 84, "ctrl_student_hil/Signal Drop-out/Signal drop-out simulation", 0,
    "eta_m_out(1,3)", offsetof(B_ctrl_student_HIL_T, eta_m_out)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 168, 0 },

  { 85, "ctrl_student_hil/Signal Drop-out/Detection/MATLAB Function", 1,
    "eta_m_c1(1,1)", offsetof(B_ctrl_student_HIL_T, eta_m_c1)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 170, 0 },

  { 86, "ctrl_student_hil/Signal Drop-out/Detection/MATLAB Function", 1,
    "eta_m_c1(1,2)", offsetof(B_ctrl_student_HIL_T, eta_m_c1)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 172, 0 },

  { 87, "ctrl_student_hil/Signal Drop-out/Detection/MATLAB Function", 1,
    "eta_m_c1(1,3)", offsetof(B_ctrl_student_HIL_T, eta_m_c1)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 174, 0 },

  { 88, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,1)", offsetof(B_ctrl_student_HIL_T, output)+0*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 176, 0 },

  { 89, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,2)", offsetof(B_ctrl_student_HIL_T, output)+1*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 178, 0 },

  { 90, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,3)", offsetof(B_ctrl_student_HIL_T, output)+2*sizeof(real_T),
    BLOCKIO_SIG, 18, 1, 2, 180, 0 },

  { 91, "ctrl_student_hil/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_student_HIL_T, count)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 182, 0 },

  { 92, "ctrl_student_hil/Guidance/s_dot generation/s calculation", 0, "s_dot",
    offsetof(B_ctrl_student_HIL_T, s_dot)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    184, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 93;
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
  1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 60;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 1, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 2, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 3, "r_in", 1, EXT_IN, 1, 1, 1 },

  { 4, "u_in", 1, EXT_IN, 1, 1, 1 },

  { 5, "v_in", 1, EXT_IN, 1, 1, 1 },

  { 6, "System Reset", 0, EXT_IN, 1, 1, 1 },

  { 7, "niose_power", 0, EXT_IN, 1, 1, 1 },

  { 8, "Signal Drop-out/Drop-out", 0, EXT_IN, 1, 1, 1 },

  { 9, "joystick/L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 10, "joystick/PosXRight", 0, EXT_IN, 1, 1, 1 },

  { 11, "joystick/PosYRight", 0, EXT_IN, 1, 1, 1 },

  { 12, "joystick/R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 13, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 14, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 15, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 16, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 17, "joystick/ArrowDown", 1, EXT_IN, 1, 1, 1 },

  { 18, "joystick/ArrowUp", 1, EXT_IN, 1, 1, 1 },

  { 19, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 20, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 21, "Guidance/Control inputs/ pathNumber", 0, EXT_IN, 1, 1, 1 },

  { 22, "Guidance/s_dot generation/my", 0, EXT_IN, 1, 1, 1 },

  { 23, "Gain Matrices/L1_11", 0, EXT_IN, 1, 1, 1 },

  { 24, "Gain Matrices/L1_22", 0, EXT_IN, 1, 1, 1 },

  { 25, "Gain Matrices/L1_33", 0, EXT_IN, 1, 1, 1 },

  { 26, "Gain Matrices/L2_11", 0, EXT_IN, 1, 1, 1 },

  { 27, "Gain Matrices/L2_22", 0, EXT_IN, 1, 1, 1 },

  { 28, "Gain Matrices/L2_33", 0, EXT_IN, 1, 1, 1 },

  { 29, "Gain Matrices/L3_11", 0, EXT_IN, 1, 1, 1 },

  { 30, "Gain Matrices/L3_22", 0, EXT_IN, 1, 1, 1 },

  { 31, "Gain Matrices/L3_33", 0, EXT_IN, 1, 1, 1 },

  { 32, "Gain Matrices/K_p2_1", 0, EXT_IN, 1, 1, 1 },

  { 33, "Gain Matrices/K_p2_2", 0, EXT_IN, 1, 1, 1 },

  { 34, "Gain Matrices/K_p2_3", 0, EXT_IN, 1, 1, 1 },

  { 0, "Signal Drop-out/eta_mpsi", 0, EXT_OUT, 1, 1, 1 },

  { 1, "Signal Drop-out/eta_mx", 0, EXT_OUT, 1, 1, 1 },

  { 2, "Signal Drop-out/eta_my", 0, EXT_OUT, 1, 1, 1 },

  { 3, " eta_tilde_x", 0, EXT_OUT, 1, 1, 1 },

  { 4, " eta_tilde_y", 0, EXT_OUT, 1, 1, 1 },

  { 5, " eta_tilde_psi", 0, EXT_OUT, 1, 1, 1 },

  { 6, "eta_hat_x", 0, EXT_OUT, 1, 1, 1 },

  { 7, "eta_hat_y", 0, EXT_OUT, 1, 1, 1 },

  { 8, "eta_d to veristand/eta_d_X", 0, EXT_OUT, 1, 1, 1 },

  { 9, "eta_d to veristand/eta_d_Y", 0, EXT_OUT, 1, 1, 1 },

  { 10, "eta_d to veristand/eta_d_PSI", 0, EXT_OUT, 1, 1, 1 },

  { 11, "eta_hat_psi", 0, EXT_OUT, 1, 1, 1 },

  { 12, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1
  },

  { 13, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 14, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 15, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 16, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 17, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 18, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 0,
    EXT_OUT, 1, 1, 1 },

  { 19, "Controller/VeriStand Output/Controller output X", 0, EXT_OUT, 1, 1, 1 },

  { 20, "Controller/VeriStand Output/Controller output Y", 0, EXT_OUT, 1, 1, 1 },

  { 21, "Controller/VeriStand Output/Controller output PSI", 0, EXT_OUT, 1, 1, 1
  },

  { 22, "Observer/nu_hat_out/ nu_x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 23, "Observer/nu_hat_out/ nu_y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 24, "Observer/nu_hat_out/nu_psi_hat", 0, EXT_OUT, 1, 1, 1 },

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
static char* NI_CompiledModelVersion = "1.277";
static char* NI_CompiledModelDateTime = "Thu Mar 30 17:34:51 2017";
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
      *numDiscStates = 1179;
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
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator1_CSTATE_e, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_b");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_b");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_b");
  }

  if (discStates && discStatesNames) {
    idx = 0;
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
      (&ctrl_student_HIL_DW.SystemReset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.SystemReset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.niose_power_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.niose_power_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_c,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
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
      (&ctrl_student_HIL_DW.Dropout_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Dropout_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_l, 0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_l, 1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_l, 2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_mpsi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_mpsi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_mx_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_mx_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.eta_my_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.eta_my_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_tilde_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_tilde_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_tilde_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_tilde_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_tilde_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_tilde_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_y_DWORK1");
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
      (&ctrl_student_HIL_DW.eta_d_X_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_d_X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_d_Y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_d_Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_d_PSI_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_d_PSI_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_psi_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.pathNumber_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.pathNumber_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.IC1_FirstOutputTime, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.IC1_FirstOutputTime");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.my_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.my_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_la, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_la");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.K_p2_1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.K_p2_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.K_p2_2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.K_p2_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.K_p2_3_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.K_p2_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ControlleroutputX_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ControlleroutputX_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ControlleroutputY_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ControlleroutputY_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ControlleroutputPSI_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ControlleroutputPSI_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.s_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.s_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_j, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_c, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading");
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

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.SystemReset_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.SystemReset_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.niose_power_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.niose_power_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Dropout_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Dropout_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_mpsi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_mpsi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_mx_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_mx_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_my_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_my_DWORK2");
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
        (&ctrl_student_HIL_DW.eta_tilde_psi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_tilde_psi_DWORK2");
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
        (&ctrl_student_HIL_DW.eta_d_PSI_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_d_PSI_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_hat_psi_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_hat_psi_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.pathNumber_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.pathNumber_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.my_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.my_DWORK2");
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
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK2");
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
        (&ctrl_student_HIL_DW.integratorresetmodel_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ControlleroutputX_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ControlleroutputX_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ControlleroutputY_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ControlleroutputY_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ControlleroutputPSI_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ControlleroutputPSI_DWORK2");
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
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 60; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3");
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE[0], 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator1_CSTATE_e, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_b[0], 2,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SystemReset_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.niose_power_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_c, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_l, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_l, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_l, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mpsi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mx_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_my_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_x_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_y_DWORK1, 0,
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_X_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_Y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_PSI_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_psi_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.pathNumber_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.IC1_FirstOutputTime, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.my_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_la, 0,
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p2_1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p2_2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.K_p2_3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControlleroutputX_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControlleroutputY_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControlleroutputPSI_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_x_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_y_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_psi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2,
      0, discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_j, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_c, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_DW.Integrator2_IWORK.IcNeedsLoading, 0, discStates[idx
       ++], 10, 0);
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

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.SystemReset_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.niose_power_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Dropout_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mpsi_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_mx_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_my_DWORK2, count,
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_tilde_psi_DWORK2, count,
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_X_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_Y_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_d_PSI_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_psi_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.pathNumber_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.my_DWORK2, count,
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2, count,
        discStates[idx++], 17, 0);
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControlleroutputX_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControlleroutputY_DWORK2,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ControlleroutputPSI_DWORK2,
        count, discStates[idx++], 17, 0);
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
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 17, 0);
    }

    for (count = 0; count < 60; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 21, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL
