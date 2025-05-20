//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    char *cmd_name;
    char *cmd_args[MAX_ARGS];
    int status;

    while (1) {
        printf("Brave System Administrator, what command would you like to execute? ");
        fgets(cmd_name, MAX_CMD_LENGTH, stdin);
        cmd_name[strcspn(cmd_name, "\n")] = 0; // trim newline

        // parse command arguments
        char *arg_ptr = cmd_name;
        int argc = 0;
        while (*arg_ptr != 0) {
            if (*arg_ptr == ' ') {
                arg_ptr++;
                continue;
            }
            cmd_args[argc++] = arg_ptr;
            arg_ptr = strchr(arg_ptr, ' ');
            if (arg_ptr != NULL) {
                *arg_ptr = 0; // trim whitespace
            }
        }

        // execute the command
        if (execvp(cmd_name, cmd_args) == -1) {
            perror("execvp");
            exit(1);
        }

        // wait for the command to complete
        wait(&status);
    }

    return 0;
}