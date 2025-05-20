//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void) {
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    char input[MAX_LINE]; /* user input */
    int should_run = 1; /* flag to determine when to exit program */
    int status, i, j, cnt; /* status code, loop variables, and word count */

    while (should_run) {
        printf("osh> "); /* print shell prompt */
        fflush(stdout);
        fgets(input, MAX_LINE, stdin); /* read user input */
        cnt = 0; /* initialize word count */
        j = 0; /* initialize character position */
        for (i = 0; i < strlen(input); i++) {
            if (input[i] == ' ' || input[i] == '\n') { /* found end of word */
                args[cnt] = (char*)malloc(j+1); /* allocate memory for word */
                strncpy(args[cnt], input+i-j, j); /* copy word to args */
                args[cnt][j] = '\0'; /* ensure null-termination */
                cnt++; /* increment word count */
                j = 0; /* reset character position */
            } else {
                j++; /* increment character position */
            }
        }
        args[cnt] = NULL; /* set last argument to null */
        if (strcmp(args[0], "exit") == 0) { /* shell exit command */
            should_run = 0;
            continue;
        }
        pid_t pid = fork(); /* create child process */
        if (pid == 0) { /* child process */
            execvp(args[0], args); /* execute command */
            perror("execvp"); /* print error message if command fails */
            exit(EXIT_FAILURE);
        } else if (pid > 0) { /* parent process */
            waitpid(pid, &status, 0); /* wait for child to complete */
        } else { /* fork failed */
            perror("fork");
        }
        for (i = 0; i < cnt; i++) { /* free memory */
            free(args[i]);
        }
    }
    return 0;
}