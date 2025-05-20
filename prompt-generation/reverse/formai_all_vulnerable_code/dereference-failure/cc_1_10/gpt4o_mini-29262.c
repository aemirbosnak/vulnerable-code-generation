//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \n"

void print_romeo_juliet() {
    printf("-----\n");
    printf("Welcome to the Verona Shell!\n");
    printf("Wherefore art thou, noble commands?\n");
    printf("-----\n");
}

void execute_command(char *command) {
    char *args[BUFFER_SIZE];
    char *token = strtok(command, TOKEN_DELIM);
    int i = 0;

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, TOKEN_DELIM);
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
        printf("Goodbye! Parting is such sweet sorrow.\n");
        exit(0);
    }

    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Alas, there is no such command.");
        }
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
    } else {
        // Forking failed
        perror("A plague o' both your houses!");
    }
}

int main() {
    char command[BUFFER_SIZE];

    print_romeo_juliet();

    while (1) {
        printf("Verona> ");
        if (fgets(command, BUFFER_SIZE, stdin) == NULL) {
            perror("Error reading command.");
            continue;
        }

        if (strlen(command) > 0) {
            execute_command(command);
        } else {
            printf("Speak, but do not whisper.\n");
        }
    }

    return 0;
}