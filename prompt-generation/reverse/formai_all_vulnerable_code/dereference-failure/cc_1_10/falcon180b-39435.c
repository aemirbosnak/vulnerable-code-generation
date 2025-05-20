//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **arguments);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    printf("Welcome to the Unix-like Shell!\n");

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_string(input);

        if(arguments[0] == NULL)
            continue;

        execute_command(arguments);
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(string, DELIM);

    while(token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if(arguments[0] == NULL)
        return 1;

    if(strcmp(arguments[0], "exit") == 0) {
        return 0;
    } else if(strcmp(arguments[0], "cd") == 0) {
        if(arguments[1] == NULL) {
            fprintf(stderr, "Usage: cd [directory]\n");
        } else {
            if(chdir(arguments[1])!= 0) {
                perror("chdir");
            }
        }
    } else if(strcmp(arguments[0], "pwd") == 0) {
        printf("%s\n", getcwd(NULL, 0));
    } else {
        pid = fork();

        if(pid == -1) {
            perror("fork");
        } else if(pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            if(execvp(arguments[0], arguments) == -1) {
                perror("execvp");
            }
        }
    }

    return 1;
}