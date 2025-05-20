//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define MAX_LINE_LENGTH 256

void print_process_info(const char *pid) {
    char path[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *file;

    // Print Process ID
    printf("Process ID: %s\n", pid);

    // Print Command Line
    snprintf(path, sizeof(path), "%s/%s/cmdline", PROC_DIR, pid);
    file = fopen(path, "r");
    if (file) {
        if (fgets(line, sizeof(line), file) != NULL) {
            printf("Command Line: %s\n", line);
        }
        fclose(file);
    } else {
        printf("Command Line: [N/A]\n");
    }

    // Print Status
    snprintf(path, sizeof(path), "%s/%s/status", PROC_DIR, pid);
    file = fopen(path, "r");
    if (file) {
        printf("Status:\n");
        while (fgets(line, sizeof(line), file) != NULL) {
            if (strstr(line, "State") || strstr(line, "Name")) {
                printf("%s", line);
            }
        }
        fclose(file);
    } else {
        printf("Status: [N/A]\n");
    }
    
    // Print Memory Usage
    snprintf(path, sizeof(path), "%s/%s/statm", PROC_DIR, pid);
    file = fopen(path, "r");
    if (file) {
        if (fgets(line, sizeof(line), file) != NULL) {
            printf("Memory Usage: %s\n", line);
        }
        fclose(file);
    } else {
        printf("Memory Usage: [N/A]\n");
    }

    printf("\n");
}

void list_processes() {
    struct dirent *entry;
    DIR *proc_dir = opendir(PROC_DIR);

    if (proc_dir == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("Processes:\n");
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a valid process ID (a number)
        if (isdigit(entry->d_name[0])) {
            print_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("=== Process Viewer ===\n");
    list_processes();

    return 0;
}