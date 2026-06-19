/***************************************************************************

   Source file LQR_Controller_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1104 7.16 (02-May-2021)
   Fri May  1 21:58:43 2026

   Copyright 2026, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "LQR_Controller_trc_ptr.h"
#include "LQR_Controller.h"
#include "LQR_Controller_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_LQR_Controller_real_T_0 = NULL;
volatile real_T *p_1_LQR_Controller_real_T_0 = NULL;
volatile real_T *p_2_LQR_Controller_real_T_0 = NULL;
volatile int_T *p_2_LQR_Controller_int_T_1 = NULL;
volatile real_T *p_3_LQR_Controller_real_T_0 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_LQR_Controller_real_T_0 = &LQR_Controller_B.SFunction1;
  p_1_LQR_Controller_real_T_0 = &LQR_Controller_P.Resolution_Gain;
  p_2_LQR_Controller_real_T_0 = &LQR_Controller_DW.DiscreteTimeIntegrator_DSTATE;
  p_2_LQR_Controller_int_T_1 = &LQR_Controller_DW.SFunction1_IWORK[0];
  p_3_LQR_Controller_real_T_0 = &LQR_Controller_Y.Position1;
}

void LQR_Controller_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
