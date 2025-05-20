//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#define PROC_DIR "/proc"
#define BUFFER_SIZE 256
#define CMDLINE_SIZE 1024

// Function to get user's name based on user ID
char* get_username(uid_t uid) {
    struct passwd *pw = getpwuid(uid);
    return pw ? pw->pw_name : "Unknown";
}

// Function to read command line of a process
void read_cmdline(pid_t pid, char *command) {
    char cmdline_path[BUFFER_SIZE];
    snprintf(cmdline_path, sizeof(cmdline_path), "%s/%d/cmdline", PROC_DIR, pid);
    
    FILE *cmdline_file = fopen(cmdline_path, "r");
    if (cmdline_file) {
        fread(command, sizeof(char), CMDLINE_SIZE, cmdline_file);
        fclose(cmdline_file);
    } else {
        strncpy(command, "N/A", CMDLINE_SIZE);
    }
}

// Function to get process information
void get_process_info() {
    DIR *dir = opendir(PROC_DIR);
    struct dirent *entry;

    if (!dir) {
        perror("opendir");
        return;
    }

    printf("%-10s %-10s %-25s %-s\n", "PID", "USER", "COMMAND", "STATUS");
    printf("--------------------------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) {
                // Get user information
                FILE *status_file;
                char status_path[BUFFER_SIZE];
                snprintf(status_path, sizeof(status_path), "%s/%d/status", PROC_DIR, pid);
                status_file = fopen(status_path, "r");
                
                if (status_file) {
                    char line[BUFFER_SIZE];
                    uid_t uid = 0;
                    char state = 'N';

                    while (fgets(line, sizeof(line), status_file)) {
                        if (sscanf(line, "Uid:\t%u", &uid) == 1) {
                            continue; // UID found
                        }
                        if (sscanf(line, "State:\t%c", &state) == 1) {
                            continue; // State found
                        }
                    }
                    fclose(status_file);

                    // Get command line
                    char command[CMDLINE_SIZE] = {0};
                    read_cmdline(pid, command);

                    printf("%-10d %-10s %-25s %-c\n", pid, get_username(uid), command, state);
                }
            }
        }
    }

    closedir(dir);
}

int main() {
    while (1) {
        printf("\nSystem Process Viewer\n");
        get_process_info();
        printf("\nPress Ctrl+C to exit...\n");
        sleep(5); // Refresh every 5 seconds
    }

    return 0;
}