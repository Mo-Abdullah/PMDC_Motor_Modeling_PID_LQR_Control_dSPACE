/*
 * LQR_Controller_data.c
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

#include "LQR_Controller.h"
#include "LQR_Controller_private.h"

/* Block parameters (default storage) */
P_LQR_Controller_T LQR_Controller_P = {
  /* Expression: -1/10000
   * Referenced by: '<Root>/Resolution'
   */
  -0.0001,

  /* Expression: 2*pi
   * Referenced by: '<Root>/Position'
   */
  6.2831853071795862,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain3'
   */
  57.295779513082323,

  /* Expression: -(2*pi)/10000
   * Referenced by: '<Root>/Steps'
   */
  -0.00062831853071795862,

  /* Expression: 1/(0.001)
   * Referenced by: '<Root>/Frequency'
   */
  1000.0,

  /* Expression: 60/(2*pi)
   * Referenced by: '<Root>/Gain1'
   */
  9.5492965855137211,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 109.545
   * Referenced by: '<Root>/kI'
   */
  109.545,

  /* Expression: 96.1531
   * Referenced by: '<Root>/k1'
   */
  96.1531,

  /* Expression: 2.128
   * Referenced by: '<Root>/k2'
   */
  2.128,

  /* Expression: 24
   * Referenced by: '<Root>/Saturation'
   */
  24.0,

  /* Expression: -24
   * Referenced by: '<Root>/Saturation'
   */
  -24.0,

  /* Expression: 1/24
   * Referenced by: '<Root>/Gain'
   */
  0.041666666666666664,

  /* Expression: 0
   * Referenced by: '<Root>/Reset 1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Reset 2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Desired Position'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<Root>/Gain2'
   */
  0.017453292519943295,

  /* Expression: 15
   * Referenced by: '<Root>/Gain4'
   */
  15.0,

  /* Expression: 1
   * Referenced by: '<Root>/Reset'
   */
  1.0
};
