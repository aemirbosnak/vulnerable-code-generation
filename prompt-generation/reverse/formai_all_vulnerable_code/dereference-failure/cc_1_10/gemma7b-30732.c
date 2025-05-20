//Gemma-7B DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry
{
    char timestamp[64];
    char message[MAX_LOG_SIZE];
    struct LogEntry* next;
} LogEntry;

LogEntry* log_insert(LogEntry* head, char* message)
{
    LogEntry* new_entry = (LogEntry*)malloc(sizeof(LogEntry));
    time_t t = time(NULL);
    strftime(new_entry->timestamp, sizeof(new_entry->timestamp), "%Y-%m-%d %H:%M:%S", localtime(&t));
    strcpy(new_entry->message, message);
    new_entry->next = NULL;

    if (head == NULL)
    {
        head = new_entry;
    }
    else
    {
        LogEntry* tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = new_entry;
    }

    return head;
}

int main()
{
    LogEntry* log = NULL;

    log_insert(log, "This is the first log entry.");
    log_insert(log, "The second log entry.");
    log_insert(log, "The third log entry.");

    LogEntry* current = log;
    while (current)
    {
        printf("%s: %s\n", current->timestamp, current->message);
        current = current->next;
    }

    return 0;
}