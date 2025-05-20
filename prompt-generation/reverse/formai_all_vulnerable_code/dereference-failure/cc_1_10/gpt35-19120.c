//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

// Function to print the shell prompt
void printPrompt() {
    char dir[MAX_INPUT_SIZE];
    getcwd(dir, sizeof(dir));
    printf("\n%s: ", dir);
}

int main() {
    char line[MAX_INPUT_SIZE]; // to hold the command line input
    char* tokens[MAX_NUM_TOKENS]; // to hold the tokens generated from the input
    int numTokens = 0; // count of number of tokens generated
    pid_t pid; // to hold the process ID of the child process
    int status; // to hold the termination status of the child process

    while (1) {
        printPrompt();

        // read the input from the user
        if (!fgets(line, MAX_INPUT_SIZE, stdin)) 
            break;

        // tokenize the input
        char* token = strtok(line, " \t\n");
        while (token != NULL && numTokens < MAX_NUM_TOKENS) {
            tokens[numTokens] = token;
            numTokens++;
            token = strtok(NULL, " \t\n");
        }
        tokens[numTokens] = NULL;

        // check for built-in commands (cd and exit)
        if (strcmp(tokens[0], "cd") == 0) {
            if (chdir(tokens[1]) != 0)
                printf("Error: Could not change directory\n");
            continue;
        } else if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        // create a child process to execute the command
        pid = fork();

        if (pid == 0) { // child process
            if (execvp(tokens[0], tokens) == -1) {
                printf("Error: Could not execute command\n");
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) { // error forking
            printf("Error: Could not fork process\n");
            exit(EXIT_FAILURE);
        } else { // parent process
            waitpid(pid, &status, 0);
        }

        // reset the tokens
        numTokens = 0;
        memset(tokens, 0, sizeof(tokens));
    }

    return 0;
}