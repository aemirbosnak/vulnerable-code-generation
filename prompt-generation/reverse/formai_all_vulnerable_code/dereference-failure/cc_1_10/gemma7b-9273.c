//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_HISTORY_SIZE 10

typedef struct History {
    char **commands;
    int size;
} History;

History history = {NULL, 0};

void add_command(char *command) {
    History *h = &history;
    h->commands = realloc(h->commands, (h->size + 1) * sizeof(char *));
    h->commands[h->size++] = command;
}

char *get_last_command() {
    History *h = &history;
    if (h->size) {
        return h->commands[h->size - 1];
    } else {
        return NULL;
    }
}

int main() {
    char input[256];
    char *command;
    int i;

    history.commands = malloc(MAX_HISTORY_SIZE * sizeof(char *));

    while (1) {
        printf("$ ");
        fgets(input, 256, stdin);

        command = strtok(input, " ");

        add_command(command);

        switch (fork()) {
            case 0:
                execvp(command, command);
                break;
            case -1:
                perror("Error executing command");
                break;
            default:
                break;
        }

        for (i = 0; i < history.size; i++) {
            printf("%s ", history.commands[i]);
        }
        printf("\n");
    }

    return 0;
}