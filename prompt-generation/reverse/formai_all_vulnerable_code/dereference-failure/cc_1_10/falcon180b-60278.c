//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

struct process_info {
    int pid;
    char name[16];
    float cpu_usage;
};

void get_process_info(struct process_info *processes, int num_processes) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Cannot open /proc/stat.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= num_processes) {
            break;
        }

        token = strtok(line, " ");
        sscanf(token, "%d", &processes[i].pid);

        token = strtok(NULL, " ");
        strncpy(processes[i].name, token, sizeof(processes[i].name) - 1);

        processes[i].cpu_usage = 0.0;
        i++;
    }

    fclose(fp);
}

void print_process_info(struct process_info *processes, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == 0) {
            continue;
        }

        printf("%-5d %-16s %-10.2f%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }
}

int main(int argc, char *argv[]) {
    int i, num_processes = 0;
    struct process_info processes[MAX_PROCESSES];

    if (argc > 1) {
        num_processes = atoi(argv[1]);
    }

    if (num_processes > MAX_PROCESSES) {
        printf("Error: Number of processes cannot exceed %d.\n", MAX_PROCESSES);
        exit(1);
    }

    get_process_info(processes, num_processes);

    while (1) {
        sleep(1);
        get_process_info(processes, num_processes);
        print_process_info(processes, num_processes);
    }

    return 0;
}