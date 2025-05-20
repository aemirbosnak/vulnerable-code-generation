//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include<unistd.h> 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<sys/wait.h> 

#define MAX_LENGTH 1024 // Maximum length of command line

// Function to read the command entered by user
char* read_line(void){
    char *line = NULL;
    ssize_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

// Function to split the command into tokens based on delimiter
char** split_line(char *line){
    int bufsize = MAX_LENGTH, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += MAX_LENGTH;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
              printf("Memory allocation error!\n");
              exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }

    tokens[position] = NULL;
    return tokens;
}

// Function to execute the command
int execute(char **args){
    pid_t pid = fork();
    int status;

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            printf("%s: command not found\n", args[0]);
        }
        exit(EXIT_FAILURE);
    } 
    else if (pid < 0) {
        // Error forking
        printf("Error forking!\n");
    } 
    else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int main(int argc, char **argv){
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);

    return EXIT_SUCCESS;
}