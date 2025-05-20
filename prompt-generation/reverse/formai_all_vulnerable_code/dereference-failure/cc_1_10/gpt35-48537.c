//FormAI DATASET v1.0 Category: System boot optimizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE 80 /* The maximum length of a command line */
#define MAX_ARGS 10 /* The maximum number of arguments in a command */

int main(void) {
    char *args[MAX_ARGS]; /* Array of pointers holding arguments */
    char buf[MAX_LINE]; /* Input buffer for commands */
    pid_t pid; /* Process ID of child process */
    int status; /* Exit status of child process */
    printf("C System Boot Optimizer:\n\n");

    while (1) {
        printf("optimizer:> ");
        fflush(stdout); /* Flush output buffer */
        fgets(buf, MAX_LINE, stdin); /* Read command line */
        buf[strlen(buf)-1] = '\0'; /* Remove newline character */
        
        /* Split command line into arguments, using whitespace as delimiter */
        char *token = strtok(buf, " ");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; /* Set last argument to NULL */
        
        if (strcmp(args[0], "exit") == 0) { /* Exit command */
            printf("Exiting optimizer...\n");
            exit(0);
        } else if (strcmp(args[0], "optimize") == 0) { /* Optimize command */
            pid = fork(); /* Create child process */
            if (pid == 0) { /* Child process */
                /* Execute optimization program */
                execvp("./optimize_program", args);
                printf("Error: Optimization program failed to execute.\n");
                exit(1);
            } else if (pid < 0) { /* Fork failed */
                printf("Error: Fork failed.\n");
                exit(1);
            } else { /* Parent process */
                /* Wait for child process to finish */
                waitpid(pid, &status, 0);
            }
        } else { /* Invalid command */
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}