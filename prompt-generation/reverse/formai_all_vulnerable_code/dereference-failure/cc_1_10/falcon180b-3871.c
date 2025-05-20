//Falcon-180B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char *command = "";
char *argv[MAX_ARGUMENTS];
int argc = 0;

void execute_command() {
    pid_t pid;
    int status;

    if (argc == 0) {
        fprintf(stderr, "Error: No command specified.\n");
        return;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        if (execvp(command, argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void parse_command(char *input) {
    char *token;
    int i = 0;

    strcpy(command, input);
    token = strtok(input, " ");
    while (token!= NULL && i < MAX_ARGUMENTS - 1) {
        argv[i++] = token;
        token = strtok(NULL, " ");
    }
    argv[i] = NULL;
    argc = i;
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        fprintf(stdout, "> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strncmp(input, "exit", 4) == 0) {
            break;
        } else {
            parse_command(input);
            execute_command();
        }
    }

    return 0;
}