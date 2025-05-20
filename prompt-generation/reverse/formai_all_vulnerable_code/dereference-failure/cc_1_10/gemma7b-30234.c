//Gemma-7B DATASET v1.0 Category: System administration ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256
#define MAX_HISTORY_SIZE 10

typedef struct CommandHistory {
    char **commands;
    int size;
} CommandHistory;

void history_init(CommandHistory *history) {
    history->commands = NULL;
    history->size = 0;
}

void history_add(CommandHistory *history, char *command) {
    history->commands = realloc(history->commands, (history->size + 1) * sizeof(char *));
    history->commands[history->size++] = strdup(command);
}

char *history_get(CommandHistory *history, int index) {
    if (index < 0 || index >= history->size) {
        return NULL;
    }
    return history->commands[index];
}

int main() {
    CommandHistory history;
    history_init(&history);

    char cmd[MAX_CMD_LEN];

    while (1) {
        printf("C System Admin: $ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        history_add(&history, cmd);

        // Execute command
        system(cmd);

        // Print history
        printf("History:\n");
        for (int i = 0; i < history.size; i++) {
            printf("%d. %s\n", i + 1, history_get(&history, i));
        }
    }

    return 0;
}