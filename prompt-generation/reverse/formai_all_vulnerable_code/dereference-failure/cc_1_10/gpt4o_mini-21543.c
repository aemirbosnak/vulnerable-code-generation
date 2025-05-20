//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 100

void print_prompt() {
    printf(">>> ");
}

void parse_input(char* input, char** arguments) {
    char* token;
    int position = 0;

    token = strtok(input, " \n");
    while (token != NULL) {
        arguments[position++] = token;
        token = strtok(NULL, " \n");
    }
    arguments[position] = NULL;
}

int execute_command(char** arguments) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) { // Child process
        if (execvp(arguments[0], arguments) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return status;
}

void shell_loop() {
    char* input = malloc(MAX_INPUT_SIZE);
    char* arguments[MAX_ARGUMENTS];
    char* built_in_commands[] = {"exit", "pwd", "cd", NULL};

    while (1) {
        print_prompt();
        if (!fgets(input, MAX_INPUT_SIZE, stdin)) {
            break; // Exit on Ctrl+D
        }

        parse_input(input, arguments);

        if (arguments[0] == NULL) {
            continue; // Empty input
        }

        // Check for built-in commands
        if (strcmp(arguments[0], "exit") == 0) {
            free(input);
            exit(0);
        } else if (strcmp(arguments[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            } else {
                perror("shell");
            }
            continue;
        } else if (strcmp(arguments[0], "cd") == 0) {
            if (arguments[1] == NULL) {
                fprintf(stderr, "shell: cd: missing argument\n");
            } else {
                if (chdir(arguments[1]) != 0) {
                    perror("shell");
                }
            }
            continue;
        }

        execute_command(arguments);
    }

    free(input);
}

int main() {
    printf("Welcome to the Imaginative Shell!\n");
    shell_loop();
    return 0;
}