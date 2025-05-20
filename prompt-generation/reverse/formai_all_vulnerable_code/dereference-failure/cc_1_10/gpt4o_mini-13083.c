//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

// Function to check if a string consists solely of digits
int is_digit_string(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0; // Not a digit
        }
        str++;
    }
    return 1; // All digits
}

// Function to read and display process information
void display_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    FILE *file;
    
    // Construct the path to the status file of the process
    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    
    file = fopen(path, "r");
    if (file == NULL) {
        return; // Could not open file, possibly an invalid PID
    }
    
    printf("Process ID: %s\n", pid);
    
    // Read the status file until we have the information we're interested in
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0 || 
            strncmp(line, "State:", 6) == 0 || 
            strncmp(line, "Uid:", 4) == 0) {
            printf("%s", line); // Print the line (Name, State, Uid)
        }
    }
    
    fclose(file);
    printf("\n");
}

// Function to list all running processes
void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    // Open the /proc directory
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("Listing all running processes:\n");
    
    // Iterate through each entry in the /proc directory
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry name is a number (PID)
        if (is_digit_string(entry->d_name)) {
            display_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Simple Linux Process Viewer\n");
    printf("===========================\n");

    // Call the function to list processes
    list_processes();

    printf("Process viewing complete.\n");
    return 0;
}