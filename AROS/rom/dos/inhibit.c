/*
    (C) 2000 AROS - The Amiga Research OS
    $Id$

    Desc:
    Lang: English
*/

#include "dos_intern.h"

/*****************************************************************************

    NAME */
#include <proto/dos.h>

	AROS_LH2(LONG, Inhibit,

/*  SYNOPSIS */
	AROS_LHA(STRPTR, name, D1),
	AROS_LHA(LONG  , onoff, D2),

/*  LOCATION */
	struct DosLibrary *, DOSBase, 121, Dos)

/*  FUNCTION

    Stop a filesystem from being used.

    INPUTS

    name   --  Name of the device to inhibit (including a ':')
    onoff  --  Specify whether to inhinit (DOSTRUE) or uninhibit (DOSFALSE)
               the device

    RESULT

    A boolean telling whether the action was carried out.

    NOTES

    After uninhibiting a device anything might have happened like the disk
    in the drive was removed.

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY
         
    26.03.2000  --  SDuvan  implemented

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct DosLibrary *, DOSBase)

    struct IOFileSys iofs;

    InitIOFS(&iofs, FSA_INHIBIT, DOSBase);

    iofs.IOFS.io_Device = GetDevice(name, &iofs.IOFS.io_Unit, DOSBase);

    if(iofs.IOFS.io_Device == NULL)
	return DOSFALSE;

    iofs.io_Union.io_INHIBIT.io_Inhibit = onoff == DOSTRUE ? TRUE : FALSE;

    DoIO(&iofs.IOFS);

    return iofs.io_DosError == 0 ? DOSTRUE : DOSFALSE;

    AROS_LIBFUNC_EXIT
} /* Inhibit */
