//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int ram_usage;
} Process;

void get_processes(Process* processes, int* num_processes) {
    FILE* file = fopen("/proc/self/status", "r");
    char line[100];
    int i = 0;

    *num_processes = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strcpy(processes[i].name, line + 6);
        } else if (strncmp(line, "VmSize:", 8) == 0) {
            processes[i].ram_usage = atoi(line + 8) / 1024;
        }

        i++;
        if (i >= MAX_PROCESSES) {
            break;
        }
    }

    fclose(file);
}

void sort_by_ram_usage(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[i].ram_usage < processes[j].ram_usage) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void print_processes(Process* processes, int num_processes) {
    printf("Process ID\tName\tRAM Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    get_processes(processes, &num_processes);
    sort_by_ram_usage(processes, num_processes);
    print_processes(processes, num_processes);

    return 0;
}