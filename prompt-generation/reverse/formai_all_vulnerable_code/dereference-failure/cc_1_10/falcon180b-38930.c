//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024
#define MAX_PID_LENGTH 6

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
} process_t;

void add_process(process_t *processes, int count, const char *command) {
    if (count >= MAX_PROCESSES) {
        printf("Error: Too many processes\n");
        return;
    }

    int pid = fork();

    if (pid == -1) {
        printf("Error: Fork failed\n");
        return;
    } else if (pid == 0) {
        char *argv[3];
        argv[0] = strdup(command);
        argv[1] = NULL;
        execvp(argv[0], argv);
        printf("Error: Execvp failed\n");
        exit(1);
    } else {
        processes[count].pid = pid;
        strncpy(processes[count].command, command, MAX_COMMAND_LENGTH);
        processes[count].command[MAX_COMMAND_LENGTH - 1] = '\0';
        processes[count].status = 0;
    }

    count++;
}

void remove_process(process_t *processes, int count, int pid) {
    for (int i = 0; i < count; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = 1;
            break;
        }
    }
}

void print_processes(process_t *processes, int count) {
    printf("PID\tCommand\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d\t%-16s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int count = 0;

    add_process(processes, count, "ls");
    add_process(processes, count, "sleep 10");

    print_processes(processes, count);

    while (1) {
        int status;
        int pid = wait(&status);

        if (pid == -1) {
            printf("Error: Wait failed\n");
            break;
        }

        for (int i = 0; i < count; i++) {
            if (processes[i].pid == pid) {
                printf("Process %d exited with status %d\n", pid, status);
                remove_process(processes, count, pid);
                break;
            }
        }
    }

    return 0;
}