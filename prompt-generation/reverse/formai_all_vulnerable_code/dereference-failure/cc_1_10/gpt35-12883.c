//FormAI DATASET v1.0 Category: Log analysis ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100  // Maximum number of log entries to read
#define MAX_LINE_LENGTH 200  // Maximum length of a single log entry line

// Struct to hold log entry information
typedef struct {
    char timestamp[20];
    char filename[50];
    int line_num;
    char message[MAX_LINE_LENGTH];
} LogEntry;

// Function to parse a single log entry line and fill out a LogEntry struct
void parseLogEntry(char *line, LogEntry *entry) {
    
    // Split the line by whitespace using strtok
    char *token;
    token = strtok(line, " ");
    strcpy(entry->timestamp, token);
    
    token = strtok(NULL, " ");
    strcpy(entry->filename, token);
    
    token = strtok(NULL, " ");
    entry->line_num = atoi(token);
    
    token = strtok(NULL, "");
    strncpy(entry->message, token, MAX_LINE_LENGTH);
}

int main() {
    
    // Open the log file
    FILE *file = fopen("example_log.txt", "r");
    if (file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }
    
    // Allocate an array of LogEntry structs
    LogEntry log_entries[MAX_LOG_ENTRIES];
    
    // Read in each log entry from the file
    char line[MAX_LINE_LENGTH];
    int num_entries = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && num_entries < MAX_LOG_ENTRIES) {
        parseLogEntry(line, &log_entries[num_entries]);
        num_entries++;
    }
    
    // Close the log file
    fclose(file);
    
    // Print out the log entries in reverse order
    for (int i = num_entries-1; i >= 0; i--) {
        printf("%s %s:%d - %s\n", log_entries[i].timestamp, log_entries[i].filename, log_entries[i].line_num, log_entries[i].message);
    }
    
    return 0;
}