//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 128

void sighandler(int signum) {
    printf("\nCaught signal %d. Exiting.\n", signum);
    exit(1);
}

int main(int argc, char** argv) {
    signal(SIGINT, sighandler);

    char input[MAX_LINE_LENGTH];
    char* args[MAX_ARGS];
    int num_args;
    pid_t pid;
    int status;

    while (1) {
        printf("my_shell> ");
        fgets(input, MAX_LINE_LENGTH, stdin);

        num_args = 0;
        char* token = strtok(input, " ");
        while (token != NULL) {
            args[num_args++] = token;
            token = strtok(NULL, " ");
        }
        args[num_args] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting my_shell.\n");
            exit(0);
        }

        pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        }

        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d.\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process terminated by signal %d.\n", WTERMSIG(status));
        }
    }

    return 0;
}