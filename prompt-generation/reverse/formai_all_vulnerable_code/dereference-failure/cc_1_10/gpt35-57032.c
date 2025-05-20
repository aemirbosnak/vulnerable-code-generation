//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <unistd.h>     // for execvp() and fork()
#include <sys/types.h>  // for pid_t
#include <sys/wait.h>   // for wait()
#include <stdlib.h>     // for exit()

#define MAX_LINE 80     // maximum length of command line

int main(void) {
    char *args[MAX_LINE/2 + 1];  // arguments to be passed to execvp()
    int should_run = 1;          // flag to determine when to exit the program
    pid_t pid;                   // process id

    while (should_run) {
        printf("shell> ");
        fflush(stdout);

        // read user input
        char input[MAX_LINE];
        fgets(input, MAX_LINE, stdin);

        // parse arguments
        int arg_count = 0;      // count of arguments
        char *token = strtok(input, " \n");
        while (token != NULL) {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " \n");
        }
        args[arg_count] = NULL;  // set last element of array to NULL

        // check for exit command
        if (strcmp(args[0], "exit") == 0) {
            should_run = 0;
            break;
        }

        // fork a child process
        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "fork failed\n");
            return 1;
        }
        else if (pid == 0) {
            // child process
            execvp(args[0], args);
            exit(0);
        }
        else {
            // parent process
            wait(NULL);
        }
    }

    return 0;
}