//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length of a command line */
#define MAX_ARGS 12 /* The maximum number of arguments */

int main(void) {
    char *args[MAX_ARGS]; /* Array of command line arguments */
    char line[MAX_LINE]; /* Input buffer */
    int should_run = 1; /* Flag to indicate if the shell should continue running */

    while (should_run) {
        /* Print the prompt */
        printf("osh>");
        fflush(stdout);

        /* Get the command line from the user */
        fgets(line, MAX_LINE, stdin);

        /* Parse the command line into arguments */
        int num_args = parse_args(line, args);

        /* Execute the command */
        if (num_args > 0) {
            int pid = fork();

            if (pid == 0) {
                /* Child process */
                if (execvp(args[0], args) == -1) {
                    perror("execvp");
                }
                exit(EXIT_FAILURE);
            } else if (pid > 0) {
                /* Parent process */
                int status;
                waitpid(pid, &status, 0);
            } else {
                perror("fork");
            }
        }

        /* Check if the user entered the exit command */
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
        }
    }

    return EXIT_SUCCESS;
}

/* Parse the command line into arguments */
int parse_args(char *line, char **args) {
    int num_args = 0;

    char *token = strtok(line, " ");
    while (token != NULL) {
        args[num_args++] = token;
        token = strtok(NULL, " ");
    }

    return num_args;
}