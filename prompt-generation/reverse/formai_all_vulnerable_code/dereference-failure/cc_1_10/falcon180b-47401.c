//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
int execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_command(input);
    int status = execute_command(args);

    if (WIFEXITED(status)) {
        printf("Exit status: %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Killed by signal %d\n", WTERMSIG(status));
    } else {
        printf("Unknown exit status\n");
    }

    free(args);
}

char **split_command(char *command) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

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
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        // Error forking
        perror("fork");
        return 1;
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        return status;
    }
}