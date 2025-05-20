//Gemma-7B DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry
{
    char timestamp[26];
    char event[MAX_LOG_SIZE];
    struct LogEntry* next;
} LogEntry;

LogEntry* head = NULL;

void logEvent(char* event)
{
    LogEntry* newEntry = malloc(sizeof(LogEntry));

    time_t t = time(NULL);
    strftime(newEntry->timestamp, 26, "%H:%M:%S", localtime(&t));

    strcpy(newEntry->event, event);

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = newEntry;
        head = newEntry;
    }
}

int main()
{
    logEvent("Hello, world!");
    logEvent("The quick brown fox jumps over the lazy dog.");
    logEvent("This is a sample event.");

    LogEntry* currentEntry = head;

    while (currentEntry)
    {
        printf("%s - %s\n", currentEntry->timestamp, currentEntry->event);
        currentEntry = currentEntry->next;
    }

    return 0;
}