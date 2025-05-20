//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* Maximum length of the command */

int main(void)
{
    char *args[MAX_LINE/2 + 1]; /* Command line arguments */
    int should_run = 1; /* Flag to determine when to exit program */
    pid_t pid;

    while (should_run)
    {
        printf("sherlock@impeccable$ "); /* Print prompt */

        fflush(stdout); /* Clear output stream.*/

        char input[MAX_LINE]; /* Buffer for the user input */

        fgets(input, MAX_LINE, stdin); /* Get user input */

        /* Tokenize the input into arguments */
        char *token = strtok(input, " \n");
        int i = 0;

        while (token != NULL)
        {
            args[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }

        args[i] = NULL; /* Set last argument to null */

        /* Check for built-in commands */
        if (strcmp(args[0], "exit") == 0)
            should_run = 0;

        /* Fork a child process to execute the command */
        pid = fork();

        if (pid < 0) /* Error occured in forking */
        {
            fprintf(stderr, "Fork Failed");
            return 1;
        }

        else if (pid == 0) /* Child process */
        {
            if (execvp(args[0], args) < 0)
            {
                printf("Could not execute command.\n");
                exit(1);
            }
        }

        else /* Parent process */
        {
            wait(NULL); /* Wait for child to complete */
        }
    }

    return 0;
}