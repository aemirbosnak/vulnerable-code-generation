//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_LENGTH 100

struct LogEntry {
    char ip[20];
    char method[10];
    char url[50];
    char status[10];
    char time[20];
};

int main() {
    FILE *logFile;
    struct LogEntry logEntries[MAX_LOG_ENTRIES];
    int numEntries = 0;

    logFile = fopen("logfile.txt", "r");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    char line[MAX_LOG_ENTRY_LENGTH];
    while (fgets(line, MAX_LOG_ENTRY_LENGTH, logFile)!= NULL) {
        if (numEntries >= MAX_LOG_ENTRIES) {
            printf("Error: Maximum number of log entries reached.\n");
            exit(1);
        }

        char *ip = strtok(line, " ");
        char *method = strtok(NULL, " ");
        char *url = strtok(NULL, " ");
        char *status = strtok(NULL, " ");
        char *time = strtok(NULL, "\n");

        strcpy(logEntries[numEntries].ip, ip);
        strcpy(logEntries[numEntries].method, method);
        strcpy(logEntries[numEntries].url, url);
        strcpy(logEntries[numEntries].status, status);
        strcpy(logEntries[numEntries].time, time);

        numEntries++;
    }

    fclose(logFile);

    printf("IP\tMethod\tURL\tStatus\tTime\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%s\t%s\t%s\t%s\n", logEntries[i].ip, logEntries[i].method, logEntries[i].url, logEntries[i].status, logEntries[i].time);
    }

    return 0;
}