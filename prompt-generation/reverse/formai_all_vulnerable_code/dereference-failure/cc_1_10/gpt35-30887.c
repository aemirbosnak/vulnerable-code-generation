//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS_NAME_LEN 256
#define MAX_NUM_PROCESSES 1024
#define MAX_CPU_USAGE_LEN 8
#define INTERVAL 1 // interval in seconds between each sampling period

typedef struct {
    int pid;
    char process_name[MAX_PROCESS_NAME_LEN];
    float cpu_usage;
} process_info;

int get_process_list(process_info *info_list) {
    int num_processes = 0;
    FILE *fp;
    char path[MAX_PROCESS_NAME_LEN];
    char line[MAX_PROCESS_NAME_LEN];
    char *token;

    fp = popen("ps -eo pid,comm,%cpu --sort=-%cpu", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute command.\n");
        return 0;
    }

    // Read process information from the output of ps command
    while (fgets(line, MAX_PROCESS_NAME_LEN, fp) != NULL && num_processes < MAX_NUM_PROCESSES) {
        token = strtok(line, " ");
        info_list[num_processes].pid = atoi(token);

        token = strtok(NULL, " ");
        strcpy(info_list[num_processes].process_name, token);

        token = strtok(NULL, " ");
        info_list[num_processes].cpu_usage = atof(token);

        num_processes++;
    }

    pclose(fp);
    return num_processes;
}

int main() {
    int num_processes;
    process_info info_list[MAX_NUM_PROCESSES];
    int i;
    char cpu_usage_str[MAX_CPU_USAGE_LEN];

    while (1) {
        num_processes = get_process_list(info_list);

        printf("\nCPU Utilization\n");
        printf("----------------------\n");
        for (i = 0; i < num_processes; i++) {
            sprintf(cpu_usage_str, "%.2f%%", info_list[i].cpu_usage);
            printf("%-8d %-20s %s\n", info_list[i].pid, info_list[i].process_name, cpu_usage_str);
        }

        sleep(INTERVAL);
        system("clear");
    }

    return 0;
}