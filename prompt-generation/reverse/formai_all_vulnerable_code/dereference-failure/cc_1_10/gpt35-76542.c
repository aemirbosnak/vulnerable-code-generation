//FormAI DATASET v1.0 Category: Log analysis ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_LOG_LINES = 100;

void analyzeLog(char *logFilePath) {
    char *logLine;
    size_t len = 0;
    ssize_t readBytes;
    int totalLinesRead = 0;
    int errorCount = 0;
    char *errorMessages[MAX_LOG_LINES];

    FILE *logFile = fopen(logFilePath, "r");
    if(logFile == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while((readBytes = getline(&logLine, &len, logFile)) != -1) {
        totalLinesRead++;
        
        if(strstr(logLine, "ERROR") != NULL) {
            errorCount++;
            char *errorMessage = (char*)malloc(sizeof(char)*strlen(logLine));
            errorMessage = strcpy(errorMessage, logLine);
            errorMessages[errorCount-1] = errorMessage;
        }
        
        if(totalLinesRead == MAX_LOG_LINES)
            break;
    }
    
    printf("Total logs read: %d\n", totalLinesRead);
    printf("Number of errors: %d\n", errorCount);
    printf("Error messages:\n");
    for(int i=0; i<errorCount; i++) {
        printf("%s", errorMessages[i]);
    }

    fclose(logFile);
}

int main() {
    char *logFilePath = "example.log";
    analyzeLog(logFilePath);

    return 0;
}