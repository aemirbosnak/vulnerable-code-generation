//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

// Read a line of input from the user
char* read_line() {
    char* line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

// Parse the input into arguments
char** parse_line(char* line) {
    int i = 0;
    char** args = malloc(MAX_ARGS * sizeof(char*));
    char* arg = strtok(line, " \n");
    while (arg != NULL) {
        args[i++] = arg;
        arg = strtok(NULL, " \n");
    }
    args[i] = NULL;
    return args;
}

// Run the command and wait for it to finish
void run_command(char** args) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        printf("Command not found.\n");
        exit(0);
    } else {
        waitpid(pid, NULL, 0);
    }
}

// Main loop
int main(int argc, char const *argv[]) {
    char* line;
    char** args;
    while (1) {
        printf("$ ");
        line = read_line();
        args = parse_line(line);
        run_command(args);
        free(line);
        free(args);
    }
    return 0;
}