//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    pid_t pid;
    char comm[BUFFER_SIZE];
    char state;
} ProcessInfo;

void get_process_info(ProcessInfo *processes, int *count) {
    DIR *dir;
    struct dirent *entry;
    char path[BUFFER_SIZE];
    FILE *status_file;

    *count = 0;
    dir = opendir("/proc");
    
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) {
                snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
                status_file = fopen(path, "r");
                if (status_file) {
                    ProcessInfo process_info;
                    process_info.pid = pid;
                    fgets(process_info.comm, sizeof(process_info.comm), status_file);
                    sscanf(process_info.comm, "Name:\t%s", process_info.comm);
                    fgets(path, sizeof(path), status_file);
                    sscanf(path, "State:\t%c", &process_info.state);
                    processes[*count] = process_info;
                    (*count)++;
                    fclose(status_file);
                }
            }
        }
    }

    closedir(dir);
}

void display_processes(ProcessInfo *processes, int count) {
    printf("%-10s %-30s %-10s\n", "PID", "COMMAND", "STATE");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10c\n", processes[i].pid, processes[i].comm, processes[i].state);
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int process_count;

    printf("~~~ C Process Viewer ~~~\n");
    get_process_info(processes, &process_count);
    
    if (process_count > 0) {
        display_processes(processes, process_count);
    } else {
        printf("No processes found.\n");
    }

    return 0;
}