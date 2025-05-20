//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define MAX_NUM_PROCESSES 100

typedef struct {
    int pid;
    char name[16];
    int ram_usage;
} Process;

void read_processes(Process* processes) {
    FILE* file = fopen("/proc/self/status", "r");
    char line[100];
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (i >= MAX_NUM_PROCESSES) {
            break;
        }

        char* token = strtok(line, " ");
        while (token!= NULL) {
            if (strcmp(token, "VmSize:") == 0) {
                token = strtok(NULL, " ");
                processes[i].ram_usage = atoi(token) / 1024;
            }
            token = strtok(NULL, " ");
        }
        i++;
    }

    fclose(file);
}

void sort_processes(Process* processes) {
    for (int i = 0; i < MAX_NUM_PROCESSES - 1; i++) {
        for (int j = i + 1; j < MAX_NUM_PROCESSES; j++) {
            if (processes[j].ram_usage > processes[i].ram_usage) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    Process processes[MAX_NUM_PROCESSES];

    read_processes(processes);
    sort_processes(processes);

    printf("Process\tRAM Usage (KB)\n");
    for (int i = 0; i < MAX_NUM_PROCESSES; i++) {
        printf("%s\t%d\n", processes[i].name, processes[i].ram_usage);
    }

    return 0;
}