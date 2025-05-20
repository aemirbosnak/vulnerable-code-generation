//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int buf_size = strlen(str) + 1;
    char *buf = malloc(buf_size);
    strcpy(buf, str);
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(buf, DELIM);
    int count = 0;
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

pid_t fork_and_exec(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    }
    return pid;
}

void handle_sigint(int signum) {
    printf("\nInterrupted by SIGINT\n");
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Happy Shell > ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_string(input);
        pid_t pid = fork_and_exec(args);
        waitpid(pid, NULL, 0);
    }
    return 0;
}