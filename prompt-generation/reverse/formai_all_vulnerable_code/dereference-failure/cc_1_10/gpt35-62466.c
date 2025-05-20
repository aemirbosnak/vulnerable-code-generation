//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// Defining the maximum length of the input buffer
#define MAX_LEN 1024

// Function to read the input from the user
char *read_input(){
    char *input = malloc(sizeof(char) * MAX_LEN); // Allocating memory for input buffer
    printf(">>> "); // Display the prompt
    fgets(input, MAX_LEN, stdin); // Read the input from the user
    return input;
}

// Function to parse the input into separate arguments
char **parse_input(char *input){
    int i = 0;
    char **args = malloc(sizeof(char*) * MAX_LEN); // Allocating memory for arguments
    char *token = strtok(input, " \n\t"); // Tokenize the input

    while(token != NULL){
        args[i] = token; // Saving the token as an argument
        i++;
        token = strtok(NULL, " \n\t"); // Get next token
    }

    args[i] = NULL; // Adding NULL terminator at the end of the array
    return args;
}

// Main function
int main(){
    char *input;
    char **args;
    int status;

    // Main loop
    do{
        input = read_input(); // Read input from user
        args = parse_input(input); // Parse the input into arguments

        // Check if user wants to exit
        if(strcmp(args[0], "exit") == 0){
            return 0;
        }

        // Forking a new process
        int pid = fork();

        // Child process
        if(pid == 0){
            // Executing the command
            if(execvp(args[0], args) == -1){
                perror("shell"); // Error handling
            }
            exit(EXIT_FAILURE);
        }
        else if(pid < 0){ // Error forking
            perror("shell");
        }
        else{
            // Waiting for child process to complete
            do{
                waitpid(pid, &status, WUNTRACED);
            }while(!WIFEXITED(status) && !WIFSIGNALED(status)); // Checking if process was terminated normally or by a signal
        }

        free(input); // Freeing allocated memory
        free(args);

    }while(1);
    return 0;
}