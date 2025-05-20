//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 100
#define DELIM " "
#define MAX_LINE 1024

char **split_line(char *line);
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_LINE];
    char **args;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        args = split_line(input);
        execute_command(args);
    }

    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = (char **)malloc(sizeof(char *) * MAX_COMMANDS);
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL && argc < MAX_COMMANDS) {
        args[argc] = token;
        argc++;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 1;

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1]!= NULL) {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        } else {
            printf("Usage: cd [directory]\n");
        }
    } else if (strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("%s\n", cwd);
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        }
    }

    return 1;
}

void handle_signal(int signum) {
    printf("\n");
    exit(0);
}