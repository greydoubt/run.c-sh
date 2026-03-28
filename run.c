#include <stdlib.h>
#include <unistd.h>

typedef enum {
    STEP_CHDIR,
    STEP_SYSTEM
} StepType;

typedef struct {
    StepType type;
    const char *arg;
} Step;

int main() {
    Step steps[] = {
        {STEP_CHDIR, "lib"},
        {STEP_SYSTEM, "cc -c -O *.c"},
        {STEP_SYSTEM, "ar r /lib/liby.a *.o"},
        {STEP_SYSTEM, "rm *.o"},

        {STEP_CHDIR, "../source"},
        {STEP_SYSTEM, "cc -s -O y?.c"},
        {STEP_SYSTEM, "cmp a.out /usr/bin/yacc"},
        {STEP_SYSTEM, "cp a.out /usr/bin/yacc"},
        {STEP_SYSTEM, "rm a.out *.o"},

        {0, NULL}
    };

    for (int i = 0; steps[i].arg != NULL; i++) {
        if (steps[i].type == STEP_CHDIR) {
            chdir(steps[i].arg);
        } else if (steps[i].type == STEP_SYSTEM) {
            system(steps[i].arg);
        }
    }

    return 0;
}
