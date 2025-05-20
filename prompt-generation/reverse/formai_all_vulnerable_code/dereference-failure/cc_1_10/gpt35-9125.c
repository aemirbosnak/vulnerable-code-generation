//FormAI DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

typedef struct log_entry {
    char timestamp[MAX_LINE];
    char level[MAX_LINE];
    char message[MAX_LINE];
    struct log_entry *next;
} LogEntry;

void print_log_entry(LogEntry *entry) {
    printf("%s %s %s\n", entry->timestamp, entry->level, entry->message);
}

void free_log_entries(LogEntry *entry) {
    if (entry == NULL) {
        return;
    }

    free_log_entries(entry->next);
    free(entry);
}

void parse_line(char *line, LogEntry **root) {
    if (strlen(line) == 0) {
        // ignore empty lines
        return;
    }

    LogEntry *entry = malloc(sizeof(LogEntry));
    entry->next = *root;
    *root = entry;

    char *token = strtok(line, " ");
    strncpy(entry->timestamp, token, MAX_LINE);

    token = strtok(NULL, " ");
    strncpy(entry->level, token, MAX_LINE);

    token = strtok(NULL, "\n");
    strncpy(entry->message, token, MAX_LINE);
}

void read_log_file(FILE *file, LogEntry **root) {
    char line[MAX_LINE];

    while (fgets(line, MAX_LINE, file) != NULL) {
        parse_line(line, root);
    }
}

void print_log_entries(LogEntry *entry, char *level) {
    if (entry == NULL) {
        return;
    }

    if (strcmp(entry->level, level) == 0) {
        print_log_entry(entry);
    }

    print_log_entries(entry->next, level);
}

void search_log_entries(LogEntry *entry, char *query) {
    if (entry == NULL) {
        return;
    }

    if (strstr(entry->message, query) != NULL) {
        print_log_entry(entry);
    }

    search_log_entries(entry->next, query);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    LogEntry *root = NULL;
    read_log_file(file, &root);
    fclose(file);

    printf("INFO messages:\n");
    print_log_entries(root, "INFO");

    printf("\nERROR messages containing 'keyboard':\n");
    search_log_entries(root, "keyboard");
    
    free_log_entries(root);
    return 0;
}