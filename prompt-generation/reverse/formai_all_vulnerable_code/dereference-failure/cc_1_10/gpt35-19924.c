//FormAI DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 200

int main() {
    // Open the log file
    FILE *logFile = fopen("example.log", "r");

    // Allocate memory for a line in the log file
    char *line = (char *) malloc(MAX_LENGTH * sizeof(char));

    // Check if log file is empty
    if (!logFile) {
        printf("Log file is empty. Exiting...\n");
        return 0;
    }

    // Counters for the number of errors, warnings, and infos
    int errorCount = 0, warningCount = 0, infoCount = 0;

    // Read the log file line by line and check for errors, warnings, and infos
    while (fgets(line, MAX_LENGTH, logFile)) {
        // Check if line contains an error
        if (strstr(line, "ERROR")) {
            errorCount++;
            printf("[ERROR] %s", line);
        }
        // Check if line contains a warning
        else if (strstr(line, "WARNING")) {
            warningCount++;
            printf("[WARNING] %s", line);
        }
        // Check if line contains an info
        else if (strstr(line, "INFO")) {
            infoCount++;
            printf("[INFO] %s", line);
        }
    }

    // Print the summary of the log file
    printf("\n\n--- SUMMARY ---\n");
    printf("Number of errors: %d\n", errorCount);
    printf("Number of warnings: %d\n", warningCount);
    printf("Number of infos: %d\n", infoCount);

    // Close the log file and free memory
    fclose(logFile);
    free(line);

    return 0;
}