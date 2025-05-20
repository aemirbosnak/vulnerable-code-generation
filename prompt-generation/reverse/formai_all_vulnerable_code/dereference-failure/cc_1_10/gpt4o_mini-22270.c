//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_BUFFER 256

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_BUFFER];
    FILE *status_file;
    char line[MAX_BUFFER];
    int pid;
    char uid[10];
    char command[MAX_BUFFER];

    // Open the /proc directory
    if ((dir = opendir("/proc")) == NULL) {
        perror("Could not open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("%-6s %-10s %s\n", "PID", "UID", "COMMAND");
    printf("%-6s %-10s %s\n", "---", "---", "-------");

    // Iterate over each entry in the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a number (which indicates a PID)
        if (isdigit(entry->d_name[0])) {
            pid = atoi(entry->d_name);
            
            // Construct the path to the status file
            snprintf(path, sizeof(path), "/proc/%d/status", pid);
            status_file = fopen(path, "r");

            if (status_file) {
                // Read the UID
                while (fgets(line, sizeof(line), status_file)) {
                    if (sscanf(line, "Uid:\t%s", uid) == 1) {
                        break;
                    }
                }

                // Read the command
                snprintf(path, sizeof(path), "/proc/%d/comm", pid);
                FILE *comm_file = fopen(path, "r");
                if (comm_file) {
                    fgets(command, sizeof(command), comm_file);
                    // Remove trailing newline, if present
                    command[strcspn(command, "\n")] = 0;
                    fclose(comm_file);
                } else {
                    strcpy(command, "N/A");
                }

                // Print the process information
                printf("%-6d %-10s %s\n", pid, uid, command);
                fclose(status_file);
            }
        }
    }

    closedir(dir);
}

int main() {
    while (1) {
        printf("\n=== Process Viewer ===\n");
        list_processes();
        printf("\nPress Ctrl+C to exit...\n");
        sleep(5); // Refresh every 5 seconds
    }

    return 0;
}