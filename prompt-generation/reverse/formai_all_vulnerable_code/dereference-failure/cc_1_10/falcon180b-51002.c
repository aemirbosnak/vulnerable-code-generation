//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LINE_LENGTH 1024
#define MAX_ARGS 64

char **split_command(char *command);
int execute_command(char **args);
void loop(void);

int main(int argc, char *argv[]) {
    loop();
    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LINE_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LINE_LENGTH, stdin);

    char *command = strtok(input, "\n");
    char **args = split_command(command);

    int status = execute_command(args);

    if (WIFEXITED(status)) {
        printf("Command exited with status %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("Command was terminated by signal %d\n", WTERMSIG(status));
    } else {
        printf("Command terminated abnormally\n");
    }

    free(args);
}

char **split_command(char *command) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    int argc = 0;
    char *token = strtok(command, " ");

    while (token!= NULL && argc < MAX_ARGS - 1) {
        args[argc] = token;
        argc++;
        token = strtok(NULL, " ");
    }

    args[argc] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error forking process\n");
        return -1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error executing command\n");
            return -1;
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}