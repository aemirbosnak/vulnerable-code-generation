//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

// Struct for shared memory
typedef struct {
    char message[SHM_SIZE];
} shared_memory_t;

int main() {
    int shmid;
    void *shmaddr;
    shared_memory_t *shared_memory;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error attaching shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory
    shared_memory = (shared_memory_t *) shmaddr;
    strcpy(shared_memory->message, "Hello, world!");

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking process.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process

        // Wait for parent to update shared memory
        sleep(1);

        // Print message from shared memory
        printf("Message from parent: %s\n", shared_memory->message);

        // Detach shared memory segment
        if (shmdt(shmaddr) == -1) {
            printf("Error detaching shared memory segment.\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process

        // Update shared memory
        sleep(2);
        strcpy(shared_memory->message, "Goodbye, world!");

        // Detach shared memory segment
        if (shmdt(shmaddr) == -1) {
            printf("Error detaching shared memory segment.\n");
            exit(1);
        }

        // Wait for child to exit
        wait(NULL);

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment.\n");
            exit(1);
        }

        // Exit parent process
        exit(0);
    }

    return 0;
}