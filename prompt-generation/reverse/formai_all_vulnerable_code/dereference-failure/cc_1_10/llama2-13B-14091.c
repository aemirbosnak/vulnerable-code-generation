//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_NAME "my_shared_memory"
#define SHM_SIZE 1024

void* shm_alloc(size_t size) {
    int shmid = shmget(IPC_PRIVATE, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    void* shm = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return shm;
}

void shm_free(void* shm) {
    munmap(shm, strlen(SHM_NAME));
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pid1> <pid2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create shared memory
    void* shm1 = shm_alloc(SHM_SIZE);
    void* shm2 = shm_alloc(SHM_SIZE);

    // Write data to shared memory
    char* data1 = "Hello from PID 1!";
    char* data2 = "Hello from PID 2!";
    memcpy(shm1, data1, strlen(data1));
    memcpy(shm2, data2, strlen(data2));

    // Create a pipe for communication
    int fd[2];
    pipe(fd);

    // Fork two processes
    pid_t pid1 = fork();
    if (pid1 == 0) {
        // Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execvp(argv[1], argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        close(fd[1]);
        dup2(fd[0], STDOUT_FILENO);
        execvp(argv[2], argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    // Communicate through shared memory
    char message[SHM_SIZE];
    read(fd[0], message, SHM_SIZE);
    printf("Received message from PID %d: %s\n", getpid(), message);

    // Send a message back
    char* message2 = "Hello from PID 1 back!";
    write(fd[1], message2, strlen(message2));

    // Wait for the other process to finish
    wait(NULL);

    // Clean up
    shm_free(shm1);
    shm_free(shm2);

    return 0;
}