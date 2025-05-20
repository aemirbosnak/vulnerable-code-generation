//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_ARGS 100
#define HISTORY_SIZE 20

void handle_sigint(int sig) {
    printf("\nIntercepted CTRL+C, use 'exit' to quit.\n");
}

char *history[HISTORY_SIZE];
int history_count = 0;

void add_to_history(char *command) {
    if (history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(command);
    } else {
        free(history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        history[HISTORY_SIZE - 1] = strdup(command);
    }
}

void print_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        do {
            wpid = waitpid(pid, &status, WNOHANG);
        } while (wpid == 0);
    }
}

int main() {
    signal(SIGINT, handle_sigint);
    
    char input[MAX_INPUT_SIZE];
    char *args[MAX_NUM_ARGS];
    char *token;

    printf("Welcome to the Quantum Shell v2.0 - Your futuristic CLI!\n");

    while (1) {
        printf("QSH> ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("\nExiting Quantum Shell.\n");
            break;
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Add command to history
        add_to_history(input);

        // Tokenize the input
        token = strtok(input, " ");
        int i = 0;
        while (token != NULL && i < MAX_NUM_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Built-in commands
        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting Quantum Shell...\n");
            break;
        } else if (strcmp(args[0], "history") == 0) {
            print_history();
        } else if (strlen(input) > 0) {
            // Execute the command
            execute_command(args);
        }
    }

    // Free history memory
    for (int j = 0; j < history_count; j++) {
        free(history[j]);
    }

    return 0;
}