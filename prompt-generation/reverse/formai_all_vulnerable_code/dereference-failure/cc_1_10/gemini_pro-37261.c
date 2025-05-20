//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data type to represent a 'Log Entry'
typedef struct LogEntry {
    char timestamp[25];    // Timestamp of the log entry
    char level[10];       // Log level (e.g. DEBUG, INFO, WARN, ERROR)
    char message[1024];   // The actual log message
} LogEntry;

// Function to parse a log file and extract log entries
int parseLogFile(const char *logFile, LogEntry **logEntries) {
    // Open the log file for reading
    FILE *fp = fopen(logFile, "r");
    if (fp == NULL) {
        perror("Error opening the log file!");
        return -1;
    }

    // Initialize the log entries array
    *logEntries = (LogEntry *) malloc(sizeof(LogEntry) * 1000);  // Assuming a maximum of 1000 log entries

    // Read the log file line by line and parse each log entry
    int numEntries = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Split the line into timestamp, level, and message fields
        char *timestamp = strtok(line, " ");
        char *level = strtok(NULL, " ");
        char *message = strtok(NULL, "\n");

        // Create a new log entry and populate the fields
        LogEntry *entry = &(*logEntries)[numEntries];
        strcpy(entry->timestamp, timestamp);
        strcpy(entry->level, level);
        strcpy(entry->message, message);

        // Increment the number of log entries
        numEntries++;
    }
    
    // Close the log file
    fclose(fp);
    
    // Return the number of log entries parsed
    return numEntries;
}

// Function to analyze the log entries and generate a report
void analyzeLogEntries(LogEntry *logEntries, int numEntries) {
    // Initialize some counters
    int numInfo = 0, numWarn = 0, numError = 0;

    // Iterate over the log entries and count the occurrences of each level
    for (int i = 0; i < numEntries; i++) {
        LogEntry entry = logEntries[i];
        if (strcmp(entry.level, "INFO") == 0) {
            numInfo++;
        } else if (strcmp(entry.level, "WARN") == 0) {
            numWarn++;
        } else if (strcmp(entry.level, "ERROR") == 0) {
            numError++;
        }
    }

    // Generate the report
    printf("Log Analysis Report\n");
    printf("--------------------\n");
    printf("Total Log Entries: %d\n", numEntries);
    printf("Info Entries: %d\n", numInfo);
    printf("Warn Entries: %d\n", numWarn);
    printf("Error Entries: %d\n", numError);
}

// Main function
int main() {
    // Parse the log file
    LogEntry *logEntries;
    int numEntries = parseLogFile("log.txt", &logEntries);
    if (numEntries < 0) {
        return -1;
    }

    // Analyze the log entries
    analyzeLogEntries(logEntries, numEntries);

    // Free the allocated memory
    free(logEntries);

    return 0;
}