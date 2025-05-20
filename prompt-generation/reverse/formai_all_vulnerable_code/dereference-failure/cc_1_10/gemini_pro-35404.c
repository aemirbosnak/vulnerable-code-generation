//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Our custom shell's history store
#define HISTORY_SIZE 10
struct history_entry {
    char *command;
    size_t length;
};

struct history_store {
    struct history_entry entries[HISTORY_SIZE];
    size_t head;
    size_t tail;
};

// Initializes the history store
void init_history_store(struct history_store *store) {
    memset(store, 0, sizeof(struct history_store));
}

// Adds a command to the history store
void add_to_history(struct history_store *store, char *command) {
    size_t length = strlen(command);
    store->entries[store->head].command = malloc(length + 1);
    strcpy(store->entries[store->head].command, command);
    store->entries[store->head].length = length;
    store->head = (store->head + 1) % HISTORY_SIZE;
    if (store->head == store->tail) {
        store->tail = (store->tail + 1) % HISTORY_SIZE;
    }
}

// Frees the memory allocated for the history store
void free_history_store(struct history_store *store) {
    for (size_t i = 0; i < HISTORY_SIZE; i++) {
        free(store->entries[i].command);
    }
}

// Prints the history store
void print_history(struct history_store *store) {
    size_t i = store->tail;
    do {
        printf("%s\n", store->entries[i].command);
        i = (i + 1) % HISTORY_SIZE;
    } while (i != store->head);
}

// The main shell loop
int main() {
    char line[1024];
    char *args[1024];
    int num_args;
    int status;
    struct history_store history;

    init_history_store(&history);

    while (1) {
        printf("$> ");
        fflush(stdout);

        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        // Remove the newline character from the end of the line
        line[strlen(line) - 1] = '\0';

        // Tokenize the line into arguments
        num_args = 0;
        args[num_args++] = strtok(line, " ");
        while ((args[num_args++] = strtok(NULL, " ")) != NULL);

        // Add the command to the history store
        add_to_history(&history, args[0]);

        // Check for built-in commands
        if (strcmp(args[0], "history") == 0) {
            print_history(&history);
            continue;
        } else if (strcmp(args[0], "exit") == 0) {
            break;
        }

        // Fork a new process to execute the command
        pid_t child_pid = fork();
        if (child_pid < 0) {
            perror("fork");
            continue;
        } else if (child_pid == 0) {
            // Child process
            execvp(args[0], args);
            fprintf(stderr, "execvp: %s: command not found\n", args[0]);
            exit(1);
        } else {
            // Parent process
            wait(&status);
        }
    }

    free_history_store(&history);
    return 0;
}