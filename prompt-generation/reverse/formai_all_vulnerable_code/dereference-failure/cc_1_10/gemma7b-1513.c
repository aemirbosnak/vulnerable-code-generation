//Gemma-7B DATASET v1.0 Category: System event logger ; Style: portable
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define MAX_LOG_ENTRIES 10

typedef struct LogEntry
{
    char timestamp[26];
    char message[MAX_LOG_SIZE];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];

void logEvent(char *message)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    sprintf(logEntries[0].timestamp, "%02d/%02d/%02d %02d:%02d:%02d", tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_hour, tm->tm_min, tm->tm_sec);
    strcpy(logEntries[0].message, message);

    for (int i = 1; i < MAX_LOG_ENTRIES; i++)
    {
        if (logEntries[i].timestamp[0] == '\0')
        {
            sprintf(logEntries[i].timestamp, "%02d/%02d/%02d %02d:%02d:%02d", tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_hour, tm->tm_min, tm->tm_sec);
            strcpy(logEntries[i].message, message);
            return;
        }
    }

    printf("Log full!\n");
}

int main()
{
    logEvent("This is a log event.");
    logEvent("Another event!");
    logEvent("The log is full!");

    for (int i = 0; i < MAX_LOG_ENTRIES; i++)
    {
        if (logEntries[i].timestamp[0] != '\0')
        {
            printf("%s: %s\n", logEntries[i].timestamp, logEntries[i].message);
        }
    }

    return 0;
}