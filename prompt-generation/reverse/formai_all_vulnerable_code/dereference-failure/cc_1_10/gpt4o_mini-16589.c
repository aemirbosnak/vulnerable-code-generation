//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100
#define BUFFER_SIZE 1024

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("exec");
        }
        exit(EXIT_FAILURE);
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parse_command(char *line, char **args) {
    char *token;
    int position = 0;

    token = strtok(line, " \n");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
}

void shell_loop() {
    char *line = NULL;
    char *args[MAX_ARGS];
    size_t len = 0;
    
    while (1) {
        printf("myshell> ");
        getline(&line, &len, stdin);

        if (strncmp(line, "exit", 4) == 0) {
            free(line);
            exit(0);
        }
        
        parse_command(line, args);
        
        // Handle built-in commands
        if (args[0] != NULL) {
            if (strncmp(args[0], "cd", 2) == 0) {
                if (args[1] == NULL) {
                    fprintf(stderr, "cd: missing argument\n");
                } else if (chdir(args[1]) != 0) {
                    perror("cd");
                }
                continue; // Continue to prompt for a new command
            } else if (strncmp(args[0], "help", 4) == 0) {
                printf("Simple shell commands:\n");
                printf("  cd <directory>  Change the current directory\n");
                printf("  exit            Exit the shell\n");
                printf("  help            Show this help message\n");
                free(line);
                line = NULL;
                len = 0;
                continue; 
            }
        }
        
        execute_command(args);
        free(line);
        line = NULL;
        len = 0;
    }
}

int main() {
    shell_loop();
    return 0;
}