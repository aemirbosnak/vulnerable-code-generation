//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10  //max number of arguments expected
#define MAX_LENGTH 100  //max length of an input string expected

int main() {
    char* args[MAX_ARGS];  //to store the individual arguments in a null-terminated array of strings
    char input[MAX_LENGTH];  //to store the raw input string
    int status;  //to store the exit status of a child process
    pid_t pid;  //to store the process ID of a child process

    while(1) {
        printf("myShell> "); //the shell prompt
        fgets(input, MAX_LENGTH, stdin);  //read the entire input line

        if (feof(stdin)) {
            exit(0);
        }

        if(strcmp(input,"\n") == 0){ //if only enter key is pressed
            continue; //restart the loop
        }
        
        char* token = strtok(input, " \n");  //split the input string into tokens separated by white space or newline
        int i = 0;

        while(token) {  //iterate through all the tokens
            args[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }

        args[i] = NULL;  //add null at the end of the args array to make it null-terminated

        if(strcmp(args[0], "exit") == 0) {  //exit the shell if user enters 'exit' as the first argument
            exit(0);
        }

        pid = fork();  //create a new child process

        if(pid == -1) { //if fork() fails
            perror("Error: fork failed");
            exit(1);
        } else if(pid == 0) {  //child process
            if(execvp(args[0], args) == -1) {  //execute the command. execvp() will replace the child process with the given command
                perror("Error");
                exit(1);
            }
        } else {  //parent process
            waitpid(pid, &status, 0);  //wait for the child process to exit and store its exit status in 'status'
        }
    }

    return 0;
}