//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 100 // maximum length of input line
#define MAX_NUM_ARGS 10     // maximum number of arguments that can be passed to a command

int main() {
    char input[MAX_LINE_LENGTH]; // input line buffer
    char *args[MAX_NUM_ARGS];    // command arguments array
    int status;                  // stores the exit status of child processes
    
    while(1) {
        printf("$ ");  // prompt for input
        fgets(input, MAX_LINE_LENGTH, stdin);  // read input from user
        
        // remove newline character at the end of input
        input[strcspn(input, "\n")] = 0;
        
        // tokenize the input string into command and arguments
        char *token = strtok(input, " ");

        int i = 0;
        while(token != NULL) {
            args[i++] = strdup(token);
            token = strtok(NULL, " ");
        }
        
        args[i] = NULL;  // last argument must be NULL
        
        // handle empty input
        if(args[0] == NULL)
            continue;
        
        // handle exit command
        if(strcmp(args[0], "exit") == 0)
            break;
        
        pid_t pid = fork();  // fork a child process

        if(pid == 0) {  // child process
            
            // execute command
            execvp(args[0], args);
            
            // if execvp returns, there was an error
            printf("Error executing command.\n");
            exit(EXIT_FAILURE);
            
        } else if(pid < 0) {  // error forking process
            
            printf("Error forking process.\n");
            exit(EXIT_FAILURE);
            
        } else {  // parent process
            
            // wait for child process to finish
            waitpid(pid, &status, 0);
            
            // check if child process exited normally
            if(WIFEXITED(status)) {
                printf("Child process exited with status %d.\n", WEXITSTATUS(status));
            } else if(WIFSIGNALED(status)) {  // child process was terminated by a signal
                printf("Child process terminated by signal %d.\n", WTERMSIG(status));
            }
        }

        // free memory allocated for arguments
        for(int i = 0; args[i] != NULL; i++) {
            free(args[i]);
        }
    }
    
    return 0;
}