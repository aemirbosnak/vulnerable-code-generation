//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <fcntl.h>

#define MESSAGE_SIZE 1024
#define SHM_NAME "my_shared_mem"

void* create_shm(size_t size) {
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

int main() {
    // Create shared memory
    void* shm = create_shm(MESSAGE_SIZE);
    if (shm == MAP_FAILED) {
        perror("create_shm");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char message[] = "Hello, world!";
        size_t written = write(shm, message, strlen(message));
        if (written != strlen(message)) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        char* message = NULL;
        size_t message_len = 0;
        read(shm, &message, &message_len);
        printf("Received message: %s\n", message);
        exit(EXIT_SUCCESS);
    }
    return 0;
}