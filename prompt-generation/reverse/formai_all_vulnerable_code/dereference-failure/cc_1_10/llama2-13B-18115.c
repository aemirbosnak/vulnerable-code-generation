//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/types.h>

#define MSG_SIZE 1024
#define SHM_SIZE 4096

int main() {
    key_t key;
    int shmid;
    char *shm;
    char *msg;

    // Create a shared memory segment
    key = IPC_PRIVATE;
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Create a message buffer
    msg = calloc(1, MSG_SIZE);
    if (msg == NULL) {
        perror("calloc");
        exit(EXIT_FAILURE);
    }

    // Set up the message to be sent
    sprintf(msg, "Hello, world!");

    // Create a pipe for interprocess communication
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Set up the message to be received
    char receive_buffer[MSG_SIZE];

    // Fork a child process to receive the message
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process
        close(pipefd[0]);
        read(pipefd[1], receive_buffer, MSG_SIZE);
        printf("Received message: %s\n", receive_buffer);
    } else {
        // Parent process
        close(pipefd[1]);

        // Send the message to the child process
        write(pipefd[0], msg, strlen(msg));
    }

    // Unmap the shared memory segment
    munmap(shm, SHM_SIZE);

    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}