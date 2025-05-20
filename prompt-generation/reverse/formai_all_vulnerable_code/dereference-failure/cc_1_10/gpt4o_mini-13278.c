//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARG_LENGTH 100
#define MAX_NUM_ARGS 100

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == 0) {
        // In child process
        if (execvp(args[0], args) == -1) {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error");
    } else {
        // In parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parse_command(char *input, char **args) {
    char *token = strtok(input, " \n");
    int position = 0;

    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

int main() {
    char *input = NULL;
    size_t len = 0;
    char *args[MAX_NUM_ARGS];

    printf("Welcome to MyShell! Type 'exit' to quit.\n");
    
    while (1) {
        printf("MyShell> ");
        getline(&input, &len, stdin);
        
        // Handle empty input
        if (input[0] == '\n') {
            continue;
        }

        // Exit command
        if (strcmp(input, "exit\n") == 0) {
            free(input);
            break;
        }

        // Parse the command
        parse_command(input, args);

        // Execute the command
        execute_command(args);
    }

    free(input);
    return 0;
}