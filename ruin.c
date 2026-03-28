#include "ruin.h"
#include "error.h"
#include <stdlib.h>

int run_commands(Command *cmds) {
    for (int i = 0; cmds[i].cmd != NULL; i++) {
        int ret = system(cmds[i].cmd);
        if (ret != 0) {
            error_command_failed(cmds[i].cmd, ret);
            return ret;
        }
    }
    return 0;
}

Runner ruin_runner = {
    .run = run_commands
};
