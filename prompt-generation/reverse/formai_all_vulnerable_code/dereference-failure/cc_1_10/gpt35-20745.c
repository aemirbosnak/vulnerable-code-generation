//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000

typedef struct {
    char timestamp[30];
    char user[20];
    char action[100];
} LogEntry;

int main() {
    LogEntry entries[MAX_LOG_ENTRIES];
    int numEntries = 0;

    FILE *filePointer;
    filePointer = fopen("medieval_logs.txt", "r");

    if (filePointer == NULL) {
        printf("File does not exist.\n");
        return 0;
    }

    char line[150];
    while (fgets(line, sizeof(line), filePointer)) {
        char *timestamp = strtok(line, ",");
        char *user = strtok(NULL, ",");
        char *action = strtok(NULL, ",");

        strcpy(entries[numEntries].timestamp, timestamp);
        strcpy(entries[numEntries].user, user);
        strcpy(entries[numEntries].action, action);

        numEntries++;
    }

    fclose(filePointer);

    // Intrusion detection
    int numSuspiciousEntries = 0;
    LogEntry suspiciousEntries[MAX_LOG_ENTRIES];
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].action, "Unauthorized access attempt") == 0) {
            strcpy(suspiciousEntries[numSuspiciousEntries].timestamp, entries[i].timestamp);
            strcpy(suspiciousEntries[numSuspiciousEntries].user, entries[i].user);
            strcpy(suspiciousEntries[numSuspiciousEntries].action, entries[i].action);

            numSuspiciousEntries++;

            if (numSuspiciousEntries >= MAX_LOG_ENTRIES) {
                break;
            }
        }
    }

    // Print intrusion report
    printf("Medieval Intrusion Detection System Report:\n");
    printf("===========================================\n");

    if (numSuspiciousEntries == 0) {
        printf("No suspicious activity detected.\n");
    } else {
        printf("%d suspicious log entries detected:\n", numSuspiciousEntries);
        for (int i = 0; i < numSuspiciousEntries; i++) {
            printf("%s - User: %s - Action: %s", suspiciousEntries[i].timestamp, suspiciousEntries[i].user, suspiciousEntries[i].action);
        }
    }

    return 0;
}