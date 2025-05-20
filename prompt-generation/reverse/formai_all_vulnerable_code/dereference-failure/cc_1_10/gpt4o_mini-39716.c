//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define PROC_PATH "/proc/"

// Function to check if a string is a number
int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Function to read the command name from the stat file of a process
void get_process_command(const char *pid, char *command) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), PROC_PATH "%s/stat", pid);
    
    FILE *file = fopen(path, "r");
    if (file) {
        fscanf(file, "%*d %s", command); // Skip pid and get command
        fclose(file);
    } else {
        strcpy(command, "unknown");
    }
}

int main() {
    DIR *proc_dir;
    struct dirent *entry;

    // Open the /proc directory
    if ((proc_dir = opendir(PROC_PATH)) == NULL) {
        perror("Could not open /proc directory");
        return EXIT_FAILURE;
    }

    printf("%-10s %-25s\n", "PID", "COMMAND");
    printf("---------------------------------------------\n");

    // Iterate through the directory entries in /proc
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a directory and is a number (PID)
        if (is_number(entry->d_name)) {
            char command[BUFFER_SIZE];
            get_process_command(entry->d_name, command);

            // Display PID and command name
            printf("%-10s %-25s\n", entry->d_name, command);
        }
    }

    closedir(proc_dir);
    return EXIT_SUCCESS;
}