//FormAI DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_ARGS 20

void handle_signal(int sig)
{
    printf("Signal received: %d\n", sig);
}

int main(void)
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_signal;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        fprintf(stderr, "Failed to set signal handler\n");
        exit(1);
    }

    char input[1024];
    char *args[MAX_ARGS];
    while(1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Split input into arguments
        char *token = strtok(input, " ");
        int i = 0;
        while(token != NULL && i < MAX_ARGS) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        // Check for built-in commands
        if(strcmp(args[0], "cd") == 0) {
            if(args[1] != NULL) {
                if(chdir(args[1]) == -1) {
                    perror("cd");
                }
            } else {
                chdir(getenv("HOME"));
            }
        } else if(strcmp(args[0], "exit") == 0) {
            exit(0);
        } else {
            // Fork a child process
            int pid = fork();
            if(pid == -1) {
                perror("fork");
                exit(1);
            }

            if(pid == 0) {
                // Child process
                if(execvp(args[0], args) == -1) {
                    perror(args[0]);
                    exit(1);
                }
            } else {
                // Parent process
                int status;
                wait(&status);
            }
        }
    }

    return 0;
}