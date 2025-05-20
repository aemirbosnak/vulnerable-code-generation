//Gemma-7B DATASET v1.0 Category: System event logger ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

typedef struct EventLog {
    char timestamp[MAX_LOG_SIZE];
    char event_name[MAX_LOG_SIZE];
    char event_details[MAX_LOG_SIZE];
    struct EventLog* next;
} EventLog;

EventLog* head = NULL;

void log_event(char* name, char* details) {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    EventLog* new_log = (EventLog*)malloc(sizeof(EventLog));
    new_log->timestamp[0] = '\0';
    strftime(new_log->timestamp, MAX_LOG_SIZE, "%Y-%m-%d %H:%M:%S", tm);
    new_log->event_name[0] = '\0';
    strcpy(new_log->event_name, name);
    new_log->event_details[0] = '\0';
    strcpy(new_log->event_details, details);
    new_log->next = NULL;

    if (head == NULL) {
        head = new_log;
    } else {
        EventLog* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_log;
    }
}

void print_log() {
    EventLog* current = head;
    while (current) {
        printf("Timestamp: %s\n", current->timestamp);
        printf("Event Name: %s\n", current->event_name);
        printf("Event Details: %s\n", current->event_details);
        printf("\n");
        current = current->next;
    }
}

int main() {
    log_event("System Start", "The system has started.");
    log_event("User Login", "John Doe has logged in.");
    log_event("File Download", "John Doe has downloaded a file named myfile.txt.");
    log_event("System Crash", "The system has crashed due to a memory error.");

    print_log();

    return 0;
}