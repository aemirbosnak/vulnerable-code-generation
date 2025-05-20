//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 10

void parse_line(char *line, char **argv) {
    while (*line != '\0') {
        // Skip whitespace
        while (*line == ' ') {
            *line++ = '\0';
        }
        // Get argument
        *argv++ = line;
        // Skip argument
        while (*line != '\0' && *line != ' ') {
            line++;
        }
    }
    *argv = '\0';
}

int main(int argc, char **argv) {
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int status;

    while (1) {
        // Print prompt
        printf("myshell> ");
        fflush(stdout);

        // Read line
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }

        // Parse line
        parse_line(line, args);

        // Built-in commands
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                chdir(getenv("HOME"));
            } else {
                chdir(args[1]);
            }
        } else {
            // Fork process
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                execvp(args[0], args);
                perror("execvp");
                exit(1);
            } else {
                // Parent process
                wait(&status);
            }
        }
    }

    return 0;
}