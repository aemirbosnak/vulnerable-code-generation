//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#define MAX_PATH 256
#define LINE_LENGTH 1024

void display_processes() {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];
    char line[LINE_LENGTH];
    FILE *status_file;

    // Open the /proc directory
    dir = opendir("/proc");
    if (!dir) {
        perror("Unable to open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-20s %-10s\n", "PID", "Process Name", "User");
    printf("------------------------------------------------\n");

    // Read each entry in /proc
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory and its name is a number (PID)
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                // Construct the status file path
                snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
                status_file = fopen(path, "r");
                
                if (status_file) {
                    char *process_name = NULL;
                    char *user_name = NULL;
                    char buf[LINE_LENGTH];

                    while (fgets(buf, sizeof(buf), status_file)) {
                        if (strncmp(buf, "Name:", 5) == 0) {
                            process_name = strdup(buf + 6); // Skip "Name: "
                            process_name[strcspn(process_name, "\n")] = 0; // Remove newline
                        }
                        if (strncmp(buf, "Uid:", 4) == 0) {
                            uid_t uid = atoi(buf + 5); // User ID
                            struct passwd *pw = getpwuid(uid); 
                            user_name = pw ? strdup(pw->pw_name) : strdup("unknown");
                        }
                    }

                    // Print PID, process name, and user name
                    if (process_name && user_name) {
                        printf("%-10d %-20s %-10s\n", pid, process_name, user_name);
                    }

                    free(process_name);
                    free(user_name);
                    fclose(status_file);
                }
            }
        }
    }
    // Close the directory
    closedir(dir);
}

int main() {
    while (1) {
        // Clear the console for fresh display
        printf("\033[H\033[J");
        printf("Current Processes:\n");
        display_processes();

        // Update every 2 seconds
        sleep(2);
    }
    return 0;
}