//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    char **tokens = NULL;
    int count = 0;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens = realloc(tokens, sizeof(char *) * ++count);
        tokens[count - 1] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LEN];
    char **args;

    printf("Grateful Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LEN, stdin);
        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        launch_shell(args);
    }

    return 0;
}