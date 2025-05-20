//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 100
#define MAX_LINE_LENGTH 200

typedef struct {
    char* timestamp;
    char* message;
} Log;

Log logs[MAX_LOGS];
int numLogs = 0;

int main()
{
    FILE* fp;
    char* filename = "example.log";
    char line[MAX_LINE_LENGTH];
    char* timestamp;
    char* message;
    int i;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file \"%s\".\n", filename);
        return -1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        line[strcspn(line, "\r\n")] = '\0'; // Remove newline character(s)

        char* token;
        token = strtok(line, " ");
        timestamp = token;

        token = strtok(NULL, "\n");
        message = token;

        logs[numLogs].timestamp = (char*) malloc(strlen(timestamp) + 1);
        strcpy(logs[numLogs].timestamp, timestamp);

        logs[numLogs].message = (char*) malloc(strlen(message) + 1);
        strcpy(logs[numLogs].message, message);

        numLogs++;
    }

    fclose(fp);

    // Print all logs
    printf("All logs:\n");
    for (i = 0; i < numLogs; i++) {
        printf("%s: %s\n", logs[i].timestamp, logs[i].message);
    }

    // Print logs from 2021-05-01 00:00:00 to 2021-05-31 23:59:59
    printf("\nLogs from 2021-05-01 00:00:00 to 2021-05-31 23:59:59:\n");
    for (i = 0; i < numLogs; i++) {
        if (strcmp(logs[i].timestamp, "2021-05-01 00:00:00") >= 0 &&
                strcmp(logs[i].timestamp, "2021-05-31 23:59:59") <= 0) {
            printf("%s: %s\n", logs[i].timestamp, logs[i].message);
        }
    }

    // Print logs containing the word "error"
    printf("\nLogs containing the word \"error\":\n");
    for (i = 0; i < numLogs; i++) {
        if (strstr(logs[i].message, "error")) {
            printf("%s: %s\n", logs[i].timestamp, logs[i].message);
        }
    }

    // Free memory allocated for logs
    for (i = 0; i < numLogs; i++) {
        free(logs[i].timestamp);
        free(logs[i].message);
    }

    return 0;
}