//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void) {
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    char command[MAX_LINE]; /* command from the user */
    int should_run = 1; /* flag to determine when to exit program */
    int i, background; /* for loop variable and background process flag */

    while (should_run) {
        printf("linus_shell$ ");
        fgets(command, MAX_LINE, stdin); /* read command from user */

        /* parse command line */
        i = 0;
        args[i] = strtok(command, " \n");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " \n");
        }

        /* check for background process */
        background = 0;
        if (i > 1 && strcmp(args[i-1], "&") == 0) {
            background = 1;
            args[i-1] = NULL;
        }

        /* execute command */
        pid_t pid = fork();
        if (pid == 0) { /* child process */
            execvp(args[0], args);
            fprintf(stderr, "Error: command not found\n");
            exit(EXIT_FAILURE);
        } else if (pid < 0) { /* error occurred */
            fprintf(stderr, "Error: fork failed\n");
            exit(EXIT_FAILURE);
        } else { /* parent process */
            if (!background) { /* wait for child process to finish */
                waitpid(pid, NULL, 0);
            }
        }

        /* check for exit command */
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
        }

        /* clear command and arguments */
        memset(command, 0, MAX_LINE);
        memset(args, 0, sizeof(args));
    }

    return 0;
}