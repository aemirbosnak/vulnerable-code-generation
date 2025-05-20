//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024  // Maximum input length
#define MAX_ARGS 64  // Maximum number of arguments
#define MAX_PATHS 100  // Maximum number of paths in PATH variable

/**
 * Parse the input into an array of arguments
 */
void parse_input(char* input, char** args)
{
    char* token;
    int i = 0;
    
    // Split input string using spaces and newline as delimiters
    token = strtok(input, " \n");
    
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    
    args[i] = NULL;
}

/**
 * Search for the executable file in all paths
 */
char* search_executable(char* cmd, char** paths)
{
    char* path;
    char* executable = (char*) malloc(MAX_LENGTH*sizeof(char));
    
    // Search for executable file in all paths
    for (int i = 0; i < MAX_PATHS; i++) {
        if (paths[i] == NULL) {
            break;
        }
        
        sprintf(executable, "%s/%s", paths[i], cmd);
        if (access(executable, X_OK) != -1) {
            return executable;
        }
    }
    
    return NULL;
}

/**
 * Handler function for SIGINT signal (CTRL+C)
 */
void sigint_handler(int sig)
{
    printf("\n");
}

int main()
{
    char input[MAX_LENGTH];  // User input
    char* args[MAX_ARGS];  // Array of arguments
    char* paths[MAX_PATHS];  // Array of paths in PATH variable
    int status;  // Status of child process
    pid_t pid;  // Process ID of child process
    
    // Set up signal handler for SIGINT signal
    signal(SIGINT, sigint_handler);
    
    // Get paths from PATH environment variable
    char* path_var = getenv("PATH");
    
    char* path = strtok(path_var, ":");
    int i = 0;
    
    while (path != NULL) {
        paths[i++] = path;
        path = strtok(NULL, ":");
    }
    
    paths[i] = NULL;
    
    while (1) {
        // Print prompt and get input from user
        printf("> ");
        fgets(input, MAX_LENGTH, stdin);
        
        // Parse input into array of arguments
        parse_input(input, args);
        
        // Exit if user inputs "exit"
        if (strcmp(args[0], "exit") == 0) {
            break;
        }
        
        // Fork child process
        pid = fork();
        
        if (pid == 0) {  // Child process
            // Search for executable file in all paths
            char* executable = search_executable(args[0], paths);
            
            if (executable == NULL) {  // Executable not found
                printf("%s: command not found\n", args[0]);
                exit(1);
            }
            
            // Replace child process with executable
            execv(executable, args);
            
            // Execution should not reach this point unless there's an error
            printf("%s: execv failed\n", args[0]);
            exit(1);
        } else {  // Parent process
            // Wait for child process to finish
            wait(&status);
        }
    }
    
    return 0;
}