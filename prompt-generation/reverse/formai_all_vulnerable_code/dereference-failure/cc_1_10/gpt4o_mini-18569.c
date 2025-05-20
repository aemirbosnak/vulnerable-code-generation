//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PROC 1024
#define BUF_SIZE 256

typedef struct {
    pid_t pid;
    char comm[BUF_SIZE];
    float cpu_usage;
    float mem_usage;
} ProcessInfo;

int get_process_info(ProcessInfo *proc_info, int *count) {
    DIR *dir;
    struct dirent *entry;
    char path[BUF_SIZE];
    FILE *stat_file;
    
    if (!(dir = opendir("/proc"))) {
        perror("opendir");
        return -1;
    }

    *count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            proc_info[*count].pid = atoi(entry->d_name);
            snprintf(path, BUF_SIZE, "/proc/%s/stat", entry->d_name);
            stat_file = fopen(path, "r");

            if (stat_file) {
                fscanf(stat_file, "%*d %s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %*u %*u %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u", proc_info[*count].comm);
                fclose(stat_file);
            }

            snprintf(path, BUF_SIZE, "/proc/%s/statm", entry->d_name);
            stat_file = fopen(path, "r");

            if (stat_file) {
                int mem_size;
                fscanf(stat_file, "%*d %d", &mem_size);
                fclose(stat_file);
                proc_info[*count].mem_usage = mem_size * (getpagesize() / 1024.0); // KB
            }

            // Placeholder for CPU usage - further implementation would track time spent
            proc_info[*count].cpu_usage = 0.0; 

            (*count)++;
            if (*count >= MAX_PROC) {
                break;
            }
        }
    }
    closedir(dir);
    return 0;
}

void print_process_info(ProcessInfo *proc_info, int count) {
    printf("%-6s %-25s %-12s %-12s\n", "PID", "COMMAND", "CPU Usage", "Mem Usage");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-25s %-12.2f %-12.2f\n", proc_info[i].pid, proc_info[i].comm, proc_info[i].cpu_usage, proc_info[i].mem_usage);
    }
}

int main() {
    ProcessInfo proc_info[MAX_PROC];
    int proc_count;

    if (get_process_info(proc_info, &proc_count) == -1) {
        fprintf(stderr, "Error while retrieving process information\n");
        return EXIT_FAILURE;
    }

    print_process_info(proc_info, proc_count);
    
    return EXIT_SUCCESS;
}