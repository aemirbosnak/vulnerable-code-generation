//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024 // Maximum command length
#define MAX_ARG_COUNT 64    // Maximum arguments count

int main() {

    char cmd[MAX_CMD_LENGTH];
    char *args[MAX_ARG_COUNT];
    int status;
    
    while(1) {
        printf("my_shell>> ");

        // Get the command from user
        fgets(cmd, MAX_CMD_LENGTH, stdin);
        cmd[strcspn(cmd, "\n")] = 0; // Remove the newline character

        // Split the command into individual arguments
        char *token = strtok(cmd, " ");
        int argCount = 0;
        while (token != NULL) {
            args[argCount++] = token;
            token = strtok(NULL, " ");
        }
        args[argCount] = NULL;

        // Handle user input
        if(strcmp(args[0], "exit") == 0) {
            // Exit the shell
            exit(0);
        } else {
            // Fork a child process to execute the command
            pid_t pid = fork();
            if( pid < 0 ) {
                printf("Failed to fork process\n");
                continue;
            } else if( pid == 0 ) {
                // Child process
                execvp(args[0], args);
                printf("Failed to execute command\n");
                exit(1);
            } else {
                // Parent process
                pid_t wpid = waitpid(pid, &status, 0);
                if( wpid == -1 ) {
                    printf("Error occurred while waiting for child process\n");
                    continue;
                }
            }
        }
    }

    return 0;
}