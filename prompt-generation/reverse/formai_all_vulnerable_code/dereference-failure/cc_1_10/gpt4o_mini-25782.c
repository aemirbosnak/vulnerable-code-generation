//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LEN 1024
#define MAX_HISTORY 10

typedef struct {
    char* commands[MAX_HISTORY];
    int count;
} History;

void add_to_history(History* history, const char* command) {
    if (history->count < MAX_HISTORY) {
        history->commands[history->count] = strdup(command);
        history->count++;
    } else {
        free(history->commands[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history->commands[i - 1] = history->commands[i];
        }
        history->commands[MAX_HISTORY - 1] = strdup(command);
    }
}

void print_history(const History* history) {
    for (int i = 0; i < history->count; i++) {
        printf("%d: %s\n", i + 1, history->commands[i]);
    }
}

void clear_history(History* history) {
    for (int i = 0; i < history->count; i++) {
        free(history->commands[i]);
    }
    history->count = 0;
}

int main() {
    char command[MAX_COMMAND_LEN];
    History history = { .count = 0 };

    printf("Welcome to Ye Olde Shell of the Realm!\n");
    printf("Type 'exit' to leave these fair lands.\n");
    printf("Type 'history' to see the tales of commands once spoken.\n");

    while (1) {
        printf("Ye Olde Shell > ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break; // Exit on EOF
        }

        // Remove the newline character
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            printf("Farewell, brave traveler!\n");
            break;
        }

        if (strcmp(command, "history") == 0) {
            print_history(&history);
            continue;
        }

        add_to_history(&history, command);

        // Command execution
        if (fork() == 0) { // Create a new process
            char* args[] = { "/bin/sh", "-c", command, NULL };
            execvp(args[0], args);
            perror("Execution Failed"); // Should only reach here if execvp fails
            exit(1);
        }

        wait(NULL); // Parent process waits for the child
    }

    clear_history(&history);
    return 0;
}