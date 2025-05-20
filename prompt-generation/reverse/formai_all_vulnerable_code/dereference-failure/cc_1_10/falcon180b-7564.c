//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESS_NAME_LENGTH 16

struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    char process_name[MAX_PROCESS_NAME_LENGTH];
    int status;
};

void get_process_info(struct process *processes, int num_processes) {
    FILE *fp;
    char line[MAX_COMMAND_LENGTH];
    char *token;
    int i = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, MAX_COMMAND_LENGTH, fp)!= NULL) {
        if (i >= num_processes) {
            break;
        }

        token = strtok(line, ":");
        strcpy(processes[i].command, token);

        token = strtok(NULL, ":");
        strcpy(processes[i].process_name, token);

        processes[i].pid = getpid();
        processes[i].status = 1;

        i++;
    }

    fclose(fp);
}

void print_process_info(struct process *processes, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("PID: %d\n", processes[i].pid);
        printf("Command: %s\n", processes[i].command);
        printf("Process Name: %s\n", processes[i].process_name);
        printf("Status: %d\n\n", processes[i].status);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    get_process_info(processes, MAX_PROCESSES);
    num_processes = MAX_PROCESSES;

    print_process_info(processes, num_processes);

    return 0;
}