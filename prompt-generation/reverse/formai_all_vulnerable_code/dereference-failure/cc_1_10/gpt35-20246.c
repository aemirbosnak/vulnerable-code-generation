//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_TOKENS 128
#define TOKEN_DELIM " \t\r\n\a"

// Function declarations
void shell_init();
char* shell_read_line();
char** shell_split_line(char* line);
int shell_execute(char** args);

int main(int argc, char *argv[]) {
    // Initialize the shell
    shell_init();

    return EXIT_SUCCESS;
}

void shell_init() {
    char* input_line;
    char** input_tokens;
    int status;

    do {
        printf("$ ");
        input_line = shell_read_line();
        input_tokens = shell_split_line(input_line);
        status = shell_execute(input_tokens);

        free(input_line);
        free(input_tokens);
    } while (status);
}

char* shell_read_line() {
    char* input_line = malloc(sizeof(char) * MAX_INPUT_LENGTH);
    int input_index = 0;
    int input_char;

    if (!input_line) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        input_char = getchar();

        if (input_char == EOF || input_char == '\n') {
            input_line[input_index] = '\0';
            return input_line;
        } else {
            input_line[input_index] = input_char;
        }

        input_index++;

        if (input_index >= MAX_INPUT_LENGTH) {
            fprintf(stderr, "Maximum input length exceeded\n");
            exit(EXIT_FAILURE);
        }
    }
}

char** shell_split_line(char* line) {
    char** input_tokens = malloc(sizeof(char*) * MAX_TOKENS);
    char* input_token;
    int token_index = 0;

    if (!input_tokens) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    input_token = strtok(line, TOKEN_DELIM);

    while (input_token != NULL) {
        input_tokens[token_index] = input_token;
        token_index++;

        if (token_index >= MAX_TOKENS) {
            fprintf(stderr, "Maximum number of tokens exceeded\n");
            exit(EXIT_FAILURE);
        }

        input_token = strtok(NULL, TOKEN_DELIM);
    }

    input_tokens[token_index] = NULL;
    return input_tokens;
}

int shell_execute(char** args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Execution error");
        }

        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Fork error");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}