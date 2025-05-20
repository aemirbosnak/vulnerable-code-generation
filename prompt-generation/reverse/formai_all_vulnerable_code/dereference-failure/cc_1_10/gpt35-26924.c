//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define MAX_COMMAND_LENGTH 100  // Maximum length of a single command
#define MAX_ARGUMENTS 10        // Maximum number of arguments a command can have

char* read_input() {
    char* input = (char*)malloc(MAX_COMMAND_LENGTH * sizeof(char)); // Allocate memory for input
    
    printf("Enter a command: "); 
    fgets(input, MAX_COMMAND_LENGTH, stdin); // Get input from user
    
    size_t len = strlen(input);
    if (input[len-1] == '\n') input[len-1] = '\0'; // Remove trailing newline character for proper tokenization
    
    return input;
}

char** parse_input(char* input) {
    char** arguments = (char**)malloc(MAX_ARGUMENTS * sizeof(char*)); // Allocate memory for arguments
    
    char* token = strtok(input, " "); // Tokenize input by space
    
    int i=0;
    while (token != NULL && i < MAX_ARGUMENTS) {
        arguments[i++] = token; // Store each token in an array
        token = strtok(NULL, " ");
    }
    arguments[i] = NULL; // Set the last array element to NULL for execvp()
    
    return arguments;
}

int main() {
    while(1) {
        char* input = read_input(); // Read input from user
        char** arguments = parse_input(input); // Parse input into arguments
        
        pid_t pid = fork(); // Create a new process
        
        if (pid == -1) { 
            printf("Could not fork process\n");
            exit(1); // Exit the program with error code
        } else if (pid == 0) {
            if (execvp(arguments[0], arguments) == -1) { // Execute command
                printf("Invalid command\n");
                exit(1); // Exit the child process with error code
            }
        } else {
            wait(NULL); // Wait for child process to complete
            printf("Command executed successfully\n");
        }
        
        free(input);
        free(arguments); // Free dynamically allocated memory
    }
    
    return 0;
}