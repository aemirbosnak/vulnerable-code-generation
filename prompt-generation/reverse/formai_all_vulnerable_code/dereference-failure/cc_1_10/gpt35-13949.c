//FormAI DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LENGTH 1000

// struct to store log entry information
typedef struct LogEntry {
    char* date;
    char* time;
    char* ip;
    char* message;  
} LogEntry;

// function to parse log file and store each entry in array of struct LogEntry
int parseLogFile(char* fileName, LogEntry logEntries[]) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        printf("Error opening file!");
        return -1;
    }

    char logEntry[MAX_LOG_LENGTH];
    int i = 0;

    // parse log file line by line
    while (fgets(logEntry, MAX_LOG_LENGTH, file)) {
        char* logLine = strdup(logEntry);
        char* token;
        token = strtok(logLine, ": ,");

        // allocate memory for struct LogEntry fields
        logEntries[i].date = (char*)malloc(strlen(token) + 1);
        strcpy(logEntries[i].date, token);
        token = strtok(NULL, ": ,");
        logEntries[i].time = (char*)malloc(strlen(token) + 1);
        strcpy(logEntries[i].time, token);
        token = strtok(NULL, ": ,");
        logEntries[i].ip = (char*)malloc(strlen(token) + 1);
        strcpy(logEntries[i].ip, token);
        token = strtok(NULL, ": ,");
        logEntries[i].message = (char*)malloc(strlen(token) + 1);
        strcpy(logEntries[i].message, token);

        i++;
        free(logLine);
    }

    fclose(file);

    return i;
}

// function to print all log entries in array of struct LogEntry
void printLogEntries(LogEntry logEntries[], int numEntries) {
    printf("LOG ENTRIES:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s %s %s %s\n", logEntries[i].date, logEntries[i].time, logEntries[i].ip, logEntries[i].message);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Invalid arguments. Usage: logAnalyzer <logFileName>\n");
        return -1;
    }

    printf("Parsing log file...\n");

    // allocate memory for array of struct LogEntry
    LogEntry logEntries[MAX_LOG_LENGTH];
    int numEntries = parseLogFile(argv[1], logEntries);

    if (numEntries == -1) {
        return -1;
    }

    printf("%d log entries parsed.\n", numEntries);

    // print all log entries
    printLogEntries(logEntries, numEntries);

    return 0;
}