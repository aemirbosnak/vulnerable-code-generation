//FormAI DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096
#define MAX_LOG_ENTRIES 100000

// Log entry struct
typedef struct {
    char date[20];
    char time[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

// Parse a single log entry from a line of text
LogEntry parse_entry(char* line) {
    LogEntry entry;
    char* token = strtok(line, " ");
    strncpy(entry.date, token, sizeof(entry.date));
    token = strtok(NULL, " ");
    strncpy(entry.time, token, sizeof(entry.time));
    token = strtok(NULL, " ");
    strncpy(entry.level, token, sizeof(entry.level));
    token = strtok(NULL, "\n");
    strncpy(entry.message, token, sizeof(entry.message));
    return entry;
}

// Read log entries from a file
int read_log_entries(char* filename, LogEntry* entries) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return -1;
    }
    char line[MAX_LINE_LENGTH];
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        entries[i] = parse_entry(line);
        i++;
    }
    fclose(file);
    return i;
}

// Print a log entry to stdout
void print_entry(LogEntry entry) {
    printf("[%s %s] %s: %s\n", entry.date, entry.time, entry.level, entry.message);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = read_log_entries(filename, entries);
    if (num_entries == -1) {
        return 1;
    }
    printf("Read %d log entries from file %s\n", num_entries, filename);
    for (int i = 0; i < num_entries; i++) {
        print_entry(entries[i]);
    }
    return 0;
}