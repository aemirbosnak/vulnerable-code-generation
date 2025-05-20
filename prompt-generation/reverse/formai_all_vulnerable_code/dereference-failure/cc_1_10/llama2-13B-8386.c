//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

int main(void) {
    // Create a shared memory segment
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget() failed");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm = shmat(shmid, NULL, 0);
    if (shm == NULL) {
        perror("shmat() failed");
        return 1;
    }

    // Write some data to the shared memory
    char message[] = "Hello, world!";
    strcpy(shm, message);

    // Create a pipe for communication
    int pipefd[2];
    pipe(pipefd);

    // Fork a child process to read from the shared memory
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        close(pipefd[0]);
        read(shmid, shm, SHM_SIZE);
        write(pipefd[1], shm, strlen(shm));
    } else {
        // Parent process
        close(pipefd[1]);
        read(pipefd[0], shm, SHM_SIZE);
        write(1, shm, strlen(shm));
    }

    // Wait for the child process to finish
    wait(NULL);

    // Detach from the shared memory segment
    shmdt(shm);

    return 0;
}