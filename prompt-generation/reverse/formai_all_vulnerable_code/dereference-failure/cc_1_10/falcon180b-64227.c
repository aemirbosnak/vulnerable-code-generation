//Falcon-180B DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_PROCESSES 10

typedef struct process {
    pid_t pid;
    int status;
    int exit_code;
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void launch_process(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error forking process\n");
        exit(1);
    } else if (pid == 0) {
        int argc = 0;
        char *argv[MAX_ARGUMENTS];
        char *token;

        argv[argc++] = strdup(command);

        token = strtok(NULL, " ");
        while (token!= NULL && argc < MAX_ARGUMENTS) {
            argv[argc++] = strdup(token);
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL;

        execvp(argv[0], argv);
        printf("Error executing command\n");
        exit(1);
    } else {
        processes[num_processes].pid = pid;
        processes[num_processes].status = 0;
        num_processes++;
    }
}

void monitor_processes() {
    int status;
    pid_t pid;

    while (1) {
        pid = waitpid(-1, &status, WNOHANG);

        if (pid == 0) {
            usleep(100000); // Sleep for a short time to reduce CPU usage
            continue;
        }

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid == pid) {
                processes[i].status = status;
                break;
            }
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the funny C system administration program!\n");

    while (1) {
        printf("Enter a command (type 'exit' to quit): ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        launch_process(input);
    }

    monitor_processes();

    return 0;
}