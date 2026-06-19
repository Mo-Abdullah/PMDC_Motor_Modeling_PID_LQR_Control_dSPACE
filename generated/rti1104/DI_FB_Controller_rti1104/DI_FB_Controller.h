/*
 * DI_FB_Controller.h
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

#ifndef RTW_HEADER_DI_FB_Controller_h_
#define RTW_HEADER_DI_FB_Controller_h_
#include <math.h>
#include <string.h>
#ifndef DI_FB_Controller_COMMON_INCLUDES_
#define DI_FB_Controller_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <def1104.h>
#include <slvdsp1104.h>
#include <rti_slv1104.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* DI_FB_Controller_COMMON_INCLUDES_ */

#include "DI_FB_Controller_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T SFunction1;                   /* '<S2>/S-Function1' */
  real_T Resolution;                   /* '<Root>/Resolution' */
  real_T Position;                     /* '<Root>/Position' */
  real_T SFunction2;                   /* '<S2>/S-Function2' */
  real_T Steps;                        /* '<Root>/Steps' */
  real_T Frequency;                    /* '<Root>/Frequency' */
  real_T DiscreteTimeIntegrator;       /* '<Root>/Discrete-Time Integrator' */
  real_T kI;                           /* '<Root>/kI' */
  real_T k1;                           /* '<Root>/k1' */
  real_T k2;                           /* '<Root>/k2' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T y;                            /* '<Root>/Function 2' */
  real_T y_b;                          /* '<Root>/Function 1' */
  real_T angel_out;                    /* '<Root>/Angel Function' */
} B_DI_FB_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  int_T SFunction1_IWORK[4];           /* '<S5>/S-Function1' */
  int_T SFunction2_IWORK[4];           /* '<S5>/S-Function2' */
  int_T SFunction3_IWORK[4];           /* '<S5>/S-Function3' */
  int_T SFunction4_IWORK[4];           /* '<S5>/S-Function4' */
} DW_DI_FB_Controller_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState DS1104ENC_SET_POS_C1_Trig_ZCE;/* '<Root>/DS1104ENC_SET_POS_C1' */
} PrevZCX_DI_FB_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Position1;                    /* '<Root>/Position1' */
  real_T SpeedOut;                     /* '<Root>/Speed Out' */
  real_T Volt;                         /* '<Root>/Volt' */
} ExtY_DI_FB_Controller_T;

/* Parameters (default storage) */
struct P_DI_FB_Controller_T_ {
  real_T Resolution_Gain;              /* Expression: -1/10000
                                        * Referenced by: '<Root>/Resolution'
                                        */
  real_T Position_Gain;                /* Expression: 2*pi
                                        * Referenced by: '<Root>/Position'
                                        */
  real_T Gain3_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Steps_Gain;                   /* Expression: -(2*pi)/10000
                                        * Referenced by: '<Root>/Steps'
                                        */
  real_T Frequency_Gain;               /* Expression: 1/(0.001)
                                        * Referenced by: '<Root>/Frequency'
                                        */
  real_T Gain1_Gain;                   /* Expression: 60/(2*pi)
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T kI_Gain;                      /* Expression: 1957
                                        * Referenced by: '<Root>/kI'
                                        */
  real_T k1_Gain;                      /* Expression: 94.81
                                        * Referenced by: '<Root>/k1'
                                        */
  real_T k2_Gain;                      /* Expression: 2.54
                                        * Referenced by: '<Root>/k2'
                                        */
  real_T Disturbance_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/Disturbance'
                                        */
  real_T Gain4_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 24
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -24
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/24
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Reset1_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Reset 1'
                                        */
  real_T Reset2_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Reset 2'
                                        */
  real_T DesiredPosition_Value;        /* Expression: 0
                                        * Referenced by: '<Root>/Desired Position'
                                        */
  real_T Gain2_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Reset_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_DI_FB_Controller_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_DI_FB_Controller_T DI_FB_Controller_P;

/* Block signals (default storage) */
extern B_DI_FB_Controller_T DI_FB_Controller_B;

/* Block states (default storage) */
extern DW_DI_FB_Controller_T DI_FB_Controller_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_DI_FB_Controller_T DI_FB_Controller_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_DI_FB_Controller_T DI_FB_Controller_Y;

/* Model entry point functions */
extern void DI_FB_Controller_initialize(void);
extern void DI_FB_Controller_output(void);
extern void DI_FB_Controller_update(void);
extern void DI_FB_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DI_FB_Controller_T *const DI_FB_Controller_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DI_FB_Controller'
 * '<S1>'   : 'DI_FB_Controller/Angel Function'
 * '<S2>'   : 'DI_FB_Controller/DS1104ENC_POS_C1'
 * '<S3>'   : 'DI_FB_Controller/DS1104ENC_SETUP'
 * '<S4>'   : 'DI_FB_Controller/DS1104ENC_SET_POS_C1'
 * '<S5>'   : 'DI_FB_Controller/DS1104SL_DSP_PWM'
 * '<S6>'   : 'DI_FB_Controller/Function 1'
 * '<S7>'   : 'DI_FB_Controller/Function 2'
 * '<S8>'   : 'DI_FB_Controller/RTI Data'
 * '<S9>'   : 'DI_FB_Controller/RTI Data/RTI Data Store'
 * '<S10>'  : 'DI_FB_Controller/RTI Data/RTI Data Store/RTI Data Store'
 * '<S11>'  : 'DI_FB_Controller/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* RTW_HEADER_DI_FB_Controller_h_ */
