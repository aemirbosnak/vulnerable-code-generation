//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define MAX_LINE 1024
#define MAX_ARGS 1024

char** split_line(char* line);
int execute_command(char** args);
void handle_signal(int signum);

int main() {
    char input[MAX_LINE];
    char** args;
    pid_t pid;
    int status;

    signal(SIGINT, handle_signal);

    while(1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        args = split_line(input);
        if(args[0] == NULL)
            continue;

        pid = fork();
        if(pid == 0) {
            execute_command(args);
            exit(0);
        } else if(pid < 0) {
            perror("fork");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char** split_line(char* line) {
    char** args = malloc(MAX_ARGS * sizeof(char*));
    int argc = 0;
    char* token = strtok(line, " ");

    while(token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char** args) {
    pid_t pid;
    int status;

    if(args[0] == NULL)
        return 1;

    if(strcmp(args[0], "exit") == 0) {
        return 0;
    } else if(strcmp(args[0], "cd") == 0) {
        if(args[1] == NULL) {
            fprintf(stderr, "Expected argument to 'cd'\n");
            return 1;
        }
        if(chdir(args[1])!= 0) {
            perror("chdir");
            return 1;
        }
    } else {
        pid = fork();
        if(pid == 0) {
            if(execvp(args[0], args) == -1) {
                perror("execvp");
                exit(1);
            }
        } else if(pid < 0) {
            perror("fork");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void handle_signal(int signum) {
    if(signum == SIGINT) {
        fprintf(stdout, "\nInterrupted\n");
    }
}