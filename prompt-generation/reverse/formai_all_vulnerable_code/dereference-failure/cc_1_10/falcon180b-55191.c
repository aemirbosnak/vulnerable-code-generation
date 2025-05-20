//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line);
void execute_command(char **args);
void sigint_handler(int signum);

int main() {
    char input[MAX_LINE];
    char **args;
    pid_t pid;

    signal(SIGINT, sigint_handler);

    printf("Welcome to the shell!\n");

    while(1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        args = split_line(input);
        if(args[0] == NULL)
            continue;

        pid = fork();
        if(pid == -1) {
            perror("fork");
            exit(1);
        } else if(pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(line, DELIM);
    while(token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;
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
        if(args[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        } else {
            if(chdir(args[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();
        if(pid == -1) {
            perror("fork");
            exit(1);
        } else if(pid == 0) {
            if(execvp(args[0], args) == -1) {
                perror("execvp");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void sigint_handler(int signum) {
    fprintf(stderr, "Interrupted by signal %d\n", signum);
    exit(1);
}