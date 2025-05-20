//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define MAX_LINE_LENGTH 256

void display_process_info(pid_t pid) {
    char path[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *file;

    // Display PID
    printf("Process ID: %d\n", pid);

    // Get the command name and status
    snprintf(path, sizeof(path), PROC_DIR "/%d/status", pid);
    file = fopen(path, "r");
    if (file) {
        while (fgets(line, sizeof(line), file)) {
            // Print only the Name and State for clarity
            if (strncmp(line, "Name:", 5) == 0 || strncmp(line, "State:", 6) == 0) {
                printf("%s", line);
            }
        }
        fclose(file);
    } else {
        printf("Error reading process status for PID: %d\n", pid);
    }

    // Get the memory usage
    snprintf(path, sizeof(path), PROC_DIR "/%d/statm", pid);
    file = fopen(path, "r");
    if (file) {
        if (fgets(line, sizeof(line), file)) {
            printf("Memory Usage: %s\n", line);
        }
        fclose(file);
    } else {
        printf("Error reading memory info for PID: %d\n", pid);
    }

    // Include a separator for readability
    printf("\n");
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    // Open process directory
    dir = opendir(PROC_DIR);
    if (!dir) {
        perror("Could not open /proc directory");
        return;
    }

    // Read the entries in the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Check if the name is a number, indicates a PID
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) {
                display_process_info(pid);
            }
        }
    }

    closedir(dir);
}

void prompt_for_pid() {
    pid_t pid;
    printf("Enter PID to view specific process info or 0 to list all processes: ");
    scanf("%d", &pid);

    if (pid == 0) {
        list_processes();
    } else {
        display_process_info(pid);
    }
}

int main() {
    printf("Welcome to the Lively C Process Viewer!\n");
    printf("========================================\n");
    while (1) {
        prompt_for_pid();
        printf("Would you like to view another process? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    printf("Thank you for using the Lively C Process Viewer! Goodbye!\n");
    return 0;
}