//Gemma-7B DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1024
#define EVENT_LOG_FILE "event.log"

typedef struct LogEntry {
    char timestamp[26];
    char event_type[64];
    char event_data[1024];
    struct LogEntry* next;
} LogEntry;

LogEntry* log_insert(LogEntry* head, char* event_type, char* event_data) {
    LogEntry* new_entry = malloc(sizeof(LogEntry));

    time_t t = time(NULL);
    strftime(new_entry->timestamp, 26, "%H:%M:%S", localtime(&t));

    strcpy(new_entry->event_type, event_type);
    strcpy(new_entry->event_data, event_data);

    new_entry->next = head;
    head = new_entry;

    return head;
}

void log_print(LogEntry* head) {
    printf("Event Log:\n");

    while (head) {
        printf("Timestamp: %s\n", head->timestamp);
        printf("Event Type: %s\n", head->event_type);
        printf("Event Data: %s\n", head->event_data);
        printf("\n");
        head = head->next;
    }
}

int main() {
    LogEntry* head = NULL;

    log_insert(head, "User Login", "John Doe");
    log_insert(head, "Item Purchase", "Apple");
    log_insert(head, "Order Placed", "Pizza");

    log_print(head);

    return 0;
}