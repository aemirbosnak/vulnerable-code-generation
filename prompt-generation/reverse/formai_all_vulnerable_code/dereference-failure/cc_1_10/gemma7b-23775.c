//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct LogEntry {
    char timestamp[MAX_BUFFER_SIZE];
    char message[MAX_BUFFER_SIZE];
    struct LogEntry* next;
} LogEntry;

LogEntry* log_insert(LogEntry* head, char* timestamp, char* message) {
    LogEntry* new_entry = malloc(sizeof(LogEntry));

    strcpy(new_entry->timestamp, timestamp);
    strcpy(new_entry->message, message);

    new_entry->next = head;
    head = new_entry;

    return head;
}

int log_search(LogEntry* head, char* query) {
    LogEntry* current_entry = head;

    while (current_entry) {
        if (strstr(current_entry->message, query)) {
            return 1;
        }

        current_entry = current_entry->next;
    }

    return 0;
}

int main() {
    LogEntry* log = NULL;

    log_insert(log, "12:00:01", "User A logged in.");
    log_insert(log, "12:00:02", "User B logged in.");
    log_insert(log, "12:00:03", "User A purchased a book.");
    log_insert(log, "12:00:04", "User B purchased a book.");

    if (log_search(log, "book")) {
        printf("Log entry found.\n");
    } else {
        printf("Log entry not found.\n");
    }

    return 0;
}