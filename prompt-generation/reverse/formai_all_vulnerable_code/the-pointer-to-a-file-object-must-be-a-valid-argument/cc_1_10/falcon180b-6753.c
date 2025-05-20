//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[20];
    int pid;
    int ram_usage;
} Process;

void get_process_info(Process *processes, int num_processes) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = fopen("/proc/self/status", "r");

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        if (token!= NULL && strcmp(token, "VmSize:") == 0) {
            token = strtok(NULL, " ");
            processes[i].ram_usage = atoi(token) / 1024;
            i++;
        }
    }

    fclose(fp);
}

void sort_processes(Process *processes, int num_processes) {
    int i, j;
    Process temp;

    for (i = 0; i < num_processes - 1; i++) {
        for (j = i + 1; j < num_processes; j++) {
            if (processes[i].ram_usage < processes[j].ram_usage) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    get_process_info(processes, MAX_PROCESSES);
    num_processes = sizeof(processes) / sizeof(Process);

    printf("Process\tPID\tRAM Usage (KB)\n");
    sort_processes(processes, num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].ram_usage);
    }

    return 0;
}