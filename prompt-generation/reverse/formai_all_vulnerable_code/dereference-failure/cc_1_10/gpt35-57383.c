//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char* userInput;
    char* token;
    const char delim[] = " \n\t\r";
    int bufferSize = 1024;
    int status;
    pid_t pid;

    //Allocating memory to userInput variable
    userInput = (char*)malloc(bufferSize * sizeof(char));
    if(userInput == NULL) {
        perror("Error : Unable to allocate memory!");
        exit(EXIT_FAILURE);
    }

    //Infinitely iterates the shell
    while(1) {
        //Printing the prompt
        printf("myShell>> ");

        //Reading user input
        if(fgets(userInput, bufferSize, stdin) == NULL)
            break;

        int count = 0;
        char* argList[100];

        //Extracting tokens from user input
        token = strtok(userInput, delim);
        while(token != NULL) {
            argList[count++] = token;
            token = strtok(NULL, delim);
        }

        argList[count] = NULL;

        //Forking process to run executable in child process
        pid = fork();

        if(pid == -1) {
            perror("Error : Unable to fork process!");
            exit(EXIT_FAILURE);
        } else if(pid == 0) {
            //Executing the command in child process
            if(execvp(argList[0], argList) < 0) {
                perror("Error : Invalid command entered!");
                exit(EXIT_FAILURE);
            }
        } else {
            //Waiting for child process to complete
            waitpid(pid, &status, WUNTRACED);
        }
    }

    //Freeing up the memory allocated
    free(userInput);
    return 0;
}