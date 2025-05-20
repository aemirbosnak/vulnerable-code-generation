//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parse_input(char *input, char **args) {
    int position = 0;
    char *token;

    token = strtok(input, " \n");
    while (token != NULL) {
        args[position] = token;
        position++;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

void shell_loop() {
    char *input = NULL;
    char *args[MAX_ARG_SIZE];
    size_t len = 0;

    while (1) {
        printf("shell> ");
        getline(&input, &len, stdin);

        if (strcmp(input, "exit\n") == 0) {
            free(input);
            exit(0);
        }

        parse_input(input, args);
        if (args[0] != NULL) {
            execute_command(args);
        }
    }
}

int main() {
    shell_loop();
    return 0;
}