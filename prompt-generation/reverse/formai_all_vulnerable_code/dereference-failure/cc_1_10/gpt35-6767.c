//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARGS 25
#define MAX_INPUT 1024

// Function to parse input and create argument array
char **parseInput(char *input){
    int i = 0;
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *arg;

    if (!args){
        printf("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    arg = strtok(input, " \t\r\n\a");
    while (arg != NULL){
        args[i] = arg;
        i++;
        arg = strtok(NULL, " \t\r\n\a");
    }
    args[i] = NULL;
    return args;
}

// Function to execute parsed input
int executeInput(char **args){
    pid_t pid, wpid;
    int status;

    pid = fork();

    // Child process
    if (pid == 0){
        // Check for input redirection
        int i = 0;
        while (args[i] != NULL){
            if (strcmp(args[i], "<") == 0){
                args[i] = NULL;
                int fd = open(args[i + 1], O_RDONLY);
                dup2(fd, STDIN_FILENO);
                close(fd);
                break;
            }
            i++;
        }

        // Check for output redirection
        i = 0;
        while (args[i] != NULL){
            if (strcmp(args[i], ">") == 0){
                args[i] = NULL;
                int fd = open(args[i + 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
                dup2(fd, STDOUT_FILENO);
                close(fd);
                break;
            }
            i++;
        }

        // Execute command
        if (execvp(args[0], args) == -1){
            perror("Shell");
        }

        exit(EXIT_FAILURE);
    }
    // Parent process
    else if (pid > 0){
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    // Error forking
    else {
        perror("Shell");
    }

    return 1;
}

int main(){
    char *input;
    char **args;
    int status = 1;

    do {
        printf("Shell> ");
        input = malloc(MAX_INPUT * sizeof(char));
        fgets(input, MAX_INPUT, stdin);
        args = parseInput(input);
        status = executeInput(args);

        free(input);
        free(args);

    } while (status);

    return 0;
}