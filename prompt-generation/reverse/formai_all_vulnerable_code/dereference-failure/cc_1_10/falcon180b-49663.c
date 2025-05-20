//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define PATH "/usr/local/bin:/usr/bin:/bin"
#define MAX_ARGUMENTS 100

char **split_string(char *string) {
    int count = 0;
    char **arguments = NULL;
    char *token;

    token = strtok(string, DELIM);
    while(token!= NULL) {
        arguments = realloc(arguments, sizeof(char *) * ++count);
        arguments[count-1] = token;
        token = strtok(NULL, DELIM);
    }
    arguments[count] = NULL;

    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if(arguments[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if(pid == -1) {
        perror("fork");
        return 1;
    } else if(pid == 0) {
        if(execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    int command_count = 0;

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        arguments = split_string(input);

        if(arguments[0] == NULL) {
            continue;
        }

        command_count++;
        if(command_count == 1) {
            printf("Welcome to the Medieval Shell, my liege.\n");
        } else if(command_count % 5 == 0) {
            printf("Thou hast entered %d commands.\n", command_count);
        }

        execute_command(arguments);
        free(arguments);
    }

    return 0;
}