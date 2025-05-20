//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 1024

typedef struct {
    char ip[16];
    char method[8];
    char url[256];
    char user_agent[256];
    int status_code;
    int bytes_sent;
    char timestamp[32];
} LogEntry;

int main() {
    FILE *logfile;
    char logbuffer[MAX_LOG_ENTRY_SIZE];
    LogEntry logentries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    // Open log file for reading
    logfile = fopen("access.log", "r");
    if (logfile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    // Read log entries from file
    while (fgets(logbuffer, MAX_LOG_ENTRY_SIZE, logfile)!= NULL) {
        LogEntry entry;
        char *token;

        // Parse log entry
        token = strtok(logbuffer, " ");
        strcpy(entry.ip, token);

        token = strtok(NULL, " ");
        strcpy(entry.method, token);

        token = strtok(NULL, " ");
        strcpy(entry.url, token);

        token = strtok(NULL, " ");
        strcpy(entry.user_agent, token);

        entry.status_code = atoi(strtok(NULL, " "));
        entry.bytes_sent = atoi(strtok(NULL, " "));

        // Convert timestamp to human-readable format
        strcpy(entry.timestamp, ctime(&entry.bytes_sent));

        // Add entry to array
        if (num_entries < MAX_LOG_ENTRIES) {
            logentries[num_entries++] = entry;
        }
    }

    // Close log file
    fclose(logfile);

    // Print summary
    printf("Total log entries: %d\n", num_entries);
    for (int i = 0; i < num_entries; i++) {
        printf("IP: %s\n", logentries[i].ip);
        printf("Method: %s\n", logentries[i].method);
        printf("URL: %s\n", logentries[i].url);
        printf("User agent: %s\n", logentries[i].user_agent);
        printf("Status code: %d\n", logentries[i].status_code);
        printf("Bytes sent: %d\n", logentries[i].bytes_sent);
        printf("Timestamp: %s\n", logentries[i].timestamp);
        printf("\n");
    }

    return 0;
}