//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 100

typedef struct process_info {
    char name[MAX_PROCESS_NAME_LENGTH];
    unsigned int pid;
    unsigned long int ram_usage;
} ProcessInfo;

void get_process_info(ProcessInfo* process_info) {
    FILE* fp;
    char line[1024];
    char* token;
    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening /proc/self/status\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ": ");
        if (strcmp(token, "Name") == 0) {
            token = strtok(NULL, ": ");
            strcpy(process_info->name, token);
        } else if (strcmp(token, "Pid") == 0) {
            token = strtok(NULL, ": ");
            process_info->pid = atoi(token);
        } else if (strcmp(token, "VmSize") == 0) {
            token = strtok(NULL, ": ");
            process_info->ram_usage = atoi(token) * 1024;
        }
    }
    fclose(fp);
}

void print_process_info(ProcessInfo* process_info) {
    printf("Process name: %s\n", process_info->name);
    printf("PID: %d\n", process_info->pid);
    printf("RAM usage: %lu bytes\n", process_info->ram_usage);
}

int main() {
    ProcessInfo process_info;
    int num_processes = 0;
    while (num_processes < MAX_PROCESSES) {
        get_process_info(&process_info);
        print_process_info(&process_info);
        num_processes++;
    }
    return 0;
}