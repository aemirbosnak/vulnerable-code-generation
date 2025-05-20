//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

typedef struct LogEntry
{
    char timestamp[20];
    char message[200];
    struct LogEntry* next;
} LogEntry;

LogEntry* log_add(LogEntry* head, char* timestamp, char* message)
{
    LogEntry* new_entry = (LogEntry*)malloc(sizeof(LogEntry));
    strcpy(new_entry->timestamp, timestamp);
    strcpy(new_entry->message, message);
    new_entry->next = NULL;

    if (head == NULL)
    {
        return new_entry;
    }

    head->next = new_entry;
    return head;
}

void log_print(LogEntry* head)
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

    log_add(log, "12:00:00", "The king has been slain!");
    log_add(log, "12:00:05", "The dragon has been slain!");
    log_add(log, "12:00:10", "The hero has saved the day!");

    log_print(log);

    return 0;
}