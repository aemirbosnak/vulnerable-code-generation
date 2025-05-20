//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define CMDLINE_SIZE 256

// Function to check if a string is a number
int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to get the command line of a process
void get_command_line(const char *pid, char *cmdline) {
    char path[BUFFER_SIZE];
    FILE *file;

    snprintf(path, sizeof(path), "/proc/%s/cmdline", pid);
    file = fopen(path, "r");
    if (file) {
        fgets(cmdline, CMDLINE_SIZE, file);
        fclose(file);
        
        // Replace null terminators with spaces to format output
        for (int i = 0; i < CMDLINE_SIZE; i++) {
            if (cmdline[i] == '\0') {
                cmdline[i] = ' ';
            }
        }
    } else {
        strcpy(cmdline, "N/A");
    }
}

// Function to display the processes
void display_processes() {
    DIR *proc_dir;
    struct dirent *entry;
    char cmdline[CMDLINE_SIZE];

    if ((proc_dir = opendir("/proc")) == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    printf("%-10s %-30s\n", "PID", "Command Line");
    printf("-------------------------------------------------------------\n");

    while ((entry = readdir(proc_dir)) != NULL) {
        // Only interested in numeric directories which represent PIDs
        if (is_number(entry->d_name)) {
            get_command_line(entry->d_name, cmdline);
            printf("%-10s %-30s\n", entry->d_name, cmdline);
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Welcome to the C Process Viewer!\n");
    printf("----------------------------------\n");
    display_processes();
    printf("\nEnd of process list.\n");

    return 0;
}