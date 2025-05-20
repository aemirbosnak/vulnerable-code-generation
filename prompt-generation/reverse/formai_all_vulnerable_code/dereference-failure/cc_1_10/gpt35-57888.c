//FormAI DATASET v1.0 Category: System process viewer ; Style: high level of detail
// This program is a unique C system process viewer that displays detailed information about the running processes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 256 // Maximum length of a path
#define MAX_COMMAND_LINE 1024 // Maximum length of a command line

int main() {
    DIR *proc_dir;
    struct dirent *entry;
    char proc_path[MAX_PATH];
    char command_line[MAX_COMMAND_LINE];
    char *pid_str;
    int pid;

    proc_dir = opendir("/proc");
    if (!proc_dir) {
        printf("Could not open /proc directory\n");
        exit(EXIT_FAILURE);
    }

    // Print header
    printf("%-10s %-20s %s\n", "PID", "COMMAND", "STAT");

    // Read each entry in /proc directory
    while ((entry = readdir(proc_dir))) {
        // Check if the entry is a directory and has a valid name
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // Get the process ID from the directory name
            pid_str = entry->d_name;
            pid = atoi(pid_str);

            // Build the path to the command line file
            sprintf(proc_path, "/proc/%s/cmdline", pid_str);

            // Open the command line file
            FILE *cmdline_file = fopen(proc_path, "r");
            if (cmdline_file) {
                // Read the command line from the file
                fgets(command_line, MAX_COMMAND_LINE, cmdline_file);
                fclose(cmdline_file);

                // Remove any null characters from the command line
                int i;
                for (i = 0; i < strlen(command_line); i++) {
                    if (command_line[i] == 0) {
                        command_line[i] = ' ';
                    }
                }

                // Print the process ID, command, and status
                printf("%-10d %-20s %c\n", pid, command_line, 'R');
            }
        }
    }

    closedir(proc_dir);
    return 0;
}