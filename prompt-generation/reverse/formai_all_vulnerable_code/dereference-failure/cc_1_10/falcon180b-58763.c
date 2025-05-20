//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct process {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int ram_usage;
} Process;

void get_processes(Process* processes, int* num_processes) {
    FILE* file = fopen("/proc/self/status", "r");
    char line[1024];
    char* token = NULL;
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (i >= MAX_PROCESSES) {
            break;
        }

        token = strtok(line, ":");
        strcpy(processes[i].name, token);

        token = strtok(NULL, ":");
        processes[i].pid = atoi(token);

        token = strtok(NULL, ":");
        processes[i].ram_usage = atoi(token);

        i++;
    }

    fclose(file);

    *num_processes = i;
}

int main(int argc, char* argv[]) {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];

    get_processes(processes, &num_processes);

    printf("Process Name\tPID\tRAM Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].ram_usage);
    }

    return 0;
}