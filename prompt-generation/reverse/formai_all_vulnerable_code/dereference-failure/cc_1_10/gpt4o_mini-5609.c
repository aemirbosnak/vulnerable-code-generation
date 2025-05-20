//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

void print_shell_prompt() {
    printf(BLUE ">> CyberPunk Shell v1.0 > " RESET);
    fflush(stdout);
}

void execute_command(char *input) {
    char *args[MAX_ARG_SIZE];
    char *token;
    int i = 0;

    // Tokenize input command
    token = strtok(input, " \n");
    while (token != NULL && i < MAX_ARG_SIZE - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    // Special command to exit
    if (strcmp(args[0], "exit") == 0) {
        printf("Exiting CyberPunk Shell...\n");
        exit(0);
    }

    // Create a child process to execute the command
    pid_t pid = fork();
    if (pid < 0) {
        perror("Failed to fork");
        exit(1);
    }

    if (pid == 0) {
        // In child process
        if (execvp(args[0], args) < 0) {
            perror("Command not found");
            exit(1);
        }
    } else {
        // In parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf(BLUE "Welcome to the CyberPunk Shell!\n" RESET);
    printf("Type 'exit' to leave the shell.\n");

    while (1) {
        print_shell_prompt();
        if (fgets(input, sizeof(input), stdin) != NULL) {
            execute_command(input);
        } else {
            perror("Failed to read input");
            continue;
        }
    }

    return 0;
}