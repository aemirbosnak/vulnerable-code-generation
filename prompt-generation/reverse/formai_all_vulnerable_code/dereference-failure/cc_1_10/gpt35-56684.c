//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

typedef struct entry {
    char *timestamp;
    char *message;
    struct entry *next;
} Entry;

Entry *head = NULL;

void add_entry(char *timestamp, char *message) {
    Entry *new_entry = malloc(sizeof(Entry));
    new_entry->timestamp = malloc(strlen(timestamp) + 1);
    strcpy(new_entry->timestamp, timestamp);
    new_entry->message = malloc(strlen(message) + 1);
    strcpy(new_entry->message, message);
    new_entry->next = head;
    head = new_entry;
}

void print_entries() {
    Entry *entry_ptr = head;
    while (entry_ptr != NULL) {
        printf("%s: %s\n", entry_ptr->timestamp, entry_ptr->message);
        entry_ptr = entry_ptr->next;
    }
}

int count_entries() {
    int count = 0;
    Entry *entry_ptr = head;
    while (entry_ptr != NULL) {
        count++;
        entry_ptr = entry_ptr->next;
    }
    return count;
}

int main() {
    char line[MAXLINE];
    while (fgets(line, MAXLINE, stdin) != NULL) {
        // assume logs are in the format "timestamp message"
        char *timestamp = strtok(line, " ");
        char *message = strtok(NULL, "\n");
        add_entry(timestamp, message);
    }

    printf("%d entries found:\n", count_entries());
    print_entries();

    return 0;
}