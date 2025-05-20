//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

struct LogEntry {
    char IP[16];
    char date[20];
    char time[10];
    char request[MAX_LINE_LENGTH];
    char status[10];
    char user_agent[MAX_LINE_LENGTH];
};

void parseLogEntry(char *line, struct LogEntry *entry) {
    char *token = strtok(line, " ");
    strcpy(entry->IP, token);
    token = strtok(NULL, " ");
    strcpy(entry->date, token);
    token = strtok(NULL, " ");
    strcpy(entry->time, token);
    token = strtok(NULL, " ");
    strcpy(entry->request, token);
    token = strtok(NULL, " ");
    strcpy(entry->status, token);
    token = strtok(NULL, " ");
    strcpy(entry->user_agent, token);
}

int main() {
    FILE *log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    struct LogEntry entry;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        parseLogEntry(line, &entry);
        printf("IP: %s\n", entry.IP);
        printf("Date: %s\n", entry.date);
        printf("Time: %s\n", entry.time);
        printf("Request: %s\n", entry.request);
        printf("Status: %s\n", entry.status);
        printf("User Agent: %s\n", entry.user_agent);
        printf("\n");
    }

    fclose(log_file);
    return 0;
}