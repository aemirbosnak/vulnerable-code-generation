//FormAI DATASET v1.0 Category: Log analysis ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LINE_LENGTH 100

typedef struct {
    char date[20];
    char time[20];
    char level[10];
    char message[100];
} LogEntry;

int main() {
    LogEntry log_entries[MAX_LOG_ENTRIES];
    int entry_count = 0;
    char line[MAX_LINE_LENGTH];

    FILE *log_file = fopen("application.log", "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(1);
    }

    while (fgets(line, sizeof(line), log_file) != NULL) {
        if (entry_count >= MAX_LOG_ENTRIES) {
            printf("Maximum number of log entries exceeded!\n");
            break;
        }

        char *date_time = strtok(line, ",");
        strcpy(log_entries[entry_count].date, strtok(date_time, " "));
        strcpy(log_entries[entry_count].time, strtok(NULL, " "));

        char *level_message = strtok(NULL, ",");
        strcpy(log_entries[entry_count].level, strtok(level_message, " "));
        strcpy(log_entries[entry_count].message, strtok(NULL, "\n"));

        entry_count++;
    }

    fclose(log_file);

    // Example analysis: count how many ERROR-level log entries there are
    int error_count = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(log_entries[i].level, "ERROR") == 0) {
            error_count++;
        }
    }

    printf("Total number of log entries: %d\n", entry_count);
    printf("Number of ERROR-level log entries: %d\n", error_count);

    return 0;
}