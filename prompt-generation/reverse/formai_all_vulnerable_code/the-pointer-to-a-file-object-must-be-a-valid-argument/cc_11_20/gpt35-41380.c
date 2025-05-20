//FormAI DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>

// Define a struct to hold log data
typedef struct {
    char date[10];
    char time[10];
    char level[10];
    char message[100];
} LogEntry;

int main() {
    FILE *logFile;
    LogEntry logEntries[100]; // arbitrary limit of 100 entries
    int entryCount = 0;
    int i;

    // Open the log file for reading
    logFile = fopen("example.log", "r");

    // Loop through the file, parsing each line into a log entry
    while(!feof(logFile)) {
        char line[150];
        fgets(line, 150, logFile);

        // Parse the line into its components
        char *tok = strtok(line, " ");
        int tokCounter = 0;
        LogEntry currentEntry;

        while(tok != NULL) {
            switch(tokCounter) {
                case 0:
                    // Date
                    strcpy(currentEntry.date, tok);
                    break;
                case 1:
                    // Time
                    strcpy(currentEntry.time, tok);
                    break;
                case 2:
                    // Log level
                    strcpy(currentEntry.level, tok);
                    break;
                default:
                    // Message segment
                    strcat(currentEntry.message, tok);
                    strcat(currentEntry.message, " ");
                    break;
            }

            tok = strtok(NULL, " ");
            tokCounter++;
        }

        // Add the log entry to the array
        logEntries[entryCount] = currentEntry;
        entryCount++;
    }

    // Close the file
    fclose(logFile);

    // Perform some analysis on the log data
    int errorCount = 0;
    int debugCount = 0;
    int warningCount = 0;
    int infoCount = 0;
    char *latestError = "No errors found.";

    for(i = 0; i < entryCount; i++) {
        if(strcmp(logEntries[i].level, "ERROR") == 0) {
            // Count the number of errors.
            errorCount++;

            // Update the latest error message.
            if(strcmp(logEntries[i].date, logEntries[0].date) > 0) {
                strcpy(latestError, logEntries[i].message);
            }
        }
        else if(strcmp(logEntries[i].level, "DEBUG") == 0) {
            // Count the number of debug messages.
            debugCount++;
        }
        else if(strcmp(logEntries[i].level, "WARNING") == 0) {
            // Count the number of warnings.
            warningCount++;
        }
        else if(strcmp(logEntries[i].level, "INFO") == 0) {
            // Count the number of info messages.
            infoCount++;
        }
    }

    // Print the analysis results to the console.
    printf("Log analysis summary:\n\n");
    printf("Total entries: %d\n", entryCount);
    printf("Errors: %d\n", errorCount);
    printf("Debug messages: %d\n", debugCount);
    printf("Warnings: %d\n", warningCount);
    printf("Info messages: %d\n", infoCount);
    printf("Latest error: %s\n", latestError);

    return 0;
}