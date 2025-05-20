//FormAI DATASET v1.0 Category: System event logger ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024

void logEvent(char *event, char *severity)
{
    FILE *logFile;
    char logLine[MAX_LENGTH];
    time_t currentTime;
    struct tm *localTime;
    
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    
    sprintf(logLine, "[%04d-%02d-%02d %02d:%02d:%02d][%s] [%s]\n",
        localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
        localTime->tm_hour, localTime->tm_min, localTime->tm_sec, 
        severity, event);
    
    logFile = fopen("systemlog.txt", "a");
    if(logFile == NULL)
    {
        fprintf(stderr, "Error opening log file\n");
        exit(1);
    }
    
    fputs(logLine, logFile);
    fclose(logFile);
}

int main()
{
    char event[MAX_LENGTH], severity[MAX_LENGTH];
    printf("Enter the event to log: ");
    fgets(event, MAX_LENGTH, stdin);
    event[strcspn(event, "\n")] = '\0';
    
    printf("Enter the severity of the event (INFO/WARNING/ERROR): ");
    fgets(severity, MAX_LENGTH, stdin);
    severity[strcspn(severity, "\n")] = '\0';
    
    if(strcmp(severity, "INFO") != 0 && strcmp(severity, "WARNING") != 0 && strcmp(severity, "ERROR") != 0)
    {
        printf("Invalid severity level\n");
        return 1;
    }
    
    logEvent(event, severity);
    printf("Event logged successfully\n");
    
    return 0;
}