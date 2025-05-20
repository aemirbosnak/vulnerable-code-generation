//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 512
#define MAX_NUM_ARGS 10

int main() {
    char command[MAX_CMD_LEN];
    char* args[MAX_NUM_ARGS];
    int status, i, num_args;

    printf("Greetings, Watson. What is it that you require? \nMy expertise lies in the field of Unix-like shells. \n");

    while (1) {
        // Prompt for command
        printf("Enter your command: ");
        fgets(command, MAX_CMD_LEN, stdin);

        // Remove newline character at the end
        command[strcspn(command, "\n")] = 0;

        // Parse command into arguments
        num_args = 0;
        args[num_args] = strtok(command, " ");
        while (args[num_args] != NULL && num_args < MAX_NUM_ARGS) {
            num_args++;
            args[num_args] = strtok(NULL, " ");
        }
        
        // Check for exit command
        if (strcmp(args[0], "exit") == 0) {
            printf("Farewell, Watson. It was a pleasure working with you. \n");
            break;
        }

        // Create child process
        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Error: Failed to create child process. \n");
            continue;
        } else if (pid == 0) {
            // Execute command in child process
            if (execvp(args[0], args) < 0) {
                fprintf(stderr, "Error: Failed to execute command. \n");
                exit(1);
            }
        } else {
            // Wait for child process to finish
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}