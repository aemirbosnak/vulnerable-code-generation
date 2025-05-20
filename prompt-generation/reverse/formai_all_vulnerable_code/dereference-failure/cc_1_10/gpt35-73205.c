//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\r\n\a"

char* read_input(void)
{
    char* input = NULL;
    ssize_t buffer_size = 0;
    getline(&input, &buffer_size, stdin);
    return input;
}

char** split_input(char* input, int* num_tokens)
{
    char** tokens = malloc(BUFFER_SIZE * sizeof(char*));
    *num_tokens = 0;
    char* token = strtok(input, TOKEN_DELIM);
    while (token != NULL) {
        tokens[*num_tokens] = token;
        (*num_tokens)++;
        token = strtok(NULL, TOKEN_DELIM);
    }
    tokens[*num_tokens] = NULL;
    return tokens;
}

int execute_input(char** tokens)
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("forking error occurred");
    } else if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp error occurred");
        }
        exit(EXIT_FAILURE);
    } else {
        int status;
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

void grateful_terminal(void)
{
    int num_tokens;
    char* input;
    char** tokens;
    int should_continue = 1;
    while (should_continue) {
        printf("Grateful Terminal > ");
        input = read_input();
        tokens = split_input(input, &num_tokens);
        should_continue = execute_input(tokens);
        free(input);
        free(tokens);
    }
}

int main(int argc, char** argv)
{
    printf("Welcome to the Grateful Terminal!\n");
    grateful_terminal();
    printf("Thank you for using the Grateful Terminal!\n");
    return 0;
}