//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[16];
    int pid;
    int ram_usage;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    FILE *fp;
    char line[64];
    char *token;

    // Open the process list file
    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open process list file.\n");
        exit(1);
    }

    // Read the process name
    fgets(line, sizeof(line), fp);
    strtok(line, ":");
    strcpy(processes[num_processes].name, line);

    // Read the process ID
    fgets(line, sizeof(line), fp);
    processes[num_processes].pid = atoi(line);

    // Read the process RAM usage
    fgets(line, sizeof(line), fp);
    processes[num_processes].ram_usage = atoi(line);

    // Loop through the rest of the processes
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_processes >= MAX_PROCESSES) {
            printf("Error: Maximum number of processes reached.\n");
            exit(1);
        }

        token = strtok(line, ":");
        strcpy(processes[num_processes].name, token);

        token = strtok(NULL, ":");
        processes[num_processes].pid = atoi(token);

        token = strtok(NULL, ":");
        processes[num_processes].ram_usage = atoi(token);

        num_processes++;
    }

    fclose(fp);

    // Sort the processes by RAM usage
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[j].ram_usage < processes[i].ram_usage) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Print the process list
    printf("Process\tPID\tRAM Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%-16s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].ram_usage);
    }

    return 0;
}