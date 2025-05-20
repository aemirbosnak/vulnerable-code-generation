//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(void) {
    char *command_buffer = malloc(MAX_COMMAND_LENGTH);
    char *current_arg = command_buffer;
    struct command *cmd;

    while (1) {
        printf("$ ");
        fgets(command_buffer, MAX_COMMAND_LENGTH, stdin);
        command_buffer[strcspn(command_buffer, "\n")] = 0;

        if (*command_buffer == '\0') {
            continue;
        }

        cmd = malloc(sizeof(struct command));
        cmd->name = command_buffer;

        // Parse command arguments
        char *arg = strtok(command_buffer, " ");
        int i = 0;
        while (arg != NULL && i < MAX_ARGS) {
            cmd->args[i++] = arg;
            arg = strtok(NULL, " ");
        }

        // Execute command
        if (execvp(cmd->name, cmd->args) == -1) {
            perror("execvp");
            free(cmd);
            continue;
        }

        // Wait for command to finish
        wait(NULL);

        free(cmd);
    }

    return 0;
}