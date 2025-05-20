//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_PROCESSES 1000
#define DELAY 5

typedef struct {
    char name[20];
    int pid;
    float cpu_usage;
} process_t;

void get_processes(process_t *processes, int num_processes) {
    FILE *fp;
    char line[100];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= num_processes) {
            break;
        }

        token = strtok(line, " ");
        strcpy(processes[i].name, token);
        processes[i].pid = atoi(token);

        token = strtok(NULL, " ");
        processes[i].cpu_usage = atof(token);

        i++;
    }

    fclose(fp);
}

void print_processes(process_t *processes, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%-20s %-10d %-10.2f\n", processes[i].name, processes[i].pid, processes[i].cpu_usage);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;
    int max_processes_reached = 0;

    while (1) {
        get_processes(processes, MAX_PROCESSES);
        num_processes = 0;

        while (num_processes < MAX_PROCESSES &&!max_processes_reached) {
            if (processes[num_processes].cpu_usage > 0) {
                num_processes++;
            } else {
                max_processes_reached = 1;
            }
        }

        if (max_processes_reached) {
            printf("\nReached maximum number of processes (%d). Exiting...\n", MAX_PROCESSES);
            break;
        }

        print_processes(processes, num_processes);
        sleep(DELAY);
    }

    return 0;
}