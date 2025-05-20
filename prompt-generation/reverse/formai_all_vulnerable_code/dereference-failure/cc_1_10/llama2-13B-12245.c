//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

void* shm_alloc(size_t size) {
    int shmid = shmget(SHM_KEY, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget() failed");
        return NULL;
    }
    return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
}

void shm_free(void* shm) {
    munmap(shm, SHM_SIZE);
    shmctl(SHM_KEY, IPC_RMID, NULL);
}

int main() {
    // Create a shared memory segment
    void* shm = shm_alloc(SHM_SIZE);
    if (!shm) {
        perror("shm_alloc() failed");
        return 1;
    }

    // Write some data to the shared memory
    char* data = "Hello, world!";
    strcpy(shm, data);

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        shm_free(shm);
        return 1;
    }
    if (pid == 0) {
        // Child process
        char* name = "Child";
        char* message = "Hello, parent!";
        write(1, message, strlen(message));
        // Communicate with the parent process using shared memory
        char* shm_data = shm;
        printf("Received message from parent: %s\n", shm_data);
        exit(0);
    } else {
        // Parent process
        char* message = "Hello, child!";
        write(1, message, strlen(message));
        // Communicate with the child process using shared memory
        char* shm_data = shm;
        printf("Received message from child: %s\n", shm_data);
    }

    shm_free(shm);
    return 0;
}