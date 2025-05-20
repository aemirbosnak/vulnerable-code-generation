//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

// Structure to store process information
typedef struct process {
    pid_t pid;        // Process ID
    char *name;       // Process name
    char *state;      // Process state
    int cpu_time;     // CPU time in milliseconds
    int mem_usage;    // Memory usage in kilobytes
} process_t;

// Function to compare two processes by CPU time
int compare_cpu_time(const void *a, const void *b) {
    process_t *p1 = (process_t *)a;
    process_t *p2 = (process_t *)b;

    return p2->cpu_time - p1->cpu_time;
}

// Function to compare two processes by memory usage
int compare_mem_usage(const void *a, const void *b) {
    process_t *p1 = (process_t *)a;
    process_t *p2 = (process_t *)b;

    return p2->mem_usage - p1->mem_usage;
}

// Function to get process information
process_t *get_process_info(pid_t pid) {
    char path[256];
    FILE *fp;
    char line[1024];
    process_t *process = (process_t *)malloc(sizeof(process_t));

    // Get process name
    snprintf(path, sizeof(path), "/proc/%d/comm", pid);
    fp = fopen(path, "r");
    if (fp == NULL) {
        return NULL;
    }
    fgets(line, sizeof(line), fp);
    fclose(fp);
    process->name = strdup(line);

    // Get process state
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    fp = fopen(path, "r");
    if (fp == NULL) {
        free(process->name);
        return NULL;
    }
    fgets(line, sizeof(line), fp);
    fclose(fp);

    // Parse process state
    char *state = strtok(line, " ");
    process->state = strdup(state + 1);

    // Get CPU time
    char *cpu_time = strtok(NULL, " ");
    process->cpu_time = atoi(cpu_time);

    // Get memory usage
    char *mem_usage = strtok(NULL, " ");
    process->mem_usage = atoi(mem_usage) / 1024;

    return process;
}

// Function to get all processes
process_t **get_all_processes(int *num_processes) {
    DIR *dir;
    struct dirent *entry;
    char path[256];
    process_t **processes = NULL;
    int num = 0;

    // Open /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        return NULL;
    }

    // Iterate over /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a directory
        if (entry->d_type != DT_DIR) {
            continue;
        }

        // Convert entry name to integer
        pid_t pid = atoi(entry->d_name);
        if (pid <= 0) {
            continue;
        }

        // Get process information
        process_t *process = get_process_info(pid);
        if (process == NULL) {
            continue;
        }

        // Add process to array
        processes = (process_t **)realloc(processes, (num + 1) * sizeof(process_t *));
        processes[num++] = process;
    }

    closedir(dir);

    *num_processes = num;
    return processes;
}

// Function to print process information
void print_process_info(process_t *process) {
    printf("%d %s %s %d %d\n", process->pid, process->name, process->state, process->cpu_time, process->mem_usage);
}

// Function to print process statistics
void print_process_statistics(process_t **processes, int num_processes) {
    // Sort processes by CPU time
    qsort(processes, num_processes, sizeof(process_t *), compare_cpu_time);

    // Print CPU time statistics
    printf("Top 10 processes by CPU time:\n");
    for (int i = 0; i < 10 && i < num_processes; i++) {
        print_process_info(processes[i]);
    }

    // Sort processes by memory usage
    qsort(processes, num_processes, sizeof(process_t *), compare_mem_usage);

    // Print memory usage statistics
    printf("Top 10 processes by memory usage:\n");
    for (int i = 0; i < 10 && i < num_processes; i++) {
        print_process_info(processes[i]);
    }
}

int main() {
    int num_processes;
    process_t **processes = get_all_processes(&num_processes);

    if (processes == NULL) {
        printf("Error getting process information\n");
        return 1;
    }

    print_process_statistics(processes, num_processes);

    // Free allocated memory
    for (int i = 0; i < num_processes; i++) {
        free(processes[i]->name);
        free(processes[i]->state);
        free(processes[i]);
    }
    free(processes);

    return 0;
}