//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024 // Maximum input length for user input
#define MAX_TOKENS 64 // Maximum number of tokens in user input
#define TOKEN_DELIMITERS " \t\r\n\a" // Token delimiter characters

int execute_command(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork(); // Creating a child process

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell"); // Error in executing the command
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        // Error in forking
        perror("shell");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED); // Wait for child process to complete
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

char *read_input()
{
    char *input = NULL;
    size_t input_buffer_size = 0;

    getline(&input, &input_buffer_size, stdin); // Read input from user

    return input;
}

char **parse_input(char *input)
{
    int token_buffer_size = MAX_TOKENS, position = 0;
    char **tokens = malloc(token_buffer_size * sizeof(char*));
    char *token;

    token = strtok(input, TOKEN_DELIMITERS); // Tokenize user input

    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= token_buffer_size) {
            token_buffer_size += MAX_TOKENS; // Increase token buffer size dynamically
            tokens = realloc(tokens, token_buffer_size * sizeof(char*));

            if (!tokens) {
                fprintf(stderr, "shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_DELIMITERS);
    }

    tokens[position] = NULL; // Set last token to NULL for execvp()

    return tokens;
}

void loop_shell()
{
    char *input;
    char **args;
    int status;

    do {
        printf("> "); // Display shell prompt
        input = read_input(); // Read input from user
        args = parse_input(input); // Parse user input
        status = execute_command(args); // Executing user command

        free(input);
        free(args);
    } while (status);
}

int main()
{
    loop_shell();
    return 0;
}