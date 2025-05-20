//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0, i = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        if (count >= MAX_ARGUMENTS) {
            printf("Too many arguments for command.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        printf("Fork failed.\n");
        return 1;
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        if (execvp(tokens[0], tokens) == -1) {
            printf("Command not found.\n");
            return 1;
        }
    }

    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    tokens = split_string(input);
    execute_command(tokens);
}

int main(void) {
    loop();
    return 0;
}