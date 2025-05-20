//FormAI DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINE_LENGTH 256

typedef struct LogEntry {
    char datetime[20];
    char level[10];
    char message[MAX_LOG_LINE_LENGTH];
} LogEntry;

typedef struct LogEntries {
    int count;
    LogEntry* entries;
} LogEntries;

LogEntries* read_log_file(char* filename);
void print_log_entry(LogEntry* entry);
void print_log_entries(LogEntries* entries);
void free_log_entries(LogEntries* entries);
LogEntries* filter_by_level(LogEntries* entries, char* level);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    LogEntries* entries = read_log_file(argv[1]);
    printf("All log entries:\n");
    print_log_entries(entries);
    printf("\n");

    char level_filter[10];
    printf("Enter log level to filter by: ");
    scanf("%s", level_filter);

    LogEntries* filtered_entries = filter_by_level(entries, level_filter);
    printf("\nFiltered log entries (%s):\n", level_filter);
    print_log_entries(filtered_entries);

    free_log_entries(entries);
    free_log_entries(filtered_entries);

    return 0;
}

LogEntries* read_log_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        exit(1);
    }

    LogEntries* entries = malloc(sizeof(LogEntries));
    entries->count = 0;

    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, MAX_LOG_LINE_LENGTH, file) != NULL) {
        // Parse log line into LogEntry struct
        char datetime[20];
        char level[10];
        char message[MAX_LOG_LINE_LENGTH];
        sscanf(line, "%s %s %[^\n]", datetime, level, message);

        LogEntry* entry = malloc(sizeof(LogEntry));
        strncpy(entry->datetime, datetime, 20);
        strncpy(entry->level, level, 10);
        strncpy(entry->message, message, MAX_LOG_LINE_LENGTH);

        // Add LogEntry to entries array
        entries->count++;
        entries->entries = realloc(entries->entries, entries->count*sizeof(LogEntry));
        entries->entries[entries->count-1] = *entry;
    }

    fclose(file);

    return entries;
}

void print_log_entry(LogEntry* entry) {
    printf("%s %s - %s\n", entry->datetime, entry->level, entry->message);
}

void print_log_entries(LogEntries* entries) {
    for (int i=0; i<entries->count; i++) {
        LogEntry* entry = &(entries->entries[i]);
        print_log_entry(entry);
    }
}

void free_log_entries(LogEntries* entries) {
    for (int i=0; i<entries->count; i++) {
        LogEntry* entry = &(entries->entries[i]);
        free(entry);
    }

    free(entries->entries);
    free(entries);
}

LogEntries* filter_by_level(LogEntries* entries, char* level) {
    LogEntries* filtered_entries = malloc(sizeof(LogEntries));
    filtered_entries->count = 0;
    filtered_entries->entries = malloc(0);

    for (int i=0; i<entries->count; i++) {
        LogEntry* entry = &(entries->entries[i]);
        if (strcmp(entry->level, level) == 0) {
            // Add LogEntry to filtered_entries array
            filtered_entries->count++;
            filtered_entries->entries = realloc(filtered_entries->entries, filtered_entries->count*sizeof(LogEntry));
            filtered_entries->entries[filtered_entries->count-1] = *entry;
        }
    }

    return filtered_entries;
}