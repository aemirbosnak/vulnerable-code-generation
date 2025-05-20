//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>
#include <unistd.h>

// Function to get the username associated with a UID
const char *get_username(uid_t uid) {
    struct passwd *pw = getpwuid(uid);
    return (pw == NULL) ? "N/A" : pw->pw_name;
}

// Function to get process command from the cmdline file
void get_process_command(pid_t pid, char *cmd, size_t size) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);

    FILE *file = fopen(path, "r");
    if (file) {
        fgets(cmd, size, file);
        fclose(file);
    } else {
        snprintf(cmd, size, "N/A");
    }
}

// Function to retrieve and display process information
void display_processes() {
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;

    if (proc_dir == NULL) {
        perror("Error opening /proc/");
        return;
    }

    printf("%-10s %-20s %-10s %-50s\n", "PID", "USER", "PRIORITY", "COMMAND");
    printf("----------------------------------------------------------\n");

    while ((entry = readdir(proc_dir)) != NULL) {
        // We only want to look at process directories
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) { // Valid PID found
                // Get UID from the status file
                char status_path[256], line[256];
                snprintf(status_path, sizeof(status_path), "/proc/%d/status", pid);
                FILE *status_file = fopen(status_path, "r");

                if (status_file) {
                    uid_t uid = 0;
                    int priority = 0;

                    while (fgets(line, sizeof(line), status_file)) {
                        if (sscanf(line, "Uid:\t%d", &uid) == 1) {
                            continue;
                        }
                        if (sscanf(line, "Priority:\t%d", &priority) == 1) {
                            break;
                        }
                    }
                    fclose(status_file);

                    // Get process command
                    char command[256];
                    get_process_command(pid, command, sizeof(command));

                    // Print process information
                    printf("%-10d %-20s %-10d %-50s\n", pid, get_username(uid), priority, command);
                }
            }
        }
    }
    closedir(proc_dir);
}

int main() {
    while (1) {
        printf("\033[H\033[J"); // Clear screen
        display_processes();
        printf("\nPress Ctrl+C to exit...\n");
        sleep(2); // Refresh every 2 seconds
    }
    return 0;
}