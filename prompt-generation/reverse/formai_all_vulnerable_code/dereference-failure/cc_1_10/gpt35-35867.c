//FormAI DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUF_SIZE 1024

// Helper function to check if a string is a number
int is_number(const char* s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

// Helper function to get the name of a process from its pid
void get_process_name(char* pid, char* name) {
    char path[BUF_SIZE];
    FILE* fp;
    sprintf(path, "/proc/%s/cmdline", pid);
    fp = fopen(path, "r");
    if (fp == NULL) {
        strcpy(name, "Unknown");
        return;
    }
    fgets(name, BUF_SIZE, fp);
    fclose(fp);
}

// Main function
int main() {
    DIR* dir;
    struct dirent* dir_entry;
    char pid[BUF_SIZE];
    char name[BUF_SIZE];
    int i;

    // Print table header
    printf("%-10s %-20s %s\n", "PID", "NAME", "STATE");

    // Open /proc directory and loop through its entries
    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: could not open /proc directory\n");
        return 1;
    }
    while ((dir_entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory and the name is a number
        if (dir_entry->d_type == DT_DIR && is_number(dir_entry->d_name)) {
            strcpy(pid, dir_entry->d_name);
            // Get the process name
            get_process_name(pid, name);
            // Print the process id, name, and state
            printf("%-10s %-20s %s\n", pid, name, "Running");
        }
    }

    // Close /proc directory
    closedir(dir);

    return 0;
}