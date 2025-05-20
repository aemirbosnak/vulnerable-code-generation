//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_ARGS 10
#define MAX_INPUT 50

// function to read command from user
int take_input(char *input)
{
    printf("my-shell> ");
    fgets(input, MAX_INPUT, stdin);
    if(strcmp(input, "exit\n") == 0) {
        return 0;
    }
    return 1;
}

// function to parse the input and return individual arguments
char **parse_input(char *input)
{
    char **args = (char **)malloc(sizeof(char*) * MAX_ARGS);
    char *arg;
    int index = 0;

    if(args == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // break the input string into individual tokens based on whitespace
    arg = strtok(input, " \n");

    while(arg != NULL && index < MAX_ARGS-1) {
        args[index++] = arg;
        arg = strtok(NULL, " \n");
    }

    args[index] = NULL;

    return args;
}

int main()
{
    char input[MAX_INPUT];
    int status;

    while(1) {
        if(take_input(input) == 0) {
            break;
        }

        // fork a child process to execute the command
        pid_t pid = fork();

        if(pid < 0) {
            perror("Failed to fork");
            exit(EXIT_FAILURE);
        } else if(pid == 0) {
            // child process
            char **args = parse_input(input);
            execvp(args[0], args);

            // in case exec fails
            perror("Command execution failed");
            exit(EXIT_FAILURE);
        } else {
            // parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}