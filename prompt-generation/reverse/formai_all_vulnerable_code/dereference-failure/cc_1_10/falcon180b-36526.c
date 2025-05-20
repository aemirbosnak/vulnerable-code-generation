//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024
#define MAX_PROCESS_NAME_SIZE 64
#define MAX_PROCESS_NAME_COUNT 256

typedef struct process_info {
    int pid;
    char name[MAX_PROCESS_NAME_SIZE];
    int status;
} process_info_t;

void read_processes(process_info_t *processes) {
    char line[MAX_LINE_SIZE];
    FILE *fp = fopen("/proc/self/status", "r");

    if (fp == NULL) {
        fprintf(stderr, "Error opening /proc/self/status: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strncpy(processes[0].name, line + 6, MAX_PROCESS_NAME_SIZE - 1);
            processes[0].name[MAX_PROCESS_NAME_SIZE - 1] = '\0';
        } else if (strncmp(line, "State:", 6) == 0) {
            processes[0].status = atoi(line + 7);
        }
    }

    fclose(fp);
}

void print_processes(process_info_t *processes) {
    printf("Process Name: %s\n", processes[0].name);
    printf("Process ID: %d\n", processes[0].pid);
    printf("Process Status: %s\n", (processes[0].status == 0)? "Running" : "Not Running");
}

int main() {
    process_info_t processes[MAX_PROCESS_NAME_COUNT];
    int num_processes = 0;

    while (num_processes < MAX_PROCESS_NAME_COUNT) {
        read_processes(processes);

        if (processes[0].status == 0) {
            printf("Process %s is running.\n", processes[0].name);
        } else {
            printf("Process %s is not running.\n", processes[0].name);
        }

        num_processes++;
    }

    return 0;
}