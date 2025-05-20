//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000

typedef struct LogEntry {
    char timestamp[20];
    char source[50];
    char event[100];
} LogEntry;

void logEvent(LogEntry *logArray, char *source, char *event) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    sprintf(logArray->timestamp, "%d-%02d-%02d %02d:%02d:%02d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    strcpy(logArray->source, source);
    strcpy(logArray->event, event);
}

int main() {
    LogEntry logArray[MAX_LOG_ENTRIES];
    int numEntries = 0;

    logEvent(&logArray[numEntries], "Intrusion Detection System", "System initialization");

    char userInput[50];

    while (1) {
        printf("Enter a command: ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = 0;

        if (strcmp(userInput, "quit") == 0) {
            logEvent(&logArray[++numEntries], "User", "Quit command entered");
            break;
        } else if (strcmp(userInput, "view logs") == 0) {
            printf("Timestamp                     Source                           Event\n");
            printf("--------------------------------------------------------------------------------\n");
            for (int i = 0; i < numEntries; i++) {
                printf("%-30s %-32s %s\n", logArray[i].timestamp, logArray[i].source, logArray[i].event);
            }
            printf("\n");
            logEvent(&logArray[++numEntries], "User", "View logs command entered");
        } else {
            printf("Invalid command. Valid commands are: view logs, quit.\n");
            logEvent(&logArray[++numEntries], "User", "Invalid command entered");
        }
    }

    return 0;
}