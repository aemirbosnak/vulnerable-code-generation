//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define MAX_PROCESSES 10

struct process {
    pid_t pid;
    int status;
};

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        // A child process has terminated
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;
    int status;

    signal(SIGCHLD, sigchld_handler);

    while (1) {
        printf("\nEnter command to execute or type 'exit' to quit: ");
        fflush(stdout);
        char command[100];
        fgets(command, sizeof(command), stdin);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == -1) {
            printf("Error forking process: %s\n", strerror(errno));
            continue;
        } else if (pid == 0) {
            // Child process
            execlp(command, command, NULL);
            exit(1);
        } else {
            // Parent process
            if (num_processes >= MAX_PROCESSES) {
                printf("Maximum number of processes reached\n");
                continue;
            }

            processes[num_processes].pid = pid;
            processes[num_processes].status = 0;
            num_processes++;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        waitpid(processes[i].pid, &status, WNOHANG);
        if (status == 0) {
            printf("Process %d is still running\n", processes[i].pid);
        } else {
            printf("Process %d exited with status %d\n", processes[i].pid, status);
        }
    }

    return 0;
}