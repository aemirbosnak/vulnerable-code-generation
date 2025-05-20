//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Function to print the process information
void print_process_info(const char *pid) {
    char path[256];
    char line[256];
    FILE *status_file;

    // Construct the path to the status file for the process
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    
    // Open the file to read the process status
    status_file = fopen(path, "r");
    if (status_file == NULL) {
        return; // If the file cannot be opened, return
    }

    // Read the process information from the file
    if (fgets(line, sizeof(line), status_file) != NULL) {
        // Variables to hold different process information
        char comm[256], state;
        int ppid, pgrp;
        
        // Parsing relevant fields from the /proc/[pid]/stat
        sscanf(line, "%*d %s %c %d %d", comm, &state, &ppid, &pgrp);
        
        // Display the process information
        printf("PID: %s\t COMMAND: %s\t STATE: %c\t PPID: %d\t PGRP: %d\n",
               pid, comm, state, ppid, pgrp);
    }

    // Close the status file
    fclose(status_file);
}

// Function to iterate over processes in /proc directory
void list_processes() {
    DIR *dir;
    struct dirent *entry;

    // Open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("Processes currently running:\n");
    printf("=======================================\n");
    printf("PID\t COMMAND\t\t STATE\t PPID\t PGRP\n");
    printf("=======================================\n");

    // Read entries in /proc
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a digit (i.e., a PID)
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
            print_process_info(entry->d_name); // Print info for the PID
        }
    }

    // Close the directory once done
    closedir(dir);
}

// Main function
int main() {
    // List the processes
    list_processes();
    return 0;
}