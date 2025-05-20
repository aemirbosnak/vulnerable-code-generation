//Falcon-180B DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMANDS 100
#define BUFFER_SIZE 1024

typedef struct {
    char **args;
    int num_args;
    pid_t pid;
} Command;

int main() {
    int num_commands = 0;
    Command *commands = malloc(MAX_COMMANDS * sizeof(Command));

    while (num_commands < MAX_COMMANDS) {
        printf("Enter command (%d/%d): ", num_commands + 1, MAX_COMMANDS);
        fgets(commands[num_commands].args[0] = malloc(BUFFER_SIZE), BUFFER_SIZE, stdin);
        commands[num_commands].num_args = 1;
        char *token = strtok(commands[num_commands].args[0], " ");
        while (token!= NULL) {
            commands[num_commands].args[++commands[num_commands].num_args] = strdup(token);
            token = strtok(NULL, " ");
        }
        num_commands++;
    }

    for (int i = 0; i < num_commands; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            printf("Fork failed: %s\n", strerror(errno));
            continue;
        } else if (pid == 0) {
            execvp(commands[i].args[0], commands[i].args);
            printf("Exec failed: %s\n", strerror(errno));
            exit(1);
        } else {
            commands[i].pid = pid;
        }
    }

    for (int i = 0; i < num_commands; i++) {
        int status;
        waitpid(commands[i].pid, &status, 0);
        printf("Command %d completed with status %d\n", i + 1, WEXITSTATUS(status));
    }

    for (int i = 0; i < num_commands; i++) {
        for (int j = 0; j < commands[i].num_args; j++) {
            free(commands[i].args[j]);
        }
        free(commands[i].args[0]);
        free(commands[i].args);
    }
    free(commands);

    return 0;
}