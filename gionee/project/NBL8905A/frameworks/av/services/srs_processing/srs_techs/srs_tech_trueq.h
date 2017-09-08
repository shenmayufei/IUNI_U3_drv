/*======================================================================*
 DTS, Inc.
 5220 Las Virgenes Road
 Calabasas, CA 91302  USA

 CONFIDENTIAL: CONTAINS CONFIDENTIAL PROPRIETARY INFORMATION OWNED BY
 DTS, INC. AND/OR ITS AFFILIATES ("DTS"), INCLUDING BUT NOT LIMITED TO
 TRADE SECRETS, KNOW-HOW, TECHNICAL AND BUSINESS INFORMATION. USE,
 DISCLOSURE OR DISTRIBUTION OF THE SOFTWARE IN ANY FORM IS LIMITED TO
 SPECIFICALLY AUTHORIZED LICENSEES OF DTS.  ANY UNAUTHORIZED
 DISCLOSURE IS A VIOLATION OF STATE, FEDERAL, AND INTERNATIONAL LAWS.
 BOTH CIVIL AND CRIMINAL PENALTIES APPLY.

 DO NOT DUPLICATE. COPYRIGHT 2014, DTS, INC. ALL RIGHTS RESERVED.
 UNAUTHORIZED DUPLICATION IS A VIOLATION OF STATE, FEDERAL AND
 INTERNATIONAL LAWS.

 ALGORITHMS, DATA STRUCTURES AND METHODS CONTAINED IN THIS SOFTWARE
 MAY BE PROTECTED BY ONE OR MORE PATENTS OR PATENT APPLICATIONS.
 UNLESS OTHERWISE PROVIDED UNDER THE TERMS OF A FULLY-EXECUTED WRITTEN
 AGREEMENT BY AND BETWEEN THE RECIPIENT HEREOF AND DTS, THE FOLLOWING
 TERMS SHALL APPLY TO ANY USE OF THE SOFTWARE (THE "PRODUCT") AND, AS
 APPLICABLE, ANY RELATED DOCUMENTATION:  (i) ANY USE OF THE PRODUCT
 AND ANY RELATED DOCUMENTATION IS AT THE RECIPIENT�S SOLE RISK:
 (ii) THE PRODUCT AND ANY RELATED DOCUMENTATION ARE PROVIDED "AS IS"
 AND WITHOUT WARRANTY OF ANY KIND AND DTS EXPRESSLY DISCLAIMS ALL
 WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO ANY
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE, REGARDLESS OF WHETHER DTS KNOWS OR HAS REASON TO KNOW OF THE
 USER'S PARTICULAR NEEDS; (iii) DTS DOES NOT WARRANT THAT THE PRODUCT
 OR ANY RELATED DOCUMENTATION WILL MEET USER'S REQUIREMENTS, OR THAT
 DEFECTS IN THE PRODUCT OR ANY RELATED DOCUMENTATION WILL BE
 CORRECTED; (iv) DTS DOES NOT WARRANT THAT THE OPERATION OF ANY
 HARDWARE OR SOFTWARE ASSOCIATED WITH THIS DOCUMENT WILL BE
 UNINTERRUPTED OR ERROR-FREE; AND (v) UNDER NO CIRCUMSTANCES,
 INCLUDING NEGLIGENCE, SHALL DTS OR THE DIRECTORS, OFFICERS, EMPLOYEES,
 OR AGENTS OF DTS, BE LIABLE TO USER FOR ANY INCIDENTAL, INDIRECT,
 SPECIAL, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, AND LOSS
 OF BUSINESS INFORMATION) ARISING OUT OF THE USE, MISUSE, OR INABILITY
 TO USE THE PRODUCT OR ANY RELATED DOCUMENTATION.
*======================================================================*/

#ifndef ANDROID_SRS_TECH_TruEQ
#define ANDROID_SRS_TECH_TruEQ

namespace android {

struct SRS_Tech_TruEQ {
    bool Skip;
    bool LEnable;
    bool REnable;
    bool LBands[4];
    bool RBands[4];

    float IGain, OGain, BGain;
    float Params[8][3]; // 2 channels, 4 bands, 3 params (center freq, gain, q)
};

struct SRS_Source_TruEQ;

// Instead of virtuals - or a 'public' class - we'll hide all of TruEQ behind this...
extern SRS_Source_TruEQ*    SRS_Create_TruEQ(SRS_Source_Out *pOut);
extern void                 SRS_Destroy_TruEQ(SRS_Source_TruEQ *pSrc, SRS_Source_Out *pOut);
extern void                 SRS_Config_TruEQ(SRS_Source_TruEQ *pSrc, SRS_Source_Out *pOut, SRS_Tech_TruEQ *pCFG, bool bBypass);
extern void                 SRS_Process_TruEQ_256(SRS_Source_TruEQ *pSrc, SRSSamp *pData);
extern char*                SRS_GetVersion_TruEQ(char *pWork, size_t maxBytes);
extern SRS_Param*           SRS_GetBank_TruEQ(int &paramCount);
extern void                 SRS_SetParam_TruEQ(SRS_Tech_TruEQ *pCFG, SRS_Param *pParam, const char *pValue);
extern const char*          SRS_GetParam_TruEQ(SRS_Tech_TruEQ *pCFG, SRS_Param *pParam);
extern void                 SRS_Default_TruEQ(SRS_Tech_TruEQ *pCFG);

};

#endif  // ANDROID_SRS_TECH_TruEQ
