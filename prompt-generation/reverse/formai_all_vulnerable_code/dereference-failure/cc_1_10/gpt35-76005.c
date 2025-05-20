//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
/* The Unix-like Shell */
/* By Donald Knuth */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void run_command(char **args);

int main(int argc, char **argv) {
    char *line;
    char **args;
    size_t len = 0;
    ssize_t read;
    int running = 1;

    while (running) {
        printf("shell> ");
        if ((read = getline(&line, &len, stdin)) == -1) {
            break;
        }
        args = malloc(sizeof(char*) * read);
        if (args == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        char *token;
        int count = 0;
        token = strtok(line, " \n");
        while (token != NULL) {
            args[count++] = token;
            token = strtok(NULL, " \n");
        }
        args[count] = NULL;

        run_command(args);

        free(args);
    }

    return 0;
}

void run_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        /* child process */
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* error */
        perror("fork");
    } else {
        /* parent process */
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}