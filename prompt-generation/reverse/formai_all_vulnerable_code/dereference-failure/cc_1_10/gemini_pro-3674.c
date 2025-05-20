//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// A tranquil log analysis program that provides insights into a forest's serenity.

// Constants representing the different types of log entries.
#define LOG_ENTRY_TYPE_SOUNDS 1
#define LOG_ENTRY_TYPE_SMELLS 2
#define LOG_ENTRY_TYPE_SIGHTS 3

// A serene struct to hold the details of each log entry.
typedef struct {
    int type;
    char* description;
} LogEntry;

// A serene function to read the log entries from a file.
LogEntry* readLogEntries(const char* filename, int* numEntries) {
    // Open the log file.
    FILE* logFile = fopen(filename, "r");
    if (logFile == NULL) {
        perror("Error opening log file");
        exit(1);
    }

    // Count the number of log entries.
    int count = 0;
    while (fgetc(logFile) != EOF) {
        count++;
    }
    rewind(logFile);

    // Allocate memory for the log entries.
    LogEntry* entries = malloc(sizeof(LogEntry) * count);
    if (entries == NULL) {
        perror("Error allocating memory for log entries");
        exit(1);
    }

    // Read the log entries.
    int i = 0;
    while (fscanf(logFile, "%d: %[^\n]\n", &entries[i].type, entries[i].description) != EOF) {
        i++;
    }

    // Close the log file.
    fclose(logFile);

    // Return the log entries.
    *numEntries = count;
    return entries;
}

// A serene function to analyze the log entries.
void analyzeLogEntries(LogEntry* entries, int numEntries) {
    // Initialize the counters.
    int soundsCount = 0;
    int smellsCount = 0;
    int sightsCount = 0;

    // Count the number of log entries of each type.
    for (int i = 0; i < numEntries; i++) {
        switch (entries[i].type) {
            case LOG_ENTRY_TYPE_SOUNDS:
                soundsCount++;
                break;
            case LOG_ENTRY_TYPE_SMELLS:
                smellsCount++;
                break;
            case LOG_ENTRY_TYPE_SIGHTS:
                sightsCount++;
                break;
        }
    }

    // Print the results.
    printf("Sounds: %d\n", soundsCount);
    printf("Smells: %d\n", smellsCount);
    printf("Sights: %d\n", sightsCount);
}

// A serene function to free the memory allocated for the log entries.
void freeLogEntries(LogEntry* entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        free(entries[i].description);
    }
    free(entries);
}

// The main function.
int main(int argc, char** argv) {
    // Check if the user provided a log file name.
    if (argc != 2) {
        printf("Usage: %s <log file name>\n", argv[0]);
        return 1;
    }

    // Read the log entries from the file.
    int numEntries;
    LogEntry* entries = readLogEntries(argv[1], &numEntries);

    // Analyze the log entries.
    analyzeLogEntries(entries, numEntries);

    // Free the memory allocated for the log entries.
    freeLogEntries(entries, numEntries);

    return 0;
}