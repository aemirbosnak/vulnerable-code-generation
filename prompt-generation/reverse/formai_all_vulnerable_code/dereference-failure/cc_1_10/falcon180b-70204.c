//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memory;
} Process;

int num_processes = 0;
Process *processes = NULL;

int compare_processes(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p2->memory - p1->memory;
}

void update_processes() {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strstr(line, "VmSize")!= NULL) {
            token = strtok(line, ":");
            token = strtok(NULL, ":");
            processes[i].memory = atoi(token) / 1024;
        } else if (strstr(line, "Name")!= NULL) {
            strncpy(processes[i].name, strtok(line, ":"), MAX_PROCESS_NAME_LENGTH);
        }
    }

    fclose(fp);
}

void sort_processes() {
    qsort(processes, num_processes, sizeof(Process), compare_processes);
}

int main() {
    processes = malloc(MAX_PROCESSES * sizeof(Process));
    if (processes == NULL) {
        printf("Error allocating memory for processes\n");
        exit(1);
    }
    num_processes = 0;

    update_processes();
    sort_processes();

    printf("Process\tMemory (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%d\n", processes[i].name, processes[i].memory);
    }

    free(processes);
    return 0;
}