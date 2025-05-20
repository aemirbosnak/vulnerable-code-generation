//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define MAX_INPUT 1024 // Maximum size of input string.
#define MAX_TOKENS 100 // Maximum number of commands that can be stored.
#define DELIM " \t\r\n\a" // Delimeter used to separate commands.

void prompt() { // Function to print prompt.
    char *username = getenv("USER"); // Get username.
    printf("\n%s@MY_SHELL>> ", username); // Print prompt.
}

int main() {
    printf("\nWelcome to my UNIX-LIKE SHELL!\n"); // Greeting message.
    printf("Type 'exit' to quit the shell.\n\n"); // Command to exit the shell.
    char *input = (char *)malloc(MAX_INPUT * sizeof(char)); // Allocate memory to input string.
    pid_t pid; // Initialize process ID variable.
    while(1) { // Keep looping for new commands.
        prompt(); // Print prompt.
        if(fgets(input, MAX_INPUT, stdin) == NULL) // Read input.
            break;
        input[strlen(input) - 1] = '\0'; // Replace newline character at end of string with null character.
        char *tokens[MAX_TOKENS]; // Declare array to store commands.
        int token_count = 0; // Initialize token count.
        char *token = strtok(input, DELIM); // Tokenize input string.
        while(token != NULL) { // Loop until all commands are separated.
            tokens[token_count++] = token; // Store token in array.
            token = strtok(NULL, DELIM); // Move to next token.
        }
        tokens[token_count] = NULL; // Set last element to null for execvp() function to work properly.
        if(strcmp(tokens[0], "exit") == 0) // Check for exit command.
            break;
        pid = fork(); // Create child process.
        if(pid < 0) { // Check for error in creating child process.
            perror("An error occurred in forking.\n");
            exit(1);
        }
        else if(pid == 0) { // Child process.
            if(execvp(tokens[0], tokens) < 0) { // Execute command.
                perror("An error occurred in executing the command.\n"); // Check for error.
                exit(1);
            }
        }
        else { // Parent process.
            wait(NULL); // Wait for child process to finish.
        }
    }
    printf("\nThank you for using my UNIX-LIKE SHELL!\n"); // Closing message.
    return 0;
}