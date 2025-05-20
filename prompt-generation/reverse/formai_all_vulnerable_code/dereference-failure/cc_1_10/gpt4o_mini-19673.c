//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;                // Process ID
    char name[BUFFER_SIZE]; // Process name
    char state[BUFFER_SIZE]; // Process state
    int ppid;              // Parent Process ID
} Process;

void read_process_info(Process* process) {
    char path[BUFFER_SIZE];
    
    // Construct the file path for the specific process
    sprintf(path, "/proc/%d/stat", process->pid);
    
    // Open the process stat file
    FILE* file = fopen(path, "r");
    if (file) {
        fscanf(file, "%d %s %s %d", &process->pid, process->name, process->state, &process->ppid);
        fclose(file);
    } else {
        // Handle if the process does not exist
        process->pid = -1; 
    }
}

void display_process_info(Process processes[], int count) {
    printf("%-10s %-25s %-10s %-10s\n", "PID", "Name", "State", "PPID");
    printf("%-10s %-25s %-10s %-10s\n", "----", "----", "-----", "----");
    for (int i = 0; i < count; i++) {
        if (processes[i].pid != -1) {
            printf("%-10d %-25s %-10s %-10d\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].ppid);
        }
    }
}

void gather_processes(Process processes[], int* count) {
    DIR* dir = opendir("/proc");
    struct dirent* entry;
    int index = 0;

    // Loop through /proc to find pid directories
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) { // Valid process ID
                processes[index].pid = pid;
                read_process_info(&processes[index]);
                index++;
                if (index >= MAX_PROCESSES) {
                    break; // Avoid overflowing the process array
                }
            }
        }
    }
    
    *count = index; // Update the count of processes
    closedir(dir);
}

int main() {
    Process processes[MAX_PROCESSES];
    int count;

    // Gather process information
    gather_processes(processes, &count);

    // Display gathered information
    display_process_info(processes, count);

    return 0;
}