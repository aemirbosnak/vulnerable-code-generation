//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_SIZE 512

struct LogEntry {
    char timestamp[20];
    char message[MAX_LOG_ENTRY_SIZE];
};

void parse_log_entry(char entry[MAX_LOG_ENTRY_SIZE], struct LogEntry* output_entry) {
    // Extract timestamp and message from log entry string
    char* token;
    token = strtok(entry, " ");
    strncpy(output_entry->timestamp, token, 20);
    token = strtok(NULL, "\n");
    strncpy(output_entry->message, token, MAX_LOG_ENTRY_SIZE);
}

int main() {
    // Open log file for reading
    FILE* fp;
    fp = fopen("example.log", "r");

    if (fp == NULL) {
        printf("Error opening log file.\n");
        return -1;
    }

    // Read log entries into array of LogEntry structs
    struct LogEntry log_entries[MAX_LOG_ENTRIES];
    int entry_count = 0;
    char entry[MAX_LOG_ENTRY_SIZE];

    while (fgets(entry, MAX_LOG_ENTRY_SIZE, fp) != NULL) {
        parse_log_entry(entry, &log_entries[entry_count]);
        entry_count++;
    }

    // Close log file
    fclose(fp);

    // Print number of log entries read
    printf("Read %d log entries.\n", entry_count);

    // Print first and last log entries
    printf("First log entry:\n");
    printf("%s - %s\n", log_entries[0].timestamp, log_entries[0].message);
    printf("Last log entry:\n");
    printf("%s - %s\n", log_entries[entry_count-1].timestamp, log_entries[entry_count-1].message);

    // Count number of entries with "error" in message
    int error_count = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strstr(log_entries[i].message, "error") != NULL) {
            error_count++;
        }
    }
    printf("Found %d entries with \"error\" in the message.\n", error_count);

    return 0;
}