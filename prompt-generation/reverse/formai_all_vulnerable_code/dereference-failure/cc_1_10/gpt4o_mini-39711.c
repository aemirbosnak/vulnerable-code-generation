//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

void display_process_info(const char *pid) {
    char path[MAX_LINE_LENGTH];
    FILE *file;

    // Constructing the status filepath
    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    
    file = fopen(path, "r");
    if (file == NULL) {
        return; // Unable to open the file, maybe process exited
    }

    printf("Process ID: %s\n", pid);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0 || strncmp(line, "State:", 6) == 0 || strncmp(line, "Pid:", 4) == 0) {
            printf("  %s", line);
        }
    }

    fclose(file);
    printf("========================================\n");
}

int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc");
        exit(EXIT_FAILURE);
    }

    printf("Listing active processes:\n");
    printf("========================================\n");
    while ((entry = readdir(dir)) != NULL) {
        if (is_numeric(entry->d_name)) {
            display_process_info(entry->d_name);
        }
    }
    closedir(dir);
}

int main() {
    printf("🎉 Welcome to the Ultimate Process Viewer! 🎉\n");
    printf("🚀 Let's explore the active processes on your system! 🚀\n");
    
    list_processes();

    printf("📊 Process viewing complete! 📊\n");
    printf("✨ Thank you for using the Ultimate Process Viewer! ✨\n");

    return 0;
}