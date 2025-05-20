//FormAI DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PID_LENGTH 6
#define MAX_COMMAND_LENGTH 50
#define MAX_BUFFER_LENGTH 1024

void printTableHeader() {
    printf("%-6s %-50s %s\n", "PID", "Command", "State");
}

int main() {
    DIR *dir = opendir("/proc");
    struct dirent *dirEntry;
    char statFilePath[MAX_BUFFER_LENGTH];
    char pid[MAX_PID_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    char state;
    
    if (dir == NULL) {
        perror("Error: Unable to open /proc directory");
        exit(EXIT_FAILURE);
    }
    
    // Print table header
    printTableHeader();

    while ((dirEntry = readdir(dir)) != NULL) {
        if (dirEntry->d_type == DT_DIR) {
            // Check if the directory name is a valid PID
            if (isdigit(*dirEntry->d_name)) {
                strcpy(pid, dirEntry->d_name);

                // Read command from /proc/PID/cmdline file
                sprintf(statFilePath, "/proc/%s/cmdline", pid);
                FILE *cmdLineFile = fopen(statFilePath, "r");

                if (cmdLineFile != NULL) {
                    fgets(command, MAX_COMMAND_LENGTH, cmdLineFile);
                    fclose(cmdLineFile);

                    // Read process state from /proc/PID/stat file
                    sprintf(statFilePath, "/proc/%s/stat", pid);
                    FILE *statFile = fopen(statFilePath, "r");

                    if (statFile != NULL) {
                        fscanf(statFile, "%*d (%[^)]) %c", command, &state);
                        fclose(statFile);

                        printf("%-6s %-50s %c\n", pid, command, state);
                    }
                }
            }
        }
    }

    closedir(dir);

    return EXIT_SUCCESS;
}