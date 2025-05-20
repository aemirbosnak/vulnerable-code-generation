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

LogEntry* head = NULL;

void log_add(char* timestamp, char* message)
{
    LogEntry* newEntry = malloc(sizeof(LogEntry));
    strcpy(newEntry->timestamp, timestamp);
    strcpy(newEntry->message, message);
    newEntry->next = head;
    head = newEntry;
}

void log_analyse(char* query)
{
    LogEntry* currentEntry = head;
    while (currentEntry)
    {
        if (strstr(currentEntry->message, query))
        {
            printf("Log Entry:\n");
            printf("Timestamp: %s\n", currentEntry->timestamp);
            printf("Message: %s\n", currentEntry->message);
            printf("\n");
        }
        currentEntry = currentEntry->next;
    }
}

int main()
{
    log_add("12:00:00", "User A logged in.");
    log_add("12:00:05", "User B purchased a book.");
    log_add("12:00:10", "User A updated their profile.");
    log_add("12:00:15", "User C commented on a post.");

    log_analyse("User A");

    return 0;
}