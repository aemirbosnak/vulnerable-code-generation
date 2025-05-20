//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    pid_t pid;
    char name[BUFFER_SIZE];
    float cpu_usage;
} ProcessInfo;

void get_process_info(ProcessInfo *processes, int *count) {
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;
    *count = 0;

    if (!proc_dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a directory and if it is a number (PID)
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            char path[BUFFER_SIZE];

            // Get the command name from the status file
            snprintf(path, sizeof(path), "/proc/%d/stat", pid);
            FILE *stat_file = fopen(path, "r");
            if (stat_file) {
                fscanf(stat_file, "%*d %s %*s %*s", processes[*count].name);
                processes[*count].pid = pid;

                // Example CPU usage calculation simplification
                // Would normally use /proc/stat for a proper calculation
                processes[*count].cpu_usage = rand() % 100; // Dummy CPU usage
                (*count)++;
                fclose(stat_file);
            }
        }
    }
    closedir(proc_dir);
}

void display_processes(ProcessInfo *processes, int count) {
    printf("\n%-10s %-20s %-10s\n", "PID", "COMMAND", "CPU (%)");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }
}

void clear_screen() {
    printf("\033[H\033[J");
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int count;
    while (1) {
        clear_screen();
        get_process_info(processes, &count);
        display_processes(processes, count);
        sleep(2); // Refresh every 2 seconds
    }
    return 0;
}