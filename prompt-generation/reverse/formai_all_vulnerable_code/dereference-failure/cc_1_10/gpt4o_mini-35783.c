//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    float cpu_usage;
    float mem_usage;
} ProcessInfo;

void get_process_info(ProcessInfo *processes, int *count);
void print_processes(ProcessInfo *processes, int count);
int compare_cpu(const void *a, const void *b);
int compare_memory(const void *a, const void *b);

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int process_count = 0;

    // Get the current system processes
    get_process_info(processes, &process_count);

    if (process_count > 0) {
        printf("System Process Viewer\n");
        printf("======================\n");
        printf("PID\tName\t\t\tCPU Usage\tMemory Usage\n");
        printf("---------------------------------------------------------------\n");
        print_processes(processes, process_count);

        printf("\nSorting processes by CPU Usage...\n");
        qsort(processes, process_count, sizeof(ProcessInfo), compare_cpu);
        print_processes(processes, process_count);

        printf("\nSorting processes by Memory Usage...\n");
        qsort(processes, process_count, sizeof(ProcessInfo), compare_memory);
        print_processes(processes, process_count);
    } else {
        printf("No processes found.\n");
    }

    return 0;
}

void get_process_info(ProcessInfo *processes, int *count) {
    DIR *dir;
    struct dirent *entry;
    char path[BUFFER_SIZE];
    FILE *file;
    char buffer[BUFFER_SIZE];

    if (!(dir = opendir("/proc"))) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
                file = fopen(path, "r");
                if (file) {
                    fscanf(file, "%d %s", &processes[*count].pid, processes[*count].name);
                    processes[*count].name[strcspn(processes[*count].name, ")")] = 0; // Clean up name
                    fclose(file);

                    // Fake CPU and memory usage for demonstration
                    processes[*count].cpu_usage = (rand() % 100) / 1.0f;  // Random CPU usage
                    processes[*count].mem_usage = (rand() % 1000) / 10.0f; // Random Memory usage
                    (*count)++;
                }
            }
        }
    }

    closedir(dir);
}

void print_processes(ProcessInfo *processes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d\t%-20s\t%.2f%%\t\t%.2fMB\n", 
                processes[i].pid, 
                processes[i].name, 
                processes[i].cpu_usage, 
                processes[i].mem_usage);
    }
}

int compare_cpu(const void *a, const void *b) {
    ProcessInfo *procA = (ProcessInfo *)a;
    ProcessInfo *procB = (ProcessInfo *)b;
    return (procB->cpu_usage - procA->cpu_usage > 0) ? 1 : -1;
}

int compare_memory(const void *a, const void *b) {
    ProcessInfo *procA = (ProcessInfo *)a;
    ProcessInfo *procB = (ProcessInfo *)b;
    return (procB->mem_usage - procA->mem_usage > 0) ? 1 : -1;
}