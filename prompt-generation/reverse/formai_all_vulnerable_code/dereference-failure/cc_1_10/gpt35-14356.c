//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_LOGS 1000

typedef struct {
    char time[20];
    char ip[16];
    char username[32];
    char action[32];
} LogEntry;

void printLogs(LogEntry logs[], int count) {
    printf("%-20s %-15s %-30s %-32s\n", "Time", "IP Address", "Username", "Action");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-15s %-30s %-32s\n", logs[i].time, logs[i].ip, logs[i].username, logs[i].action);
    }
}

int main() {
    FILE *fp;
    char input[MAX_INPUT_SIZE];
    char *token;
    LogEntry logs[MAX_LOGS];
    int logCount = 0;

    fp = fopen("logs.txt", "r");
    if (fp == NULL) {
        printf("Could not open logs.txt\n");
        return 1;
    }

    while (fgets(input, MAX_INPUT_SIZE, fp) != NULL) {
        token = strtok(input, " ");
        strcpy(logs[logCount].time, token);

        token = strtok(NULL, " ");
        strcpy(logs[logCount].ip, token);

        token = strtok(NULL, " ");
        strcpy(logs[logCount].username, token);

        token = strtok(NULL, "\n");
        strcpy(logs[logCount].action, token);

        logCount++;
    }

    fclose(fp);

    printLogs(logs, logCount);

    return 0;
}