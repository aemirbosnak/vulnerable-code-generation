//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t processes[], int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <interval>\n", argv[0]);
        return 1;
    }

    int interval = atoi(argv[1]);
    if (interval <= 0) {
        printf("Invalid interval\n");
        return 1;
    }

    signal(SIGCHLD, SIG_IGN);

    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        for (int i = 0; i < num_processes; i++) {
            if (kill(processes[i].pid, 0) == -1 && errno == ESRCH) {
                // Process has exited, remove it from the list
                for (int j = i; j < num_processes - 1; j++) {
                    processes[j] = processes[j + 1];
                }
                num_processes--;
                i--;
            }
        }

        int status;
        pid_t pid = waitpid(-1, &status, WNOHANG);
        if (pid > 0) {
            // A process has exited, add it to the list
            for (int i = 0; i < num_processes; i++) {
                if (processes[i].pid == 0) {
                    processes[i].pid = pid;
                    sprintf(processes[i].command, "Unknown");
                    break;
                }
            }
            num_processes++;
        }

        if (num_processes == MAX_PROCESSES) {
            printf("Maximum number of processes reached\n");
            break;
        }

        sleep(interval);
    }

    print_processes(processes, num_processes);

    return 0;
}