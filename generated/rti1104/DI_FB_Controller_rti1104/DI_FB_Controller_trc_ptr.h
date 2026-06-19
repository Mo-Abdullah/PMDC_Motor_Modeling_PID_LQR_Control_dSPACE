/*********************** dSPACE target specific file *************************

   Header file DI_FB_Controller_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 7.16 (02-May-2021)
   Fri May  1 21:52:08 2026

   Copyright 2026, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_DI_FB_Controller_trc_ptr_h_
#define RTI_HEADER_DI_FB_Controller_trc_ptr_h_

/* Include the model header file. */
#include "DI_FB_Controller.h"
#include "DI_FB_Controller_private.h"
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
EXTERN_C volatile real_T *p_0_DI_FB_Controller_real_T_0;
EXTERN_C volatile real_T *p_1_DI_FB_Controller_real_T_0;
EXTERN_C volatile real_T *p_2_DI_FB_Controller_real_T_0;
EXTERN_C volatile int_T *p_2_DI_FB_Controller_int_T_1;
EXTERN_C volatile real_T *p_3_DI_FB_Controller_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void DI_FB_Controller_rti_init_trc_pointers(void);

#endif                              /* RTI_HEADER_DI_FB_Controller_trc_ptr_h_ */
