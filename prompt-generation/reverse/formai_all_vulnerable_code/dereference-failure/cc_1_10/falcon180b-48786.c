//Falcon-180B DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

void execute_command(char *command) {
    pid_t pid;
    int status;
    char *argv[MAX_ARGUMENTS];
    int argc = 0;

    argv[argc++] = strtok(command, " ");
    while ((argv[argc] = strtok(NULL, " "))!= NULL) {
        argc++;
    }

    switch (pid = fork()) {
        case -1: {
            printf("Error forking process.\n");
            exit(1);
        }
        case 0: {
            execvp(argv[0], argv);
            printf("Error executing '%s'.\n", argv[0]);
            exit(1);
        }
        default: {
            waitpid(pid, &status, 0);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    execute_command(command);

    return 0;
}