//Falcon-180B DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESSES 10

typedef struct process {
    pid_t pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void add_process(process_t *process) {
    if (num_processes >= MAX_PROCESSES) {
        fprintf(stderr, "Error: Maximum number of processes reached.\n");
        return;
    }

    processes[num_processes++] = *process;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s command [arguments]\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    for (int i = 2; i < argc; i++) {
        strcat(command, " ");
        strcat(command, argv[i]);
    }

    process_t process;
    process.pid = fork();

    if (process.pid == -1) {
        fprintf(stderr, "Error: Failed to fork.\n");
        return 1;
    } else if (process.pid == 0) {
        execlp(command, command, NULL);
        fprintf(stderr, "Error: Failed to execute command.\n");
        return 1;
    }

    add_process(&process);

    int status;
    waitpid(process.pid, &status, 0);

    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == process.pid) {
            processes[i].status = status;
            break;
        }
    }

    printf("Command executed with PID %d and status %d.\n", process.pid, status);

    return 0;
}