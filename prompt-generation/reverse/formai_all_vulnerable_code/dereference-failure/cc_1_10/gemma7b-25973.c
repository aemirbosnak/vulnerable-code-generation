//Gemma-7B DATASET v1.0 Category: System event logger ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry
{
    char timestamp[26];
    char event_name[256];
    char event_details[MAX_LOG_SIZE];
    struct LogEntry* next;
} LogEntry;

LogEntry* head = NULL;

void log_event(char* event_name, char* event_details)
{
    LogEntry* new_entry = malloc(sizeof(LogEntry));
    new_entry->next = head;
    head = new_entry;

    sprintf(new_entry->timestamp, "%c%c%c%c%c%c%c%c%c%c", __TIME__);
    strcpy(new_entry->event_name, event_name);
    strcpy(new_entry->event_details, event_details);
}

void print_logs()
{
    LogEntry* current = head;
    printf("Logs:\n");
    while (current)
    {
        printf("Timestamp: %s\n", current->timestamp);
        printf("Event Name: %s\n", current->event_name);
        printf("Event Details: %s\n", current->event_details);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    log_event("System Start", "The system has started.");
    log_event("User Login", "User with username 'John Doe' has logged in.");
    log_event("File Created", "A new file named 'my_file.txt' has been created.");
    log_event("Error Occurred", "An error has occurred in the system.");
    print_logs();

    return 0;
}