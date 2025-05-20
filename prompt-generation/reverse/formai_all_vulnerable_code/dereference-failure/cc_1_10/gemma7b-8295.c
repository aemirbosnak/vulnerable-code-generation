//Gemma-7B DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

typedef struct EventLog
{
    char timestamp[26];
    char event_name[256];
    char event_data[MAX_LOG_SIZE];
    struct EventLog* next;
} EventLog;

EventLog* log_head = NULL;

void log_event(char* event_name, char* event_data)
{
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    EventLog* new_log = malloc(sizeof(EventLog));
    new_log->timestamp[0] = tm->tm_hour;
    new_log->timestamp[1] = tm->tm_min;
    new_log->timestamp[2] = tm->tm_sec;
    new_log->event_name[0] = '\0';
    strcpy(new_log->event_name, event_name);
    new_log->event_data[0] = '\0';
    strcpy(new_log->event_data, event_data);
    new_log->next = log_head;
    log_head = new_log;
}

int main()
{
    log_event("System Boot", "System booted successfully.");
    log_event("User Login", "User named John Doe logged in.");
    log_event("File Create", "File named myfile.txt was created.");

    EventLog* current_log = log_head;
    while (current_log)
    {
        printf("Timestamp: %s\n", current_log->timestamp);
        printf("Event Name: %s\n", current_log->event_name);
        printf("Event Data: %s\n", current_log->event_data);
        printf("\n");
        current_log = current_log->next;
    }

    return 0;
}