//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Struct to hold information for each log line
typedef struct {
    char date[20];
    char time[20];
    char hostname[256];
    char message[512];
} LogLine;

// Function to parse log file and split each line into information
int parseLogFile(FILE *logFile, LogLine logLines[], int maxLines) {
    char line[MAX_LINE_LENGTH];
    int currentLine = 0;

    while (fgets(line, MAX_LINE_LENGTH, logFile) && currentLine < maxLines) {
        char *token;
        char delimiter[] = " [";
        int index = 0;
        bool foundClosingBracket = false;

        // Split line into tokens using delimiter "["
        token = strtok(line, delimiter);

        while (token) {
            // Remove trailing whitespace from token
            char lastChar = token[strlen(token) - 1];

            while (lastChar == ' ' || lastChar == '\t' || lastChar == '\n' || lastChar == '\r') {
                token[strlen(token) - 1] = '\0';
                lastChar = token[strlen(token) - 1];
            }

            // Check if token contains closing bracket, signifying end of hostname
            if (strchr(token, ']')) {
                foundClosingBracket = true;
            }

            // Assign token to appropriate field in LogLine struct
            if (index == 0) {
                strncpy(logLines[currentLine].date, token, 20);
            } else if (index == 1) {
                strncpy(logLines[currentLine].time, token, 20);
            } else if (foundClosingBracket) {
                strncat(logLines[currentLine].hostname, token, 256);
            } else {
                strncat(logLines[currentLine].message, token, 512);
            }

            // Get next token
            token = strtok(NULL, delimiter);
            index++;
        }

        currentLine++;
    }

    return currentLine;
}

// Function to print an individual LogLine struct
void printLogLine(LogLine logLine) {
    printf("%s %s [%s] %s\n", logLine.date, logLine.time, logLine.hostname, logLine.message);
}

int main() {
    FILE *logFile;
    LogLine logLines[1000];
    int maxLines = 1000;
    int numLines;

    // Open log file
    logFile = fopen("example.log", "r");

    // Parse log file
    numLines = parseLogFile(logFile, logLines, maxLines);

    // Print each LogLine struct
    for (int i = 0; i < numLines; i++) {
        printLogLine(logLines[i]);
    }

    // Close log file
    fclose(logFile);

    return 0;
}