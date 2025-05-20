//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LogEntry {
    char *message;
    int level;
    struct LogEntry *next;
} LogEntry;

LogEntry *parse_log(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    LogEntry *head = NULL;
    LogEntry *tail = NULL;

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char *message = strdup(buffer);
        int level = atoi(strtok(message, ":"));
        LogEntry *entry = malloc(sizeof(LogEntry));
        entry->message = message;
        entry->level = level;
        entry->next = NULL;

        if (head == NULL) {
            head = entry;
            tail = entry;
        } else {
            tail->next = entry;
            tail = entry;
        }
    }

    fclose(fp);

    return head;
}

void print_log(LogEntry *entry) {
    if (entry == NULL) {
        return;
    }

    printf("%d: %s", entry->level, entry->message);

    print_log(entry->next);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    LogEntry *head = parse_log(argv[1]);
    print_log(head);

    return EXIT_SUCCESS;
}