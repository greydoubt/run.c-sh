#include "error.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

/* Report failure of a system() command */
void error_command_failed(const char *cmd, int ret) {
    fprintf(stderr, "Error: command failed\n");
    fprintf(stderr, "  cmd: %s\n", cmd);
    fprintf(stderr, "  return code: %d\n", ret);

    if (errno != 0) {
        fprintf(stderr, "  errno: %d (%s)\n", errno, strerror(errno));
    }
}

/* Generic error message */
void error_msg(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);

    if (errno != 0) {
        fprintf(stderr, "  errno: %d (%s)\n", errno, strerror(errno));
    }
}
