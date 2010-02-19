/*
    Copyright � 1995-2010, The AROS Development Team. All rights reserved.
    $Id$

    Desc:
    Lang: english
*/

#include <hidd/graphics.h>

#include "cybergraphics_intern.h"

/*****************************************************************************

    NAME */
#include <clib/cybergraphics_protos.h>

	AROS_LH1(void, UnLockBitMap,

/*  SYNOPSIS */
	AROS_LHA(APTR, Handle, A0),

/*  LOCATION */
	struct Library *, CyberGfxBase, 29, Cybergraphics)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY
	27-11-96    digulla automatically created from
			    cybergraphics_lib.fd and clib/cybergraphics_protos.h

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    
    if (Handle)
        HIDD_BM_ReleaseDirectAccess((OOP_Object *)Handle);

    AROS_LIBFUNC_EXIT
} /* UnLockBitMap */
