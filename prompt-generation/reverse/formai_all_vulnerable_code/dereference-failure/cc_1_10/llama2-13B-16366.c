//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget() failed");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat() failed");
        return 1;
    }

    // Create a pipe for communication
    int fd[2];
    pipe(fd);

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }
    if (pid > 0) {
        // Parent process
        close(fd[0]);
        write(fd[1], "Hello, world!", 13);
        wait(NULL);
        return 0;
    }

    // Child process
    close(fd[1]);
    read(fd[0], shm, BUFFER_SIZE);
    printf("Received message: %s\n", shm);
    return 0;
}