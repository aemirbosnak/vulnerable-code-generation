//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <time.h>

#define SHM_KEY 1234
#define SEM_KEY 5678
#define MAX_BUFFER 10

// Semaphore operations
void sem_wait(int semid) {
    struct sembuf sb = {0, -1, 0};
    semop(semid, &sb, 1);
}

void sem_signal(int semid) {
    struct sembuf sb = {0, 1, 0};
    semop(semid, &sb, 1);
}

// Shared memory structure
struct shm_area {
    int buffer[MAX_BUFFER];
    int count;
};

int main() {
    int shm_id = shmget(SHM_KEY, sizeof(struct shm_area), IPC_CREAT | 0666);
    int sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);

    // Initialize semaphore
    semctl(sem_id, 0, SETVAL, 1);

    struct shm_area *shm_ptr = (struct shm_area *)shmat(shm_id, NULL, 0);
    shm_ptr->count = 0;

    // Fork two processes: producer and consumer
    pid_t pid = fork();
    if (pid > 0) {
        // Producer process
        srand(time(NULL));
        for (int i = 0; i < 20; i++) {
            sleep(rand() % 2);  // simulate varying production time

            sem_wait(sem_id);
            if (shm_ptr->count < MAX_BUFFER) {
                int num = rand() % 100;
                shm_ptr->buffer[shm_ptr->count++] = num;
                printf("Produced: %d (Count: %d)\n", num, shm_ptr->count);
            } else {
                printf("Buffer full, producer is waiting...\n");
            }
            sem_signal(sem_id);
        }
        shmdt(shm_ptr);
    } else if (pid == 0) {
        // Consumer process
        for (int i = 0; i < 20; i++) {
            sleep(rand() % 3);  // simulate varying consumption time

            sem_wait(sem_id);
            if (shm_ptr->count > 0) {
                int num = shm_ptr->buffer[--shm_ptr->count];
                printf("Consumed: %d (Count: %d)\n", num, shm_ptr->count);
            } else {
                printf("Buffer empty, consumer is waiting...\n");
            }
            sem_signal(sem_id);
        }
        shmdt(shm_ptr);
        exit(0);
    } else {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    // Wait for both processes to finish
    wait(NULL); // Wait for child process

    // Cleanup
    shmctl(shm_id, IPC_RMID, NULL);
    semctl(sem_id, 0, IPC_RMID, 0);
    printf("Cleanup done, exiting program.\n");

    return 0;
}