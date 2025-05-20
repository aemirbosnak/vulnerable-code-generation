//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct LogEntry {
    char timestamp[MAX_LOG_SIZE];
    char message[MAX_LOG_SIZE];
    struct LogEntry* next;
} LogEntry;

LogEntry* head = NULL;

void log_add(char* timestamp, char* message) {
    LogEntry* new_entry = malloc(sizeof(LogEntry));
    strcpy(new_entry->timestamp, timestamp);
    strcpy(new_entry->message, message);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        LogEntry* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_entry;
    }
}

void log_search(char* query) {
    LogEntry* current = head;
    while (current) {
        if (strstr(current->message, query) != NULL) {
            printf("%s - %s\n", current->timestamp, current->message);
        }
        current = current->next;
    }
}

int main() {
    log_add("12:00:00", "User logged in");
    log_add("12:00:05", "User purchased item");
    log_add("12:00:10", "User added item to cart");
    log_add("12:00:15", "User checked out");

    log_search("user");

    return 0;
}