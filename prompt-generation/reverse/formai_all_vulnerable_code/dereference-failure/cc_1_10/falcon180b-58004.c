//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 80

typedef struct {
    pid_t pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int status;
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    char command[80] = "ps -ax";
    FILE *fp;
    char line[MAX_PROCESS_NAME_LENGTH];
    char *token;
    int status;

    // Get the list of processes
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: Failed to execute command.\n");
        exit(1);
    }

    while (fgets(line, MAX_PROCESS_NAME_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");
        processes[num_processes].pid = atoi(token);
        token = strtok(NULL, " ");
        strncpy(processes[num_processes].name, token, MAX_PROCESS_NAME_LENGTH - 1);
        processes[num_processes].name[MAX_PROCESS_NAME_LENGTH - 1] = '\0';
        num_processes++;
    }

    pclose(fp);

    // Print the list of processes
    print_processes(processes, num_processes);

    // Monitor the processes
    while (1) {
        sleep(1);
        for (int i = 0; i < num_processes; i++) {
            if (kill(processes[i].pid, 0) == -1) {
                // Process no longer exists
                processes[i].status = -1;
            } else {
                // Process is still running
                processes[i].status = 0;
            }
        }
        print_processes(processes, num_processes);
    }

    return 0;
}