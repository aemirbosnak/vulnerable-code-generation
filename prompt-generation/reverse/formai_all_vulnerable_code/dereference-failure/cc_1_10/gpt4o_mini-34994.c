//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define MAX_PATH 256

typedef struct {
    int pid;
    char name[256];
    long vm_size;  // Virtual memory size in KB
} Process;

// Function to check if a string is a number
int isNumber(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Function to read the process information
void loadProcesses(Process *processes, int *count) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];
    char line[256];

    // Initialize the process count
    *count = 0;

    // Open the /proc directory
    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Iterate through entries in /proc
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry name is a number
        if (isNumber(entry->d_name)) {
            // Construct the path to the status file
            snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);

            // Open the status file
            FILE *file = fopen(path, "r");
            if (file) {
                // Read status file to extract the Name and VmSize
                while (fgets(line, sizeof(line), file)) {
                    if (strncmp(line, "Name:", 5) == 0) {
                        sscanf(line + 6, "%s", processes[*count].name);
                    }
                    if (strncmp(line, "VmSize:", 7) == 0) {
                        sscanf(line + 8, "%ld", &processes[*count].vm_size);
                    }
                }
                fclose(file);

                // Store the PID and increment the count
                processes[*count].pid = atoi(entry->d_name);
                (*count)++;
            }
        }
    }
    closedir(dir);
}

// Function to display the processes in a structured manner
void displayProcesses(Process *processes, int count) {
    printf("%-10s%-25s%-15s\n", "PID", "Process Name", "Virtual Mem (KB)");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d%-25s%-15ld\n", processes[i].pid, processes[i].name, processes[i].vm_size);
    }
}

// Main function
int main() {
    Process processes[MAX_PROCESSES];
    int processCount = 0;

    // Load the processes
    loadProcesses(processes, &processCount);

    // Display loaded processes
    displayProcesses(processes, processCount);

    return 0;
}