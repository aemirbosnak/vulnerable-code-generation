//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[20];
    int pid;
    int mem_usage;
} process_t;

int main() {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    FILE *fp;
    char line[1024];
    char *token;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/status\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");
        if (strcmp(token, "VmSize") == 0) {
            num_processes++;
            if (num_processes >= MAX_PROCESSES) {
                printf("Error: Maximum number of processes reached\n");
                fclose(fp);
                return 2;
            }
            strcpy(processes[num_processes - 1].name, "self");
            processes[num_processes - 1].pid = getpid();
            processes[num_processes - 1].mem_usage = atoi(token + strlen(token) + 1) / 1024;
        }
    }

    fclose(fp);

    while (1) {
        system("clear");
        printf("Process\tPID\tMemory Usage (KB)\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].mem_usage);
        }
        sleep(1);
    }

    return 0;
}