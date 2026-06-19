/*
 * LQR_Controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LQR_Controller".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri May  1 21:58:43 2026
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LQR_Controller_trc_ptr.h"
#include "LQR_Controller.h"
#include "LQR_Controller_private.h"

/* Block signals (default storage) */
B_LQR_Controller_T LQR_Controller_B;

/* Block states (default storage) */
DW_LQR_Controller_T LQR_Controller_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_LQR_Controller_T LQR_Controller_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_LQR_Controller_T LQR_Controller_Y;

/* Real-time model */
static RT_MODEL_LQR_Controller_T LQR_Controller_M_;
RT_MODEL_LQR_Controller_T *const LQR_Controller_M = &LQR_Controller_M_;
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
  (LQR_Controller_M->Timing.TaskCounters.TID[1])++;
  if ((LQR_Controller_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    LQR_Controller_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model output function */
void LQR_Controller_output(void)
{
  real_T u0;
  real_T u1;
  real_T u2;
  ZCEventType zcEvent;

  /* S-Function (rti_commonblock): '<S1>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<Root>/Resolution' */
  LQR_Controller_B.Resolution = LQR_Controller_P.Resolution_Gain *
    LQR_Controller_B.SFunction1;

  /* Gain: '<Root>/Position' */
  LQR_Controller_B.Position = LQR_Controller_P.Position_Gain *
    LQR_Controller_B.Resolution;

  /* Outport: '<Root>/Position1' incorporates:
   *  Gain: '<Root>/Gain3'
   */
  LQR_Controller_Y.Position1 = LQR_Controller_P.Gain3_Gain *
    LQR_Controller_B.Position;

  /* S-Function (rti_commonblock): '<S1>/S-Function2' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<Root>/Steps' */
  LQR_Controller_B.Steps = LQR_Controller_P.Steps_Gain *
    LQR_Controller_B.SFunction2;

  /* Gain: '<Root>/Frequency' */
  LQR_Controller_B.Frequency = LQR_Controller_P.Frequency_Gain *
    LQR_Controller_B.Steps;

  /* Outport: '<Root>/Speed Out' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  LQR_Controller_Y.SpeedOut = LQR_Controller_P.Gain1_Gain *
    LQR_Controller_B.Frequency;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  LQR_Controller_B.DiscreteTimeIntegrator =
    LQR_Controller_DW.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<Root>/kI' */
  LQR_Controller_B.kI = LQR_Controller_P.kI_Gain *
    LQR_Controller_B.DiscreteTimeIntegrator;

  /* Gain: '<Root>/k1' */
  LQR_Controller_B.k1 = LQR_Controller_P.k1_Gain * LQR_Controller_B.Position;

  /* Gain: '<Root>/k2' */
  LQR_Controller_B.k2 = LQR_Controller_P.k2_Gain * LQR_Controller_B.Frequency;

  /* Sum: '<Root>/Sum1' */
  LQR_Controller_B.Sum1 = (LQR_Controller_B.kI - LQR_Controller_B.k1) -
    LQR_Controller_B.k2;

  /* Saturate: '<Root>/Saturation' */
  u0 = LQR_Controller_B.Sum1;
  u1 = LQR_Controller_P.Saturation_LowerSat;
  u2 = LQR_Controller_P.Saturation_UpperSat;
  if (u0 > u2) {
    /* Outport: '<Root>/Volt' */
    LQR_Controller_Y.Volt = u2;
  } else if (u0 < u1) {
    /* Outport: '<Root>/Volt' */
    LQR_Controller_Y.Volt = u1;
  } else {
    /* Outport: '<Root>/Volt' */
    LQR_Controller_Y.Volt = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain' incorporates:
   *  Outport: '<Root>/Volt'
   */
  LQR_Controller_B.Gain = LQR_Controller_P.Gain_Gain * LQR_Controller_Y.Volt;

  /* MATLAB Function: '<Root>/Function 1' */
  /* MATLAB Function 'Function 1': '<S5>:1' */
  /* '<S5>:1:3' */
  LQR_Controller_B.y_b = 0.5 - LQR_Controller_B.Gain / 2.0;

  /* S-Function (rti_commonblock): '<S4>/S-Function1' incorporates:
   *  Constant: '<Root>/Reset 1'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  LQR_Controller_DW.SFunction1_IWORK[0] = LQR_Controller_P.Reset1_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[6],
    LQR_Controller_B.y_b);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (LQR_Controller_DW.SFunction1_IWORK[0] == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwmStopFlagCh1 == 1)||(slaveDSPPwmStopFlagCh1 == 2))
               /* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwmStopFlagCh1 = 0;
      ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH1_MSK,
        SLVDSP1104_PWM_TTL_LOW);
    }
  } else if (LQR_Controller_DW.SFunction1_IWORK[0] == 0 ) {
    /* PWM Stop signal disabled -> trigger PWM generation once */
    if ((slaveDSPPwmStopFlagCh1 == 0)||(slaveDSPPwmStopFlagCh1 == 2)) {
      slaveDSPPwmStopFlagCh1 = 1;
      ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH1_MSK);
    }
  }

  /* S-Function (rti_commonblock): '<S4>/S-Function2' incorporates:
   *  Constant: '<Root>/Reset 1'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  LQR_Controller_DW.SFunction2_IWORK[1] = LQR_Controller_P.Reset1_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[7],
    LQR_Controller_B.y_b);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (LQR_Controller_DW.SFunction2_IWORK[1] == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwmStopFlagCh2 == 1)||(slaveDSPPwmStopFlagCh2 == 2))
               /* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwmStopFlagCh2 = 0;
      ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH2_MSK,
        SLVDSP1104_PWM_TTL_LOW);
    }
  } else if (LQR_Controller_DW.SFunction2_IWORK[1] == 0 ) {
    /* PWM Stop signal disabled -> trigger PWM generation once */
    if ((slaveDSPPwmStopFlagCh2 == 0)||(slaveDSPPwmStopFlagCh2 == 2)) {
      slaveDSPPwmStopFlagCh2 = 1;
      ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH2_MSK);
    }
  }

  /* MATLAB Function: '<Root>/Function 2' */
  /* MATLAB Function 'Function 2': '<S6>:1' */
  /* '<S6>:1:4' */
  LQR_Controller_B.y = LQR_Controller_B.Gain / 2.0 + 0.5;

  /* S-Function (rti_commonblock): '<S4>/S-Function3' incorporates:
   *  Constant: '<Root>/Reset 2'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  LQR_Controller_DW.SFunction3_IWORK[2] = LQR_Controller_P.Reset2_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[8],
    LQR_Controller_B.y);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (LQR_Controller_DW.SFunction3_IWORK[2] == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwmStopFlagCh3 == 1)||(slaveDSPPwmStopFlagCh3 == 2))
               /* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwmStopFlagCh3 = 0;
      ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH3_MSK,
        SLVDSP1104_PWM_TTL_LOW);
    }
  } else if (LQR_Controller_DW.SFunction3_IWORK[2] == 0 ) {
    /* PWM Stop signal disabled -> trigger PWM generation once */
    if ((slaveDSPPwmStopFlagCh3 == 0)||(slaveDSPPwmStopFlagCh3 == 2)) {
      slaveDSPPwmStopFlagCh3 = 1;
      ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH3_MSK);
    }
  }

  /* S-Function (rti_commonblock): '<S4>/S-Function4' incorporates:
   *  Constant: '<Root>/Reset 2'
   */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  LQR_Controller_DW.SFunction4_IWORK[3] = LQR_Controller_P.Reset2_Value;

  /* write the duty cycle down */
  ds1104_slave_dsp_pwm_duty_write(0, rti_slv1104_fcn_index[9],
    LQR_Controller_B.y);

  /* set outputs to TTL-level or retrigger PWM generation */
  if (LQR_Controller_DW.SFunction4_IWORK[3] == 1 ) {
    /*  if (flag == RUN)||(flag == UNDEF) */
    if ((slaveDSPPwmStopFlagCh4 == 1)||(slaveDSPPwmStopFlagCh4 == 2))
               /* PWM Stop signal from Input Port -> set outputs to TTL-level */
    {
      slaveDSPPwmStopFlagCh4 = 0;
      ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH4_MSK,
        SLVDSP1104_PWM_TTL_LOW);
    }
  } else if (LQR_Controller_DW.SFunction4_IWORK[3] == 0 ) {
    /* PWM Stop signal disabled -> trigger PWM generation once */
    if ((slaveDSPPwmStopFlagCh4 == 0)||(slaveDSPPwmStopFlagCh4 == 2)) {
      slaveDSPPwmStopFlagCh4 = 1;
      ds1104_slave_dsp_pwm_start(0, SLVDSP1104_PWM_CH4_MSK);
    }
  }

  if (LQR_Controller_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<Root>/Gain2' incorporates:
     *  Constant: '<Root>/Desired Position'
     */
    LQR_Controller_B.Gain2 = LQR_Controller_P.Gain2_Gain *
      LQR_Controller_P.DesiredPosition_Value;
  }

  /* Sum: '<Root>/Sum' */
  LQR_Controller_B.Sum = LQR_Controller_B.Gain2 - LQR_Controller_B.Position;

  /* Gain: '<Root>/Gain4' */
  LQR_Controller_B.Gain4 = LQR_Controller_P.Gain4_Gain * LQR_Controller_B.Sum;

  /* Outputs for Triggered SubSystem: '<Root>/DS1104ENC_SET_POS_C1' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  /* Constant: '<Root>/Reset' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &LQR_Controller_PrevZCX.DS1104ENC_SET_POS_C1_Trig_ZCE,
                     (LQR_Controller_P.Reset_Value));
  if (zcEvent != NO_ZCEVENT) {
    /* S-Function (rti_commonblock): '<S3>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1104 Unit:ENC_SET */
    ds1104_inc_position_write(1, 0, DS1104_INC_LINE_SUBDIV_4);
  }

  /* End of Outputs for SubSystem: '<Root>/DS1104ENC_SET_POS_C1' */

  /* S-Function (rti_commonblock): '<S2>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S2>/S-Function2' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
void LQR_Controller_update(void)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  LQR_Controller_DW.DiscreteTimeIntegrator_DSTATE +=
    LQR_Controller_P.DiscreteTimeIntegrator_gainval * LQR_Controller_B.Gain4;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++LQR_Controller_M->Timing.clockTick0)) {
    ++LQR_Controller_M->Timing.clockTickH0;
  }

  LQR_Controller_M->Timing.taskTime0 = LQR_Controller_M->Timing.clockTick0 *
    LQR_Controller_M->Timing.stepSize0 + LQR_Controller_M->Timing.clockTickH0 *
    LQR_Controller_M->Timing.stepSize0 * 4294967296.0;
  rate_scheduler();
}

/* Model initialize function */
void LQR_Controller_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LQR_Controller_M, 0,
                sizeof(RT_MODEL_LQR_Controller_T));
  LQR_Controller_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &LQR_Controller_B), 0,
                sizeof(B_LQR_Controller_T));

  /* states (dwork) */
  (void) memset((void *)&LQR_Controller_DW, 0,
                sizeof(DW_LQR_Controller_T));

  /* external outputs */
  (void) memset((void *)&LQR_Controller_Y, 0,
                sizeof(ExtY_LQR_Controller_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    LQR_Controller_rti_init_trc_pointers();
  }

  /* Start for S-Function (rti_commonblock): '<S4>/S-Function1' incorporates:
   *  Constant: '<Root>/Reset 1'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  LQR_Controller_DW.SFunction1_IWORK[0] = 0;

  /* Start for S-Function (rti_commonblock): '<S4>/S-Function2' incorporates:
   *  Constant: '<Root>/Reset 1'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  LQR_Controller_DW.SFunction2_IWORK[1] = 0;

  /* Start for S-Function (rti_commonblock): '<S4>/S-Function3' incorporates:
   *  Constant: '<Root>/Reset 2'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  LQR_Controller_DW.SFunction3_IWORK[2] = 0;

  /* Start for S-Function (rti_commonblock): '<S4>/S-Function4' incorporates:
   *  Constant: '<Root>/Reset 2'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  LQR_Controller_DW.SFunction4_IWORK[3] = 0;
  LQR_Controller_PrevZCX.DS1104ENC_SET_POS_C1_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  LQR_Controller_DW.DiscreteTimeIntegrator_DSTATE =
    LQR_Controller_P.DiscreteTimeIntegrator_IC;
}

/* Model terminate function */
void LQR_Controller_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S4>/S-Function1' incorporates:
   *  Constant: '<Root>/Reset 1'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH1_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh1 = 2;

  /* Terminate for S-Function (rti_commonblock): '<S4>/S-Function2' incorporates:
   *  Constant: '<Root>/Reset 1'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH2_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh2 = 2;

  /* Terminate for S-Function (rti_commonblock): '<S4>/S-Function3' incorporates:
   *  Constant: '<Root>/Reset 2'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH3_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh3 = 2;

  /* Terminate for S-Function (rti_commonblock): '<S4>/S-Function4' incorporates:
   *  Constant: '<Root>/Reset 2'
   */

  /* dSPACE I/O Board DS1104 #1 Unit:PWM Group:PWM */
  ds1104_slave_dsp_pwm_output_set(0, SLVDSP1104_PWM_CH4_MSK,
    SLVDSP1104_PWM_TTL_LOW);

  /* flag = UNDEF */
  slaveDSPPwmStopFlagCh4 = 2;
}
