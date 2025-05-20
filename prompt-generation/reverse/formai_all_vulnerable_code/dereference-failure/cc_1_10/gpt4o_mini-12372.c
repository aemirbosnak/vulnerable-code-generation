//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <signal.h>

#define SIZE 128
#define MAX_ITEMS 10

// Semaphore operation
void sem_wait(int semid) {
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
}

void sem_signal(int semid) {
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = 1;
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
}

// Shared memory structure
typedef struct {
    int count;               // Count of produced items
    char data[MAX_ITEMS][SIZE]; // Buffer for data
} SharedMemory;

int shm_id;
int sem_id;

void cleanup() {
    shmctl(shm_id, IPC_RMID, NULL);
    semctl(sem_id, 0, IPC_RMID);
}

void producer() {
    SharedMemory *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (SharedMemory *)(-1)) {
        perror("Shmat Error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        snprintf(shm_ptr->data[i], SIZE, "Item %d", i);
        shm_ptr->count++;
        printf("Produced: %s\n", shm_ptr->data[i]);
        sem_signal(sem_id);
        sleep(1);
    }

    shmdt(shm_ptr);
}

void consumer() {
    SharedMemory *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (SharedMemory *)(-1)) {
        perror("Shmat Error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        sem_wait(sem_id);
        printf("Consumed: %s\n", shm_ptr->data[i]);
        shm_ptr->count--;
    }

    shmdt(shm_ptr);
}

int main() {
    key_t key = ftok("shmfile", 65);
    shm_id = shmget(key, sizeof(SharedMemory), 0666|IPC_CREAT);
    if (shm_id < 0) {
        perror("Shmget Error");
        exit(EXIT_FAILURE);
    }

    sem_id = semget(key, 1, 0666|IPC_CREAT);
    if (sem_id < 0) {
        perror("Semget Error");
        exit(EXIT_FAILURE);
    }
    semctl(sem_id, 0, SETVAL, 0);
    
    SharedMemory *shm_ptr = shmat(shm_id, NULL, 0);
    shm_ptr->count = 0;
    shmdt(shm_ptr);

    if (fork() == 0) {
        producer();
        exit(0);
    } else {
        consumer();
    }

    cleanup();
    return 0;
}