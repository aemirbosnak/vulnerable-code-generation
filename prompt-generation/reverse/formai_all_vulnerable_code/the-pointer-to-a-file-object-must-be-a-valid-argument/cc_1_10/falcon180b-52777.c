//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

typedef struct process_info {
    int pid;
    char name[20];
    float cpu_usage;
    float memory_usage;
} ProcessInfo;

void get_process_info(ProcessInfo *process_info) {
    char proc_path[20];
    sprintf(proc_path, "/proc/%d", process_info->pid);
    FILE *fp = fopen(proc_path, "r");
    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strcpy(process_info->name, line + 6);
        } else if (strncmp(line, "CPU:", 4) == 0) {
            sscanf(line, "CPU: %f", &process_info->cpu_usage);
        } else if (strncmp(line, "Mem:", 4) == 0) {
            sscanf(line, "Mem: %f", &process_info->memory_usage);
        }
    }
    fclose(fp);
}

void display_process_info(ProcessInfo *process_info) {
    printf("PID: %d\n", process_info->pid);
    printf("Name: %s\n", process_info->name);
    printf("CPU Usage: %.2f%%\n", process_info->cpu_usage);
    printf("Memory Usage: %.2f%%\n\n", process_info->memory_usage);
}

int main() {
    ProcessInfo process_info;
    int proc_count = 0;
    char proc_file[20];
    sprintf(proc_file, "/proc/self/task/%d/children", getpid());
    FILE *fp = fopen(proc_file, "r");
    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        int pid = atoi(line);
        get_process_info(&process_info);
        display_process_info(&process_info);
        proc_count++;
    }
    fclose(fp);
    return 0;
}