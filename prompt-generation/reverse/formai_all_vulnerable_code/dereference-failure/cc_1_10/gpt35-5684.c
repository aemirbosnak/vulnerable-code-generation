//FormAI DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

int main() {
    DIR *directory; // Directory pointer
    struct dirent *entry; // Directory entry pointer
    char path[80], line[512], *token; // Directory path, line buffer, and token pointer
    FILE* file; // File pointer for reading process information

    // Open the /proc directory
    if ((directory = opendir("/proc")) == NULL) {
        printf("Error: Could not open /proc directory\n");
        return 1; // Exit program with failure
    }

    // Print table header
    printf("%-10s %-10s %-30s\n", "PID", "PPID", "CMD");

    // Loop through all directories in /proc directory
    while ((entry = readdir(directory)) != NULL) {
        // Check if current directory entry is a number
        if (atoi(entry->d_name) != 0) {
            // Build the full file path to the process status file
            strcpy(path, "/proc/");
            strcat(path, entry->d_name);
            strcat(path, "/status");

            // Open the process status file
            if ((file = fopen(path, "r")) == NULL) {
                continue; // Could not open file, skip this process
            }

            // Read in each line of the process status file
            while (fgets(line, sizeof(line), file)) {
                // Find the first token in the line
                token = strtok(line, " ");

                // Check if the token is "Name:"
                if (strcmp(token, "Name:") == 0) {
                    // Get the next token (the process name)
                    token = strtok(NULL, " ");

                    // Print the process information
                    printf("%-10s %-10s %-30s\n", entry->d_name, "N/A", token);

                    // Exit the loop since we found the process information we need
                    break;
                }
            }

            fclose(file); // Close the process status file
        }
    }

    closedir(directory); // Close the /proc directory
    return 0; // Exit program with success
}