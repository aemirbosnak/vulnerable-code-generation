//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <errno.h> 
#include <sys/wait.h> 

int main() 
{ 
    char input[1024]; 
    char *args[64]; 
    int status; 
    pid_t pid;

    while (1) 
    { 
        printf(" $ "); 
        fgets(input, 1024, stdin); 
        
        // remove trailing newline character
        input[strcspn(input, "\n")] = 0;
        
        // split the input into separate arguments
        char *arg = strtok(input, " ");
        int i = 0;
        while (arg != NULL) {
            args[i] = arg;
            arg = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            printf("Command not found\n");
            exit(errno);
        } 
        else if (pid > 0) {
            waitpid(pid, &status, 0);
        } 
        else {
            fprintf(stderr, "Error: Fork failed\n");
            exit(errno);
        }
    } 
    return 0; 
}