//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 512

// Function to determine if a string is a number
int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to read and display process information
void display_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *status_file;

    // Constructing the path to the process's status file
    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    
    // Opening the status file
    status_file = fopen(path, "r");
    if (status_file == NULL) {
        fprintf(stderr, "Oops! Could not open file for PID: %s\n", pid);
        return;
    }

    printf("✨ Process ID: %s\n", pid);
    printf("=====================================\n");
    
    // Reading and printing the status information
    while (fgets(buffer, sizeof(buffer), status_file) != NULL) {
        if (strncmp(buffer, "Name:", 5) == 0 || 
            strncmp(buffer, "State:", 6) == 0 || 
            strncmp(buffer, "PPid:", 5) == 0) {
            printf("%s", buffer);
        }
    }

    printf("=====================================\n");
    fclose(status_file);
}

// Main function
int main(void) {
    DIR *proc_dir;
    struct dirent *entry;

    // Opening the /proc directory
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Oh no! Could not open /proc directory!");
        return EXIT_FAILURE;
    }

    printf("🌟 Welcome to the Process Viewer! 🌟\n");
    printf("Here are the current processes running on your delightful machine:\n\n");

    // Iterating through entries in /proc
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a number (meaning a PID)
        if (is_number(entry->d_name)) {
            // Display the process information for this PID
            display_process_info(entry->d_name);
        }
    }

    // Closing the directory stream
    closedir(proc_dir);
    printf("🎉 Thanks for using the Process Viewer! Goodbye! 🎉\n");
    
    return EXIT_SUCCESS;
}