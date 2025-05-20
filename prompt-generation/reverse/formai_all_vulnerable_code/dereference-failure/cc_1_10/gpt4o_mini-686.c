//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

void display_prompt() {
    printf("Whispers of the void> ");
}

char* read_input() {
    char* input = malloc(MAX_INPUT_SIZE);
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        free(input);
        return NULL;
    }
    input[strcspn(input, "\n")] = 0; // Remove newline character
    return input;
}

char** parse_input(char* input) {
    char** args = malloc(MAX_ARG_SIZE * sizeof(char*));
    char* token = strtok(input, " ");
    int index = 0;

    while (token != NULL) {
        args[index++] = token;
        token = strtok(NULL, " ");
    }
    args[index] = NULL; // NULL-terminate the array of arguments
    return args;
}

void execute_command(char** args) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed, a cat swallowed the moon.");
        return;
    } else if (pid == 0) {
        // In child process
        if (execvp(args[0], args) < 0) {
            perror("The silence of the command echoes back.");
            exit(1);
        }
    } else {
        // In parent process
        wait(NULL);
    }
}

void free_memory(char* input, char** args) {
    free(input);
    free(args);
}

void surreal_shell() {
    while (1) {
        display_prompt();

        char* input = read_input();
        if (input == NULL) {
            break; // Exit on EOF
        }

        if (strcmp(input, "exit") == 0) {
            free(input);
            break; // Exit the shell
        }

        char** args = parse_input(input);
        if (args[0] == NULL) {
            free_memory(input, args);
            continue; // Empty command
        }

        if (strcmp(args[0], "whisper") == 0) {
            printf("The whisper of the command sends many ripples in time.\n");
        } else if (strcmp(args[0], "dream") == 0) {
            printf("Close your eyes and imagine a world where commands are colors.\n");
        } else if (strcmp(args[0], "echo") == 0) {
            printf("Echoes in the void: ");
            for (int i = 1; args[i] != NULL; i++) {
                printf("%s ", args[i]);
            }
            printf("\n");
        } else {
            execute_command(args);
        }

        free_memory(input, args);
    }
}

int main() {
    surreal_shell();
    return 0;
}