//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELAY 1

char **split_command(char *command);
pid_t fork();
void execute_command(char **arguments);

int main() {
    char input[MAX_COMMAND_LENGTH];
    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **arguments = split_command(input);
        if(arguments == NULL) {
            printf("Invalid command\n");
            continue;
        }
        pid_t child_pid = fork();
        if(child_pid == 0) {
            execute_command(arguments);
            exit(0);
        } else if(child_pid < 0) {
            printf("Fork failed: %s\n", strerror(errno));
        } else {
            int status;
            waitpid(child_pid, &status, 0);
        }
    }
    return 0;
}

char **split_command(char *command) {
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argument_count = 0;
    char *token = strtok(command, " ");
    while(token!= NULL) {
        arguments[argument_count] = token;
        argument_count++;
        if(argument_count >= MAX_ARGUMENTS) {
            printf("Too many arguments\n");
            free(arguments);
            return NULL;
        }
        token = strtok(NULL, " ");
    }
    arguments[argument_count] = NULL;
    return arguments;
}

void execute_command(char **arguments) {
    if(arguments[0] == NULL) {
        return;
    }
    pid_t pid = fork();
    if(pid == 0) {
        if(execvp(arguments[0], arguments) == -1) {
            printf("Command not found: %s\n", arguments[0]);
            exit(1);
        }
    } else if(pid < 0) {
        printf("Fork failed: %s\n", strerror(errno));
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}