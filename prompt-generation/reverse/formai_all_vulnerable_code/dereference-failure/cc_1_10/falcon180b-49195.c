//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function prototypes
char **split_string(char *str);
pid_t launch_shell(char **args);
int execute_command(char **args);
void loop(void);
void print_prompt(void);

int main(void) {
    loop();
    return 0;
}

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            token = strdup(str);
            bufsize++;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            tokens[i++] = token;
        }
        str++;
    }

    tokens[i] = NULL;
    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    if ((pid = launch_shell(args)) == -1) {
        return 1;
    }

    if (waitpid(pid, NULL, WUNTRACED) == -1) {
        perror("waitpid");
        return 1;
    }

    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    print_prompt();

    if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
        perror("fgets");
        exit(1);
    }

    args = split_string(input);
    execute_command(args);
    free(args);
}

void print_prompt(void) {
    printf("> ");
}