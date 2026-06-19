/*********************** dSPACE target specific file *************************

   Header file LQR_Controller_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 7.16 (02-May-2021)
   Fri May  1 21:58:43 2026

   Copyright 2026, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_LQR_Controller_trc_ptr_h_
#define RTI_HEADER_LQR_Controller_trc_ptr_h_

/* Include the model header file. */
#include "LQR_Controller.h"
#include "LQR_Controller_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_LQR_Controller_real_T_0;
EXTERN_C volatile real_T *p_1_LQR_Controller_real_T_0;
EXTERN_C volatile real_T *p_2_LQR_Controller_real_T_0;
EXTERN_C volatile int_T *p_2_LQR_Controller_int_T_1;
EXTERN_C volatile real_T *p_3_LQR_Controller_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void LQR_Controller_rti_init_trc_pointers(void);

#endif                                /* RTI_HEADER_LQR_Controller_trc_ptr_h_ */
