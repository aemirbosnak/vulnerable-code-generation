//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

// Define process structure to hold essential details.
typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    char state[16];
} Process;

// Function to read the process information from /proc directory.
void read_processes(Process processes[], int* count) {
    DIR* proc_dir;
    struct dirent* entry;
    char path[BUFFER_SIZE];
    FILE* status_file;
    char buffer[BUFFER_SIZE];

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Failed to open /proc directory");
        exit(EXIT_FAILURE);
    }

    *count = 0;

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) { // Check if it's a PID
            processes[*count].pid = atoi(entry->d_name);

            // Construct the file path to status file.
            snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
            status_file = fopen(path, "r");

            if (status_file) {
                while (fgets(buffer, sizeof(buffer), status_file)) {
                    if (sscanf(buffer, "Name:\t%[^\n]", processes[*count].name) == 1) continue;
                    if (sscanf(buffer, "State:\t%[^\n]", processes[*count].state) == 1) break;
                }
                fclose(status_file);
            }
            (*count)++;
        }

        if (*count >= MAX_PROCESSES) break; // Limit reached
    }

    closedir(proc_dir);
}

// Function to display the process information.
void display_processes(Process processes[], int count) {
    printf("%-6s %-30s %-10s\n", "PID", "Process Name", "State");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (processes[i].pid > 0) { // Only display valid processes
            printf("%-6d %-30s %-10s\n", processes[i].pid, processes[i].name, processes[i].state);
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int process_count;

    printf("=== Process Viewer ===\n");
    read_processes(processes, &process_count);
    display_processes(processes, process_count);

    return 0;
}