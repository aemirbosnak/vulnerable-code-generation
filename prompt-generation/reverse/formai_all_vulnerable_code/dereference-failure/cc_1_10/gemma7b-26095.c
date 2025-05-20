//Gemma-7B DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry
{
    char timestamp[26];
    char message[MAX_LOG_SIZE];
    struct LogEntry* next;
} LogEntry;

LogEntry* log_head = NULL;

void log_event(char* message)
{
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    LogEntry* new_entry = malloc(sizeof(LogEntry));
    new_entry->timestamp[0] = tm->tm_hour;
    new_entry->timestamp[1] = tm->tm_min;
    new_entry->timestamp[2] = tm->tm_sec;
    new_entry->message[0] = '\0';
    strcpy(new_entry->message, message);

    if (log_head == NULL)
    {
        log_head = new_entry;
    }
    else
    {
        LogEntry* current = log_head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = new_entry;
    }
}

int main()
{
    log_event("Hello, world!");
    log_event("This is a test event.");
    log_event("Goodbye, cruel world!");

    LogEntry* current = log_head;
    while (current)
    {
        printf("Timestamp: %s, Message: %s\n", current->timestamp, current->message);
        current = current->next;
    }

    return 0;
}