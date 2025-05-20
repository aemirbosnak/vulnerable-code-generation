//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

// Struct for shared memory
struct shm {
    int count;
    char buffer[SIZE];
};

int main() {
    int shmid;
    key_t key;
    struct shm *shm;

    // Generate a unique key
    key = ftok("shm_example.c", 'a');

    // Create shared memory segment
    shmid = shmget(key, sizeof(struct shm), IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Failed to create shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shm = shmat(shmid, NULL, 0);

    if (shm == (void*) -1) {
        printf("Failed to attach to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    shm->count = 0;
    for (int i = 0; i < SIZE; i++) {
        shm->buffer[i] = '\0';
    }

    int pid = fork();

    if (pid == 0) {
        // Child process
        sleep(2);

        shm->count++;
        sprintf(shm->buffer, "Child process wrote this message\n");

        exit(0);
    } else {
        // Parent process
        wait(NULL);

        printf("Shared memory count: %d\n", shm->count);
        printf("Shared memory buffer: %s", shm->buffer);

        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}