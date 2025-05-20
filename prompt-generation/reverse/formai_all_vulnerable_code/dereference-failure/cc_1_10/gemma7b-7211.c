//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry
{
    char timestamp[MAX_LOG_SIZE];
    char message[MAX_LOG_SIZE];
    struct LogEntry* next;
} LogEntry;

LogEntry* Log_AddEntry(LogEntry* head, char* timestamp, char* message)
{
    LogEntry* newEntry = malloc(sizeof(LogEntry));

    strcpy(newEntry->timestamp, timestamp);
    strcpy(newEntry->message, message);

    newEntry->next = NULL;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        LogEntry* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newEntry;
    }

    return head;
}

void Log_PrintEntries(LogEntry* head)
{
    LogEntry* current = head;
    while (current)
    {
        printf("%s: %s\n", current->timestamp, current->message);
        current = current->next;
    }
}

int main()
{
    LogEntry* log = NULL;

    Log_AddEntry(log, "13:37:01", "System boots up.");
    Log_AddEntry(log, "13:37:02", "User logs in.");
    Log_AddEntry(log, "13:37:03", "Game starts.");
    Log_AddEntry(log, "13:37:04", "Character level up.");

    Log_PrintEntries(log);

    return 0;
}