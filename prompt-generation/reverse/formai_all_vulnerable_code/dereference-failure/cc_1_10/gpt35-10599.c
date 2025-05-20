//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 50

int main() {
    char input[MAX_COMMANDS * MAX_COMMAND_LENGTH];
    char* commands[MAX_COMMANDS];
    char* token;

    while(1) {
        printf(">>> ");

        // Read user input
        fgets(input, sizeof(input), stdin);

        // Tokenize the input and store it in an array
        int i = 0;
        token = strtok(input, " \n");
        while(token != NULL) {
            commands[i++] = token;
            token = strtok(NULL, " \n");
        }
        commands[i] = NULL;

        // Exit if the user inputs "exit"
        if(strcmp(commands[0], "exit") == 0) {
            printf("Exiting...\n");
            exit(0);
        }

        // Create a new process to execute the command
        pid_t pid = fork();
        if(pid == 0) {
            // Child process
            execvp(commands[0], commands);
            printf("Command not found.\n");
            exit(0);
        } else if(pid > 0) {
            // Parent process
            wait(NULL);
        } else {
            // Error: Could not create process
            printf("Failed to create child process.\n");
        }
    }
    return 0;
}