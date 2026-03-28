#ifndef ERROR_H
#define ERROR_H

/* Report a failed command */
void error_command_failed(const char *cmd, int ret);

/* Generic error helper */
void error_msg(const char *msg);

#endif
