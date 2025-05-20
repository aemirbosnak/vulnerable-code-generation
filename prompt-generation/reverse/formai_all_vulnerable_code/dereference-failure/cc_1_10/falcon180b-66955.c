//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024
#define DELIM " \t\r\n\a"

// Function to split a line into tokens
char **split_line(char *line) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        argc++;
        argv = realloc(argv, sizeof(char *) * argc);
        argv[argc - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

// Function to execute a command
int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

// Function to handle user input
void handle_input(char *line) {
    char **argv;
    int argc;

    // Split line into tokens
    argv = split_line(line);
    argc = argc - 1;

    // Execute command
    execute_command(argv);

    // Free memory
    for (int i = 0; i < argc; i++) {
        free(argv[i]);
    }
    free(argv);
}

// Function to print prompt and read user input
void read_input(void) {
    char input_buffer[MAX_LINE_SIZE];
    printf("> ");
    fgets(input_buffer, MAX_LINE_SIZE, stdin);
    handle_input(input_buffer);
}

// Main function
int main(void) {
    while (1) {
        read_input();
    }

    return 0;
}