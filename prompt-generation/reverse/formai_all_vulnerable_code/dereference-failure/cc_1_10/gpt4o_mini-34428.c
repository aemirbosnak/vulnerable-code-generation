//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "system.log"
#define MAX_LINE_LENGTH 256
#define ERROR_COUNT_THRESHOLD 5
#define WARNING_COUNT_THRESHOLD 10

typedef struct {
    char **lines;
    int count;
    int size;
} LogBuffer;

void initLogBuffer(LogBuffer *logBuf, int initialSize) {
    logBuf->lines = (char **)malloc(sizeof(char *) * initialSize);
    for (int i = 0; i < initialSize; i++) {
        logBuf->lines[i] = (char *)malloc(MAX_LINE_LENGTH);
    }
    logBuf->count = 0;
    logBuf->size = initialSize;
}

void freeLogBuffer(LogBuffer *logBuf) {
    for (int i = 0; i < logBuf->size; i++) {
        free(logBuf->lines[i]);
    }
    free(logBuf->lines);
}

void addLogLine(LogBuffer *logBuf, const char *line) {
    if (logBuf->count >= logBuf->size) {
        logBuf->size *= 2;
        logBuf->lines = (char **)realloc(logBuf->lines, sizeof(char *) * logBuf->size);
        for (int i = logBuf->count; i < logBuf->size; i++) {
            logBuf->lines[i] = (char *)malloc(MAX_LINE_LENGTH);
        }
    }
    strncpy(logBuf->lines[logBuf->count++], line, MAX_LINE_LENGTH - 1);
    logBuf->lines[logBuf->count - 1][MAX_LINE_LENGTH - 1] = '\0'; // Ensure null-termination
}

void analyzeLogs(LogBuffer *logBuf) {
    int errorCount = 0;
    int warningCount = 0;

    for (int i = 0; i < logBuf->count; i++) {
        if (strstr(logBuf->lines[i], "ERROR") != NULL) {
            errorCount++;
        } else if (strstr(logBuf->lines[i], "WARNING") != NULL) {
            warningCount++;
        }
    }

    printf("Log Analysis Report:\n");
    printf("Total Lines: %d\n", logBuf->count);
    printf("Errors: %d\n", errorCount);
    printf("Warnings: %d\n", warningCount);

    if (errorCount > ERROR_COUNT_THRESHOLD) {
        printf("High error count detected. Investigate urgently!\n");
    }
    if (warningCount > WARNING_COUNT_THRESHOLD) {
        printf("High warning count detected. Adjustment recommended!\n");
    }
}

int main() {
    LogBuffer logBuf;
    initLogBuffer(&logBuf, 10);

    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        fprintf(stderr, "Could not open log file: %s\n", LOG_FILE);
        freeLogBuffer(&logBuf);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        addLogLine(&logBuf, line);
    }
    fclose(file);

    analyzeLogs(&logBuf);
    freeLogBuffer(&logBuf);
    
    return EXIT_SUCCESS;
}