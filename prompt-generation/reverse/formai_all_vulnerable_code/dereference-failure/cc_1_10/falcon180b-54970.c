//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_PROCESS_NUM 1024
#define MAX_PROCESS_NAME_LEN 16

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
    int ram_usage;
} Process;

void get_processes(Process *processes) {
    FILE *fp;
    char line[1024];
    char name[MAX_PROCESS_NAME_LEN];
    int pid, ram_usage;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (sscanf(line, "Name:\t%s", name) == 1) {
            sscanf(line, "VmRSS:\t%d", &ram_usage);
            pid = getpid();
            strncpy(processes[pid].name, name, MAX_PROCESS_NAME_LEN);
            processes[pid].ram_usage = ram_usage;
        }
    }

    fclose(fp);
}

int main() {
    Process processes[MAX_PROCESS_NUM];
    int num_processes = 0;
    int i, max_ram_usage = 0;

    get_processes(processes);

    while (1) {
        sleep(1);

        get_processes(processes);

        for (i = 0; i < num_processes; i++) {
            if (processes[i].ram_usage > max_ram_usage) {
                max_ram_usage = processes[i].ram_usage;
            }
        }

        printf("Process\tRAM Usage (KB)\n");
        for (i = 0; i < num_processes; i++) {
            printf("%s\t%d\n", processes[i].name, processes[i].ram_usage / 1024);
        }

        if (max_ram_usage > 0) {
            printf("\nMax RAM Usage: %d KB\n", max_ram_usage);
        }

        fflush(stdout);
    }

    return 0;
}