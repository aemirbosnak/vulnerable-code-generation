//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGUMENTS 1000

char *command;
char **arguments;
int num_arguments;
int background;

void parse_command(char *input) {
    char *token = strtok(input, " ");
    command = token;

    while ((token = strtok(NULL, " "))!= NULL) {
        arguments = realloc(arguments, sizeof(char *) * ++num_arguments);
        arguments[num_arguments - 1] = token;
    }
}

void execute_command() {
    pid_t pid;

    if (background) {
        pid = fork();
        if (pid == 0) {
            execvp(command, arguments);
            perror("execvp");
            exit(1);
        }
    } else {
        pid = fork();
        if (pid == 0) {
            execvp(command, arguments);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, NULL, 0);
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    FILE *fp;

    fp = fopen("/dev/tty", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open tty\n");
        return 1;
    }

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, fp);
    parse_command(input);

    printf("Enter 'bg' to run in background or press enter to run in foreground: ");
    fgets(input, MAX_COMMAND_LENGTH, fp);
    if (strcmp(input, "bg") == 0) {
        background = 1;
    }

    execute_command();

    return 0;
}