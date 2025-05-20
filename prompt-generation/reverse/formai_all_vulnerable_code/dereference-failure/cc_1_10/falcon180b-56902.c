//Falcon-180B DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str, char delim);
int execute_command(char **args);
void sigchld_handler(int signum);

int main(void) {
    setbuf(stdout, NULL);
    signal(SIGCHLD, sigchld_handler);

    while (1) {
        printf("> ");
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_string(input, DELIM);
        execute_command(args);
    }

    return 0;
}

char **split_string(char *str, char delim) {
    int bufsize = BUFFER_SIZE;
    int numtokens = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(str, delim);

    while (token!= NULL) {
        numtokens++;
        tokens = realloc(tokens, sizeof(char *) * numtokens);
        tokens[numtokens - 1] = strdup(token);
        token = strtok(NULL, delim);
    }

    tokens[numtokens] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}