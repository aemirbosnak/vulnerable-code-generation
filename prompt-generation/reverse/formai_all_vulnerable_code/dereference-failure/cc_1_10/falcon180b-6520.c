//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
/* This is a C program that creates a basic Unix-like Shell */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

/* Function prototypes */
char **split_string(char *string);
int execute_command(char **args);
void handle_signal(int signum);
void loop(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    loop();
    return 0;
}

/* Splits a string into an array of strings based on a delimiter */
char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens = realloc(tokens, sizeof(char *) * ++count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    tokens[count - 1] = NULL;
    return tokens;
}

/* Executes a command and returns its exit status */
int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Command not found.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Failed to execute command.\n");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

/* Handles SIGINT and SIGQUIT signals by exiting the program */
void handle_signal(int signum) {
    if (signum == SIGINT || signum == SIGQUIT) {
        fprintf(stdout, "\nExiting...\n");
        exit(0);
    }
}

/* Main loop of the shell */
void loop(void) {
    char *prompt = "> ";
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("%s", prompt);
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        execute_command(args);

        free(args[0]);
        free(args);
    }
}