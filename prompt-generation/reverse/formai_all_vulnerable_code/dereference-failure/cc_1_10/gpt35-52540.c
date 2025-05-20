//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 80 // Maximum characters per command
#define MAX_HISTORY 10 // Maximum number of commands in history

char *history[MAX_HISTORY]; // History of commands
int hist_count = 0; // Count of commands in history

void printIntro();
void printPrompt();
void printHistory();
void addHistory(char *command);

int main(){
    char *args[MAX_LINE/2 + 1]; // Arguments of the command
    int should_run = 1; // Flag to exit the shell
    char command[MAX_LINE]; // Buffer to store the command
    int background = 0; // Flag for background execution

    printIntro(); // Print the introduction

    while(should_run){
        printPrompt(); // Print the prompt

        fgets(command, MAX_LINE, stdin); // Get the command from user
        command[strlen(command)-1] = '\0'; // Remove the newline character

        if(strcmp(command, "exit")==0){ // Check if the user wants to exit
            should_run = 0;
            continue;
        }

        if(strcmp(command, "history")==0){ // Check if the user wants to see the history
            printHistory();
            continue;
        }

        addHistory(command); // Add the command to history

        int i = 0;
        char *token = strtok(command, " "); // Tokenize the command

        while(token!=NULL){ // Loop through the tokens
            if(strcmp(token, "&")==0){ // Check for background execution
                background = 1;
                break;
            }

            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL; // Mark the end of arguments

        pid_t pid = fork(); // Fork to create a child process

        if(pid<0){ // Check for error in forking
            fprintf(stderr, "Fork failed\n");
        }
        else if(pid==0){ // Code for the child process
            execvp(args[0], args); // Execute the command
            fprintf(stderr, "Command not found: %s\n", args[0]); // Error if execvp fails
            exit(1);
        }
        else{ // Code for the parent process
            if(!background){ // Wait for the child process if not running in background
                waitpid(pid, NULL, 0);
            }
        }
    }

    return 0;
}

void printIntro(){
    printf("Welcome to the Lord's Shell\n");
    printf("Type 'exit' to leave the shell\n");
    printf("Type 'history' to see the commands in history\n\n");
}

void printPrompt(){
    printf("My Lord's command: ");
}

void printHistory(){
    printf("Commands in history:\n");

    for(int i=0; i<hist_count; i++){
        printf("%d. %s\n", i+1, history[i]);
    }
}

void addHistory(char *command){
    if(hist_count==MAX_HISTORY){ // Check for maximum number of commands in history
        free(history[0]); // Deallocate memory for the oldest command
        memcpy(history, history+1, (MAX_HISTORY-1)*sizeof(char*)); // Shift the commands by one index
        hist_count--;
    }

    history[hist_count++] = strdup(command); // Add the latest command to history
}