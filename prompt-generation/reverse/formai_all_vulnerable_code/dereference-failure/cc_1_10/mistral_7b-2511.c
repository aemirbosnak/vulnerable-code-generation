//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 12345
#define PIPE_SIZE 10

int main() {
    int fd[2], shmid;
    char msg[PIPE_SIZE];
    char *shm;

    if (pipe(fd) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if ((shmid = shmget(SHM_KEY, sizeof(int), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(fd[0]); // Close read end
        close(1); // Close standard output
        dup2(fd[1], 1); // Redirect standard output to write end of pipe

        *shm = 42; // Write data to shared memory
        shmdt(shm);

        close(fd[1]); // Close write end
        exit(EXIT_SUCCESS);
    } else { // Child process
        close(fd[1]); // Close write end
        close(0); // Close standard input
        dup2(fd[0], 0); // Redirect standard input to read end of pipe

        char received[PIPE_SIZE];
        read(0, received, PIPE_SIZE);
        printf("Received: %d\n", *((int *)received));

        close(fd[0]); // Close read end
        exit(EXIT_SUCCESS);
    }
}