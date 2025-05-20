//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>

#define MAX_MEM 1024
#define MAX_SHM 64

typedef struct {
    char *name;
    char *data;
    size_t size;
} shmid_t;

void *shm_create(size_t size) {
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return addr;
}

void shm_destroy(void *addr) {
    munmap(addr, strlen(addr));
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <name> <size>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, atoi(argv[2]), IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Create a mapping of the shared memory segment
    void *addr = mmap(NULL, atoi(argv[2]), PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Set the name of the shared memory segment
    char *name = strdup(argv[1]);
    shmid_t *shm = (shmid_t *)addr;
    shm->name = name;
    shm->data = addr;
    shm->size = atoi(argv[2]);

    // Fork a child process to access the shared memory segment
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char *message = "Hello from child process!";
        size_t message_len = strlen(message);
        void *message_addr = addr + shm->size - message_len;
        memcpy(message_addr, message, message_len);
        printf("Child process wrote %s to shared memory\n", message);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent process read %s from shared memory\n", shm->data);
        shm_destroy(addr);
        exit(EXIT_SUCCESS);
    }

    return 0;
}