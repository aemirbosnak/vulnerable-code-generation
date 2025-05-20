//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10

// Function to split the input string into arguments
char** split_args(char* input) {
    char** args = malloc(sizeof(char*) * MAX_ARGS);
    int i = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

// Function to execute the given command
int execute_command(char** args) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "Error: Could not execute command %s\n", args[0]);
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
    }
    return 0;
}

// Function to get the current working directory
char* get_cwd() {
    char* cwd = malloc(sizeof(char) * 1024);
    getcwd(cwd, 1024);
    return cwd;
}

// Function to change the current working directory
int change_dir(char* path) {
    if (chdir(path) != 0) {
        fprintf(stderr, "Error: Could not change directory to %s\n", path);
        return -1;
    }
    return 0;
}

// Function to print the prompt
void print_prompt() {
    char* cwd = get_cwd();
    printf("%s > ", cwd);
    free(cwd);
}

// Main function
int main() {
    while (1) {
        print_prompt();
        char* input = malloc(sizeof(char) * 1024);
        fgets(input, 1024, stdin);
        input[strlen(input) - 1] = '\0'; // Remove the newline character
        if (strcmp(input, "exit") == 0) { // Handle the exit command
            break;
        } else if (strcmp(input, "cd") == 0) { // Handle the cd command
            char** args = split_args(input);
            if (args[1] == NULL) {
                fprintf(stderr, "Error: No directory specified for cd\n");
            } else {
                change_dir(args[1]);
            }
            free(args);
        } else { // Handle any other command
            char** args = split_args(input);
            execute_command(args);
            free(args);
        }
        free(input);
    }
    return 0;
}