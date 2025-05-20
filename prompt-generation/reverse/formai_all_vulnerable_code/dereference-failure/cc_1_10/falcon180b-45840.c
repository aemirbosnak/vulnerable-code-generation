//Falcon-180B DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 80
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0

char **split_string(char *string);
void execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Retro Shell!\n");
    while(TRUE) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);
        execute_command(args);
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    int len = strlen(string);
    char **args = malloc(sizeof(char *) * (len + 1));
    char *token;

    token = strtok(string, DELIM);
    while(token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL)
        return;

    if(strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if(strcmp(args[0], "cd") == 0) {
        if(args[1]!= NULL) {
            if(chdir(args[1])!= 0) {
                perror("chdir");
            }
        } else {
            fprintf(stderr, "Usage: cd <directory>\n");
        }
    } else if(strcmp(args[0], "pwd") == 0) {
        printf("%s\n", getcwd(NULL, 0));
    } else {
        pid = fork();

        if(pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else if(pid < 0) {
            perror("fork");
        } else {
            waitpid(pid, &status, 0);
        }
    }
}