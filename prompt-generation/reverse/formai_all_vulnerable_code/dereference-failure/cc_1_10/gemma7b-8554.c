//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 10

typedef struct HistoryEntry {
    char *command;
    struct HistoryEntry *next;
} HistoryEntry;

HistoryEntry *history = NULL;

void add_history(char *command) {
    HistoryEntry *new_entry = malloc(sizeof(HistoryEntry));
    new_entry->command = strdup(command);
    new_entry->next = history;
    history = new_entry;

    if (history->next) {
        free(history->next);
    }

    if (history->command) {
        free(history->command);
    }
}

int main() {
    char prompt[] = "surreal-shell$ ";
    char input[256];
    int i = 0;
    HistoryEntry *prev_entry = NULL;

    while (1) {
        printf("%s", prompt);
        fgets(input, 256, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        add_history(input);

        // Execute the command
        system(input);

        prev_entry = history;
    }

    return 0;
}