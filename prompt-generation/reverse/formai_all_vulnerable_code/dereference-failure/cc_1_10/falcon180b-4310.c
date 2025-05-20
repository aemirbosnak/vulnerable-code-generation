//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 16

struct process_info {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int cpu_percentage;
};

void get_process_info(struct process_info *process_list, int num_processes) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            token = strtok(line, " ");
            while (token!= NULL) {
                if (i >= num_processes) {
                    break;
                }
                process_list[i].pid = atoi(token);
                process_list[i].cpu_percentage = 0;
                i++;
                token = strtok(NULL, " ");
            }
        }
    }

    fclose(fp);
}

void print_process_info(struct process_info *process_list, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (process_list[i].pid == 0) {
            break;
        }
        printf("PID: %d, Name: %s, CPU Usage: %d%%\n", process_list[i].pid, process_list[i].name, process_list[i].cpu_percentage);
    }
}

int main() {
    int num_processes = 0;
    struct process_info *process_list = malloc(MAX_PROCESSES * sizeof(struct process_info));

    if (process_list == NULL) {
        printf("Error allocating memory for process list\n");
        exit(1);
    }

    while (num_processes < MAX_PROCESSES) {
        get_process_info(process_list, num_processes);
        num_processes++;
    }

    print_process_info(process_list, num_processes);

    free(process_list);

    return 0;
}