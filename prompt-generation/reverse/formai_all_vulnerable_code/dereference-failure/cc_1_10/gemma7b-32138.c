//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
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

LogEntry* head = NULL;

void log_add(char* timestamp, char* message)
{
    LogEntry* new_entry = malloc(sizeof(LogEntry));

    strcpy(new_entry->timestamp, timestamp);
    strcpy(new_entry->message, message);

    if (head == NULL)
    {
        head = new_entry;
    }
    else
    {
        head->next = new_entry;
        head = new_entry;
    }
}

void log_parse(char* query)
{
    LogEntry* current = head;

    while (current)
    {
        if (strstr(current->message, query))
        {
            printf("Log Entry:\n");
            printf("Timestamp: %s\n", current->timestamp);
            printf("Message: %s\n", current->message);
            printf("\n");
        }
        current = current->next;
    }

    printf("No entries found for query: %s\n", query);
}

int main()
{
    log_add("12:00:00", "The water is running low.");
    log_add("13:00:00", "The generator is broken.");
    log_add("14:00:00", "The crops are failing.");

    log_parse("water");

    log_parse("generator");

    return 0;
}