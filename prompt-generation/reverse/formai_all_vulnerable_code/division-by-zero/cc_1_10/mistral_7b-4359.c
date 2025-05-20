//MISTRAL-7B DATASET v1.0 Category: CPU usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

#define NUM_CHILDREN 5
#define PIPE_SIZE 1024

int main() {
    int parent_fd[2], child_fd[2 * NUM_CHILDREN];
    pid_t children[NUM_CHILDREN];
    int i;
    struct timeval start_tv, end_tv;
    long parent_cpu_usage = 0;

    for (i = 0; i < 2 * NUM_CHILDREN; i++) {
        if (pipe(child_fd + i) < 0) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_CHILDREN; i++) {
        if (pipe(parent_fd) < 0) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }

        children[i] = fork();

        if (children[i] < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (children[i] > 0) { // Parent process
            close(parent_fd[0]);
            close(child_fd[i]);

            gettimeofday(&start_tv, NULL);
            waitpid(children[i], NULL, 0);
            gettimeofday(&end_tv, NULL);

            parent_cpu_usage += (100 * 1000 / (end_tv.tv_sec - start_tv.tv_sec +
                                               (end_tv.tv_usec - start_tv.tv_usec) / 1000000)) * (100 / NUM_CHILDREN);

            close(parent_fd[1]);
        } else { // Child process
            close(parent_fd[1]);
            close(child_fd[i]);

            setsid(); // Detach from terminal and create a new session

            dup2(parent_fd[0], STDIN_FILENO);
            close(parent_fd[0]);

            execlp("/usr/bin/nice", "nice", "-n19", "ps", "-o", "%cpu,%mem,cmd", "--no-headers", getenv("PPID"), NULL);

            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_CHILDREN; i++) {
        waitpid(children[i], NULL, 0);
    }

    printf("Aggregated CPU usage: %d%%\n", parent_cpu_usage);

    return EXIT_SUCCESS;
}