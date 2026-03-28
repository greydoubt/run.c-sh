#ifndef RUIN_H
#define RUIN_H

#include <stdlib.h>
#include <unistd.h>

/* Data structure representing a shell command */
typedef struct {
    const char *cmd;
} Command;

/* Optional helper function */
void run_commands(Command *cmds);

#endif
