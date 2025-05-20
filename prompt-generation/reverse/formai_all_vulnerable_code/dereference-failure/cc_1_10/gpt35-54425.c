//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

#define PROMPT "$ "

void read_command(char *command);
void parse_command(char *command, char **arguments);
void execute_command(char **arguments);

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];

    while (1) {
        printf("%s", PROMPT);
        read_command(command);
        parse_command(command, arguments);
        execute_command(arguments);
    }

    return 0;
}

void read_command(char *command) {
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    // remove the '\n' character from the end
    command[strlen(command) - 1] = '\0';
}

void parse_command(char *command, char **arguments) {
    char *token;
    int i = 0;

    // get the first argument
    token = strtok(command, " ");

    // loop through the rest of the arguments
    while (token != NULL && i < MAX_ARGUMENTS - 1) {
        arguments[i++] = token;
        token = strtok(NULL, " ");
    }

    // set the last argument to NULL (required by execvp)
    arguments[i] = NULL;
}

void execute_command(char **arguments) {
    pid_t pid;
    int status;

    // fork a new process
    pid = fork();

    if (pid == -1) { // error forking
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // child process
        // execute the command
        execvp(arguments[0], arguments);

        // if execvp returns, there was an error
        perror(arguments[0]);
        exit(EXIT_FAILURE);
    } else { // parent process
        do {
            // wait for the child process to complete
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}