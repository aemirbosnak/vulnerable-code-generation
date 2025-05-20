//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
void execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_string(input);
    if (args == NULL) {
        printf("Error: command too long.\n");
        return;
    }

    execute_command(args);
}

char **split_string(char *string) {
    char **tokens = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2 + 1));
    int count = 0;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count++] = token;
        if (count >= MAX_COMMAND_LENGTH / 2) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1]!= NULL) {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        } else {
            fprintf(stderr, "Usage: cd [directory]\n");
        }
    } else if (strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!= NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd");
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
        } else {
            waitpid(pid, &status, 0);
        }
    }
}