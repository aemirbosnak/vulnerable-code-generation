//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_LEN 1024 // Maximum length of user input

int main(){
    char input[MAX_LEN]; // Define buffer for user input
    char *args[100]; // Define array of pointers to store all the arguments in the input

    while(1){
        printf("my_shell$ "); // Print prompt
        fgets(input, MAX_LEN, stdin); // Read user input
        
        // Split user input into arguments
        char *token;
        int i = 0;
        token = strtok(input, " \n");
        while(token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " \n");
        }
        args[i] = NULL; // Set the last argument as NULL as required by execvp()
        
        // Exit shell if user types 'exit'
        if(strcmp(args[0], "exit") == 0){
            printf("Goodbye!\n");
            exit(0);
        }

        int pid, status;
        pid = fork(); // Create a new process

        if(pid < 0){
            printf("Error creating new process...\n");
            exit(1);
        }
        else if (pid == 0){ // Child process
            if(execvp(args[0], args) == -1){ // Execute command
                printf("Unknown command\n"); // Print error message if command is not recognized
            }
            exit(0);
        }
        else{ // Parent process
            waitpid(pid, &status, 0); // Wait for child process to finish
        }
    }
    return 0;
}