//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 256

// Function to read the status of a process from /proc/[pid]/status
void read_process_status(pid_t pid) {
    char filepath[BUFFER_SIZE];
    snprintf(filepath, sizeof(filepath), "/proc/%d/status", pid);

    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Failed to open process status file");
        return;
    }

    printf("Process ID: %d\n", pid);
    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "State:", 6) == 0 || strncmp(line, "Name:", 5) == 0 ||
            strncmp(line, "Uid:", 4) == 0 || strncmp(line, "VmSize:", 7) == 0) {
            printf("%s", line);
        }
    }
    fclose(file);
    printf("\n");
}

// Function to check if a string is a number (for PIDs)
int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to list all processes in the /proc directory
void list_processes() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("Active processes:\n");
    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            pid_t pid = atoi(entry->d_name);
            read_process_status(pid);
        }
    }

    closedir(dir);
}

// Main function to display the process viewer
int main() {
    printf("Welcome to the C Process Viewer!\n");
    printf("Press Enter to list all active processes...\n");
    getchar();

    list_processes();

    return 0;
}