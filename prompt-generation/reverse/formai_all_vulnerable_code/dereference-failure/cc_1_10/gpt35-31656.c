//FormAI DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_DIR_LEN 256
#define MAX_BUFFER_SIZE 1024

void printProcessInfo(char *pid) {
    char buffer[MAX_BUFFER_SIZE];
    char procFilePath[MAX_DIR_LEN];
    FILE *statFile;

    // Open the process status file for the given pid
    sprintf(procFilePath, "/proc/%s/status", pid);
    statFile = fopen(procFilePath, "r");

    if (statFile) {
        // Read the file contents line by line
        while (fgets(buffer, MAX_BUFFER_SIZE - 1, statFile)) {
            // Check if the current line starts with Name or State
            if (strncmp(buffer, "Name:", 5) == 0 || strncmp(buffer, "State:", 6) == 0) {
                printf("%s", buffer);
            }
        }

        fclose(statFile);
    }
}

int main() {
    DIR *procDirectory;
    struct dirent *dirEntry;
    char procFilePath[MAX_DIR_LEN];

    // Open the /proc directory
    procDirectory = opendir("/proc");

    if (procDirectory) {
        // Read each directory entry in the /proc directory
        while ((dirEntry = readdir(procDirectory)) != NULL) {
            // Ignore any entry that is not a directory or not a number
            if (!isdigit(dirEntry->d_name[0])) {
                continue;
            }

            // Print the process info for the current pid
            printf("PID: %s\n", dirEntry->d_name);
            printProcessInfo(dirEntry->d_name);

            // Print a separator line
            printf("----------------------------------------------------------------\n");
        }

        closedir(procDirectory);
    }

    return 0;
}