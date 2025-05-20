//FormAI DATASET v1.0 Category: Log analysis ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LogEntry {
    char timestamp[20];
    char type[10];
    char message[100];
} LogEntry;

LogEntry* parseLine(char* line);
void printLogEntries(LogEntry* entries, int count);
void filterByType(LogEntry* entries, int* count, char* type);
void filterByTimestamp(LogEntry* entries, int* count, char* timestamp);

int main() {
    FILE* file = fopen("log.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }
    
    int lines = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }
    rewind(file);
    
    LogEntry* entries = (LogEntry*) malloc(lines * sizeof(LogEntry));
    int i = 0;
    char line[130];
    while (fgets(line, 130, file)) {
        entries[i++] = *parseLine(line);
    }
    fclose(file);
    
    int count = lines;
    printf("\nAll log entries:\n");
    printLogEntries(entries, count);
    
    char type[10];
    printf("\nEnter type to filter by (DEBUG, INFO, WARNING, ERROR): ");
    scanf("%s", type);
    filterByType(entries, &count, type);
    printf("\nLog entries filtered by type %s:\n", type);
    printLogEntries(entries, count);
    
    char timestamp[20];
    printf("\nEnter timestamp to filter by (format: YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", timestamp);
    filterByTimestamp(entries, &count, timestamp);
    printf("\nLog entries filtered by timestamp %s:\n", timestamp);
    printLogEntries(entries, count);
    
    free(entries);
    return 0;
}

LogEntry* parseLine(char* line) {
    char* timestamp = strtok(line, " ");
    char* type = strtok(NULL, " ");
    char* message = strtok(NULL, "\n");
    
    LogEntry* entry = (LogEntry*) malloc(sizeof(LogEntry));
    strcpy(entry->timestamp, timestamp);
    strcpy(entry->type, type);
    strcpy(entry->message, message);
    
    return entry;
}

void printLogEntries(LogEntry* entries, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %s %s\n", entries[i].timestamp, entries[i].type, entries[i].message);
    }
}

void filterByType(LogEntry* entries, int* count, char* type) {
    int i = 0, j = 0;
    while (i < *count) {
        if (strcmp(entries[i].type, type) == 0) {
            entries[j++] = entries[i];
        }
        i++;
    }
    *count = j;
}

void filterByTimestamp(LogEntry* entries, int* count, char* timestamp) {
    int i = 0, j = 0;
    while (i < *count) {
        if (strcmp(entries[i].timestamp, timestamp) == 0) {
            entries[j++] = entries[i];
        }
        i++;
    }
    *count = j;
}