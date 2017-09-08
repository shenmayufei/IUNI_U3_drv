/******************************************************************************
 *
 *  Id: AKVersion.h 59 2010-07-30 01:55:35Z rikita 
 *
 * -- Copyright Notice --
 *
 * Copyright (c) 2004 - 2010 Asahi Kasei Microdevices Corporation, Japan
 * All Rights Reserved.
 *
 * This software program is proprietary program of Asahi Kasei Microdevices 
 * Corporation("AKM") licensed to authorized Licensee under Software License 
 * Agreement (SLA) executed between the Licensee and AKM.
 * 
 * Use of the software by unauthorized third party, or use of the software 
 * beyond the scope of the SLA is strictly prohibited.
 *
 * -- End Asahi Kasei Microdevices Copyright Notice --
 *
 ******************************************************************************/
#ifndef AKSC_INC_AKVERSION_H
#define AKSC_INC_AKVERSION_H

#include "AKMDevice.h"

//========================= Type declaration  ===========================//

//========================= Constant definition =========================//

//========================= Prototype of Function =======================//
AKLIB_C_API_START
int16 AKSC_GetVersion_Major(void);
int16 AKSC_GetVersion_Minor(void);
int16 AKSC_GetVersion_Revision(void);
int16 AKSC_GetVersion_DateCode(void);
AKLIB_C_API_END

#endif

