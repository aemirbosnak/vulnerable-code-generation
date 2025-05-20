//Falcon-180B DATASET v1.0 Category: System event logger ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_LOG_FILE_SIZE (1024 * 1024) // 1 MB
#define MAX_LOG_ENTRIES 1000

// Log entry structure
typedef struct {
    time_t timestamp;
    char message[512];
} LogEntry;

void initLogFile(char* logFilePath) {
    FILE* logFile = fopen(logFilePath, "w");
    if (logFile == NULL) {
        printf("Error: Could not create log file.\n");
        exit(1);
    }
    fclose(logFile);
}

void logMessage(char* logFilePath, char* message) {
    LogEntry entry;
    time(&entry.timestamp);
    strncpy(entry.message, message, sizeof(entry.message));

    FILE* logFile = fopen(logFilePath, "a");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    fprintf(logFile, "%s - %s\n", ctime(&entry.timestamp), entry.message);
    fclose(logFile);
}

void readLogFile(char* logFilePath, LogEntry* entries, int* numEntries) {
    FILE* logFile = fopen(logFilePath, "r");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    int entryCount = 0;
    while (fgets(entries[entryCount].message, sizeof(entries[entryCount].message), logFile)!= NULL) {
        entryCount++;
        if (entryCount >= MAX_LOG_ENTRIES) {
            break;
        }
    }

    *numEntries = entryCount;
    fclose(logFile);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s [logFilePath] [message]\n", argv[0]);
        return 1;
    }

    char* logFilePath = argv[1];
    char* message = argv[2];

    initLogFile(logFilePath);
    logMessage(logFilePath, message);

    LogEntry entries[MAX_LOG_ENTRIES];
    int numEntries;
    readLogFile(logFilePath, entries, &numEntries);

    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].message);
    }

    return 0;
}