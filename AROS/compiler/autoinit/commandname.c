#include <exec/tasks.h>
#include <proto/exec.h>

#include "autoinit_intern.h"

char *__get_command_name()
{
    struct Task *me = FindTask(NULL);

    /*
     * TODO:
     * In AROS task's name always corresponds to command name.
     * However at least on AmigaOS v3 this is not true for CLI
     * proceses. In this case process name is still 'Shell process',
     * and command name is placed in cli_CommandName
     * P.S. I may remember something wrong - Pavel Fedin
     */
    return me->tc_Node.ln_Name;
}
