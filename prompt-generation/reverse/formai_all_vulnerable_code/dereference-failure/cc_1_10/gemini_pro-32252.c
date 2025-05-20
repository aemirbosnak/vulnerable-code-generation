//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

#define SEGSIZE 100

int main() {
    int shmid;
    char *shmptr;
    int semid;
    struct sembuf sem_op;

    /* Create a shared memory segment */
    shmid = shmget(IPC_PRIVATE, SEGSIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    /* Attach the shared memory segment to the address space of the current process */
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    /* Create a semaphore set */
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid < 0) {
        perror("semget");
        exit(1);
    }

    /* Initialize the semaphore to 1 */
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    if (semop(semid, &sem_op, 1) < 0) {
        perror("semop");
        exit(1);
    }

    /* Write to the shared memory segment */
    printf("Enter some text: ");
    fgets(shmptr, SEGSIZE, stdin);

    /* Decrement the semaphore to indicate that the shared memory segment is now available for reading */
    sem_op.sem_op = -1;
    if (semop(semid, &sem_op, 1) < 0) {
        perror("semop");
        exit(1);
    }

    /* Wait for the semaphore to be incremented again, indicating that the other process has finished reading */
    sem_op.sem_op = 1;
    if (semop(semid, &sem_op, 1) < 0) {
        perror("semop");
        exit(1);
    }

    /* Detach the shared memory segment from the address space of the current process */
    if (shmdt(shmptr) < 0) {
        perror("shmdt");
        exit(1);
    }

    /* Destroy the shared memory segment */
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        perror("shmctl");
        exit(1);
    }

    /* Destroy the semaphore set */
    if (semctl(semid, 0, IPC_RMID) < 0) {
        perror("semctl");
        exit(1);
    }

    return 0;
}