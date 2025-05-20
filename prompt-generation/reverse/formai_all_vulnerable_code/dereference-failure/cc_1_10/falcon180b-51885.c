//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 100

typedef struct process {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    long int ram_usage;
} Process;

int main() {
    int num_processes = 0;
    Process *processes = malloc(MAX_PROCESSES * sizeof(Process));
    if (processes == NULL) {
        printf("Error: could not allocate memory for processes.\n");
        return 1;
    }
    memset(processes, 0, MAX_PROCESSES * sizeof(Process));

    while (1) {
        num_processes = 0;
        FILE *fp = fopen("/proc/self/status", "r");
        if (fp == NULL) {
            printf("Error: could not open /proc/self/status.\n");
            return 1;
        }

        char line[1000];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            if (strncmp(line, "VmSize:", 7) == 0) {
                char *ptr = &line[7];
                long int ram_usage = strtol(ptr, &ptr, 10);
                if (ptr == &line[7]) {
                    printf("Error: could not parse VmSize from /proc/self/status.\n");
                    return 1;
                }
                if (num_processes >= MAX_PROCESSES) {
                    printf("Error: maximum number of processes reached.\n");
                    return 1;
                }
                strncpy(processes[num_processes].name, "self", MAX_PROCESS_NAME_LENGTH);
                processes[num_processes].pid = getpid();
                processes[num_processes].ram_usage = ram_usage;
                num_processes++;
            }
        }

        fclose(fp);

        printf("Process ID\tProcess Name\tRAM Usage (KB)\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%d\t%s\t%ld\n", processes[i].pid, processes[i].name, processes[i].ram_usage / 1024);
        }

        sleep(5);
    }

    free(processes);
    return 0;
}