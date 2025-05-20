//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memory_usage;
} process_t;

int main() {
    process_t *processes = (process_t*) malloc(MAX_PROCESSES * sizeof(process_t));
    int num_processes = 0;
    int total_memory_usage = 0;

    FILE *fp = popen("ps -eo pid,comm=", "r");
    if (fp == NULL) {
        printf("Error executing ps command.\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int pid = atoi(line);
        char *name = strtok(line, " ");
        int memory_usage = 0;

        if (num_processes >= MAX_PROCESSES) {
            printf("Reached maximum number of processes (%d).\n", MAX_PROCESSES);
            break;
        }

        processes[num_processes].pid = pid;
        strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LENGTH - 1);
        processes[num_processes].name[MAX_PROCESS_NAME_LENGTH - 1] = '\0';

        num_processes++;
        total_memory_usage += memory_usage;
    }

    pclose(fp);

    printf("Processes:\n");
    printf("----------------------------------------------------\n");
    printf("| PID | Name | Memory Usage (KB) |\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < num_processes; i++) {
        int memory_usage = processes[i].memory_usage;
        if (memory_usage == 0) {
            memory_usage = 1;
        }

        printf("| %6d | %-20s | %10d |\n", processes[i].pid, processes[i].name, memory_usage);
        total_memory_usage += memory_usage;
    }

    printf("\nTotal memory usage: %d KB\n", total_memory_usage);

    free(processes);
    return 0;
}