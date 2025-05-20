//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: real-life
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_LENGTH 1024 // Maximum length of the user input
#define TOK_DELIM " \t\r\n\a" // delimiters for command parsing

// Function to read user input
char *read_input(){
    char* line = NULL;
    ssize_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

// Function to parse input and separate commands
char **parse_input(char* line){
    int bufsize = MAX_LENGTH, index = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        printf("Memory allocation error.");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL){
        tokens[index] = token;
        index++;

        if (index >= bufsize) {
            bufsize += MAX_LENGTH;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                printf("Memory allocation error.");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOK_DELIM);
    }
    tokens[index] = NULL;
    return tokens;
}

// Function to execute commands
void execute(char **args){
    pid_t pid, wait_pid;
    int status;

    pid = fork();
    if (pid == 0){
        // Child process
        if (execvp(args[0], args) == -1)
            perror("Error executing command");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0){
        // Forking error
        perror("Error forking");
    }
    else{
        // Parent process
        do {
            wait_pid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main(){
    char *line;
    char **args;
    int status;

    do {
        printf(">> ");
        line = read_input();
        args = parse_input(line);
        execute(args);

        free(line);
        free(args);
    } while (status);

    return EXIT_SUCCESS;
}