//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1024

typedef struct process_info {
    int pid;
    char name[64];
    int cpu_usage;
    int memory_usage;
} ProcessInfo;

int main() {
    ProcessInfo *processes = malloc(MAX_PROCESSES * sizeof(ProcessInfo));
    int num_processes = 0;

    while (1) {
        printf("\nSystem Process Viewer\n");
        printf("======================\n");
        printf("Press 'q' to quit\n");

        // Get the number of active processes
        FILE *fp;
        char filename[64] = "/proc/self/task";
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error opening task file\n");
            exit(1);
        }
        char line[256];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            num_processes++;
        }
        fclose(fp);

        if (num_processes > MAX_PROCESSES) {
            printf("Maximum number of processes reached\n");
            break;
        }

        // Get process information
        int i;
        for (i = 0; i < num_processes; i++) {
            sprintf(filename, "/proc/%d/stat", i);
            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("Error opening stat file\n");
                exit(1);
            }
            fscanf(fp, "%d %s %d %d", &processes[i].pid, processes[i].name, &processes[i].cpu_usage, &processes[i].memory_usage);
            fclose(fp);
        }

        // Display process information
        printf("\nProcess ID\tName\tCPU Usage\tMemory Usage\n");
        for (i = 0; i < num_processes; i++) {
            printf("%d\t%s\t%d\t%d\n", processes[i].pid, processes[i].name, processes[i].cpu_usage, processes[i].memory_usage);
        }
    }

    free(processes);
    return 0;
}