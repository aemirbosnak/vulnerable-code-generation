//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);

int main(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    printf("Enter commands. Type 'exit' to quit.\n");

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (strcmp(input_buffer, "exit") == 0) {
            break;
        }

        args = split_string(input_buffer);
        status = execute_command(args);

        if (status == -1) {
            printf("Error executing command.\n");
        }
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(string, DELIM);

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
        return -1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}