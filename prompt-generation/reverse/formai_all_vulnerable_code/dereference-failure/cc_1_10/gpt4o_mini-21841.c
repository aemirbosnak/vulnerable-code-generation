//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_SIZE 64
#define PROMPT "FunShell> "
#define READ_LINE_SIZE 100

void print_welcome_message() {
    printf("*******************************************\n");
    printf("* Welcome to FunShell!                   *\n");
    printf("* Where commands meet chuckles!          *\n");
    printf("*******************************************\n");
}

void print_farewell_message() {
    printf("*******************************************\n");
    printf("* Thank you for using FunShell!          *\n");
    printf("* Remember, laughter is the best script! *\n");
    printf("*******************************************\n");
}

char *read_line() {
    char *line = malloc(BUFFER_SIZE);
    if (fgets(line, BUFFER_SIZE, stdin) == NULL) {
        free(line);
        return NULL; 
    }
    return line;
}

char **split_line(char *line) {
    char **tokens = malloc(TOKEN_SIZE * sizeof(char*));
    char *token;
    int position = 0;

    token = strtok(line, " \n");
    while (token != NULL) {
        tokens[position++] = token;
        if (position >= TOKEN_SIZE) {
            tokens = realloc(tokens, TOKEN_SIZE * sizeof(char*));
        }
        token = strtok(NULL, " \n");
    }
    tokens[position] = NULL; 
    return tokens;
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            if (strcmp(args[0], "joke") == 0) {
                printf("Why did the programmer quit his job? Because he didn't get arrays!\n");
            } else {
                perror("FunShell");
            }
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) { // Error forking
        perror("FunShell");
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main() {
    print_welcome_message();

    char *line;
    char **args;

    while (1) {
        printf(PROMPT);
        line = read_line();
        if (line == NULL) {
            break; // EOF
        }
        args = split_line(line);

        if (args[0] == NULL) {
            free(line);
            free(args);
            continue; // No command entered
        }
        
        if (strcmp(args[0], "exit") == 0) {
            free(line);
            free(args);
            print_farewell_message();
            exit(EXIT_SUCCESS);
        }

        execute_command(args);

        free(line);
        free(args);
    }

    return 0;
}