#ifndef PCIMOCK_INTERN_H
#define PCIMOCK_INTERN_H

#include <exec/types.h>
#include <exec/libraries.h>
#include <oop/oop.h>

#include LC_LIBDEFS_FILE

struct staticdata
{
    OOP_Class       *driverClass;
    OOP_Class       *irqMockClass;
    OOP_Class       *pciMockHardwareClass;
    OOP_Class       *NV44AMockHardwareClass;
    OOP_Class       *NVG86MockHardwareClass;
    OOP_Class       *NVGTS250MockHardwareClass;
    OOP_Class       *NVGF100MockHardwareClass;
    OOP_AttrBase    hiddPCIDriverAB;
    OOP_AttrBase    hiddAB;
    OOP_AttrBase    hiddPCIMockHardwareAB;
    
    OOP_Object      *mockHardware;
};

LIBBASETYPE
{
    struct Library      Base;
    struct staticdata   sd;
};

#define METHOD(base, id, name) \
  base ## __ ## id ## __ ## name (OOP_Class *cl, OOP_Object *o, struct p ## id ## _ ## name *msg)

#define BASE(lib)                   ((LIBBASETYPEPTR)(lib))

#define SD(cl)                      (&BASE(cl->UserData)->sd)

struct HIDDIRQMockData
{
};

#endif /* PCIMOCK_INTERN_H */

