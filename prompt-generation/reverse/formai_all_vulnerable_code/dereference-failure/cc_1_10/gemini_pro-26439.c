//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a log entry
typedef struct {
    char *timestamp;
    char *source;
    char *message;
} LogEntry;

// Define a function to parse a log entry from a string
LogEntry *parseLogEntry(char *line) {
    // Allocate memory for the log entry
    LogEntry *entry = malloc(sizeof(LogEntry));

    // Parse the timestamp
    char *timestamp = strtok(line, " ");
    entry->timestamp = strdup(timestamp);

    // Parse the source
    char *source = strtok(NULL, " ");
    entry->source = strdup(source);

    // Parse the message
    char *message = strtok(NULL, "\n");
    entry->message = strdup(message);

    // Return the log entry
    return entry;
}

// Define a function to print a log entry
void printLogEntry(LogEntry *entry) {
    printf("%s %s: %s\n", entry->timestamp, entry->source, entry->message);
}

// Define a function to analyze a log file
void analyzeLogFile(char *filename) {
    // Open the log file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening log file");
        return;
    }

    // Read the log file line by line
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the log entry
        LogEntry *entry = parseLogEntry(line);

        // Print the log entry
        printLogEntry(entry);

        // Free the memory allocated for the log entry
        free(entry->timestamp);
        free(entry->source);
        free(entry->message);
        free(entry);
    }

    // Close the log file
    fclose(fp);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user specified a log file
    if (argc != 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        return 1;
    }

    // Analyze the log file
    analyzeLogFile(argv[1]);

    // Return 0 to indicate success
    return 0;
}