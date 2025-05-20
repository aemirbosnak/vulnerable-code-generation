//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100

// Function to execute a command
void execute_command(char **args) {
    pid_t pid, wpid;
    int status;
    
    // Create a child process
    pid = fork();
    
    if (pid == 0) {
        // In child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error forking");
    } else {
        // In parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

// Function to parse the command input
void parse_command(char *input, char **args) {
    char *token;
    
    token = strtok(input, " \n");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;
}

// Function to handle the shell prompt
void shell_prompt() {
    char *input = NULL;
    size_t len = 0;
    char *args[MAX_ARGS];

    while (1) {
        // Display the prompt
        printf("mysh> ");
        
        // Read a line of input
        if (getline(&input, &len, stdin) == -1) {
            perror("getline");
            continue;
        }
        
        // Check for exit command
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        // Parse the command
        parse_command(input, args);
        
        // Execute the command
        execute_command(args);
    }

    free(input);
}

int main(int argc, char **argv) {
    shell_prompt();
    return 0;
}