//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_NAME "random_message"

void *shm_alloc(size_t size) {
    int shmid = shmget(IPC_PRIVATE, size, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    void *ptr = shmat(shmid, NULL, 0);
    if (ptr == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void shm_free(void *ptr) {
    shmctl(IPC_PRIVATE, IPC_RMID, NULL);
}

int main() {
    // Create a shared memory segment
    void *shm = shm_alloc(1024);
    if (!shm) {
        perror("shm_alloc");
        exit(EXIT_FAILURE);
    }

    // Write some random data to the shared memory
    srand(time(NULL));
    char *message = "Random message from process ";
    int i;
    for (i = 0; i < 1024; i++) {
        message[i] = 'A' + rand() % 26;
    }
    strcpy(shm, message);

    // Fork a new process to read the shared memory
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // In the new process, read the shared memory
        char *shm_ptr = shm;
        printf("Received message: %s\n", shm_ptr);
        exit(EXIT_SUCCESS);
    } else {
        // In the parent process, wait for the new process to finish
        wait(NULL);
    }

    // Clean up the shared memory
    shm_free(shm);

    return EXIT_SUCCESS;
}