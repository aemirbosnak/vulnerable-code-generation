//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SIZE 10
#define SEM_ID 0x7F00
#define SHM_ID 0x7F01

int semid;
int shmid;
int *shm;
int *semaphore;

void init() {
    int i;
    semid = semget(IPC_PRIVATE, 1, 0777 | IPC_CREAT);
    semaphore = (int *) semctl(semid, 0, GETVAL);
    for (i = 0; i < SIZE; i++) {
        semaphore[i] = 1;
    }
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), 0777 | IPC_CREAT);
    shm = (int *) shmat(shmid, NULL, 0);
}

void cleanup() {
    int i;
    for (i = 0; i < SIZE; i++) {
        semaphore[i] = 0;
    }
    semctl(semid, 0, SETVAL, semaphore);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
}

void producer() {
    int i = 0;
    while (1) {
        sleep(1);
        semaphore[i] = 0;
        shm[i] = i;
        printf("Produced %d\n", i);
        i++;
        if (i == SIZE) {
            i = 0;
        }
    }
}

void consumer() {
    int i = 0;
    while (1) {
        semaphore[i] = 0;
        if (shm[i]!= 0) {
            printf("Consumed %d\n", shm[i]);
            shm[i] = 0;
        }
        i++;
        if (i == SIZE) {
            i = 0;
        }
        sleep(1);
    }
}

int main() {
    int pid;
    init();
    if (fork() == 0) {
        producer();
    } else {
        consumer();
    }
    cleanup();
    return 0;
}