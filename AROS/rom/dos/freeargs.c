/*
    Copyright (C) 1995-1998 AROS - The Amiga Replacement OS
    $Id$

    Desc: Free arguments structure from ReadArgs()
    Lang: english
*/
#include <proto/exec.h>
#include <dos/rdargs.h>
#include "dos_intern.h"

/*****************************************************************************

    NAME */
#include <proto/dos.h>

	AROS_LH1(void, FreeArgs,

/*  SYNOPSIS */
	AROS_LHA(struct RDArgs *, args, D1),

/*  LOCATION */
	struct DosLibrary *, DOSBase, 143, Dos)

/*  FUNCTION
	FreeArgs() will clean up after a call to ReadArgs(). If the
	RDArgs structure was allocated by the system in a call to 
	ReadArgs(), then it will be freed. If however, you allocated
	the RDArgs structure with AllocDosObject(), then you will
	have to free it yourself with FreeDosObject().

    INPUTS
	args		- The data used by ReadArgs(). May be NULL,
			  in which case, FreeArgs() does nothing.

    RESULT
	Some memory will have been returned to the system.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	ReadArgs()

    INTERNALS

    HISTORY
	29-10-95    digulla automatically created from
			    dos_lib.fd and clib/dos_protos.h

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct DosLibrary *,DOSBase)

    if(!args)
	return;

    /* ReadArgs() failed. Clean everything up. */
    if (args->RDA_DAList)
    {
	FreeVec(((struct DAList *)args->RDA_DAList)->ArgBuf);
	FreeVec(((struct DAList *)args->RDA_DAList)->StrBuf);
	FreeVec(((struct DAList *)args->RDA_DAList)->MultVec);
	FreeVec((struct DAList *)args->RDA_DAList);

	/*
	    Why do I put this here. Unless the user has been bad and
	    set RDA_DAList to something other than NULL, then this
	    RDArgs structure was allocated by ReadArgs(), so we can
	    free it. Otherwise the RDArgs was allocated by
	    AllocDosObject(), so we are not allowed to free it.

	    See the original AmigaOS autodoc if you don't believe me
	*/
	FreeVec(args);
    }

    AROS_LIBFUNC_EXIT
} /* FreeArgs */
