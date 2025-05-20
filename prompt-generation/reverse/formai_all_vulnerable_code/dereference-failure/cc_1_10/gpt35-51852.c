//FormAI DATASET v1.0 Category: Log analysis ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our log data structure
typedef struct log {
    char time[20];
    char message[100];
    int level;
} Log;

int main() {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    Log logs[100]; // Assume we have at most 100 logs
    int num_logs = 0;

    file = fopen("example_log.log", "r");

    if (file == NULL) {
        printf("Failed to open log file.\n");
        exit(EXIT_FAILURE);
    }

    // Read in log file line by line
    while ((read = getline(&line, &len, file)) != -1) {

        // Tokenize the line to extract time, level, and message
        char *token = strtok(line, " ");
        Log log_entry;
        strcpy(log_entry.time, token);

        token = strtok(NULL, " ");
        log_entry.level = atoi(token);

        token = strtok(NULL, "\n");
        strcpy(log_entry.message, token);

        // Add the log entry to our array of logs
        logs[num_logs] = log_entry;
        num_logs++;
    }

    // Search for logs with level >= 3
    printf("Logs with level >= 3:\n");
    for (int i = 0; i < num_logs; i++) {
        if (logs[i].level >= 3) {
            printf("%s [%d]: %s\n", logs[i].time, logs[i].level, logs[i].message);
        }
    }

    // Search for logs containing "error"
    printf("Logs containing 'error':\n");
    for (int i = 0; i < num_logs; i++) {
        if (strstr(logs[i].message, "error") != NULL) {
            printf("%s [%d]: %s\n", logs[i].time, logs[i].level, logs[i].message);
        }
    }

    // Free memory and close file
    if (line) {
        free(line);
    }
    fclose(file);

    return 0;
}