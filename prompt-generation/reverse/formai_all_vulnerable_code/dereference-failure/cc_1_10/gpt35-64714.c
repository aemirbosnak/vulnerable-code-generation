//FormAI DATASET v1.0 Category: Log analysis ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG 100 // maximum number of log entries
#define MAX_LINE 200 // maximum length of a log entry

struct LogEntry {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char message[MAX_LINE];
};

int main() {
    struct LogEntry logs[MAX_LOG];
    int num_logs = 0;
    char line[MAX_LINE];
    char* token;

    // read log file
    FILE* file = fopen("logfile.txt", "r");
    if (file == NULL) {
        printf("Error: could not open logfile.txt\n");
        return 1;
    }
    while (fgets(line, MAX_LINE, file) != NULL && num_logs < MAX_LOG) {
        struct LogEntry entry;
        token = strtok(line, "/");
        entry.year = atoi(token);
        token = strtok(NULL, "/");
        entry.month = atoi(token);
        token = strtok(NULL, " ");
        entry.day = atoi(token);
        token = strtok(NULL, ":");
        entry.hour = atoi(token);
        token = strtok(NULL, ":");
        entry.minute = atoi(token);
        token = strtok(NULL, " ");
        entry.second = atoi(token);
        token = strtok(NULL, "\n");
        strncpy(entry.message, token, MAX_LINE);
        logs[num_logs++] = entry;
    }
    fclose(file);

    // analyze logs
    int num_errors = 0;
    int num_warnings = 0;
    int num_infos = 0;
    int num_debugs = 0;
    for (int i = 0; i < num_logs; i++) {
        if (strstr(logs[i].message, "[ERROR]")) {
            num_errors++;
        } else if (strstr(logs[i].message, "[WARNING]")) {
            num_warnings++;
        } else if (strstr(logs[i].message, "[INFO]")) {
            num_infos++;
        } else if (strstr(logs[i].message, "[DEBUG]")) {
            num_debugs++;
        }
    }

    // output analysis
    printf("Log analysis:\n");
    printf("Number of log entries: %d\n", num_logs);
    printf("Number of error entries: %d\n", num_errors);
    printf("Number of warning entries: %d\n", num_warnings);
    printf("Number of info entries: %d\n", num_infos);
    printf("Number of debug entries: %d\n", num_debugs);
    printf("\n");

    return 0;
}