//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char comm[BUFFER_SIZE];
    char state;
    unsigned long utime;
    unsigned long stime;
} ProcessInfo;

void fetch_processes(ProcessInfo *processes, int *count) {
    DIR *dir;
    struct dirent *entry;
    char path[BUFFER_SIZE], buffer[BUFFER_SIZE];
    FILE *status_file;

    *count = 0;
    dir = opendir("/proc");
    if (!dir) {
        perror("Failed to open /proc");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Check for numerical PID entries
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
                status_file = fopen(path, "r");
                if (status_file) {
                    // Read pid, comm, state, utime, stime
                    fscanf(status_file, "%d %s %c %*s %*s %*s %*s %*s %*s %*s %lu %lu",
                           &processes[*count].pid, processes[*count].comm,
                           &processes[*count].state, &processes[*count].utime,
                           &processes[*count].stime);
                    processes[*count].comm[strlen(processes[*count].comm) - 1] = '\0'; // Trim trailing parentheses
                    fclose(status_file);
                    (*count)++;
                }
            }
        }
    }
    closedir(dir);
}

void display_processes(const ProcessInfo *processes, int count) {
    printf("%-10s %-25s %-8s %-10s %-10s\n", "PID", "COMMAND", "STATE", "UTIME", "STIME");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-8c %-10lu %-10lu\n",
               processes[i].pid, processes[i].comm, processes[i].state,
               processes[i].utime, processes[i].stime);
    }
}

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting process viewer...\n");
        exit(0);
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int process_count;

    // Setup signal handler
    signal(SIGINT, signal_handler);

    while (1) {
        fetch_processes(processes, &process_count);
        display_processes(processes, process_count);
        printf("Press Ctrl+C to exit.\n");

        // Clear screen and refresh every 2 seconds
        sleep(2);
        printf("\033[H\033[J"); // ANSI escape code to clear the screen
    }

    return 0;
}