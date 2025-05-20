//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1000

typedef struct process {
    int pid;
    char name[16];
    int ram_usage;
} Process;

void get_processes(Process *processes) {
    FILE *fp = fopen("/proc/self/task", "r");
    char line[128];
    int count = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_PROCESSES) {
            break;
        }

        int pid = atoi(line);
        Process process;

        sprintf(process.name, "Process %d", pid);
        process.pid = pid;
        process.ram_usage = 0;

        strcat(process.name, ":");
        processes[count++] = process;
    }

    fclose(fp);
}

void update_ram_usage(Process *processes) {
    FILE *fp;
    char filename[16];

    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].pid == 0) {
            break;
        }

        sprintf(filename, "/proc/%d/status", processes[i].pid);
        fp = fopen(filename, "r");

        char line[128];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            if (strstr(line, "VmSize")!= NULL) {
                processes[i].ram_usage = atoi(line) / 1024;
                break;
            }
        }

        fclose(fp);
    }
}

void print_processes(Process *processes) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].pid == 0) {
            break;
        }

        printf("%-16s %d KB\n", processes[i].name, processes[i].ram_usage);
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    get_processes(processes);
    update_ram_usage(processes);
    print_processes(processes);

    return 0;
}