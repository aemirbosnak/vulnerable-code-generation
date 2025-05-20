//Falcon-180B DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_COMMANDS 10

int main() {
    int num_commands = 0;
    char **commands = malloc(MAX_COMMANDS * sizeof(char*));
    pid_t child_pid;
    int status;

    printf("Welcome to the C System Administration Shell!\n");

    while (1) {
        printf("> ");
        fflush(stdout);
        char input[BUFFER_SIZE];
        fgets(input, BUFFER_SIZE, stdin);
        char *command = strtok(input, "\n");

        if (command == NULL) {
            continue;
        }

        commands[num_commands] = strdup(command);
        num_commands++;

        if (num_commands >= MAX_COMMANDS) {
            printf("Error: Too many commands.\n");
            exit(1);
        }
    }

    for (int i = 0; i < num_commands; i++) {
        child_pid = fork();

        if (child_pid == -1) {
            printf("Error: Fork failed.\n");
            exit(1);
        } else if (child_pid == 0) {
            char *argv[2];
            argv[0] = commands[i];
            argv[1] = NULL;

            execvp(argv[0], argv);

            printf("Error: Command not found.\n");
            exit(1);
        } else {
            waitpid(child_pid, &status, WUNTRACED);
        }
    }

    free(commands);
    return 0;
}