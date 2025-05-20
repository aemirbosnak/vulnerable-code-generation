//Falcon-180B DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_PROCESSES 50

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

int num_processes = 0;
process_t *processes = NULL;

void handle_signal(int signal) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].status == 0) {
            processes[i].status = signal;
            break;
        }
    }
}

void execute_command(char *command) {
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        system(command);
        exit(0);
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        processes[num_processes].status = status;
        num_processes++;
    }
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    processes = malloc(MAX_PROCESSES * sizeof(process_t));
    if (processes == NULL) {
        perror("malloc");
        exit(1);
    }

    while (1) {
        printf("Enter command to execute: ");
        fgets(processes[num_processes].command, MAX_COMMAND_LENGTH, stdin);
        execute_command(processes[num_processes].command);
    }

    return 0;
}