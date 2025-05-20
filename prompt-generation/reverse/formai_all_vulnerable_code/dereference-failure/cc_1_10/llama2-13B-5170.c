//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024 * 1024 * 10

typedef struct shm_block {
    char data[SHM_SIZE];
    int ref_count;
} shm_block_t;

int main(int argc, char *argv[]) {
    // Create a shared memory segment
    key_t key = SHM_KEY;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Fork child processes
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process
        printf("Child process %d running\n", getpid());

        // Attach to shared memory segment
        shm_block_t *block = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
        if (block == MAP_FAILED) {
            perror("mmap");
            exit(EXIT_FAILURE);
        }

        // Modify shared memory
        block->data[0] = 'C';
        block->ref_count++;

        // Signal parent process
        kill(getppid(), SIGUSR1);

        // Wait for parent process to finish
        wait(NULL);
    } else {
        // Parent process
        printf("Parent process %d running\n", getpid());

        // Attach to shared memory segment
        shm_block_t *block = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
        if (block == MAP_FAILED) {
            perror("mmap");
            exit(EXIT_FAILURE);
        }

        // Check if child process has modified shared memory
        if (block->data[0] == 'C') {
            printf("Child process has modified shared memory\n");
        }

        // Wait for child process to finish
        wait(NULL);
    }

    // Destroy shared memory segment
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}