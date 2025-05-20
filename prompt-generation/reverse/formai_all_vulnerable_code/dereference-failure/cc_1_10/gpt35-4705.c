//FormAI DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_LOG_LINES 5000

// define struct for log entries
typedef struct log_entry {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

// function declarations
void read_log_entries(char* file_path, LogEntry* entries);
void filter_by_level(LogEntry* entries, int num_entries, char* level);
void print_entries(LogEntry* entries, int num_entries);

int main(int argc, char** argv) {
    // check for correct usage
    if (argc < 3) {
        printf("Usage: %s log_file_path log_level\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    char* level = argv[2];

    // allocate memory for log entries
    LogEntry* entries = (LogEntry*) malloc(MAX_LOG_LINES * sizeof(LogEntry));
    if (entries == NULL) {
        printf("Error: memory allocation failed!\n");
        return 1;
    }

    // read log entries from file
    read_log_entries(file_path, entries);

    // filter log entries by level
    filter_by_level(entries, MAX_LOG_LINES, level);

    // print filtered log entries
    print_entries(entries, MAX_LOG_LINES);

    // free allocated memory
    free(entries);
    entries = NULL;

    return 0;
}

// function to read log entries from file
void read_log_entries(char* file_path, LogEntry* entries) {
    FILE* file = fopen(file_path, "r");

    if (file == NULL) {
        printf("Error: could not open file %s!\n", file_path);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && i < MAX_LOG_LINES) {
        // split line into timestamp, level, and message
        char* token;
        int j = 0;

        token = strtok(line, " ");
        strcpy(entries[i].timestamp, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].level, token);

        token = strtok(NULL, "\n");
        strcpy(entries[i].message, token);

        i++;
    }

    fclose(file);
}

// function to filter log entries by level
void filter_by_level(LogEntry* entries, int num_entries, char* level) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].level, level) != 0) {
            strcpy(entries[i].timestamp, "");
            strcpy(entries[i].level, "");
            strcpy(entries[i].message, "");
        }
    }
}

// function to print log entries
void print_entries(LogEntry* entries, int num_entries) {
    printf("Filtered Log Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strlen(entries[i].timestamp) > 0) {
            printf("%s %s: %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
        }
    }
}