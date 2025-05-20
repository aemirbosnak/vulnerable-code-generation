//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

/* Function to read input from the command line */
char* read_input() {
    char* input = malloc(sizeof(char) * MAX_LINE);
    if (input == NULL) {
        printf("Error: unable to allocate memory\n");
        exit(1);
    }
    printf("osh> ");
    fgets(input, MAX_LINE, stdin);
    return input;
}

/* Function to parse the input command into separate arguments */
char** parse_input(char* input) {
    char** args = malloc(sizeof(char*) * MAX_LINE/2 + 1);
    if (args == NULL) {
        printf("Error: unable to allocate memory\n");
        exit(1);
    }
    char* token = strtok(input, " \n");
    int i = 0;
    while (token != NULL) {
        args[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }
    args[i] = NULL;
    return args;
}

/* Main shell program */
int main(void)
{
    char* input;
    char** args;
    int should_run = 1; /* flag to determine when to exit program */
    pid_t pid;
    int status;

    while (should_run) {
        input = read_input(); /* read user command line input */
        args = parse_input(input); /* parse input into separate arguments */

        /* check if user entered exit command */
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            break;
        }

        pid = fork(); /* create child process to execute command */
        if (pid < 0) { /* error occurred */
            printf("Fork failed\n");
            exit(1);
        } else if (pid == 0) { /* child process */
            if (execvp(args[0], args) < 0) { /* if execvp returns -1 */
                printf("Command not found\n");
                exit(1);
            }
        } else { /* parent process */
            waitpid(pid, &status, 0); /* wait for child process to finish */
        }

        /* free allocated memory */
        free(input);
        free(args);
    }

    return 0;
}