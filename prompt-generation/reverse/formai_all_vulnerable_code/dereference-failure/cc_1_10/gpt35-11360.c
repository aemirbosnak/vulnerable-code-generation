//FormAI DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// Define the maximum number of child processes to spawn
#define MAX_CHILDREN 10

// Define the SIGCHLD handler to handle child process exits
void sigchld_handler(int sig) {
    int status;
    pid_t pid;

    // Wait for all child processes to exit
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        printf("Child process %d has exited with status %d\n", pid, status);
    }
}

// Define the main function for the program
int main(int argc, char *argv[]) {
    pid_t pid[MAX_CHILDREN];
    int num_children;
    int i;

    // Set the SIGCHLD handler to handle child process exits
    signal(SIGCHLD, sigchld_handler);

    // Parse the command line arguments to determine the number of child processes to spawn
    num_children = atoi(argv[1]);

    // Spawn the child processes
    for (i = 0; i < num_children; i++) {
        pid[i] = fork();

        if (pid[i] == 0) {
            // Child process code
            printf("Child process %d is running\n", getpid());
            sleep(10);
            printf("Child process %d is exiting\n", getpid());
            exit(0);
        } else if (pid[i] < 0) {
            // Error occurred while forking
            printf("Error occurred while forking child process %d\n", i);
            exit(1);
        }
    }

    // Parent process code
    printf("Parent process is waiting for child processes to exit\n");

    // Wait for all child processes to exit
    while (1) {
        pause();
    }

    return 0;
}