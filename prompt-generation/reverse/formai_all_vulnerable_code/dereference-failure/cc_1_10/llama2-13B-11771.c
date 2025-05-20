//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_NAME "brave_comm"
#define MSG_LEN 1024

int main(void) {
    // Create a shared memory segment
    int shmid = shmget(SHM_NAME, MSG_LEN, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm = mmap(NULL, MSG_LEN, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write a message to the shared memory
    char *message = "Hello, brave world!";
    memcpy(shm, message, strlen(message));

    // Create a pipe for communication
    int fd[2];
    pipe(fd);

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    // In the child process, read from the shared memory and write to the pipe
    if (pid == 0) {
        char *msg = shm;
        write(fd[1], msg, strlen(msg));
    }

    // In the parent process, read from the pipe and write to the shared memory
    else {
        read(fd[0], shm, MSG_LEN);
        memcpy(message, shm, strlen(shm));
        printf("Received message: %s\n", message);
    }

    // Close the pipe and shared memory segment
    close(fd[0]);
    close(fd[1]);
    munmap(shm, MSG_LEN);
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}