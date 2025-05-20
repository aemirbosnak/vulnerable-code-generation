//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        printf("$ ");
        fgets(cmd_name, MAX_CMD_LENGTH, stdin);
        cmd_name[strcspn(cmd_name, "\n")] = 0;

        if (cmd_name[0] == '\0') {
            continue;
        }

        // Tokenize the command name and arguments
        char *token = strtok(cmd_name, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS) {
            cmd_args[i++] = token;
            token = strtok(NULL, " ");
        }

        // Execute the command
        if (execvp(cmd_name, cmd_args) == -1) {
            perror("execvp");
            continue;
        }

        // Wait for the command to complete
        wait(&status);

        // Print the command status
        if (WIFEXITED(status)) {
            printf("Command %s exited with status %d\n", cmd_name, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Command %s terminated with signal %d\n", cmd_name, WTERMSIG(status));
        } else {
            printf("Command %s terminated with status %d\n", cmd_name, status);
        }
    }

    return 0;
}