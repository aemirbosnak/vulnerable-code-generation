//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define SEM_KEY 0x1234
#define SEM_MAX 10
#define SHM_KEY 0x5678
#define SHM_SIZE 100

int main() {
    int semid, shmid;
    char *shm;
    struct sembuf sembuf;

    semid = semget(SEM_KEY, SEM_MAX, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    strcpy(shm, "Hello, world!");

    while (1) {
        sembuf.sem_num = 0;
        sembuf.sem_op = -1;
        sembuf.sem_flg = SEM_UNDO;
        semop(semid, &sembuf, 1);

        sleep(1);

        sembuf.sem_num = 0;
        sembuf.sem_op = 1;
        sembuf.sem_flg = SEM_UNDO;
        semop(semid, &sembuf, 1);

        sleep(1);
    }

    return 0;
}