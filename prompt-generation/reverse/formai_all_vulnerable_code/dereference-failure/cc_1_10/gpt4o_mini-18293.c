//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGS 100
#define DELIM " \t\r\n"

// Function to execute commands
void execute_command(char **args) {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        // Parent process
        wait(NULL);
    }
}

// Function to parse the command line
char **parse_command(char *input) {
    char **args = malloc(MAX_NUM_ARGS * sizeof(char*));
    char *arg;
    int position = 0;

    arg = strtok(input, DELIM);
    while (arg != NULL) {
        args[position++] = arg;
        arg = strtok(NULL, DELIM);
    }
    args[position] = NULL;
    return args;
}

// Handle signals (Ctrl+C)
void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nType 'exit' to quit or run another command\n");
    }
}

// Shell loop
void shell_loop() {
    char *input = NULL;
    size_t len = 0;
    
    while (1) {
        printf("myshell> ");
        getline(&input, &len, stdin);
        
        if (strncmp(input, "exit", 4) == 0) {
            free(input);
            exit(0);
        }

        char **args = parse_command(input);
        if (args[0] != NULL) {
            if (args[0][0] == '#') {
                free(args);
                continue; // Comment line, just skip
            }
            execute_command(args);
        }

        free(args);
    }
}

int main(int argc, char *argv[]) {
    // Set up signal handler for Ctrl+C
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("Welcome to My Shell!\n");
    shell_loop();

    return 0;
}