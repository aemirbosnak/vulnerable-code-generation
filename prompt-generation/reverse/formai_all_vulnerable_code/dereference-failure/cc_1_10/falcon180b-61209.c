//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to split command into arguments
char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argc++;
        argv = realloc(argv, sizeof(char *) * argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

// Function to execute command and return exit status
int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        execvp(argv[0], argv);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        // Error forking
        perror("fork");
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

// Main function for shell
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    int status;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        argv = split_command(input);
        status = execute_command(argv);

        if (status == 0) {
            printf("Command executed successfully.\n");
        } else {
            printf("Command failed with exit status %d.\n", status);
        }

        free(argv);
    }

    return 0;
}