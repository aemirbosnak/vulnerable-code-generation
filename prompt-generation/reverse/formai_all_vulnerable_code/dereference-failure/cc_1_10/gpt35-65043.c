//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_CMD_LENGTH 100
#define MAX_ARGS 10

int main() {
    char input_cmd[MAX_CMD_LENGTH];
    char* args[MAX_ARGS];

    while(1) {
        // Print the shell prompt
        printf("Shell prompt> ");

        // Read the input command from the user
        fgets(input_cmd, MAX_CMD_LENGTH, stdin);

        // Parse the input command into arguments
        char* token;
        int arg_count = 0;
        token = strtok(input_cmd, " ");
        while(token != NULL && arg_count < MAX_ARGS - 1) {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        // Exit the shell if the command is "exit"
        if(strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        // Fork a child process to execute the command
        pid_t pid = fork();

        if(pid == 0) { // Child process
            // Execute the command
            if(execvp(args[0], args) < 0) {
                printf("Error executing command\n");
                exit(0);
            }
        }
        else if(pid < 0) { // Error forking a child process
            printf("Error forking child process\n");
        }
        else { // Parent process
            // Wait for the child process to complete
            wait(NULL);
        }
    }

    return 0;
}