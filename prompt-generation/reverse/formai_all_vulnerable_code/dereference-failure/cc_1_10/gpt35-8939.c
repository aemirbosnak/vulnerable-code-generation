//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void print_prompt(char* path) {
    printf("\n%s > ", path);
}

char* read_input() {
    char* input = (char*) malloc(MAX_INPUT * sizeof(char));
    fgets(input, MAX_INPUT, stdin);

    return input;
}

char** parse_input(char* input) {
    char** args = (char**) malloc(MAX_ARGS * sizeof(char*));
    char* arg = strtok(input, " ");
    int i = 0;
    while (arg != NULL) {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    args[i-1][strlen(args[i-1])-1] = '\0'; // remove newline character

    args = (char**) realloc(args, i * sizeof(char*));
    args[i] = NULL; // set last array element to NULL

    return args;
}

int execute_command(char** args) {
    pid_t pid = fork();

    if (pid == -1) {
        printf("Error: Could not create child process\n");
        return -1;
    }
    else if (pid == 0) { // child process
        if (execvp(args[0], args) == -1) {
            printf("Error: Could not execute command %s\n", args[0]);
            return -1;
        }
    }
    else { // parent process
        wait(NULL);
    }
    return 0;
}

int main() {
    char* path = get_current_dir_name();

    printf("Welcome to the custom terminal\n");
    printf("--------------------------------\n");
    printf("Type 'exit' or press ctrl+c to exit\n");

    while(1) {
        print_prompt(path);
        char* input = read_input();
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        char** args = parse_input(input);
        if (execute_command(args) == -1) {
            break;
        }
    }

    return 0;
}