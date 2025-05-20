//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

void display_intro() {
    printf("🌹 Welcome to 'Eternal Echoes', a tiny shell that yearns to take you\n");
    printf("🌷 through the romantic realms of command lines and dreams.\n");
    printf("✨ Type 'exit' to part ways or let your commands wander.\n\n");
}

void parse_input(char *input, char **args) {
    char *token;
    int position = 0;

    token = strtok(input, " \n");
    while (token != NULL && position < MAX_ARG_SIZE - 1) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

int execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Eternal Echoes: Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("Eternal Echoes: Fork failed");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

int main() {
    char *input = NULL;
    char *args[MAX_ARG_SIZE];
    size_t len = 0;

    display_intro();

    while (1) {
        printf("💖 Eternal Echoes > ");
        getline(&input, &len, stdin);
        
        // If user wishes to bid farewell, do so gracefully.
        if (strncmp(input, "exit", 4) == 0) {
            printf("💔 Parting is such sweet sorrow...\n");
            break;
        }

        // Heartfelt parsing of user input.
        parse_input(input, args);

        // Execute the command with all the curly twists and turns.
        if (args[0] != NULL) {
            execute_command(args);
        }
    }

    free(input);
    return 0;
}