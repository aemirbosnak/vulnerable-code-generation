//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int shmid;
    key_t key;
    char *shm, *s;
    int *numbers;
    int i;

    /* create a key for the shared memory segment */
    key = 5678;

    /* create the shared memory segment */
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0)
        error("shmget");

    /* attach the shared memory segment */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
        error("shmat");

    /* cast the shared memory segment to an array of integers */
    numbers = (int *)shm;

    /* generate some random numbers and store them in the shared memory segment */
    for (i = 0; i < 10; i++)
        numbers[i] = rand() % 100 + 1;

    /* detach the shared memory segment */
    if (shmdt(shm) == -1)
        error("shmdt");

    /* wait for the consumer process to read the numbers */
    sleep(5);

    /* attach the shared memory segment again */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
        error("shmat");

    /* cast the shared memory segment to an array of integers again */
    numbers = (int *)shm;

    /* read the numbers from the shared memory segment and print them to the screen */
    for (i = 0; i < 10; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    /* detach the shared memory segment again */
    if (shmdt(shm) == -1)
        error("shmdt");

    /* remove the shared memory segment */
    if (shmctl(shmid, IPC_RMID, 0) == -1)
        error("shmctl");

    return 0;
}