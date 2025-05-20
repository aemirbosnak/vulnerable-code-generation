//Gemma-7B DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1024

typedef struct LogEntry
{
    char timestamp[26];
    char message[256];
    struct LogEntry* next;
} LogEntry;

LogEntry* log_head = NULL;

void log_event(char* message)
{
    LogEntry* new_entry = malloc(sizeof(LogEntry));

    time_t t = time(NULL);
    strftime(new_entry->timestamp, 26, "%H:%M:%S", localtime(&t));

    strcpy(new_entry->message, message);

    if (log_head == NULL)
    {
        log_head = new_entry;
    }
    else
    {
        log_head->next = new_entry;
        log_head = new_entry;
    }

    if (log_head->next == NULL)
    {
        printf("Log full!\n");
    }
}

int main()
{
    log_event("Cat sat on the mat.");
    log_event("Dog went for a walk.");
    log_event("The sun shone brightly.");

    LogEntry* current_entry = log_head;
    while (current_entry)
    {
        printf("%s: %s\n", current_entry->timestamp, current_entry->message);
        current_entry = current_entry->next;
    }

    return 0;
}