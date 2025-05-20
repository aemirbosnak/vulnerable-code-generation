//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 64

/* Function to execute the command with arguments */
void execute(char **args) {
    pid_t pid = fork();     // Create a new child process
    
    if (pid == -1) {        // Check for error while creating the child process
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {    // Child process
        if (execvp(args[0], args) == -1) {     // Execute the command with arguments
            perror("execvp failed");           // Check for errors while executing the command
            exit(1);
        }
    } 
    else {                  // Parent process
        int status;
        if (waitpid(pid, &status, 0) == -1) {  // Wait for child process to terminate
            perror("waitpid failed");           // Check for errors while waiting
            exit(1);
        }
    }
}

/* Function to parse the input string and return an array of arguments*/
char **parse_input(char *input) {
    int i = 0;
    char **args = malloc(MAX_ARGS * sizeof(char*));
    char *token = strtok(input, " \t\r\n\a");
    
    while(token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\r\n\a");
    }
    args[i] = NULL;
    return args;
}

int main(int argc, char **argv) {
    char input[MAX_LENGTH];
    char **args;
    
    while(1) {
        printf("my_shell$ ");
        fgets(input, MAX_LENGTH, stdin);    // Read input from user
        args = parse_input(input);          // Parse the input
        
        if (strcmp(args[0], "exit") == 0) { // Exit if the user enters "exit"
            exit(0);
        }
        execute(args);                      // Execute the command
        free(args);                         // Free the dynamically allocated memory for argument array
    }
    return 0;
}