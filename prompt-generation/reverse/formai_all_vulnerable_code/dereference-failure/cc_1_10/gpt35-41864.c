//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include<stdio.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<string.h> 
  
#define MAX_LENGTH 1000 
  
// function to take input 
int TakeInput(char* userInput) 
{ 
    char currentInput; 
    int index = 0; 
 
    // loop through the input until newline is encountered 
    while (currentInput != '\n') 
    { 
        scanf("%c", &currentInput); 
        userInput[index++] = currentInput; 
    } 
  
    // Replace newline with NULL character 
    userInput[--index] = '\0'; 
    return index; 
} 
  
// function to split the input into words 
void SplitInput(char* userInput, char** args) 
{ 
    int length = strlen(userInput); 
    char* currentArg = strtok(userInput, " "); 
    int index = 0; 
  
    // loop through input and split into words using strtok() 
    while (currentArg != NULL) 
    { 
        args[index++] = currentArg; 
        currentArg = strtok(NULL, " "); 
    } 
  
    // set NULL at the end of the arguments 
    args[index] = NULL;  
} 
  
int main(int argc, char* argv[]) 
{ 
    char userInput[MAX_LENGTH]; 
    char* args[50]; 
    int inputLength, shouldRun = 1; 
    pid_t pid; 
    int status; 
  
    // loop until user enters "exit" 
    while (shouldRun) 
    { 
        printf(">>> "); 
  
        // call TakeInput function to get user input 
        inputLength = TakeInput(userInput); 
  
        // check for "exit" command 
        if (strcmp(userInput, "exit") == 0) 
        { 
            shouldRun = 0; 
        } 
        else
        { 
            // call SplitInput function to split the input into words 
            SplitInput(userInput, args); 
  
            // fork a process 
            pid = fork(); 
  
            if (pid < 0) 
            { 
                fprintf(stderr, "Fork Failed\n"); 
                return 1; 
            } 
            else if (pid == 0) 
            { 
                // child process 
                if (execvp(args[0], args) < 0) 
                { 
                    fprintf(stderr, "Execvp Failed\n"); 
                    return 1; 
                } 
            } 
            else
            { 
                // parent process 
                waitpid(pid, &status, 0); 
            } 
        } 
    } 
  
    return 0; 
}