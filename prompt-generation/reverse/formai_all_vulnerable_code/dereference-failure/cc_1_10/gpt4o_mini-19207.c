//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

// Function to check if a string represents a number
int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Function to read the process information from a specific PID
void read_process_info(const char *pid) {
    char filepath[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    FILE *status_file;

    // Construct the path to the /proc/[pid]/status file
    snprintf(filepath, sizeof(filepath), "/proc/%s/status", pid);
    
    status_file = fopen(filepath, "r");
    if (status_file) {
        printf("Process ID: %s\n", pid);
        while (fgets(line, sizeof(line), status_file)) {
            // Print out the process status information
            if (strncmp(line, "Name:", 5) == 0 ||
                strncmp(line, "State:", 6) == 0 ||
                strncmp(line, "Pid:", 4) == 0 ||
                strncmp(line, "Uid:", 4) == 0) {
                printf("%s", line);
            }
        }
        fclose(status_file);
        printf("\n");
    } else {
        printf("Could not open /proc/%s/status file.\n", pid);
    }
}

// Function to list all processes
void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("Listing all currently running processes:\n\n");

    // Read directory entries
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry name is a number (proc PID)
        if (is_number(entry->d_name)) {
            read_process_info(entry->d_name);
        }
    }
    closedir(proc_dir);
    printf("End of process list.\n");
}

// Main function
int main() {
    printf("Welcome to the Linux Process Viewer!\n");
    printf("Exploring the vibrant ecosystem of processes...\n\n");

    list_processes();

    printf("Thank you for using the Process Viewer. Goodbye!\n");
    return 0;
}