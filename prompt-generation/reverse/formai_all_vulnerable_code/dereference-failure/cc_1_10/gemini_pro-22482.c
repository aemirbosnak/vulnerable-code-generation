//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 16

// Declare the built-in commands
void cd(char *args[]);
void exit_shell();

int main() {

    // Declare the shell's main loop
    while (1) {

        // Prompt the user for input
        printf("SHOCKED SHELL>> ");
        fflush(stdout);

        // Read the user's input
        char cmd[MAX_CMD_LEN];
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Parse the user's input into arguments
        char *args[MAX_ARGS];
        int num_args = 0;
        char *token = strtok(cmd, " ");
        while (token != NULL) {
            args[num_args++] = token;
            token = strtok(NULL, " ");
        }

        // Check if the user entered a built-in command
        if (strcmp(args[0], "cd") == 0) {
            cd(args);
        } 
        else if (strcmp(args[0], "exit") == 0) {
            exit_shell();
        } 
        else {
            //Fork a new process to execute the command
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                execvp(args[0], args);
                perror("Error executing command");
                exit(1);
            } 
            else if (pid > 0) {
                // Parent process
                int status;
                wait(&status);
            } 
            else {
                // Error forking
                perror("Error forking");
            }
        }
    }

    return 0;
}

// Define the built-in commands
void cd(char *args[]) {
    if (args[1] == NULL) {
        printf("Error: no directory specified\n");
    } 
    else {
        if (chdir(args[1]) != 0) {
            printf("Error: directory not found\n");
        }
    }
}

void exit_shell() {
    printf("Exiting shell...\n");
    exit(0);
}