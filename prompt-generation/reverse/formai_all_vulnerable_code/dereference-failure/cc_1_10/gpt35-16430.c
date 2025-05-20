//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFF_SIZE 1024

char* read_command() {
    char *buffer = malloc(sizeof(char) * BUFF_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Error: unable to allocate buffer.");
        exit(EXIT_FAILURE);
    }
    fgets(buffer, BUFF_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // remove trailing newline
    return buffer;
}

char** split_args(char* command) {
    int num_args = 0;
    char** args = malloc(sizeof(char*) * BUFF_SIZE);
    if (args == NULL) {
        fprintf(stderr, "Error: unable to allocate args.");
        exit(EXIT_FAILURE);
    }
    char *arg = strtok(command, " ");
    while (arg != NULL) {
        args[num_args++] = arg;
        arg = strtok(NULL, " ");
    }
    args[num_args] = NULL;
    return args;
}

int main() {
    while (1) {
        printf("-> ");
        char* command = read_command();
        char** args = split_args(command);

        pid_t pid = fork();
        if (pid == 0) {
            // child process
            execvp(args[0], args);
            fprintf(stderr, "Error: command not found.\n");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            // parent process
            wait(NULL);
        } else {
            // error forking
            fprintf(stderr, "Error: Failed to fork process.\n");
        }

        free(command);
        free(args);
    }

    return 0;
}