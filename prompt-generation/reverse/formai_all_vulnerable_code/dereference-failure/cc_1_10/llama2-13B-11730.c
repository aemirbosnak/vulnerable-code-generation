//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SHM_SIZE 4096
#define SHM_NAME "my_shm"

void* shm_create(void) {
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0600);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    void* shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    return shm;
}

void shm_write(void* shm, const char* message) {
    size_t len = strlen(message);
    memcpy(shm, message, len);
}

void shm_read(void* shm, char* message) {
    size_t len = strlen(shm);
    memcpy(message, shm, len);
}

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        void* shm = shm_create();
        shm_write(shm, "Hello from child process!");
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        void* shm = shmget(SHM_NAME, SHM_SIZE, IPC_PRIVATE);
        if (shm == NULL) {
            perror("shmget");
            exit(EXIT_FAILURE);
        }

        char message[4096];
        shm_read(shm, message);
        printf("Received message from child process: %s\n", message);

        wait(NULL);
    }

    return 0;
}