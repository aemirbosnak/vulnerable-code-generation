//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_ARGS 10

int main(void) {

    char line[MAX_LINE];
    char *args[MAX_ARGS];
    int status;
    bool should_run = true;

    while (should_run) {
        printf(">>> ");
        fflush(stdout);

        // read user input
        fgets(line, MAX_LINE, stdin);

        // parse input into arguments
        int i = 0;
        args[i] = strtok(line, " \n");
        while (args[i] != NULL && i < (MAX_ARGS - 1)) {
            args[++i] = strtok(NULL, " \n");
        }
        args[i] = NULL;

        // exit if user types "exit"
        if (strcmp(args[0], "exit") == 0) {
            should_run = false;
            continue;
        }

        // fork child process
        pid_t pid = fork();

        if (pid < 0) { // fork failed
            printf("Fork failed.\n");
            return 1;
        } else if (pid == 0) { // child process
            if (execvp(args[0], args) < 0) {
                printf("Unable to execute command.\n");
                return 1;
            }
        } else { // parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}