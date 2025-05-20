//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

// Function to trim whitespace from the start and end of a string
char *trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the trimmed string
    *(end + 1) = '\0';

    return str;
}

// Function to parse the input command into arguments
int parse_input(char *input, char **args) {
    int position = 0;
    char *token;

    token = strtok(input, " \n");
    while (token != NULL && position < MAX_ARG_SIZE - 1) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL; // Last argument must be NULL

    return position;
}

// Function to execute the command
void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

// Main shell loop
void shell_loop() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_SIZE];

    while (1) {
        printf("myshell> ");
        if (!fgets(input, sizeof(input), stdin)) {
            break; // Exit on EOF
        }

        // Trim whitespace
        char *trimmed_input = trim_whitespace(input);

        // Exit the shell
        if (strcmp(trimmed_input, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        // Parse the input
        int arg_count = parse_input(trimmed_input, args);

        // Execute the command
        if (arg_count > 0) {
            execute_command(args);
        }
    }
}

// Main function
int main() {
    printf("Welcome to myshell! Type 'exit' to quit.\n");
    shell_loop();
    return EXIT_SUCCESS;
}