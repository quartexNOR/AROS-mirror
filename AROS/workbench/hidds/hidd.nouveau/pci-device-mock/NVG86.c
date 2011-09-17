/*
    Copyright 2011, The AROS Development Team. All rights reserved.
    $Id$
*/

#include <aros/debug.h>
#include <proto/oop.h>

#include "pcimockhardware.h"
#include "pcimockhardware_intern.h"
#include "pcimock_intern.h"

OOP_Object * METHOD(NVG86MockHardware, Root, New)
{
    o = (OOP_Object *)OOP_DoSuperMethod(cl, o, (OOP_Msg)msg);

    GET_PCIMOCKHWDATA
    DEF_NEXTCAPADDR
    
    /* Allocate address space regions */
    ALLOC_ASR(hwdata, PCI_CONFIG_SPACE, 256);
    ALLOC_ASR(hwdata, PCI_BAR0, 0x1000000);
    ALLOC_ASR(hwdata, PCI_BAR1, 0x10000000);
    ALLOC_ASR(hwdata, PCI_BAR3, 0x2000000);
    ALLOC_ASR(hwdata, PCI_ROM, 0x20000);

    /* Fill in pci config space */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x00, 0x042410de); /* PCICS_PRODUCT, PCICS_VENDOR */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x04, 0x00300006); /* PCICS_STATUS, PCICS_COMMAND */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x08, 0x030000a1); /* PCICS_CLASS, PCICS_SUBCLASS, PCICS_PROGIF, PCICS_REVISION */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x0c, 0x00000000); /* PCICS_BIST, PCICS_HEADERTYPE, PCICS_LATENCY, PCICS_CACHELS */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x10, hwdata->Regions[PCI_BAR0].Address); /* PCICS_BAR0 */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x14, hwdata->Regions[PCI_BAR1].Address); /* PCICS_BAR1 */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x1c, hwdata->Regions[PCI_BAR3].Address); /* PCICS_BAR3 */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x2c, 0x81c71043); /* PCICS_SUBSYSTEM, PCICS_SUBVENDOR */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x30, hwdata->Regions[PCI_ROM].Address); /* PCICS_EXPROM_BASE */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x34, 0x00000080); /* PCICS_CAP_PTR */
    SET_ASR_DWORD(hwdata, PCI_CONFIG_SPACE, 0x3c, 0x0000010b); /* PCICS_INT_PIN, PCICS_INT_LINE */

    /* Capabilities */
    ADD_PCI_CAP(hwdata, 0x10); /* CAPABILITY: PCICAP_PCIE */
    ADD_PCI_CAP(hwdata, 0xff); /* CAPABILITY: END */

    /* Fill in BAR 0 */
    SET_ASR_DWORD(hwdata, PCI_BAR0, 0x00000000, 0x086000a1); /* NV03_PMC_BOOT_0 */
    SET_ASR_DWORD(hwdata, PCI_BAR0, 0x0010020c, 0x10000000); /* NV04_PFB_FIFO_DATA */
    SET_ASR_DWORD(hwdata, PCI_BAR0, 0x00100200, 0x00000000); /* r0 */
    SET_ASR_DWORD(hwdata, PCI_BAR0, 0x00100204, 0x01086000); /* r4 */
    SET_ASR_DWORD(hwdata, PCI_BAR0, 0x00100250, 0x00000000); /* rt */
    SET_ASR_DWORD(hwdata, PCI_BAR0, 0x00001540, 0x00010000); /* ru */

    return o;
}

