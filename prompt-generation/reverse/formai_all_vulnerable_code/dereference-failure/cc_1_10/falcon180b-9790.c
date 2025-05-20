//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 1000
#define MAX_LINE 1000

char **split(char *line);
int execute_command(char **args);
void sigint_handler(int signum);

int main() {
    char input[MAX_LINE];
    char **args;
    pid_t pid;
    int status;

    signal(SIGINT, sigint_handler);

    printf("Enter commands, type 'exit' to quit:\n");
    while (fgets(input, MAX_LINE, stdin)!= NULL) {
        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        args = split(input);
        pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split(char *line) {
    int count = 0;
    char *token;
    char **args = malloc(MAX_COMMANDS * sizeof(char*));

    token = strtok(line, " ");
    while (token!= NULL) {
        args[count++] = token;
        token = strtok(NULL, " ");
    }
    args[count] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void sigint_handler(int signum) {
    printf("\nInterrupted by user.\n");
}