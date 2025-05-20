//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define MAX_SIZE 100
#define SEM_KEY 1234
#define SHM_KEY 5678

struct data {
    char message[MAX_SIZE];
    int count;
};

int main() {
    int shmid;
    key_t shm_key = SHM_KEY;
    struct data *shared_memory = NULL;
    int semid;
    int sem_key = SEM_KEY;
    struct sembuf sem_op;

    shared_memory = (struct data *) shmat(shmid, NULL, 0);

    if (shared_memory == (void *) -1) {
        fprintf(stderr, "Shared memory attach failed\n");
        exit(1);
    }

    while (1) {
        memset(shared_memory->message, 0, MAX_SIZE);
        sprintf(shared_memory->message, "Hello World %d", shared_memory->count);
        shared_memory->count++;

        sem_op.sem_num = 0;
        sem_op.sem_op = 1;
        sem_op.sem_flg = 0;

        if (semop(semid, &sem_op, 1) == -1) {
            fprintf(stderr, "Semaphore operation failed\n");
            exit(1);
        }

        sleep(1);
    }

    return 0;
}