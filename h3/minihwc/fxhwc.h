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
** $Header$
** $Log$
** Revision 1.2  2000/10/03 18:29:57  mercury
** 003-clean_up_h3-000, h3 tree cleanup.
**
** Revision 1.1.1.1  1999/12/07 21:49:43  joseph
** Initial checkin into SourceForge.
**
** 
** 3     3/17/99 6:14p Dow
** Fixes Phantom Menace, OGL, and others.
** 
** 1     3/04/98 4:13p Dow
**
*/
#ifndef FXHWC_H
#define FXHWC_H



/*
**  I/O Macros
*/
#warning Here!
#define HWC_IO_LOAD(regInfo, reg, val) \
GDBG_INFO(120, "%s:  Storing 0x%x to IO Register %s\n", \
((SstIORegs *) regInfo.ioMemBase)->


#endif                          /* FXHWC_H not defined */
