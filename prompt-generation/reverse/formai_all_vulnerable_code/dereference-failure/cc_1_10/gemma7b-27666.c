//Gemma-7B DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry
{
    char timestamp[20];
    char message[MAX_LOG_SIZE];
    struct LogEntry* next;
} LogEntry;

LogEntry* head = NULL;

void logEvent(char* message)
{
    LogEntry* newEntry = (LogEntry*)malloc(sizeof(LogEntry));

    strcpy(newEntry->timestamp, __TIME__);
    strcpy(newEntry->message, message);

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
    logEvent("User logged in");
    logEvent("User purchased item");
    logEvent("User deleted account");

    LogEntry* currentEntry = head;

    while (currentEntry)
    {
        printf("Timestamp: %s\n", currentEntry->timestamp);
        printf("Message: %s\n", currentEntry->message);
        printf("\n");

        currentEntry = currentEntry->next;
    }

    return 0;
}