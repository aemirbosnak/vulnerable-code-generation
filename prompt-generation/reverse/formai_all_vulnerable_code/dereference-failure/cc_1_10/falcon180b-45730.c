//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int count = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            tokens = realloc(tokens, sizeof(char *) * ++count);
            token = strdup(++str);
            tokens[count - 1] = token;
            str = strchr(str, '\0') + 1;
        } else {
            str++;
        }
    }

    tokens = realloc(tokens, sizeof(char *) * count);
    tokens[count - 1] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: Command not found.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Enter a command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    args = split_string(input);
    execute_command(args);

    return 0;
}