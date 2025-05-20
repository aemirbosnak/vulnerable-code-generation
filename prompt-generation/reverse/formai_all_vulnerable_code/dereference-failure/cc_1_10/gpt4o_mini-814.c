//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

/* Function prototypes */
void display_processes();
void print_color(const char *text, const char *color_code);

int main() {
    printf("🔥 Welcome to the Ultimate Process Viewer! 🔥\n");
    printf("=============================================\n");
    display_processes();
    printf("=============================================\n");
    printf("👍 Thank you for using the Process Viewer! 👍\n");
    return 0;
}

void display_processes() {
    struct dirent *entry;
    DIR *dp = opendir("/proc");

    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("%-20s %-20s %-15s %-10s\n", "PID", "COMMAND", "STATE", "USER");
    printf("----------------------------------------------------\n");

    while ((entry = readdir(dp))) {
        // Check if the entry is a PID
        if (isdigit(entry->d_name[0])) {
            char path[40], cmd[256], state[16], uid[10];

            // Build the path to the status file
            snprintf(path, 40, "/proc/%s/status", entry->d_name);
            FILE *fp = fopen(path, "r");

            if (fp == NULL) {
                continue;
            }

            // Read the command (name) and state
            fgets(cmd, sizeof(cmd), fp);
            fgets(state, sizeof(state), fp);
            fgets(uid, sizeof(uid), fp);
            fclose(fp);

            // Extract process name and state
            char process_name[256];
            sscanf(cmd, "Name:\t%s", process_name);
            char process_state[10];
            sscanf(state, "State:\t%s", process_state);
            char user_id[10];
            sscanf(uid, "Uid:\t%s", user_id);
            
            // Use the UID to get the username
            char username[32];
            snprintf(path, 40, "/etc/passwd");
            FILE *passwd_fp = fopen(path, "r");
            if (passwd_fp) {
                char line[512];
                while (fgets(line, sizeof(line), passwd_fp)) {
                    char *puid = strtok(line, ":");
                    char *suid = strtok(NULL, ":");
                    if (strcmp(suid, user_id) == 0) {
                        strcpy(username, puid);
                        break;
                    }
                }
                fclose(passwd_fp);
            } else {
                strcpy(username, "Unknown");
            }
          
            // Print colorful output
            print_color(entry->d_name, "\033[0;32m"); // Green for PID
            printf("    "); 
            print_color(process_name, "\033[0;36m"); // Cyan for Command
            printf("    ");
            print_color(process_state, "\033[0;33m"); // Yellow for State
            printf("    ");
            print_color(username, "\033[0;34m"); // Blue for User
            printf("\n");
        }
    }
    closedir(dp);
}

void print_color(const char *text, const char *color_code) {
    printf("%s%s\033[0m", color_code, text);
}