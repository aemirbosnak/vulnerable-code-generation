//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define LOG_FILE      "cryptic_log.txt"
#define MAX_LINE      256
#define MAX_ENTRIES   1000

typedef struct {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE];
} LogEntry;

void parse_log(FILE *file, LogEntry entries[], int *entry_count);
void display_logs(const LogEntry entries[], int entry_count);
void filter_by_level(const LogEntry entries[], int entry_count, const char *level);
void free_entries(LogEntry entries[], int entry_count);
void log_error(const char *message);

int main() {
    LogEntry entries[MAX_ENTRIES];
    int entry_count = 0;

    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        log_error("Failed to open log file");
        return EXIT_FAILURE;
    }

    parse_log(file, entries, &entry_count);
    fclose(file);
    
    printf("Parsed %d log entries:\n\n", entry_count);
    display_logs(entries, entry_count);
    
    printf("\nFilters:\n");
    filter_by_level(entries, entry_count, "ERROR");
    
    free_entries(entries, entry_count);
    return EXIT_SUCCESS;
}

void parse_log(FILE *file, LogEntry entries[], int *entry_count) {
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), file) && *entry_count < MAX_ENTRIES) {
        LogEntry entry;
        sscanf(line, "%19s %9s %255[^\n]", entry.timestamp, entry.level, entry.message);
        entries[(*entry_count)++] = entry;
    }
}

void display_logs(const LogEntry entries[], int entry_count) {
    for (int i = 0; i < entry_count; i++) {
        printf("[%s] [%s]: %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
    }
}

void filter_by_level(const LogEntry entries[], int entry_count, const char *level) {
    printf("Logs with level '%s':\n", level);
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(entries[i].level, level) == 0) {
            printf("[%s] [%s]: %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
        }
    }
}

void free_entries(LogEntry entries[], int entry_count) {
    // In this simplistic example, nothing dynamically allocated;
    // but this function is a placeholder for future expansions
}

void log_error(const char *message) {
    fprintf(stderr, "Error: %s. Code: %s\n", message, strerror(errno));
}