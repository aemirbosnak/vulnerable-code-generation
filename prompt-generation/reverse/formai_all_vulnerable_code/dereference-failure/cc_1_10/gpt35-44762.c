//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 1000
#define MAX_LENGTH 100

typedef struct {
    char timestamp[MAX_LENGTH];
    char message[MAX_LENGTH];
} LogEntry;

void printMenu() {
    printf("\n********** Log Analyzer **********\n");
    printf("1. Load log file\n");
    printf("2. Display log entries\n");
    printf("3. Search log\n");
    printf("4. Exit\n");
}

int main() {
    LogEntry logEntries[MAX_LINES];
    int logLineCount = 0;

    while (1) {
        printMenu();
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the name of the log file: ");
            char fileName[MAX_LENGTH];
            scanf("%s", fileName);
            FILE *filePointer = fopen(fileName, "r");

            if (filePointer == NULL) {
                printf("Could not open file");
                continue;
            }

            char buffer[MAX_LENGTH];
            while (fgets(buffer, MAX_LENGTH, filePointer)) {
                char *token = strtok(buffer, ":");
                strcpy(logEntries[logLineCount].timestamp, token);

                token = strtok(NULL, ":");
                strcpy(logEntries[logLineCount].message, token);
                logLineCount++;
            }

            printf("%d log entries read from file\n", logLineCount);
            fclose(filePointer);
        } else if (choice == 2) {
            if (logLineCount == 0) {
                printf("No log entries loaded yet\n");
                continue;
            }

            printf("Timestamp\tMessage\n");
            for (int i = 0; i < logLineCount; i++) {
                printf("%s\t%s", logEntries[i].timestamp, logEntries[i].message);
            }
        } else if (choice == 3) {
            if (logLineCount == 0) {
                printf("No log entries loaded yet\n");
                continue;
            }

            printf("Enter search term: ");
            char searchTerm[MAX_LENGTH];
            scanf("%s", searchTerm);

            printf("Timestamp\tMessage\n");
            for (int i = 0; i < logLineCount; i++) {
                if (strstr(logEntries[i].message, searchTerm) != NULL) {
                    printf("%s\t%s", logEntries[i].timestamp, logEntries[i].message);
                }
            }
        } else if (choice == 4) {
            printf("Exiting program\n");
            exit(0);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}