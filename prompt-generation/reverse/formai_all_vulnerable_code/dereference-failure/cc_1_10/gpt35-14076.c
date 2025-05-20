//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void printPrompt() {
    char cwd[BUFFER_SIZE];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s$ ", cwd);
    } else {
        printf("Error: Unable to get current directory.\n");
    }
}

int main(int argc, char *argv[]) {
    char command[BUFFER_SIZE];
    char *args[BUFFER_SIZE];
    char *token;
    int status;

    while (1) {
        printPrompt();

        if (!fgets(command, sizeof(command), stdin)) {
            break;
        }

        // Remove trailing newline from command
        command[strcspn(command, "\n")] = 0;

        // Parse command string into arguments
        int i = 0;
        token = strtok(command, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Exit shell if user inputs 'exit' or 'quit'
        if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0) {
            break;
        }

        // Fork child process to execute command
        int pid = fork();
        if (pid == 0) {
            // Child process
            if (execvp(args[0], args) < 0) {
                printf("Error: Unable to execute command.\n");
                exit(1);
            }
        } else if (pid < 0) {
            // Fork error
            printf("Error: Unable to fork child process.\n");
            exit(1);
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}