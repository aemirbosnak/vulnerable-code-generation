//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <signal.h>

#define SEM_KEY 100
#define SEM_SIZE 3
#define SHM_KEY 200
#define SHM_SIZE 1024

int semid;
int shmid;

void handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Received SIGUSR1\n");
        semctl(semid, 0, IPC_RMID);
        shmctl(shmid, IPC_RMID, NULL);
        exit(0);
    }
}

int main() {
    int i;
    key_t key;
    int sem_id;
    int shm_id;
    char *shm_ptr;

    signal(SIGUSR1, handler);

    key = ftok(".", 'a');
    sem_id = semget(key, SEM_SIZE, 0666 | IPC_CREAT);
    if (sem_id == -1) {
        perror("semget");
        exit(1);
    }
    semctl(sem_id, 0, SETVAL, 1);

    shm_id = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *) - 1) {
        perror("shmat");
        exit(1);
    }

    for (i = 0; i < SEM_SIZE; i++) {
        semctl(sem_id, i, IPC_RMID);
    }

    for (i = 0; i < SHM_SIZE; i++) {
        *(shm_ptr + i) = 0;
    }

    printf("Shared memory and semaphore created\n");
    while (1) {
        sleep(1);
    }

    return 0;
}