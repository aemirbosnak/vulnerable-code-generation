//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_ARGUMENTS 10
#define MAX_COMMANDS 5

typedef struct {
    char *args[MAX_ARGUMENTS];
    int numArgs;
} command_t;

typedef struct {
    command_t commands[MAX_COMMANDS];
    int numCommands;
} job_t;

void parseInput(char *input, job_t *job) {
    char *token, *lineCopy;
    lineCopy = input;
    job->numCommands = 0;
    token = strtok(lineCopy, "|");
    while (token != NULL) {
        command_t command;
        command.numArgs = 0;
        char *argToken = strtok(token, " ");
        while (argToken != NULL) {
            command.args[command.numArgs++] = argToken;
            argToken = strtok(NULL, " ");
        }
        job->commands[job->numCommands++] = command;
        token = strtok(NULL, "|");
    }
}

void executeJob(job_t *job) {
    int numPipes = job->numCommands - 1;
    int pipefds[2*numPipes];
    for (int i = 0; i < numPipes; i++) {
        if (pipe(pipefds + i*2) < 0) {
            perror("pipe error");
            exit(1);
        }
    }
    int status, pid, i = 0;
    signal(SIGCHLD, SIG_IGN);
    bool isLastCommand = false;
    while (i < job->numCommands) {
        isLastCommand = (i == job->numCommands - 1);
        pid = fork();
        if (pid == 0) {
            if (i != 0) {
                if (dup2(pipefds[(i-1)*2], 0) < 0) {
                    perror("dup2 error for read end of pipe");
                    exit(1);
                }
            }

            if (!isLastCommand) {
                if (dup2(pipefds[i*2 + 1], 1) < 0) {
                    perror("dup2 error for write end of pipe");
                    exit(1);
                }
            }
            for (int j = 0; j < 2*numPipes; j++) {
                close(pipefds[j]);
            }
            execvp(job->commands[i].args[0], job->commands[i].args);
            exit(1);
        } else if (pid < 0) {
            perror("fork error");
            exit(1);
        }
        i++;
    }
    for (int j = 0; j < 2*numPipes; j++) {
        close(pipefds[j]);
    }

    for (int j = 0; j < job->numCommands; j++) {
        wait(&status);
    }
}

int main() {
    while (1) {
        printf("$ ");
        char buffer[1024];
        fgets(buffer, 1024, stdin);
        job_t job;
        parseInput(buffer, &job);
        executeJob(&job);
    }
    return 0;
}