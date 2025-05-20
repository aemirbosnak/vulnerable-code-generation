//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <time.h>

#define PIPE_SIZE 1024

typedef struct {
    int read_end;
    int write_end;
    pid_t producer_pid;
    pid_t consumer_pid;
    int count;
} pipe_t;

int main() {
    int i;
    int random_number;
    int square;
    pipe_t *pipe_info;
    int fd[2];
    pid_t consumer_pid;

    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    pipe_info = malloc(sizeof(pipe_t));
    pipe_info->read_end = fd[0];
    pipe_info->write_end = fd[1];
    pipe_info->count = 0;

    consumer_pid = fork();

    if (consumer_pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (consumer_pid > 0) { // Parent process (Producer)
        close(fd[0]); // Close reading end of pipe in producer

        for (i = 0; i < 10; i++) {
            random_number = rand() % 10;
            write(fd[1], &random_number, sizeof(int));
            printf("Producer generated number: %d\n", random_number);
            fflush(stdout);
            sleep(1);
        }

        close(fd[1]); // Close writing end of pipe in producer

        wait(NULL); // Wait for child process (Consumer) to finish
        free(pipe_info);
    } else { // Child process (Consumer)
        close(fd[1]); // Close writing end of pipe in consumer

        while (read(fd[0], &random_number, sizeof(int)) > 0) {
            square = random_number * random_number;
            printf("Consumer received number: %d, square: %d\n", random_number, square);
            fflush(stdout);
            pipe_info->count++;
        }

        close(fd[0]); // Close reading end of pipe in consumer

        printf("Consumer finished, sent %d numbers\n", pipe_info->count);
        free(pipe_info);
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}