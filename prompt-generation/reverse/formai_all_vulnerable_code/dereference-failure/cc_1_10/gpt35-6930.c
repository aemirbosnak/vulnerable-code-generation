//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/wait.h> 
  
#define MAX_CHARACTERS 1000 
#define MAX_ARGUMENTS 100 
  
void start_shell() 
{ 
    char command[MAX_CHARACTERS]; 
    char* arguments[MAX_ARGUMENTS]; 
    int should_run = 1;  
    
    while (should_run) { 
        printf(">> "); 
        fflush(stdout); 
  
        // Get the command from the user 
        fgets(command, MAX_CHARACTERS, stdin); 
  
        // Tokenize the user's input 
        int i = 0; 
        arguments[i] = strtok(command, " \n\0"); 
  
        while (arguments[i] != NULL) { 
            i++; 
            arguments[i] = strtok(NULL, " \n\0"); 
        } 
  
        // Check if it's the exit command 
        if (strcmp(arguments[0], "exit") == 0) { 
            should_run = 0; 
            break; 
        } 
  
        pid_t pid = fork(); 
  
        if (pid == -1) { 
            printf("Forking child process failed!\n"); 
            exit(EXIT_FAILURE); 
        } 
        else if (pid == 0) { 
            // Child process executes the command 
            if (execvp(arguments[0], arguments) == -1) { 
                printf("An error occurred while executing command!\n"); 
                exit(EXIT_FAILURE); 
            } 
        } 
        else { 
            // Parent process waits for child to finish 
            int status; 
            wait(&status); 
        } 
    } 
} 
  
// Driver program 
int main() 
{ 
    start_shell(); 
    return 0; 
}