//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAXLINE 80 // max line length
#define MAXARGS 20 // max arguments

void handle_input(char *user_input, char **args);
int execute(char **args);

int main(void) {
    char user_input[MAXLINE]; // user input string
    char *args[MAXARGS]; // array of arguments
    int should_run = 1; // flag to run loop
    
    while (should_run) {
        printf(" visionary-sh$ "); // display shell prompt
        fflush(stdout); // flush the output buffer
        
        // get user input
        fgets(user_input, MAXLINE, stdin);
        user_input[strlen(user_input)-1] = '\0'; // remove trailing newline
        
        // handle user input
        handle_input(user_input, args);
        
        // execute input
        should_run = execute(args);
        
        // clean up arguments
        for (int i = 0; i < MAXARGS; i++) {
            args[i] = NULL;
        }
    }
    return 0;
}

void handle_input(char *user_input, char **args) {
    char *token;
    int i = 0;
    
    // split user input into arguments
    token = strtok(user_input, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // set last argument to NULL
}

int execute(char **args) {
    int background = 0; // flag for running in background
    int status; // exit status for child process
    pid_t pid; // process ID for child process
    
    // check for background process
    if (strcmp(args[MAXARGS-2], "&") == 0) {
        background = 1;
        args[MAXARGS-2] = NULL;
    }
    
    // fork child process
    pid = fork();
    
    // error in fork
    if (pid < 0) {
        printf("Fork failed\n");
        return 0;
    }
    // child process
    else if (pid == 0) {
        execvp(args[0], args);
        printf("Command not found\n");
        exit(1);
    }
    // parent process
    else {
        // wait for child to terminate if not running in background
        if (!background) {
            waitpid(pid, &status, 0);
            printf("Command completed\n");
        }
    }
    return 1;
}