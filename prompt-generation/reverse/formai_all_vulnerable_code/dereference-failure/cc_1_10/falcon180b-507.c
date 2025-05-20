//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_string(char *string);
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

    char **args = split_string(input);
    if (args == NULL) {
        printf("Error: Invalid command.\n");
        return;
    }

    int status = execute_command(args);

    if (WIFEXITED(status)) {
        printf("Command exited with status %d.\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Command was terminated by signal %d.\n", WTERMSIG(status));
    } else {
        printf("Command exited abnormally.\n");
    }

    free(args);
}

char **split_string(char *string) {
    int argc = 0;
    char **args = NULL;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    args = realloc(args, sizeof(char *) * argc);
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}