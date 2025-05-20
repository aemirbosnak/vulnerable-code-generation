//FormAI DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LINE_LENGTH 100

typedef struct log_entry {
    char timestamp[20];
    char message[MAX_LOG_LINE_LENGTH];
} log_entry;

int main() {
    char log_file_name[50];
    printf("Enter log file name: ");
    scanf("%s", log_file_name);

    FILE *log_file = fopen(log_file_name, "r");
    if (log_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, MAX_LOG_LINE_LENGTH, log_file) != NULL) {
        // parse log entry
        char* token;
        token = strtok(line, ",");
        strcpy(log_entries[num_entries].timestamp, token);
        token = strtok(NULL, ",");
        strcpy(log_entries[num_entries].message, token);

        num_entries++;
    }

    // analyze log entries
    int num_warnings = 0;
    int num_errors = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(log_entries[i].message, "WARNING") != NULL) {
            num_warnings++;
        }
        if (strstr(log_entries[i].message, "ERROR") != NULL) {
            num_errors++;
        }
    }

    printf("Number of log entries: %d\n", num_entries);
    printf("Number of warnings: %d\n", num_warnings);
    printf("Number of errors: %d\n", num_errors);

    return 0;
}