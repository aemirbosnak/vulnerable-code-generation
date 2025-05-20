//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;

    proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("Unable to open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("PID\tCMD\n");
    printf("------------------------------------\n");
    
    // Read entries in the /proc directory
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the directory entry is a number (indicating a PID)
        if (isdigit(*entry->d_name)) {
            char path[BUFFER_SIZE];
            char cmdline[BUFFER_SIZE];

            // Construct the path to the cmdline file
            snprintf(path, sizeof(path), "/proc/%s/cmdline", entry->d_name);
            FILE *cmd_file = fopen(path, "r");

            if (cmd_file) {
                // Read the command line for the process
                fgets(cmdline, sizeof(cmdline), cmd_file);
                fclose(cmd_file);
                
                // Replace null bytes with spaces
                for (int i = 0; cmdline[i] != '\0'; i++) {
                    if (cmdline[i] == '\0') {
                        cmdline[i] = ' ';
                    }
                }

                // Print the PID and the command
                printf("%s\t%s\n", entry->d_name, cmdline);
            }
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Simple Process Viewer\n");
    printf("======================\n");
    list_processes();
    return 0;
}