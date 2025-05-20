//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

char **split(char *str, int *n) {
    char **tokens = malloc((strlen(str)+1)*sizeof(char*));
    int i = 0;
    char *token = strtok(str, DELIM);
    while(token!= NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;
    *n = i;
    return tokens;
}

int launch(char **cmd) {
    pid_t pid;
    int status;
    pid = fork();
    if(pid == 0) {
        execvp(cmd[0], cmd);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if(pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
        if(WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;
    int n;
    while(TRUE) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        tokens = split(input, &n);
        if(n == 0) {
            continue;
        }
        if(strcmp(tokens[0], "exit") == 0) {
            break;
        } else if(strcmp(tokens[0], "cd") == 0) {
            if(chdir(tokens[1])!= 0) {
                printf("cd: %s: No such file or directory\n", tokens[1]);
            }
        } else {
            int status = launch(tokens);
            if(status == -1) {
                printf("launch: Child died with signal %d, %s\n", WTERMSIG(status), tokens[0]);
            }
        }
        free(tokens);
    }
    return EXIT_SUCCESS;
}