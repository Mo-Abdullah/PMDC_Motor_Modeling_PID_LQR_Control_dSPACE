/*
 * DI_FB_Controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DI_FB_Controller".
 *
 * Model version              : 1.19
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri May  1 21:52:08 2026
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DI_FB_Controller_trc_ptr.h"
#include "DI_FB_Controller.h"
#include "DI_FB_Controller_private.h"

/* Block signals (default storage) */
B_DI_FB_Controller_T DI_FB_Controller_B;

/* Block states (default storage) */
DW_DI_FB_Controller_T DI_FB_Controller_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_DI_FB_Controller_T DI_FB_Controller_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_DI_FB_Controller_T DI_FB_Controller_Y;

/* Real-time model */
static RT_MODEL_DI_FB_Controller_T DI_FB_Controller_M_;
RT_MODEL_DI_FB_Controller_T *const DI_FB_Controller_M = &DI_FB_Controller_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (DI_FB_Controller_M->Timing.TaskCounters.TID[1])++;
  if ((DI_FB_Controller_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    DI_FB_Controller_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model output function */
void DI_FB_Controller_output(void)
{
  real_T count_real;
  real_T u1;
  real_T u2;
  ZCEventType zcEvent;

  /* S-Function (rti_commonblock): '<S2>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<Root>/Resolution' */
  DI_FB_Controller_B.Resolution = DI_FB_Controller_P.Resolution_Gain *
    DI_FB_Controller_B.SFunction1;

  /* Gain: '<Root>/Position' */
  DI_FB_Controller_B.Position = DI_FB_Controller_P.Position_Gain *
    DI_FB_Controller_B.Resolution;

  /* Outport: '<Root>/Position1' incorporates:
   *  Gain: '<Root>/Gain3'
   */
  DI_FB_Controller_Y.Position1 = DI_FB_Controller_P.Gain3_Gain *
    DI_FB_Controller_B.Position;

  /* S-Function (rti_commonblock): '<S2>/S-Function2' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<Root>/Steps' */
  DI_FB_Controller_B.Steps = DI_FB_Controller_P.Steps_Gain *
    DI_FB_Controller_B.SFunction2;

  /* Gain: '<Root>/Frequency' */
  DI_FB_Controller_B.Frequency = DI_FB_Controller_P.Frequency_Gain *
    DI_FB_Controller_B.Steps;

  /* Outport: '<Root>/Speed Out' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  DI_FB_Controller_Y.SpeedOut = DI_FB_Controller_P.Gain1_Gain *
    DI_FB_Controller_B.Frequency;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  DI_FB_Controller_B.DiscreteTimeIntegrator =
    DI_FB_Controller_DW.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<Root>/kI' */
  DI_FB_Controller_B.kI = DI_FB_Controller_P.kI_Gain *
    DI_FB_Controller_B.DiscreteTimeIntegrator;

  /* Gain: '<Root>/k1' */
  DI_FB_Controller_B.k1 = DI_FB_Controller_P.k1_Gain *
    DI_FB_Controller_B.Position;

  /* Gain: '<Root>/k2' */
  DI_FB_Controller_B.k2 = DI_FB_Controller_P.k2_Gain *
    DI_FB_Controller_B.Frequency;

  /* Gain: '<Root>/Gain4' incorporates:
   *  Constant: '<Root>/Disturbance'
   */
  DI_FB_Controller_B.Gain4 = DI_FB_Controller_P.Gain4_Gain *
    DI_FB_Controller_P.Disturbance_Value;

  /* Sum: '<Root>/Sum1' */
  DI_FB_Controller_B.Sum1 = ((DI_FB_Controller_B.kI - DI_FB_Controller_B.k1) -
    DI_FB_Controller_B.k2) + DI_FB_Controller_B.Gain4;

  /* Saturate: '<Root>/Saturation' */
  count_real = DI_FB_Controller_B.Sum1;
  u1 = DI_FB_Controller_P.Saturation_LowerSat;
  u2 = DI_FB_Controller_P.Saturation_UpperSat;
  if (count_real > u2) {
    /* Outport: '<Root>/Volt' */
    DI_FB_Controller_Y.Volt = u2;
  } else if (count_real < u1) {
    /* Outport: '<Root>/Volt' */
    DI_FB_Controller_Y.Volt = u1;
  } else {
    /* Outport: '<Root>/Volt' */
    DI_FB_Controller_Y.Volt = count_real;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain' incorporates:
   *  Outport: '<Root>/Volt'
   */
  DI_FB_Controller_B.Gain = DI_FB_Controller_P.Gain_Gain *
    DI_FB_Controller_Y.Volt;

  /* MATLAB Function: '<Root>/Function 1' */
  /* MATLAB Function 'Function 1': '<S6>:1' */
  /* '<S6>:1:3' */
  DI_FB_Controller_B.y_b = 0.5 - DI_FB_Controller_B.Gain / 2.0;

  /* S-Function (rti_commonblock): '<S5>/S-Function1' incorporates:
   *  Constant: '<Root>/Reset 1'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  DI_FB_Controller_DW.SFunction1_IWORK[0] = DI_FB_Controller_P.Reset1_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[6],
    DI_FB_Controller_B.y_b);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (DI_FB_Controller_DW.SFunction1_IWORK[0] == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwmStopFlagCh1 == 1)||(slaveDSPPwmStopFlagCh1 == 2))
               /* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwmStopFlagCh1 = 0;
      ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH1_MSK,
        SLVDSP1104_PWM_TTL_LOW);
    }
  } else if (DI_FB_Controller_DW.SFunction1_IWORK[0] == 0 ) {
    /* PWM Stop signal disabled -> trigger PWM generation once */
    if ((slaveDSPPwmStopFlagCh1 == 0)||(slaveDSPPwmStopFlagCh1 == 2)) {
      slaveDSPPwmStopFlagCh1 = 1;
      ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH1_MSK);
    }
  }

  /* S-Function (rti_commonblock): '<S5>/S-Function2' incorporates:
   *  Constant: '<Root>/Reset 1'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  DI_FB_Controller_DW.SFunction2_IWORK[1] = DI_FB_Controller_P.Reset1_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[7],
    DI_FB_Controller_B.y_b);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (DI_FB_Controller_DW.SFunction2_IWORK[1] == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwmStopFlagCh2 == 1)||(slaveDSPPwmStopFlagCh2 == 2))
               /* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwmStopFlagCh2 = 0;
      ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH2_MSK,
        SLVDSP1104_PWM_TTL_LOW);
    }
  } else if (DI_FB_Controller_DW.SFunction2_IWORK[1] == 0 ) {
    /* PWM Stop signal disabled -> trigger PWM generation once */
    if ((slaveDSPPwmStopFlagCh2 == 0)||(slaveDSPPwmStopFlagCh2 == 2)) {
      slaveDSPPwmStopFlagCh2 = 1;
      ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH2_MSK);
    }
  }

  /* MATLAB Function: '<Root>/Function 2' */
  /* MATLAB Function 'Function 2': '<S7>:1' */
  /* '<S7>:1:4' */
  DI_FB_Controller_B.y = DI_FB_Controller_B.Gain / 2.0 + 0.5;

  /* S-Function (rti_commonblock): '<S5>/S-Function3' incorporates:
   *  Constant: '<Root>/Reset 2'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  DI_FB_Controller_DW.SFunction3_IWORK[2] = DI_FB_Controller_P.Reset2_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[8],
    DI_FB_Controller_B.y);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (DI_FB_Controller_DW.SFunction3_IWORK[2] == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwmStopFlagCh3 == 1)||(slaveDSPPwmStopFlagCh3 == 2))
               /* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwmStopFlagCh3 = 0;
      ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH3_MSK,
        SLVDSP1104_PWM_TTL_LOW);
    }
  } else if (DI_FB_Controller_DW.SFunction3_IWORK[2] == 0 ) {
    /* PWM Stop signal disabled -> trigger PWM generation once */
    if ((slaveDSPPwmStopFlagCh3 == 0)||(slaveDSPPwmStopFlagCh3 == 2)) {
      slaveDSPPwmStopFlagCh3 = 1;
      ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH3_MSK);
    }
  }

  /* S-Function (rti_commonblock): '<S5>/S-Function4' incorporates:
   *  Constant: '<Root>/Reset 2'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  DI_FB_Controller_DW.SFunction4_IWORK[3] = DI_FB_Controller_P.Reset2_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[9],
    DI_FB_Controller_B.y);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (DI_FB_Controller_DW.SFunction4_IWORK[3] == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwmStopFlagCh4 == 1)||(slaveDSPPwmStopFlagCh4 == 2))
               /* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwmStopFlagCh4 = 0;
      ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH4_MSK,
        SLVDSP1104_PWM_TTL_LOW);
    }
  } else if (DI_FB_Controller_DW.SFunction4_IWORK[3] == 0 ) {
    /* PWM Stop signal disabled -> trigger PWM generation once */
    if ((slaveDSPPwmStopFlagCh4 == 0)||(slaveDSPPwmStopFlagCh4 == 2)) {
      slaveDSPPwmStopFlagCh4 = 1;
      ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH4_MSK);
    }
  }

  if (DI_FB_Controller_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLAB Function: '<Root>/Angel Function' incorporates:
     *  Constant: '<Root>/Desired Position'
     */
    /* MATLAB Function 'Angel Function': '<S1>:1' */
    /* '<S1>:1:3' */
    /* '<S1>:1:4' */
    /* '<S1>:1:5' */
    count_real = DI_FB_Controller_P.DesiredPosition_Value / 360.0 * 10000.0;
    if (fabs(count_real - rt_roundd_snf(count_real)) < 1.0E-9) {
      /* '<S1>:1:7' */
      /* '<S1>:1:8' */
      DI_FB_Controller_B.angel_out = DI_FB_Controller_P.DesiredPosition_Value;
    } else {
      /* '<S1>:1:10' */
      DI_FB_Controller_B.angel_out = DI_FB_Controller_P.DesiredPosition_Value /
        30.0 * 0.006 + DI_FB_Controller_P.DesiredPosition_Value;
    }

    /* End of MATLAB Function: '<Root>/Angel Function' */

    /* Gain: '<Root>/Gain2' */
    DI_FB_Controller_B.Gain2 = DI_FB_Controller_P.Gain2_Gain *
      DI_FB_Controller_B.angel_out;
  }

  /* Sum: '<Root>/Sum' */
  DI_FB_Controller_B.Sum = DI_FB_Controller_B.Gain2 -
    DI_FB_Controller_B.Position;

  /* Outputs for Triggered SubSystem: '<Root>/DS1104ENC_SET_POS_C1' incorporates:
   *  TriggerPort: '<S4>/Trigger'
   */
  /* Constant: '<Root>/Reset' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &DI_FB_Controller_PrevZCX.DS1104ENC_SET_POS_C1_Trig_ZCE,
                     (DI_FB_Controller_P.Reset_Value));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (rti_commonblock): '<S4>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1104 Unit:ENC_SET */
    ds1104_inc_position_write(1, 0, DS1104_INC_LINE_SUBDIV_4);
  }

  /* End of Outputs for SubSystem: '<Root>/DS1104ENC_SET_POS_C1' */

  /* S-Function (rti_commonblock): '<S3>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S3>/S-Function2' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
void DI_FB_Controller_update(void)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  DI_FB_Controller_DW.DiscreteTimeIntegrator_DSTATE +=
    DI_FB_Controller_P.DiscreteTimeIntegrator_gainval * DI_FB_Controller_B.Sum;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++DI_FB_Controller_M->Timing.clockTick0)) {
    ++DI_FB_Controller_M->Timing.clockTickH0;
  }

  DI_FB_Controller_M->Timing.taskTime0 = DI_FB_Controller_M->Timing.clockTick0 *
    DI_FB_Controller_M->Timing.stepSize0 +
    DI_FB_Controller_M->Timing.clockTickH0 *
    DI_FB_Controller_M->Timing.stepSize0 * 4294967296.0;
  rate_scheduler();
}

/* Model initialize function */
void DI_FB_Controller_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)DI_FB_Controller_M, 0,
                sizeof(RT_MODEL_DI_FB_Controller_T));
  DI_FB_Controller_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &DI_FB_Controller_B), 0,
                sizeof(B_DI_FB_Controller_T));

  /* states (dwork) */
  (void) memset((void *)&DI_FB_Controller_DW, 0,
                sizeof(DW_DI_FB_Controller_T));

  /* external outputs */
  (void) memset((void *)&DI_FB_Controller_Y, 0,
                sizeof(ExtY_DI_FB_Controller_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    DI_FB_Controller_rti_init_trc_pointers();
  }

  /* Start for S-Function (rti_commonblock): '<S5>/S-Function1' incorporates:
   *  Constant: '<Root>/Reset 1'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  DI_FB_Controller_DW.SFunction1_IWORK[0] = 0;

  /* Start for S-Function (rti_commonblock): '<S5>/S-Function2' incorporates:
   *  Constant: '<Root>/Reset 1'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  DI_FB_Controller_DW.SFunction2_IWORK[1] = 0;

  /* Start for S-Function (rti_commonblock): '<S5>/S-Function3' incorporates:
   *  Constant: '<Root>/Reset 2'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  DI_FB_Controller_DW.SFunction3_IWORK[2] = 0;

  /* Start for S-Function (rti_commonblock): '<S5>/S-Function4' incorporates:
   *  Constant: '<Root>/Reset 2'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  DI_FB_Controller_DW.SFunction4_IWORK[3] = 0;
  DI_FB_Controller_PrevZCX.DS1104ENC_SET_POS_C1_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  DI_FB_Controller_DW.DiscreteTimeIntegrator_DSTATE =
    DI_FB_Controller_P.DiscreteTimeIntegrator_IC;
}

/* Model terminate function */
void DI_FB_Controller_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S5>/S-Function1' incorporates:
   *  Constant: '<Root>/Reset 1'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH1_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh1 = 2;

  /* Terminate for S-Function (rti_commonblock): '<S5>/S-Function2' incorporates:
   *  Constant: '<Root>/Reset 1'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH2_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh2 = 2;

  /* Terminate for S-Function (rti_commonblock): '<S5>/S-Function3' incorporates:
   *  Constant: '<Root>/Reset 2'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH3_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh3 = 2;

  /* Terminate for S-Function (rti_commonblock): '<S5>/S-Function4' incorporates:
   *  Constant: '<Root>/Reset 2'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH4_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh4 = 2;
}
