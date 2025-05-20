//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024
#define MESSAGE_SIZE 512

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        return 1;
    }

    // Allocate a buffer within the shared memory
    char *message = (char *) shm + BUFFER_SIZE / 2;
    char *read_buffer = (char *) shm + BUFFER_SIZE / 2 + MESSAGE_SIZE;
    size_t message_size = MESSAGE_SIZE;

    // Create a pipe for communication
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork a child process
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process
        close(fd[0]);
        write(fd[1], "Hello, parent!", 13);
        wait(NULL);
    } else {
        // Parent process
        close(fd[1]);
        read(fd[0], read_buffer, message_size);
        printf("Received message: %s\n", read_buffer);
    }

    // Clean up
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}