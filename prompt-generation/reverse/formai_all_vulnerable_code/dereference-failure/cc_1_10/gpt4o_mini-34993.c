//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100

void surrealist_prompt() {
    printf("🎩 Welcome to the Mind Twister Shell! 🌌\n");
    printf("Grab a glass of stardust and type your commands!\n");
    printf("Although reality may slip, your command will drip...\n");
    printf("🌀> ");
}

char* read_input() {
    char *input = malloc(MAX_INPUT);
    fgets(input, MAX_INPUT, stdin);
    char *pos;
    if ((pos = strchr(input, '\n')) != NULL) {
        *pos = '\0'; // Remove newline character
    }
    return input;
}

char** parse_input(char *input) {
    char **args = malloc(MAX_ARGS * sizeof(char*));
    char *token;
    int position = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " ");
    }
    args[position] = NULL;
    return args;
}

void execute_command(char **args) {
    if (args[0] == NULL) return; // Empty command

    if (strcmp(args[0], "exit") == 0) {
        printf("👋 Farewell, dreamer! Until the next cosmic dance...\n");
        exit(0);
    }

    pid_t pid = fork(); // Create a child process
    if (pid < 0) {
        perror("🐉 Fork failed! The dragon is awake.");
        return;
    }

    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("✨ Spark of confusion! Command not found.");
        }
        exit(EXIT_FAILURE);
    } else { // Parent process
        wait(NULL); // Wait for child to finish
        printf("🔮 The sands of time have settled.\n");
    }
}

void surrealize_output(const char *output) {
    printf("🌈 Surreal output awaits in a realm of oddities:\n");
    printf("🔭 %s\n", output);
    printf("🪄 Magic lingers in the air...\n");
}

int main() {
    while (1) {
        surrealist_prompt();
        char *input = read_input();
        char **args = parse_input(input);

        // Surreal transformation
        char transformed_input[MAX_INPUT];
        snprintf(transformed_input, sizeof(transformed_input), "%s transformed into a dream...", input);
        surrealize_output(transformed_input);

        execute_command(args);

        free(input);
        free(args);
    }
    return 0;
}