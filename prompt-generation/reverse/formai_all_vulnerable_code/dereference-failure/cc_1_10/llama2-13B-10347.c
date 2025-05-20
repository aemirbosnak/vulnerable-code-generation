//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    char *cmd_buf = malloc(MAX_CMD_LENGTH);
    struct command *cmd = malloc(sizeof(struct command));

    while (1) {
        printf("$ ");
        fgets(cmd_buf, MAX_CMD_LENGTH, stdin);
        cmd_buf[strcspn(cmd_buf, "\n")] = 0;

        // Parse command and arguments
        char *token = strtok(cmd_buf, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS) {
            cmd->args[i++] = token;
            token = strtok(NULL, " ");
        }

        // Execute command
        if (cmd->name[0] == '.' && cmd->name[1] == 'x') {
            // Execute external command
            int status;
            if (execv(cmd->name, cmd->args) == -1) {
                perror("execv");
                exit(1);
            }
            wait(&status);
        } else {
            // Execute internal command
            int ret = system(cmd->name);
            if (ret == -1) {
                perror("system");
                exit(1);
            }
        }
    }

    return 0;
}