//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_PROCESSES 50
#define MAX_COMMAND_LENGTH 1024
#define DELAY 3

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

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    signal(SIGCHLD, SIG_IGN);

    while (1) {
        print_processes(processes, num_processes);

        char input[MAX_COMMAND_LENGTH];
        printf("Enter command to run: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (num_processes >= MAX_PROCESSES) {
            printf("Maximum number of processes reached.\n");
            continue;
        }

        pid_t pid = fork();
        if (pid == -1) {
            printf("Fork failed: %s\n", strerror(errno));
            continue;
        } else if (pid == 0) {
            if (execlp(input, input, NULL) == -1) {
                printf("Execlp failed: %s\n", strerror(errno));
                exit(1);
            }
        } else {
            processes[num_processes].pid = pid;
            strcpy(processes[num_processes].command, input);
            num_processes++;
        }

        wait(NULL);
    }

    return 0;
}