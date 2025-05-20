//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define SUCCESS 0
#define FAILURE 1

// Declare a struct to hold relevant fields of a log line
typedef struct {
    char time[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogLine;

// Function to parse a line of log and fill up the LogLine struct
int parseLogLine(char* line, LogLine* logLine) {
    char* token;
    int i=0;
    while ((token = strsep(&line, " ")) != NULL) {
        if (i == 0) {
            strcpy(logLine->time, token);
        } else if (i == 1) {
            strcpy(logLine->level, token);
        } else {
            strcat(logLine->message, token);
            strcat(logLine->message, " ");
        }
        i++;
    }

    // Remove the last space and newline character from the message
    logLine->message[strlen(logLine->message)-2] = '\0';

    return SUCCESS;
}

int main(int argc, char* argv[]) {
    FILE* logFile;
    char* logFileName;
    char line[MAX_LINE_LENGTH];
    LogLine logLine;

    // Check if a log file name is provided as a command line argument
    if (argc != 2) {
        printf("Usage: %s <log_file_name>\n", argv[0]);
        return FAILURE;
    }
    logFileName = argv[1];

    // Open the log file
    logFile = fopen(logFileName, "r");
    if (logFile == NULL) {
        printf("Failed to open log file %s\n", logFileName);
        return FAILURE;
    }

    // Read each line of the log file and parse it
    while (fgets(line, MAX_LINE_LENGTH, logFile)) {
        parseLogLine(line, &logLine);

        // Do any analysis with the log data and print the result
        if (strstr(logLine.message, "error") != NULL) {
            printf("Time: %s, Level: %s, Message: %s", logLine.time, logLine.level, logLine.message);
        }
    }

    // Close the log file and return success
    fclose(logFile);
    return SUCCESS;
}