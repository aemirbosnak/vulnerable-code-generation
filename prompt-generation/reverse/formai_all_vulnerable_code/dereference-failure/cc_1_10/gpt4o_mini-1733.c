//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRY 256
#define MAX_LOG_LINE 1024

typedef struct LogEntry {
    char timestamp[20];
    char level[10];
    char message[MAX_LOG_ENTRY];
    struct LogEntry *next;
} LogEntry;

LogEntry* createLogEntry(const char *line) {
    LogEntry *entry = malloc(sizeof(LogEntry));
    if (entry == NULL) {
        perror("Failed to allocate memory for log entry");
        exit(EXIT_FAILURE);
    }

    sscanf(line, "%19s %9s %255[^\n]", entry->timestamp, entry->level, entry->message);
    entry->next = NULL;
    return entry;
}

void freeLogEntries(LogEntry *head) {
    LogEntry *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void analyzeLogs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open log file");
        return;
    }

    LogEntry *head = NULL, *tail = NULL;
    char line[MAX_LOG_LINE];
    int infoCount = 0, warnCount = 0, errorCount = 0;
    LogEntry *oldest = NULL, *mostRecent = NULL;

    while (fgets(line, sizeof(line), file)) {
        LogEntry *entry = createLogEntry(line);
        if (head == NULL) {
            head = entry;
            tail = entry;
            oldest = entry;
        } else {
            tail->next = entry;
            tail = entry;
        }

        if (mostRecent == NULL || strcmp(entry->timestamp, mostRecent->timestamp) > 0) {
            mostRecent = entry;
        }

        if (strcmp(entry->level, "INFO") == 0) {
            infoCount++;
        } else if (strcmp(entry->level, "WARN") == 0) {
            warnCount++;
        } else if (strcmp(entry->level, "ERROR") == 0) {
            errorCount++;
        }
    }
    fclose(file);

    printf("Log Analysis Report:\n");
    printf("----------------------\n");
    printf("Total INFO logs: %d\n", infoCount);
    printf("Total WARN logs: %d\n", warnCount);
    printf("Total ERROR logs: %d\n", errorCount);
    
    if (oldest) {
        printf("Oldest Log Entry: [%s] [%s] %s\n", oldest->timestamp, oldest->level, oldest->message);
    }
    if (mostRecent) {
        printf("Most Recent Log Entry: [%s] [%s] %s\n", mostRecent->timestamp, mostRecent->level, mostRecent->message);
    }

    freeLogEntries(head);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyzeLogs(argv[1]);
    return EXIT_SUCCESS;
}