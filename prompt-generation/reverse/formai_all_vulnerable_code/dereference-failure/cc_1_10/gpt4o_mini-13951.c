//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_MSG_LENGTH 256
#define MAX_LINE_LENGTH 512

typedef struct LogEntry {
    time_t timestamp;
    char message[MAX_LOG_MSG_LENGTH];
} LogEntry;

typedef struct Log {
    LogEntry *entries;
    size_t size;
    size_t capacity;
} Log;

// Function prototypes
Log* createLog(size_t initialCapacity);
void destroyLog(Log* log);
void addLogEntry(Log* log, const char* message);
void printLog(Log* log);
void filterLogByKeyword(Log* log, const char* keyword);
void sortLogByTimestamp(Log* log);
void shiftRight(LogEntry* arr, size_t index, size_t size);

int main() {
    Log* myLog = createLog(5);
    
    addLogEntry(myLog, "System started successfully.");
    addLogEntry(myLog, "Error: Failed to connect to database.");
    addLogEntry(myLog, "Warning: Disk space low.");
    addLogEntry(myLog, "System shutdown initiated.");
    addLogEntry(myLog, "System started successfully.");
    
    printf("All log entries:\n");
    printLog(myLog);
    
    printf("\nFiltering log entries by keyword 'Error':\n");
    filterLogByKeyword(myLog, "Error");
    
    printf("\nSorting log entries by timestamp:\n");
    sortLogByTimestamp(myLog);
    printLog(myLog);
    
    destroyLog(myLog);
    return 0;
}

Log* createLog(size_t initialCapacity) {
    Log* log = malloc(sizeof(Log));
    log->entries = malloc(sizeof(LogEntry) * initialCapacity);
    log->size = 0;
    log->capacity = initialCapacity;
    return log;
}

void destroyLog(Log* log) {
    free(log->entries);
    free(log);
}

void addLogEntry(Log* log, const char* message) {
    if (log->size >= log->capacity) {
        log->capacity *= 2;
        log->entries = realloc(log->entries, sizeof(LogEntry) * log->capacity);
    }
    log->entries[log->size].timestamp = time(NULL);
    strncpy(log->entries[log->size].message, message, MAX_LOG_MSG_LENGTH - 1);
    log->entries[log->size].message[MAX_LOG_MSG_LENGTH - 1] = '\0'; // Null-terminate
    log->size++;
}

void printLog(Log* log) {
    for (size_t i = 0; i < log->size; i++) {
        char timeString[25];
        struct tm* tm_info = localtime(&log->entries[i].timestamp);
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("[%s] %s\n", timeString, log->entries[i].message);
    }
}

void filterLogByKeyword(Log* log, const char* keyword) {
    for (size_t i = 0; i < log->size; i++) {
        if (strstr(log->entries[i].message, keyword)) {
            char timeString[25];
            struct tm* tm_info = localtime(&log->entries[i].timestamp);
            strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", tm_info);
            printf("[%s] %s\n", timeString, log->entries[i].message);
        }
    }
}

void sortLogByTimestamp(Log* log) {
    for (size_t i = 0; i < log->size - 1; i++) {
        for (size_t j = 0; j < log->size - i - 1; j++) {
            if (log->entries[j].timestamp > log->entries[j + 1].timestamp) {
                LogEntry temp = log->entries[j];
                log->entries[j] = log->entries[j + 1];
                log->entries[j + 1] = temp;
            }
        }
    }
}