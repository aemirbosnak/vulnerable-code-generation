//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64
#define DELIM " \t\r\n"

int main() {
    char cmd[MAX_CMD_LEN];
    char* args[MAX_ARGS];
    int status;

    while(1) {
        // Print shell prompt
        printf("myshell> ");
        fflush(stdout);

        // Read input command from the user
        if(fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
            printf("\n");
            break;
        }

        // Parse command into arguments
        char* arg;
        int i = 0;
        args[i++] = strtok(cmd, DELIM);
        while((arg = strtok(NULL, DELIM)) != NULL) {
            args[i++] = arg;
        }

        // Check for exit command and exit if needed
        if(strcmp(args[0], "exit") == 0) {
            break;
        }

        // Fork current process and execute command in child process
        pid_t pid = fork();
        if(pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if(pid == 0) {
            if(execvp(args[0], args) < 0) {
                perror("execvp failed");
                exit(EXIT_FAILURE);
            }
        } else {
            // Wait for child process to finish
            wait(&status);
        }
    }

    return 0;
}