//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 100 // Maximum length of the input string
#define MAX_TOKENS 10 // Maximum number of tokens in a command
#define PROMPT "jUX > "

// Read user input
char* read_input() {
    char *input = malloc(MAX_LENGTH);
    fgets(input, MAX_LENGTH, stdin);
    return input;
}

// Parse user input into tokens
char** parse_input(char* input) {
    char** tokens = malloc(MAX_TOKENS * sizeof(char*));
    char* token;
    int i = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    return tokens;
}

int main() {
    while (1) {
        printf(PROMPT);
        char* input = read_input();
        char** tokens = parse_input(input);

        if (tokens[0] == NULL) {
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid == 0) {
            execvp(tokens[0], tokens);
            printf("Unknown command: %s\n", tokens[0]);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            printf("Fork failed.\n");
        } else {
            wait(NULL);
        }

        free(input);
        free(tokens);
    }

    return EXIT_SUCCESS;
}