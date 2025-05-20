//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 100

void handle_signal(int signal) {
    printf("\nSignal %d caught. Shell is terminated.\n", signal);
    exit(0);
}

void execute_command(char **args, int bg) {
    int fd[2], status;
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("Shell error: pipe creation failed.");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("Shell error: fork failed.");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        if (bg) {
            signal(SIGINT, SIG_IGN);
            signal(SIGTSTP, SIG_IGN);
        }
        else {
            signal(SIGINT, SIG_DFL);
            signal(SIGTSTP, SIG_DFL);
        }

        if (fd[1] != STDOUT_FILENO) {
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
        }

        if (fd[0] != STDIN_FILENO) {
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
        }

        if (execvp(args[0], args) == -1) {
            printf("Exec failed for %s\n", args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else {
        if (!bg) {
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    char *input;
    char *args[MAX_ARGS];
    int status, counter, n, bg;

    signal(SIGINT, handle_signal);
    signal(SIGTSTP, handle_signal);

    printf("Welcome to My Shell!\n");

    while (1) {
        printf("MyShell> ");
        fflush(stdout);

        input = (char *) malloc(1024*sizeof(char));

        if(fgets(input, 1024, stdin) == NULL) {
            printf("Shell error: input failed.");
        }

        if(input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        if(strcmp(input, "exit") == 0) {
            exit(0);
        }

        counter = 0;
        args[counter] = strtok(input, " ");

        while(args[counter] != NULL) {
            counter++;
            args[counter] = strtok(NULL, " ");
        }

        bg = 0;

        if(strcmp(args[counter-1], "&") == 0) {
            bg = 1;
            args[counter-1] = NULL;
            counter--;
        }

        execute_command(args, bg);

        free(input);
    }

    return 0;
}