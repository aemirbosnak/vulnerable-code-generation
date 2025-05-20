//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
#define MAX_PATH_LENGTH 1024

void read_input(char *input) {
    printf("$ ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    if (input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
}

void parse_input(char *input, char **args) {
    char *token;
    int i = 0;
    token = strtok(input, " ");
    while (token != NULL && i < MAX_ARGS-1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;     
}

void execute_command(char **args) {
    pid_t pid;
    int status;
    if ((pid = fork()) < 0) {
        printf("Error: fork failed.\n");
        exit(1);
    } else if (pid == 0) { // child process
        if (execvp(args[0], args) < 0) {
            printf("Error: exec failed.\n");
            exit(1);
        }
    } else { // parent process
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    char path[MAX_PATH_LENGTH];
    while (1) {
        read_input(input);
        parse_input(input, args);
        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                chdir(getenv("HOME"));
            } else {
                chdir(args[1]);
            }
        } else if (strcmp(args[0], "pwd") == 0) {
            printf("%s\n", getcwd(path, MAX_PATH_LENGTH));
        } else if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else {
            execute_command(args);
        }
    }   
    return 0;
}