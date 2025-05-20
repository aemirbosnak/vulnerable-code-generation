//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

void sender(int semid, key_t key, int count) {
    int i;
    int *msg;
    struct sembuf sem_op;

    msg = (int *)shmat(semid, 0, 0);
    if (msg == (int *)-1) {
        perror("shmat");
        exit(1);
    }

    for (i = 0; i < count; i++) {
        sem_op.sem_num = 1;
        sem_op.sem_op = -1;
        semop(semid, &sem_op, 1);
        printf("Sent message: %d\n", *msg);
    }

    shmdt(msg);
}

void receiver(int semid, key_t key, int count) {
    int i;
    int *msg;
    struct sembuf sem_op;

    msg = (int *)shmat(semid, 0, 0);
    if (msg == (int *)-1) {
        perror("shmat");
        exit(1);
    }

    for (i = 0; i < count; i++) {
        sem_op.sem_num = 1;
        sem_op.sem_op = 0;
        semop(semid, &sem_op, 1);
        printf("Received message: %d\n", *msg);
    }

    shmdt(msg);
}

int main() {
    int semid, semid2, shmid, count;
    key_t key;
    char *msg;

    if ((semid = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT)) == -1) {
        perror("semget");
        exit(1);
    }

    if ((semid2 = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT)) == -1) {
        perror("semget");
        exit(1);
    }

    if ((key = ftok(".","")) == (key_t)-1) {
        perror("ftok");
        exit(1);
    }

    if ((shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    if ((msg = (char *)shmat(shmid, 0, 0)) == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    strcpy(msg, "Hello from sender");

    if ((semctl(semid, 0, SETVAL, 1)) == -1) {
        perror("semctl");
        exit(1);
    }

    sender(semid, key, 1);
    receiver(semid2, key, 1);

    shmdt(msg);
    semctl(semid, 0, IPC_RMID);
    semctl(semid2, 0, IPC_RMID);
    exit(0);
}