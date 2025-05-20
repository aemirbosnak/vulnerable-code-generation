//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split a string into an array of tokens
char** tokenize(char* str, char* delim) {
    char** tokens = malloc(sizeof(char*) * 100);
    int i = 0;
    char* token = strtok(str, delim);
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, delim);
    }
    tokens[i] = NULL;
    return tokens;
}

// Function to execute a command
int execute(char** tokens) {
    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            printf("Error: no directory specified\n");
            return 1;
        } else {
            if (chdir(tokens[1]) != 0) {
                printf("Error: no such directory\n");
                return 1;
            }
        }
    } else if (strcmp(tokens[0], "ls") == 0) {
        system("ls");
    } else if (strcmp(tokens[0], "pwd") == 0) {
        system("pwd");
    } else if (strcmp(tokens[0], "echo") == 0) {
        for (int i = 1; tokens[i] != NULL; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    } else {
        printf("Error: command not found\n");
        return 1;
    }
    return 0;
}

// Main function
int main() {
    // Set up the prompt
    printf("Welcome to the funniest shell ever!\n");
    printf("Type 'exit' to exit.\n");

    // Loop until the user exits
    while (1) {
        // Get the user's input
        char input[100];
        printf("%s ",getenv("USER"));
        printf("owo=> ");
        fgets(input, sizeof(input), stdin);

        // Tokenize the input
        char** tokens = tokenize(input, " ");

        // Execute the command
        int status = execute(tokens);

        // Free the tokens
        free(tokens);

        // Check if the user exited
        if (status == 0) {
            break;
        }
    }

    return 0;
}