//FormAI DATASET v1.0 Category: Log analysis ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store log data
struct Log {
    char date[20];
    char time[20];
    char logLevel[10];
    char message[100];
};

// Define a function to parse a log line and return a Log struct
struct Log parseLogLine(char *logLine) {
    struct Log log;
    char *token;

    // Parse date
    token = strtok(logLine, " ");
    strcpy(log.date, token);

    // Parse time
    token = strtok(NULL, " ");
    strcpy(log.time, token);

    // Parse log level
    token = strtok(NULL, " ");
    strcpy(log.logLevel, token);

    // Parse message
    token = strtok(NULL, "\n");
    strcpy(log.message, token);

    return log;
}

int main() {
    FILE *logFile;
    char logLine[150];
    struct Log log;
    int i, numWarnings = 0, numErrors = 0;

    // Open the log file for reading
    logFile = fopen("example.log", "r");

    // Check if the file could be opened
    if (logFile == NULL) {
        printf("Error opening log file");
        return 1;
    }

    // Read each line of the log file and parse it
    while (fgets(logLine, sizeof(logLine), logFile)) {
        log = parseLogLine(logLine);

        // Count the number of warnings and errors
        if (strcmp(log.logLevel, "WARN") == 0) {
            numWarnings++;
        } else if (strcmp(log.logLevel, "ERROR") == 0) {
            numErrors++;
        }

        // Print the log message
        printf("[%s %s] %s: %s\n", log.date, log.time, log.logLevel, log.message);
    }

    // Close the log file
    fclose(logFile);

    // Print the total number of warnings and errors
    printf("\nTotal number of warnings: %d\n", numWarnings);
    printf("Total number of errors: %d\n", numErrors);

    return 0;
}