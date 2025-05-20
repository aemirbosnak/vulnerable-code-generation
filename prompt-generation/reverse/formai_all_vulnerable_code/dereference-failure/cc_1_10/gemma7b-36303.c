//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct LogEntry
{
    char timestamp[MAX_BUFFER_SIZE];
    char message[MAX_BUFFER_SIZE];
    struct LogEntry* next;
} LogEntry;

LogEntry* CreateLogEntry(char* timestamp, char* message)
{
    LogEntry* newEntry = malloc(sizeof(LogEntry));

    strncpy(newEntry->timestamp, timestamp, MAX_BUFFER_SIZE);
    strncpy(newEntry->message, message, MAX_BUFFER_SIZE);
    newEntry->next = NULL;

    return newEntry;
}

void AppendLogEntry(LogEntry* head, char* timestamp, char* message)
{
    LogEntry* newEntry = CreateLogEntry(timestamp, message);

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        LogEntry* currentEntry = head;
        while (currentEntry->next != NULL)
        {
            currentEntry = currentEntry->next;
        }
        currentEntry->next = newEntry;
    }
}

void AnalyzeLog(LogEntry* head)
{
    printf("Log Analysis:\n");

    LogEntry* currentEntry = head;
    while (currentEntry)
    {
        printf("Timestamp: %s\n", currentEntry->timestamp);
        printf("Message: %s\n", currentEntry->message);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

int main()
{
    LogEntry* head = NULL;

    AppendLogEntry(head, "10:00:00.000", "User logged in.");
    AppendLogEntry(head, "10:00:01.000", "User purchased item.");
    AppendLogEntry(head, "10:00:02.000", "User logged out.");

    AnalyzeLog(head);

    return 0;
}