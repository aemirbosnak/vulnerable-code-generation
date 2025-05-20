//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 100 // Maximum length of user input
#define TRUE 1 // Used to set loop conditions to true
#define FALSE 0 // Used to set loop conditions to false
#define SHELL_NAME "Artistic Shell" // Name of the Unix-like shell

/* --------------- Function Declarations --------------- */

void clearScreen();

/* --------------- Main program --------------- */

int main()
{
    char userInput[MAX_LENGTH]; // Declare an array to hold user input
    char *token; // Declare a pointer to a token
    char *args[MAX_LENGTH]; // Declare an array to hold pointers to tokens
    int loop = TRUE; // Set loop condition to true
    pid_t pid; // Declare process ID variable

    clearScreen(); // Clear the screen

    while (loop) // Loop until loop condition is FALSE
    {
        printf("%s>>> ", SHELL_NAME); // Print the prompt
        fgets(userInput, MAX_LENGTH, stdin); // Get user input

        token = strtok(userInput, " \n"); // Get the first token

        int i = 0;
        while (token != NULL) // Loop while there are tokens
        {
            args[i++] = token; // Add token to args array
            token = strtok(NULL, " \n"); // Get the next token
        }
        args[i] = NULL; // Set last element of args to NULL

        if (strcmp(args[0], "exit") == 0) // If the first arg is "exit"
        {
            loop = FALSE; // Set loop condition to false
        }
        else if (strcmp(args[0], "cls") == 0) // If the first arg is "cls"
        {
            clearScreen(); // Call clearScreen function
        }
        else // Otherwise, fork a process and execute user input
        {
            pid = fork(); // Fork a new process

            if (pid < 0) // Error occurred
            {
                fprintf(stderr, "Fork failed.\n"); // Print error message
                exit(1); // Exit the program
            }
            else if (pid == 0) // Child process
            {
                if (execvp(args[0], args) == -1) // Execute the command
                {
                    printf("Command not found.\n"); // Print error message
                }
                exit(EXIT_FAILURE); // Exit the child process
            }
            else // Parent process
            {
                wait(NULL); // Wait for child process to finish
            }
        }
    }

    return 0; // Exit the program
}

/* --------------- Function Definitions --------------- */

void clearScreen()
{
    printf("\033[H\033[J"); // Send ANSI escape sequence to clear screen
}