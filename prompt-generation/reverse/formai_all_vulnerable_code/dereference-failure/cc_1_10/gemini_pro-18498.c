//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a log entry
typedef struct {
    char *timestamp;
    char *level;
    char *message;
} LogEntry;

// Function to parse a log entry from a line of text
LogEntry *parseLogEntry(char *line) {
    LogEntry *entry = malloc(sizeof(LogEntry));

    // Split the line into timestamp, level, and message
    char *fields[3];
    int numFields = 0;
    char *field = strtok(line, " ");
    while (field != NULL) {
        fields[numFields++] = field;
        field = strtok(NULL, " ");
    }

    // Check that we got all three fields
    if (numFields != 3) {
        free(entry);
        return NULL;
    }

    // Assign the fields to the entry
    entry->timestamp = strdup(fields[0]);
    entry->level = strdup(fields[1]);
    entry->message = strdup(fields[2]);

    return entry;
}

// Function to free a log entry
void freeLogEntry(LogEntry *entry) {
    free(entry->timestamp);
    free(entry->level);
    free(entry->message);
    free(entry);
}

// Function to print a log entry
void printLogEntry(LogEntry *entry) {
    printf("%s %s %s\n", entry->timestamp, entry->level, entry->message);
}

// Function to read log entries from a file
LogEntry **readLogEntries(char *filename, int *numEntries) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Count the number of lines in the file
    int numLines = 0;
    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
        numLines++;
    }
    fclose(file);

    // Allocate an array to store the log entries
    LogEntry **entries = malloc(sizeof(LogEntry *) * numLines);

    // Reopen the file and parse each line
    file = fopen(filename, "r");
    int i = 0;
    while (fgets(line, 1024, file) != NULL) {
        entries[i++] = parseLogEntry(line);
    }
    fclose(file);

    *numEntries = numLines;

    return entries;
}

// Function to free an array of log entries
void freeLogEntries(LogEntry **entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        freeLogEntry(entries[i]);
    }
    free(entries);
}

// Function to find all log entries with a given level
LogEntry **findLogEntriesByLevel(LogEntry **entries, int numEntries, char *level) {
    // Allocate an array to store the matching log entries
    LogEntry **matchingEntries = malloc(sizeof(LogEntry *) * numEntries);

    // Count the number of matching log entries
    int numMatchingEntries = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i]->level, level) == 0) {
            matchingEntries[numMatchingEntries++] = entries[i];
        }
    }

    // Reallocate the array to the correct size
    matchingEntries = realloc(matchingEntries, sizeof(LogEntry *) * numMatchingEntries);

    return matchingEntries;
}

// Function to print the log entries with a given level
void printLogEntriesByLevel(LogEntry **entries, int numEntries, char *level) {
    LogEntry **matchingEntries = findLogEntriesByLevel(entries, numEntries, level);

    for (int i = 0; i < numEntries; i++) {
        printLogEntry(matchingEntries[i]);
    }

    freeLogEntries(matchingEntries, numEntries);
}

int main(int argc, char *argv[]) {
    // Check that the user provided a filename
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the log entries from the file
    int numEntries;
    LogEntry **entries = readLogEntries(argv[1], &numEntries);

    // Print all the log entries
    for (int i = 0; i < numEntries; i++) {
        printLogEntry(entries[i]);
    }

    // Find and print all the log entries with a level of "ERROR"
    printLogEntriesByLevel(entries, numEntries, "ERROR");

    // Free the log entries
    freeLogEntries(entries, numEntries);

    return 0;
}