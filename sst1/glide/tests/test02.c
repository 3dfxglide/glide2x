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
*/

#include <stdlib.h>
#include <stdio.h>
#ifndef __linux__
#include <conio.h>
#endif
#include <assert.h>
#include <string.h>

#include <glide.h>
#include "tlib.h"


GrHwConfiguration hwconfig;
static char version[80];

static const char name[]    = "test02";
static const char purpose[] = "draws a parabolic envelope of lines";
static const char usage[]   = "-n <frames> -r <res> -d <filename>";

void main( int argc, char **argv) {
    char match; 
    char **remArgs;
    int  rv;

    GrScreenResolution_t resolution = GR_RESOLUTION_640x480;
    float                scrWidth   = 640.0f;
    float                scrHeight  = 480.0f;
    int frames                      = -1;
    FxBool               scrgrab = FXFALSE;
    char                 filename[256];

    /* Process Command Line Arguments */
    while( rv = tlGetOpt( argc, argv, "nrd", &match, &remArgs ) ) {
        if ( rv == -1 ) {
            printf( "Unrecognized command line argument\n" );
            printf( "%s %s\n", name, usage );
            printf( "Available resolutions:\n%s\n",
                    tlGetResolutionList() );
            return;
        }
        switch( match ) {
        case 'n':
            frames = atoi( remArgs[0] );
            break;
        case 'r':
            resolution = tlGetResolutionConstant( remArgs[0], 
                                                  &scrWidth, 
                                                  &scrHeight );
            break;
        case 'd':
            scrgrab = FXTRUE;
            frames = 1;
            strcpy(filename, remArgs[0]);
            break;
        }
    }

    tlSetScreen( scrWidth, scrHeight );

    grGlideGetVersion( version );

    printf( "%s:\n%s\n", name, purpose );
    printf( "%s\n", version );
    printf( "Resolution: %s\n", tlGetResolutionString( resolution ) );
    if ( frames == -1 ) {
        printf( "Press A Key To Begin Test.\n" );
        tlGetCH();
    }
    
    /* Initialize Glide */
    grGlideInit();
    assert( grSstQueryHardware( &hwconfig ) );
    grSstSelect( 0 );
    assert( grSstWinOpen( 0,
                      resolution,
                      GR_REFRESH_60Hz,
                      GR_COLORFORMAT_ABGR,
                      GR_ORIGIN_UPPER_LEFT,
                      2, 1) );
    
    tlConSet( 0.0f, 0.0f, 1.0f, 1.0f, 
              60, 30, 0xff0000 );

    /* Set up Render State - flat shading */
    grColorCombine( GR_COMBINE_FUNCTION_LOCAL,
                    GR_COMBINE_FACTOR_NONE,
                    GR_COMBINE_LOCAL_CONSTANT,
                    GR_COMBINE_OTHER_NONE,
                    FXFALSE );
    grConstantColorValue( 0xFFFFFF );

    
    tlConOutput( "Press a key to quit\n" );
    while( frames-- && tlOkToRender()) {
        int i;
        GrVertex vtxA, vtxB;

        if (hwconfig.SSTs[0].type == GR_SSTTYPE_SST96) {
          tlGetDimsByConst(resolution, 
                           &scrWidth, 
                           &scrHeight );
        
          grClipWindow(0, 0, (FxU32) scrWidth, (FxU32) scrHeight);
        }

        grBufferClear( 0x00, 0, GR_WDEPTHVALUE_FARTHEST );

        for( i = 0; i < 100; i++ ) {
            float pos = ((float)i)/100.0f;
            
            vtxA.x = tlScaleX( pos ), vtxA.y = tlScaleY( 0.0f );
            vtxB.x = tlScaleX( 1.0f), vtxB.y = tlScaleY( pos );

            grDrawLine( &vtxA, &vtxB );
        }


        tlConRender();
        grBufferSwap( 1 );

        /* grab the frame buffer */
        if (scrgrab) {
          if (!tlScreenDump(filename, (FxU16)scrWidth, (FxU16)scrHeight))
            printf( "Cannot open %s\n", filename);
          scrgrab = FXFALSE;
        }

        if ( tlKbHit() ) frames = 0;
    }
    
    grGlideShutdown();
    return;
}





