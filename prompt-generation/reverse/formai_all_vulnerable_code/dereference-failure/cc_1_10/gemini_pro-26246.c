//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define the shared memory key
#define SHM_KEY 1234

// Define the size of the shared memory segment
#define SHM_SIZE 1024

// Define the structure of the shared memory segment
typedef struct {
    char message[SHM_SIZE];
} shared_memory_segment;

int main(int argc, char *argv[]) {
    // Create the shared memory segment
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the current process
    shared_memory_segment *shm = shmat(shm_id, NULL, 0);
    if (shm == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    printf("Shared memory segment attached at address %p\n", shm);

    // Write a message to the shared memory segment
    strcpy(shm->message, "The game is afoot!");

    // Detach the shared memory segment from the current process
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Destroy the shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}