//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024 // Maximum length of inputs

void main(){
    char input[MAX_LENGTH];
    char *args[MAX_LENGTH/2 + 1];
    int should_run = 1;

    while(should_run){
        printf("sh> ");
        fflush(stdout); // Flush the output buffer
        fgets(input, MAX_LENGTH, stdin); // Get the user input

        // Tokenize the input string
        char *token;
        int i = 0;
        token = strtok(input, " \n");
        while(token != NULL){
            args[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }
        args[i] = NULL;

        if(strcmp(args[0], "exit") == 0){ // Handle the "exit" command
            should_run = 0;
        }
        else{
            pid_t pid;
            pid = fork(); // Create a new process

            if(pid < 0){ // Handle errors from fork()
                printf("Error: Fork failed.\n");
                exit(1);
            }
            else if(pid == 0){ // Child process
                execvp(args[0], args); // Execute the command
                exit(0); // Exit the child process
            }
            else{ // Parent process
                wait(NULL); // Wait for child process to finish
            }
        }
    }
}