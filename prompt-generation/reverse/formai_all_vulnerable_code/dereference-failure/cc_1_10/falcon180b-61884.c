//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024
#define MAX_PATH_LENGTH 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t processes[], int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <process_name>\n", argv[0]);
        return 1;
    }

    char process_name[MAX_COMMAND_LENGTH];
    strcpy(process_name, argv[1]);

    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    FILE *fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/status\n");
        return 1;
    }

    char line[MAX_PATH_LENGTH];
    while (fgets(line, MAX_PATH_LENGTH, fp)!= NULL) {
        if (strstr(line, "Name:")!= NULL) {
            char *name = strtok(line, ":");
            name = strtok(NULL, ":");
            if (strcmp(name, process_name) == 0) {
                pid_t pid = getpid();
                strcpy(processes[num_processes].command, argv[1]);
                processes[num_processes].pid = pid;
                num_processes++;
            }
        }
    }

    fclose(fp);

    if (num_processes == 0) {
        printf("No processes found with name '%s'\n", process_name);
        return 1;
    }

    print_processes(processes, num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Killing process %d\n", processes[i].pid);
        kill(processes[i].pid, SIGKILL);
    }

    return 0;
}