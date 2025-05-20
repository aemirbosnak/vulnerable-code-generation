//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 256

typedef struct {
    char ip[16];
    char date[20];
    char time[10];
    char request[MAX_LOG_ENTRY_LENGTH];
    char response_code[10];
    char response_message[MAX_LOG_ENTRY_LENGTH];
} LogEntry;

int compare_entries(const void *a, const void *b) {
    const LogEntry *entry1 = (const LogEntry *)a;
    const LogEntry *entry2 = (const LogEntry *)b;

    if (strcmp(entry1->date, entry2->date) < 0) {
        return -1;
    } else if (strcmp(entry1->date, entry2->date) > 0) {
        return 1;
    } else {
        if (strcmp(entry1->time, entry2->time) < 0) {
            return -1;
        } else if (strcmp(entry1->time, entry2->time) > 0) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    FILE *logfile;
    char line[MAX_LOG_ENTRY_LENGTH];
    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    logfile = fopen("access.log", "r");

    if (logfile == NULL) {
        printf("Error: could not open log file\n");
        exit(1);
    }

    while (fgets(line, MAX_LOG_ENTRY_LENGTH, logfile)!= NULL) {
        LogEntry entry;
        char *token;

        // Parse the log entry
        token = strtok(line, " ");
        strcpy(entry.ip, token);

        token = strtok(NULL, " ");
        strcpy(entry.date, token);

        token = strtok(NULL, " ");
        strcpy(entry.time, token);

        token = strtok(NULL, " ");
        strcpy(entry.request, token);

        token = strtok(NULL, " ");
        strcpy(entry.response_code, token);

        token = strtok(NULL, " ");
        strcpy(entry.response_message, token);

        // Add the entry to the array
        if (num_entries < MAX_LOG_ENTRIES) {
            entries[num_entries++] = entry;
        } else {
            printf("Warning: log file contains more than %d entries\n", MAX_LOG_ENTRIES);
        }
    }

    fclose(logfile);

    // Sort the entries by date and time
    qsort(entries, num_entries, sizeof(LogEntry), compare_entries);

    // Print the sorted entries
    printf("Log Entries:\n");
    printf("---------------------\n");
    printf("IP\tDate\tTime\tRequest\tResponse Code\tResponse Message\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", entries[i].ip, entries[i].date, entries[i].time, entries[i].request, entries[i].response_code, entries[i].response_message);
    }

    return 0;
}