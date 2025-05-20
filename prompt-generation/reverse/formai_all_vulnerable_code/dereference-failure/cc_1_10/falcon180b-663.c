//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_LINE_LENGTH 1024

typedef struct {
    pid_t pid;
    char name[MAX_LINE_LENGTH];
    int cpu_usage;
} process_t;

void read_processes(process_t* processes) {
    char line[MAX_LINE_LENGTH];
    FILE* fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/stat\n");
        exit(1);
    }
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            sscanf(line, "cpu %*d %*d %*d %*d %d", &processes->cpu_usage);
            break;
        }
    }
    fclose(fp);
}

void read_process_name(process_t* process, int pid) {
    char path[MAX_LINE_LENGTH];
    snprintf(path, MAX_LINE_LENGTH, "/proc/%d/cmdline", pid);
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        strcpy(process->name, "unknown");
    } else {
        fgets(process->name, MAX_LINE_LENGTH, fp);
        fclose(fp);
        process->name[strcspn(process->name, "\n")] = '\0';
    }
}

int compare_processes(const void* a, const void* b) {
    const process_t* process_a = (const process_t*)a;
    const process_t* process_b = (const process_t*)b;
    return process_b->cpu_usage - process_a->cpu_usage;
}

void print_processes(process_t* processes, int num_processes) {
    qsort(processes, num_processes, sizeof(process_t), compare_processes);
    for (int i = 0; i < num_processes; i++) {
        printf("%-10s %-30s %5d%%\n", processes[i].name, "", processes[i].cpu_usage);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [interval]\n", argv[0]);
        return 1;
    }
    int interval = atoi(argv[1]);
    if (interval <= 0) {
        printf("Error: invalid interval\n");
        return 1;
    }
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;
    while (1) {
        read_processes(processes);
        for (int i = 0; i < MAX_PROCESSES && num_processes < MAX_PROCESSES; i++) {
            if (processes[i].pid > 0) {
                read_process_name(&processes[i], processes[i].pid);
                num_processes++;
            }
        }
        print_processes(processes, num_processes);
        sleep(interval);
    }
    return 0;
}