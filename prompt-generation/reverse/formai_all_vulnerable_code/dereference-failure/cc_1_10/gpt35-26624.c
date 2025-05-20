//FormAI DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

/* Struct to hold log data */
typedef struct LogEntry {
    char date[20];
    char time[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

/* Function to parse a line of log data into a LogEntry struct */
LogEntry parse_log_entry(char *line) {
    LogEntry entry;
    char *token;

    token = strtok(line, " ");
    strcpy(entry.date, token);

    token = strtok(NULL, " ");
    strcpy(entry.time, token);

    token = strtok(NULL, " ");
    strcpy(entry.level, token);

    token = strtok(NULL, "\n");
    strcpy(entry.message, token);

    return entry;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: Please specify the name of the log file to read\n");
        return EXIT_FAILURE;
    }

    FILE *log_file = fopen(argv[1], "r");

    if (!log_file) {
        printf("Error: Failed to open log file\n");
        return EXIT_FAILURE;
    }

    int num_entries = 0;
    char line[MAX_LINE_LENGTH];
    LogEntry entries[1000];

    /* Read each line of the log file */
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        LogEntry entry = parse_log_entry(line);
        entries[num_entries++] = entry;
    }

    /* Print out the number of log entries */
    printf("Number of log entries: %d\n", num_entries);

    /* Count the number of log entries at each level */
    int num_debug = 0;
    int num_info = 0;
    int num_warning = 0;
    int num_error = 0;

    for (int i = 0; i < num_entries; i++) {
        LogEntry entry = entries[i];

        if (strcmp(entry.level, "DEBUG") == 0) {
            num_debug++;
        } else if (strcmp(entry.level, "INFO") == 0) {
            num_info++;
        } else if (strcmp(entry.level, "WARNING") == 0) {
            num_warning++;
        } else if (strcmp(entry.level, "ERROR") == 0) {
            num_error++;
        }
    }

    /* Print out the number of log entries at each level */
    printf("Number of DEBUG entries: %d\n", num_debug);
    printf("Number of INFO entries: %d\n", num_info);
    printf("Number of WARNING entries: %d\n", num_warning);
    printf("Number of ERROR entries: %d\n", num_error);

    fclose(log_file);

    return EXIT_SUCCESS;
}