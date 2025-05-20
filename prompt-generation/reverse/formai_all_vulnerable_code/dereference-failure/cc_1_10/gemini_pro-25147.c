//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 128
#define MAX_JOBS 16

typedef struct job {
    pid_t pid;
    char *name;
    int status;
} job;

job jobs[MAX_JOBS];
int num_jobs = 0;

void sigchld_handler(int sig) {
    pid_t pid;
    int status;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        for (int i = 0; i < num_jobs; i++) {
            if (jobs[i].pid == pid) {
                jobs[i].status = status;
                break;
            }
        }
    }
}

int main() {
    char *line = NULL;
    size_t line_length = 0;
    char *args[MAX_ARGS];
    int num_args = 0;
    int status;
    bool running = true;

    // Ignore SIGCHLD signals (which are sent when child processes terminate)
    signal(SIGCHLD, SIG_IGN);

    // Register the signal handler for SIGCHLD
    signal(SIGCHLD, sigchld_handler);

    while (running) {
        // Prompt the user for a command
        printf("shell$ ");
        fflush(stdout);

        // Get the line of input from the user
        if (getline(&line, &line_length, stdin) == -1) {
            perror("getline");
            exit(1);
        }

        // Parse the line of input into arguments
        num_args = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            args[num_args++] = token;
            token = strtok(NULL, " ");
        }

        // Check for special commands
        if (strcmp(args[0], "exit") == 0) {
            running = false;
        } else if (strcmp(args[0], "jobs") == 0) {
            // List all running jobs
            for (int i = 0; i < num_jobs; i++) {
                printf("%d %s\n", jobs[i].pid, jobs[i].name);
            }
        } else {
            // Fork a child process to execute the command
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(1);
            } else if (pid == 0) {
                // Child process
                execvp(args[0], args);
                perror("execvp");
                exit(1);
            } else {
                // Parent process
                job new_job;
                new_job.pid = pid;
                new_job.name = strdup(args[0]);
                new_job.status = 0;
                jobs[num_jobs++] = new_job;
            }
        }
    }

    // Wait for all child processes to terminate
    for (int i = 0; i < num_jobs; i++) {
        waitpid(jobs[i].pid, &status, 0);
    }

    // Free the memory allocated for the line of input
    free(line);

    // Free the memory allocated for the arguments
    for (int i = 0; i < num_args; i++) {
        free(args[i]);
    }

    return 0;
}