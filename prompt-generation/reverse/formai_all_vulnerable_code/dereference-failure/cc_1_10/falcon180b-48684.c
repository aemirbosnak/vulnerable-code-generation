//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE 1024
#define MAX_COMMAND 1024
#define MAX_ARGUMENT 1024

char *command = "ls";
char *argument = "-l";

int main() {
    char input[MAX_LINE];
    char *token;
    char *command_line = calloc(MAX_COMMAND, sizeof(char));
    char *arguments[MAX_ARGUMENT];
    int argument_count = 0;

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);
        strcat(command_line, input);

        token = strtok(input, " \n");
        while (token!= NULL) {
            if (argument_count >= MAX_ARGUMENT) {
                printf("Too many arguments.\n");
                exit(1);
            }
            arguments[argument_count] = token;
            argument_count++;
            token = strtok(NULL, " \n");
        }

        if (argument_count == 0) {
            continue;
        }

        pid_t pid = fork();
        if (pid == 0) {
            if (execvp(command, arguments) == -1) {
                printf("Error executing command.\n");
                exit(1);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
        }

        argument_count = 0;
        strcpy(command_line, "");
    }

    return 0;
}