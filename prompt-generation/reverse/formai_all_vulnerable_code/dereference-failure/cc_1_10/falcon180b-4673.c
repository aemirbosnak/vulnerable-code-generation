//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct {
    pid_t pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int mem_usage;
} process_t;

int compare_processes_by_mem_usage(const void *a, const void *b) {
    const process_t *process_a = a;
    const process_t *process_b = b;

    if (process_a->mem_usage > process_b->mem_usage) {
        return -1;
    } else if (process_a->mem_usage < process_b->mem_usage) {
        return 1;
    }

    return 0;
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;
    FILE *fp;
    char line[1024];
    char *token;
    int i;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        if (strcmp(token, "VmSize:") == 0) {
            token = strtok(NULL, " ");
            processes[num_processes].mem_usage = atoi(token) * 1024;
            processes[num_processes].pid = getpid();
            strncpy(processes[num_processes].name, "main", MAX_PROCESS_NAME_LENGTH);
            num_processes++;
        }
    }

    fclose(fp);

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/stat\n");
        exit(1);
    }

    fgets(line, sizeof(line), fp);
    sscanf(line, "cpu %d %d %d %d", &processes[0].mem_usage, &processes[0].mem_usage, &processes[0].mem_usage, &processes[0].mem_usage);

    fclose(fp);

    qsort(processes, num_processes, sizeof(process_t), compare_processes_by_mem_usage);

    printf("Process\tPID\tMemory Usage (KB)\n");
    for (i = 0; i < num_processes; i++) {
        printf("%-16s\t%5d\t%8d\n", processes[i].name, processes[i].pid, processes[i].mem_usage / 1024);
    }

    return 0;
}