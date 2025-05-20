//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

#define MAX_PROCESSES 1024
#define MAX_NAME_LEN 16

typedef struct {
    char name[MAX_NAME_LEN];
    pid_t pid;
    int priority;
    int status;
    float cpu_usage;
} Process;

void get_process_info(Process *processes, int count) {
    char proc_file_path[MAX_NAME_LEN];
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    for (i = 0; i < count; i++) {
        sprintf(proc_file_path, "/proc/%d/stat", processes[i].pid);
        fp = fopen(proc_file_path, "r");
        if (fp == NULL) {
            continue;
        }

        fgets(line, sizeof(line), fp);
        fclose(fp);

        token = strtok(line, " ");
        processes[i].name[0] = '\0';
        while (token!= NULL) {
            strncat(processes[i].name, token, MAX_NAME_LEN - strlen(processes[i].name) - 1);
            strcat(processes[i].name, " ");
            token = strtok(NULL, " ");
        }
        processes[i].name[strlen(processes[i].name) - 1] = '\0';
    }
}

void get_cpu_usage(Process *processes, int count) {
    struct rusage usage;
    int i;

    for (i = 0; i < count; i++) {
        if (getrusage(RUSAGE_SELF, &usage)!= -1) {
            processes[i].cpu_usage = (float)usage.ru_utime.tv_sec + (float)usage.ru_utime.tv_usec / 1000000;
        }
    }
}

void print_processes(Process *processes, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%-16s %-6d %-6d %-10.2f%%\n", processes[i].name, processes[i].pid, processes[i].priority, processes[i].cpu_usage);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int count = 0;
    int max_processes = sysconf(_SC_CHILD_MAX);

    if (max_processes > MAX_PROCESSES) {
        max_processes = MAX_PROCESSES;
    }

    get_process_info(processes, max_processes);
    get_cpu_usage(processes, max_processes);
    print_processes(processes, max_processes);

    return 0;
}