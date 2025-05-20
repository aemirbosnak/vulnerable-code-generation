//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
pid_t fork();
int execute_command(char **args);
void print_prompt();

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t child_pid;

    print_prompt();

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        child_pid = fork();

        if (child_pid == 0) {
            execute_command(args);
            exit(0);
        } else if (child_pid < 0) {
            fprintf(stderr, "Fork failed.\n");
        } else {
            waitpid(child_pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *string) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

pid_t fork() {
    return fork();
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Fork failed.\n");
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void print_prompt() {
    printf("Happy Shell > ");
}