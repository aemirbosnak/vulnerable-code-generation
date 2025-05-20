//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
pid_t fork();
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_string(input);
        pid_t pid = fork();
        if(pid == -1) {
            printf("Fork failed\n");
        } else if(pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}

char **split_string(char *str) {
    char **tokens = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH/2));
    int token_count = 0;
    char *token = strtok(str, DELIM);
    while(token!= NULL) {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, DELIM);
    }
    tokens[token_count] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid = fork();
    if(pid == -1) {
        perror("Fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();
    if(pid == -1) {
        perror("Fork");
        exit(1);
    } else if(pid == 0) {
        if(args[0] == NULL) {
            printf("Command not found\n");
            exit(1);
        } else {
            execvp(args[0], args);
            perror("Execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}