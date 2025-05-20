//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 64
#define DELIMITERS " \t\r\n\a"

void execute_command(char **args);

int main() {
    char *input_buffer;
    char **args;
    int status;

    input_buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
    if (!input_buffer) {
        perror("Error: Unable to allocate input buffer.");
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf(">>>");
        fgets(input_buffer, BUFFER_SIZE, stdin);

        // parse input into arguments
        args = (char **) malloc(MAX_ARGS * sizeof(char*));
        if (!args) {
            perror("Error: Unable to allocate arguments buffer.");
            exit(EXIT_FAILURE);
        }
        char *arg;
        int i=0;
        arg = strtok(input_buffer, DELIMITERS);
        while(arg != NULL) {
            args[i++] = arg;
            arg = strtok(NULL, DELIMITERS);
        }
        args[i] = NULL;

        // execute command
        execute_command(args);

        free(args);
    }

    free(input_buffer);

    return EXIT_SUCCESS;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) { // child process
        if (execvp(args[0], args) == -1) {
            perror("Error: Unable to execute command.");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) { // error forking process
        perror("Error: Unable to fork process.");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status)); // wait until child process exits
    }
}