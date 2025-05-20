//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define MAX_LENGTH 100
#define SHM_KEY 0x12345678
#define SEM_KEY 0x87654321
#define SEM_ID 0
#define SHM_ID 1

int main() {
    int shm_id;
    int sem_id;
    char *shm_ptr;
    int sem_value = 0;

    // Create shared memory segment
    shm_id = shmget(SHM_KEY, MAX_LENGTH, IPC_CREAT | 0666);
    if (shm_id == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment
    shm_ptr = (char *)shmat(shm_id, NULL, 0);
    if (shm_ptr == (char *)-1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize semaphore
    sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    semctl(sem_id, SEM_ID, SETVAL, sem_value);

    // Shared memory communication
    strcpy(shm_ptr, "Hello, world!");
    printf("Shared memory value: %s\n", shm_ptr);

    // Semaphore communication
    sem_wait(sem_id);
    printf("Semaphore value: %d\n", sem_value);
    sem_post(sem_id);

    return 0;
}