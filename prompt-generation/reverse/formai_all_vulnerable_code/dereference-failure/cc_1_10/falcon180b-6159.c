//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);
void print_prompt(char *prompt);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char *prompt = "mysh> ";
    while (1) {
        print_prompt(prompt);
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_string(input);
        int status = execute_command(args);
        if (status == 1) {
            break;
        }
        free(args);
    }
    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **result = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(string, DELIM);
    while (token!= NULL && count < MAX_ARGUMENTS) {
        result[count++] = token;
        token = strtok(NULL, DELIM);
    }
    result[count] = NULL;
    return result;
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        return 1;
    }
    if (strcmp(args[0], "exit") == 0) {
        return 1;
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return 0;
}

void print_prompt(char *prompt) {
    printf("%s", prompt);
}