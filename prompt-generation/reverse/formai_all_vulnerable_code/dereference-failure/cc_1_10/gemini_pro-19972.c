//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

// Structure to store process information
typedef struct {
    pid_t pid;           // Process ID
    char name[256];      // Process name
    int cpu_usage;       // CPU usage in percentage
    int mem_usage;       // Memory usage in kilobytes
} ProcessInfo;

// Function to compare two process information structures by CPU usage
int compare_cpu_usage(const void *a, const void *b) {
    ProcessInfo *info1 = (ProcessInfo *)a;
    ProcessInfo *info2 = (ProcessInfo *)b;

    return info2->cpu_usage - info1->cpu_usage;
}

// Function to compare two process information structures by memory usage
int compare_mem_usage(const void *a, const void *b) {
    ProcessInfo *info1 = (ProcessInfo *)a;
    ProcessInfo *info2 = (ProcessInfo *)b;

    return info2->mem_usage - info1->mem_usage;
}

// Function to get process information
void get_process_info(ProcessInfo *info, pid_t pid) {
    char path[256];
    FILE *fp;

    // Get process name
    snprintf(path, sizeof(path), "/proc/%d/comm", pid);
    fp = fopen(path, "r");
    if (fp != NULL) {
        fgets(info->name, sizeof(info->name), fp);
        info->name[strlen(info->name) - 1] = '\0'; // Remove newline character
        fclose(fp);
    }

    // Get CPU usage
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    fp = fopen(path, "r");
    if (fp != NULL) {
        // Skip 13 fields
        for (int i = 0; i < 13; i++) {
            fscanf(fp, " %*s");
        }
        fscanf(fp, " %d", &info->cpu_usage);
        fclose(fp);
    }

    // Get memory usage
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    fp = fopen(path, "r");
    if (fp != NULL) {
        while (fgets(path, sizeof(path), fp) != NULL) {
            if (strstr(path, "VmRSS:") != NULL) {
                sscanf(path, "VmRSS: %d kB", &info->mem_usage);
                break;
            }
        }
        fclose(fp);
    }
}

// Function to print process information
void print_process_info(ProcessInfo *info) {
    printf("%d %s %d%% %d kB\n", info->pid, info->name, info->cpu_usage, info->mem_usage);
}

int main() {
    // Get all process IDs
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Initialize an array to store process information
    int num_processes = 100;
    ProcessInfo *processes = malloc(sizeof(ProcessInfo) * num_processes);
    if (processes == NULL) {
        perror("malloc");
        closedir(dir);
        return EXIT_FAILURE;
    }

    int i = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip entries that are not directories
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        // Get process ID
        pid_t pid = atoi(entry->d_name);

        // Get process information
        get_process_info(&processes[i], pid);

        i++;
        if (i == num_processes) {
            // Reallocate the array to store more processes
            num_processes *= 2;
            processes = realloc(processes, sizeof(ProcessInfo) * num_processes);
            if (processes == NULL) {
                perror("realloc");
                closedir(dir);
                return EXIT_FAILURE;
            }
        }
    }
    closedir(dir);

    // Sort processes by CPU usage
    qsort(processes, i, sizeof(ProcessInfo), compare_cpu_usage);

    // Print process information
    printf("Process Information (Sorted by CPU Usage):\n");
    for (int j = 0; j < i; j++) {
        print_process_info(&processes[j]);
    }

    // Sort processes by memory usage
    qsort(processes, i, sizeof(ProcessInfo), compare_mem_usage);

    // Print process information
    printf("\nProcess Information (Sorted by Memory Usage):\n");
    for (int j = 0; j < i; j++) {
        print_process_info(&processes[j]);
    }

    // Free the allocated memory
    free(processes);

    return EXIT_SUCCESS;
}