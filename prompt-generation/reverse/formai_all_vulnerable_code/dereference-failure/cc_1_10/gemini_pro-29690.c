//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *date;
    char *time;
    char *level;
    char *message;
} LogEntry;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the log file
    FILE *logfile = fopen(argv[1], "r");
    if (logfile == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Allocate an array of log entries
    LogEntry *logEntries = malloc(sizeof(LogEntry) * 100);
    if (logEntries == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the log file line by line
    char line[1024];
    int i = 0;
    while (fgets(line, sizeof(line), logfile) != NULL) {
        // Parse the log line
        char *date = strtok(line, " ");
        char *time = strtok(NULL, " ");
        char *level = strtok(NULL, " ");
        char *message = strtok(NULL, "\n");

        // Store the log entry
        logEntries[i].date = strdup(date);
        logEntries[i].time = strdup(time);
        logEntries[i].level = strdup(level);
        logEntries[i].message = strdup(message);

        i++;
    }

    // Close the log file
    fclose(logfile);

    // Print the log entries
    for (int j = 0; j < i; j++) {
        printf("%s %s %s %s\n", logEntries[j].date, logEntries[j].time, logEntries[j].level, logEntries[j].message);

        // Free the log entry
        free(logEntries[j].date);
        free(logEntries[j].time);
        free(logEntries[j].level);
        free(logEntries[j].message);
    }

    // Free the array of log entries
    free(logEntries);

    return EXIT_SUCCESS;
}