//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_ARGS 100

void print_prompt() {
    printf("🛸 Futuristic Shell >>> ");
}

void parse_input(char* input, char** args) {
    char* token;
    int position = 0;

    token = strtok(input, " \n");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

void execute_command(char** args) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
        }
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

void loop() {
    char* input = malloc(MAX_INPUT_SIZE);
    char* args[MAX_NUM_ARGS];

    while (1) {
        print_prompt();
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            perror("Reading input failed");
            continue;
        }

        if (strcmp(input, "exit\n") == 0) {
            printf("Shutting down the futuristic shell. Goodbye!\n");
            break;
        }

        parse_input(input, args);
        execute_command(args);
    }

    free(input);
}

int main() {
    printf("Welcome to the Futuristic Shell v1.0 🚀\n");
    printf("Type 'exit' to leave the shell.\n");
    loop();
    return 0;
}