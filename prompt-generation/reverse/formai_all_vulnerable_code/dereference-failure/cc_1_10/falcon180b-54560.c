//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} Process;

void add_process(Process *processes, int num_processes, int pid, char *command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
    processes[num_processes].pid = pid;
    num_processes++;
}

void print_processes(Process *processes, int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    FILE *fp = popen("ps -ef", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute ps command.\n");
        return 1;
    }

    char line[MAX_COMMAND_LENGTH];
    while (fgets(line, MAX_COMMAND_LENGTH, fp)!= NULL) {
        char *token = strtok(line, " ");
        int pid = atoi(token);

        token = strtok(NULL, " ");
        while (token!= NULL) {
            add_process(processes, num_processes, pid, token);
            token = strtok(NULL, " ");
        }
    }

    pclose(fp);

    print_processes(processes, num_processes);

    return 0;
}