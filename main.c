#include "run.h"


const int shared_var = 10;
#include "ruin.h"

void run_commands(Command *cmds) {
    for (int i = 0; cmds[i].cmd != NULL; i++) {
        system(cmds[i].cmd);
    }
}

int main() {
    chdir("lib");

    Command lib_steps[] = {
        {"cc -c -O *.c"},
        {"ar r /lib/liby.a *.o"},
        {"rm *.o"},
        {NULL}
    };

    run_commands(lib_steps);

    chdir("../source");

    Command src_steps[] = {
        {"cc -s -O y?.c"},
        {"cmp a.out /usr/bin/yacc"},
        {"cp a.out /usr/bin/yacc"},
        {"rm a.out *.o"},
        {NULL}
    };

    run_commands(src_steps);

    return 0;
}
