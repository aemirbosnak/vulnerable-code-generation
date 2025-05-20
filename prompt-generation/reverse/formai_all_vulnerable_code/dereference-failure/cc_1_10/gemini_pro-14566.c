//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int level;
    char *message;
    time_t timestamp;
} LogEntry;

// A simple linked list to store the log entries
typedef struct {
    LogEntry *entry;
    struct LogList *next;
} LogList;

// Create a new log entry
LogEntry *new_log_entry(int level, char *message) {
    LogEntry *entry = malloc(sizeof(LogEntry));
    entry->level = level;
    entry->message = strdup(message);
    entry->timestamp = time(NULL);
    return entry;
}

// Add a log entry to the log list
void add_log_entry(LogList **head, LogEntry *entry) {
    LogList *new_head = malloc(sizeof(LogList));
    new_head->entry = entry;
    new_head->next = *head;
    *head = new_head;
}

// Print the log entries
void print_log_entries(LogList *head) {
    while (head != NULL) {
        printf("%s: %s\n", ctime(&head->entry->timestamp), head->entry->message);
        head = head->next;
    }
}

// Free the log entries
void free_log_entries(LogList *head) {
    while (head != NULL) {
        free(head->entry->message);
        free(head->entry);
        LogList *next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    // Create a new log list
    LogList *head = NULL;

    // Add some log entries
    add_log_entry(&head, new_log_entry(1, "Info: Program started"));
    add_log_entry(&head, new_log_entry(2, "Warning: Memory low"));
    add_log_entry(&head, new_log_entry(3, "Error: Program crashed"));

    // Print the log entries
    print_log_entries(head);

    // Free the log entries
    free_log_entries(head);

    return 0;
}