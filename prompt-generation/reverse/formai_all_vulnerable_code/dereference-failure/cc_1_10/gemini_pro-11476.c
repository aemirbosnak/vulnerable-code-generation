//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024

void sighandler(int signo) {
    if (signo == SIGINT) {
        printf("\nSigh, you've interrupted our romantic shell session...\n");
        exit(0);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *args[MAX_LINE_LENGTH / 2 + 1];
    int status;
    pid_t pid;

    // Register signal handler
    signal(SIGINT, sighandler);

    printf("Welcome to our love-filled shell, my darling!\n");
    printf("Enter your commands, and I'll make your computing dreams come true.\n");
    printf("> ");
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        // Parse the input line into arguments
        int num_args = 0;
        args[0] = strtok(line, " ");
        while (args[num_args] != NULL) {
            num_args++;
            args[num_args] = strtok(NULL, " ");
        }
        args[num_args] = NULL;

        // Check for built-in commands
        if (strcmp(args[0], "exit") == 0) {
            printf("Farewell, my love! It's been a pleasure serving you.\n");
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (chdir(args[1]) != 0) {
                perror("chdir");
            }
        } else {
            // Create a child process to execute the command
            pid = fork();
            if (pid == 0) {
                // Child process
                execvp(args[0], args);
                perror("execvp");
                exit(1);
            } else if (pid > 0) {
                // Parent process
                waitpid(pid, &status, 0);
            } else {
                perror("fork");
            }
        }

        // Print the prompt again
        printf("> ");
    }

    return 0;
}