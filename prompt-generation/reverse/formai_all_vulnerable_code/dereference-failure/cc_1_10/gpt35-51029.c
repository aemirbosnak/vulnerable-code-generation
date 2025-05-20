//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 200
#define IP_SIZE 16
#define DATE_SIZE 20
#define METHOD_SIZE 10

typedef struct LogEntry {
    char ip[IP_SIZE];
    char date[DATE_SIZE];
    char method[METHOD_SIZE];
    int status;
    char userAgent[LINE_SIZE];
} LogEntry;

void parseEntry(char* line, LogEntry* entry) {
    char* token;
    token = strtok(line, " ");
    strncpy(entry->ip, token, IP_SIZE);

    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    strncpy(entry->date, token+1, DATE_SIZE);

    token = strtok(NULL, " ");
    strncpy(entry->method, token+1, METHOD_SIZE);

    token = strtok(NULL, " ");
    entry->status = atoi(token);

    token = strtok(NULL, "\"");
    token = strtok(NULL, "\"");
    strncpy(entry->userAgent, token+1, LINE_SIZE);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    FILE* logFile = fopen(argv[1], "r");
    if(logFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char line[LINE_SIZE];
    LogEntry entry;
    int numEntries = 0;
    int numErrors = 0;
    int numRedirects = 0;
    int statusCounts[6] = {0};

    while(fgets(line, LINE_SIZE, logFile) != NULL) {
        parseEntry(line, &entry);

        if(entry.status >= 400) {
            numErrors++;
        }
        if(entry.status == 302) {
            numRedirects++;
        }

        statusCounts[entry.status/100]++;

        numEntries++;
    }

    fclose(logFile);

    printf("Total entries: %d\n", numEntries);
    printf("Errors: %d\n", numErrors);
    printf("Redirects: %d\n", numRedirects);
    printf("Status details: %d %d %d %d %d %d\n", statusCounts[0], statusCounts[1], statusCounts[2], statusCounts[3], statusCounts[4], statusCounts[5]);

    return 0;
}