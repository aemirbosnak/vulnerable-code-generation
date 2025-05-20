//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    struct command *current_command = NULL;

    while (1) {
        printf("$ ");
        fgets(command_buffer, MAX_COMMAND_LENGTH, stdin);
        command_buffer[strcspn(command_buffer, "\n")] = 0; // trim newline

        if (current_command != NULL) {
            // handle multiple commands
            if (strcmp(current_command->name, command_buffer) == 0) {
                // command is a continuation of the current command
                char *arg = current_command->args[0];
                current_command->args[0] = command_buffer;
                current_command->args[1] = arg;
                break;
            } else {
                // command is a new command, start a new structure
                current_command = malloc(sizeof(struct command));
                current_command->name = command_buffer;
                current_command->args[0] = command_buffer;
                current_command->args[1] = NULL;
            }
        } else {
            // start a new command
            current_command = malloc(sizeof(struct command));
            current_command->name = command_buffer;
            current_command->args[0] = command_buffer;
            current_command->args[1] = NULL;
        }
    }

    // execute the last command
    if (current_command != NULL) {
        char **args = current_command->args;
        int status;
        if (execv(current_command->name, args) == -1) {
            perror("execv");
            exit(1);
        }
        wait(&status);
    }

    return 0;
}