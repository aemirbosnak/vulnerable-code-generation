//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024 // Maximum buffer size

int main(int argc, char *argv[]) 
{
    char input[BUFFER_SIZE]; // User input
    char *args[BUFFER_SIZE / 2]; // Process arguments
    int status; // Status of the child process
    pid_t pid; // Process ID

    printf("Welcome to Puzzle Shell!\n");
    printf("Type 'help' for a list of available commands.\n\n"); 

    while(1) {
        // Print command prompt
        printf("puzzle-shell$ ");
        fflush(stdout);

        // Read input from user
        fgets(input, BUFFER_SIZE, stdin);

        // Remove the newline character from input
        input[strlen(input)-1] = '\0';

        // Split input into multiple arguments
        char *token = strtok(input, " ");
        int argcount = 0;
        while (token != NULL) {
            args[argcount] = token;
            argcount++;
            token = strtok(NULL, " ");
        }
        args[argcount] = NULL;

        // Check if command is a built-in command
        if (strcmp(args[0], "help") == 0) {
            printf("\n**** Puzzle Shell Help ****\n");
            printf("Available commands:\n");
            printf("    help - Show this help message\n");
            printf("    puzzle - Solve the puzzle of unknown origin\n");
            printf("    exit - Exit the shell\n");
            printf("\n");
        } 
        else if (strcmp(args[0], "puzzle") == 0) {
            printf("\nYou have selected the puzzle command.\n");
            printf("You must answer the riddle correctly before proceeding.\n");
            printf("What has a neck but no head, arms but no hands?\n");

            // Read user input for puzzle
            fgets(input, BUFFER_SIZE, stdin);
            input[strlen(input)-1] = '\0';

            // Check if user answered the puzzle correctly
            if (strcmp(input, "a bottle") == 0) {
                printf("\nCongratulations! You have solved the puzzle!\n");
                printf("Now you can proceed with the puzzle command.\n\n");
            }
            else {
                printf("\nSorry, that's the wrong answer. Try again later.\n\n");
            }
        } 
        else if (strcmp(args[0], "exit") == 0) {
            printf("\nThank you for using Puzzle Shell.\nGoodbye!\n");
            exit(0);
        }
        else {
            // Fork a new process to execute command
            pid = fork();

            if (pid < 0) {
                printf("Error: Fork Failed\n");
                exit(1);
            } 
            else if (pid == 0) {
                // Child process executes the command
                if (execvp(args[0], args) < 0) {
                    printf("Error: Command not found\n");
                    exit(1);
                }
            } 
            else {
                // Parent process waits for child process to finish
                waitpid(-1, &status, 0);
            }
        }
    }
    return 0;
}