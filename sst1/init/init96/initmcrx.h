/*
** THIS SOFTWARE IS SUBJECT TO COPYRIGHT PROTECTION AND IS OFFERED ONLY
** PURSUANT TO THE 3DFX GLIDE GENERAL PUBLIC LICENSE. THERE IS NO RIGHT
** TO USE THE GLIDE TRADEMARK WITHOUT PRIOR WRITTEN PERMISSION OF 3DFX
** INTERACTIVE, INC. A COPY OF THIS LICENSE MAY BE OBTAINED FROM THE 
** DISTRIBUTOR OR BY CONTACTING 3DFX INTERACTIVE INC(info@3dfx.com). 
** THIS PROGRAM IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER 
** EXPRESSED OR IMPLIED. SEE THE 3DFX GLIDE GENERAL PUBLIC LICENSE FOR A
** FULL TEXT OF THE NON-WARRANTY PROVISIONS.  
** 
** USE, DUPLICATION OR DISCLOSURE BY THE GOVERNMENT IS SUBJECT TO
** RESTRICTIONS AS SET FORTH IN SUBDIVISION (C)(1)(II) OF THE RIGHTS IN
** TECHNICAL DATA AND COMPUTER SOFTWARE CLAUSE AT DFARS 252.227-7013,
** AND/OR IN SIMILAR OR SUCCESSOR CLAUSES IN THE FAR, DOD OR NASA FAR
** SUPPLEMENT. UNPUBLISHED RIGHTS RESERVED UNDER THE COPYRIGHT LAWS OF
** THE UNITED STATES.  
** 
** COPYRIGHT 3DFX INTERACTIVE, INC. 1999, ALL RIGHTS RESERVED
**
**
** $Revision$ 
** $Date$ 
**
*/
#ifndef __INITMCRX_H__
#define __INITMCRX_H__
#define SETMCRX(d,s) d = s
#define GETMCRX(s) s 

#ifdef INIT_MCRX_LIB
#define INITMCRXENTRY(fun, type, args) FX_EXPORT type FX_CALL fun args
#else
#define INITMCRXENTRY(fun, type, args) FX_ENTRY type FX_CSTYLE fun args
#endif
INITMCRXENTRY(initMCRXGetHALData, Init96HALData *, (void) );
INITMCRXENTRY(initMCRXAperture, FxBool, (InitRegisterDesc *rd) );
INITMCRXENTRY(initMCRXSetVideo, FxBool, ( GrScreenResolution_t res, GrScreenRefresh_t refresh, FxU32 *xr, FxU32 *yr ));
INITMCRXENTRY(initMCRXEnableRegs, FxBool,(InitRegisterDesc *rd));
INITMCRXENTRY(initMCRXDisableRegs,FxBool,(InitRegisterDesc *rd));
INITMCRXENTRY(initMCRXWrapFIFO, FxBool , (InitRegisterDesc *rd, InitFIFOData *fd) );
#ifdef H3D
INITMCRXENTRY(initMCRXUseTiles, int, (InitRegisterDesc *rd,
        FxU32 *buffers, FxU32 nBuffers,
        FxU32 strideInBytes, FxU32 width, FxU32 height, FxU32 PageFlipped));
#else
INITMCRXENTRY(initMCRXUseTiles, int, (InitRegisterDesc *rd,
        FxU32 *buffers, FxU32 nBuffers,
        FxU32 strideInBytes, FxU32 width, FxU32 height));
#endif
INITMCRXENTRY(initMCRXGetInfo, FxBool,(VG96Info *info));
#endif /* __INITMCRX_H__ */

