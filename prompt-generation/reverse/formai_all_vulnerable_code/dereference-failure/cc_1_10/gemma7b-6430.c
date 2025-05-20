//Gemma-7B DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry
{
    char timestamp[26];
    char event_name[256];
    char event_details[MAX_LOG_SIZE];
} LogEntry;

LogEntry log_entries[1024];

void log_event(char *event_name, char *event_details)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    LogEntry new_entry;
    new_entry.timestamp[0] = '\0';
    snprintf(new_entry.timestamp, 26, "%d/%d/%d %H:%M:%S", tm->tm_year, tm->tm_mon, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
    new_entry.event_name[0] = '\0';
    strcpy(new_entry.event_name, event_name);
    new_entry.event_details[0] = '\0';
    strcpy(new_entry.event_details, event_details);

    int i = 0;
    for (; i < 1024; i++)
    {
        if (log_entries[i].timestamp[0] == '\0')
        {
            log_entries[i] = new_entry;
            break;
        }
    }

    if (i == 1024)
    {
        printf("Log full!\n");
    }
}

int main()
{
    log_event("System boot", "The system has booted successfully.");
    log_event("User login", "User with username 'john.doe' has logged in.");
    log_event("Application launch", "Application 'My App' has been launched.");

    return 0;
}