//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

void executeCommand(char *tokens[MAX_NUM_TOKENS], int numTokens) {
    pid_t pid = fork();
    if (pid == -1) {
        printf("fork failed\n");
        return;
    } else if (pid == 0) {
        // child process

        // check for pipes
        int hasPipe = 0;
        int pipefd[2];
        int pipeIndex;
        for (int i = 0; i < numTokens; i++) {
            if (strcmp(tokens[i], "|") == 0) {
                hasPipe = 1;
                pipeIndex = i;
                tokens[i] = NULL;
                pipe(pipefd);
                break;
            }
        }

        if (hasPipe) {
            pid_t childPid = fork();
            if (childPid == -1) {
                printf("fork failed\n");
                exit(EXIT_FAILURE);
            } else if (childPid == 0) {
                // grandchild process (writes to pipe)
                close(pipefd[0]); // close read end of pipe
                dup2(pipefd[1], STDOUT_FILENO); // write to pipe instead of stdout
                close(pipefd[1]); // close unused write end of pipe
                execvp(tokens[0], tokens);
                printf("%s: command not found\n", tokens[0]);
                exit(EXIT_FAILURE);
            } else {
                // child process (reads from pipe)
                close(pipefd[1]); // close write end of pipe
                dup2(pipefd[0], STDIN_FILENO); // read from pipe instead of stdin
                close(pipefd[0]); // close unused read end of pipe
                execvp(tokens[pipeIndex+1], &tokens[pipeIndex+1]);
                printf("%s: command not found\n", tokens[pipeIndex+1]);
                exit(EXIT_FAILURE);
            }
        } else {
            // no pipes, execute command normally
            execvp(tokens[0], tokens);
            printf("%s: command not found\n", tokens[0]);
            exit(EXIT_FAILURE);
        }
    } else {
        // parent process
        wait(NULL); // wait for child process to complete
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        // print prompt and get input
        printf("prompt> ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // tokenize input
        char *tokens[MAX_NUM_TOKENS];
        char *token = strtok(input, " ");
        int numTokens = 0;
        while (token != NULL && numTokens < MAX_NUM_TOKENS) {
            tokens[numTokens++] = token;
            token = strtok(NULL, " ");
        }
        tokens[numTokens] = NULL;

        // check for exit command
        if (strcmp(tokens[0], "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // execute command
        executeCommand(tokens, numTokens);
    }

    return 0;
}