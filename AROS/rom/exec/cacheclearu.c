/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id$

    Desc: CacheClearU - Simple way of clearing the caches.
    Lang: english
*/

#include <exec/types.h>
#include <exec/execbase.h>
#include <aros/libcall.h>

/*****************************************************************************

    NAME */
#include <proto/exec.h>

	AROS_LH0(void, CacheClearU,

/*  LOCATION */
	struct ExecBase *, SysBase, 106, Exec)

/*  FUNCTION
	Flush the entire contents of the CPU instruction and data caches.
	If some of the cache contains dirty data, push it to memory first.

	For most systems DMA will not effect processor caches. If *any*
	external (non-processor) event changes system memory, you MUST
	clear the cache. For example:

	    DMA
	    Code relocation to run at a different address
	    Building jump tables
	    Loading code from disk

    INPUTS

    RESULT
	The caches will be flushed.

    NOTES
	It is possible that on some systems the entire cache will be
	even if this was not the specific request.

    EXAMPLE

    BUGS

    SEE ALSO
	CacheClearE(), CacheControl(), CachePreDMA(), CachePostDMA()

    INTERNALS
	Although it is not necessary, but it could be more efficient if
	this function was replaced by a function in $(KERNEL).

    HISTORY

******************************************************************************/
{
    AROS_LIBFUNC_INIT

    /* Just dump the whole lot */
    CacheClearE(0, 0xFFFFFFFF, CACRF_ClearI | CACRF_ClearD);

    AROS_LIBFUNC_EXIT
} /* CacheClearU */
