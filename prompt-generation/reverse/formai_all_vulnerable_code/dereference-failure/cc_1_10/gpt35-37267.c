//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_ATTACK_COUNT 3

// Structure to hold log information
typedef struct {
    int hour;
    int minute;
    int second;
    char ip[16];
    char message[100];
} Log;

// Function to parse log line and populate Log structure
Log parseLogLine(char* logLine) {
    Log logEntry;
    char* token = strtok(logLine, " ");
    logEntry.hour = atoi(token);
    token = strtok(NULL, " ");
    logEntry.minute = atoi(token);
    token = strtok(NULL, " ");
    logEntry.second = atoi(token);
    token = strtok(NULL, " ");
    strcpy(logEntry.ip, token);
    token = strtok(NULL, "\n");
    strcpy(logEntry.message, token);
    return logEntry;
}

// Function to check if IP has done more than the allowed number of attacks within the given window
int checkForIntrusion(Log logEntries[], int currentLogIndex) {
    int i, count = 0;
    for (i = currentLogIndex-1; i >= 0 && logEntries[currentLogIndex].hour - logEntries[i].hour <= 1; i--) {
        if (!strcmp(logEntries[currentLogIndex].ip, logEntries[i].ip)) {
            count++;
            if (count >= MAX_ATTACK_COUNT)
                return 1;
        }
    }
    return 0;
}

int main() {
    char logs[MAX_LOG_SIZE];
    Log logEntries[MAX_LOG_SIZE];
    FILE* logFile = fopen("system-log.txt", "r");
    if (!logFile) {
        printf("Error opening log file.\n");
        exit(1);
    }
    fgets(logs, MAX_LOG_SIZE, logFile);
    int logIndex = 0;
    while (!feof(logFile)) {
        Log logEntry = parseLogLine(logs);
        logEntries[logIndex] = logEntry;
        if (checkForIntrusion(logEntries, logIndex)) {
            printf("Possible intrusion detected from %s\n", logEntry.ip);
        }
        logIndex++;
        fgets(logs, MAX_LOG_SIZE, logFile);
    }
    fclose(logFile);
    return 0;
}