//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// Define the process directory location
#define PROC_LOC "/proc/"

int main(int argc, char const *argv[])
{
    // Define variables
    DIR *dir;
    struct dirent *entry;
    char proc[255];

    // Open the directory
    dir = opendir(PROC_LOC);
    if (dir == NULL) {
        printf("Failed to open directory %s\n", PROC_LOC);
        exit(EXIT_FAILURE);
    }

    // Print headers
    printf("PID\t\tCOMM\n");
    printf("=====================\n");

    // Loop through all directories in proc
    while ((entry = readdir(dir)) != NULL) {
        // Skip non-numeric directories
        if (!isdigit(*entry->d_name)) {
            continue;
        }

        // Build the proc directory path
        strcpy(proc, PROC_LOC);
        strcat(proc, entry->d_name);

        // Open the status file for the process
        strcat(proc, "/status");
        FILE *file = fopen(proc, "r");

        // If the file is not null, read the process name
        if (file) {
            char line[256];
            while (fgets(line, sizeof(line), file)) {
                if (strncmp(line, "Name:", 5) == 0) {
                    printf("%s\t", entry->d_name);
                    printf("%s", line + 6);
                    break;
                }
            }
            fclose(file);
        }
    }

    // Close the directory
    closedir(dir);

    return EXIT_SUCCESS;
}