//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);

int main() {
    char input[MAX_LINE];
    printf("Welcome to the Shell\n");
    while(1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);
        char **args = split_line(input);
        int status = execute_command(args);
        if(WIFEXITED(status)) {
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        } else if(WIFSIGNALED(status)) {
            printf("Command killed by signal %d\n", WTERMSIG(status));
        }
        free(args);
    }
    return 0;
}

char **split_line(char *line) {
    int count = 0;
    char **args = malloc(sizeof(char *));
    args[0] = strtok(line, DELIM);
    while(args[count]!= NULL) {
        count++;
        args = realloc(args, sizeof(char *) * (count + 1));
        args[count - 1] = strtok(NULL, DELIM);
    }
    args[count] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if(args[0] == NULL) {
        return 1;
    }
    if(strcmp(args[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if(pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else if(pid < 0) {
        perror("fork");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }
    return status;
}