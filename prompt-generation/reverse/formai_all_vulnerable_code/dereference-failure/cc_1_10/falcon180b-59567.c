//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmptr;
    int i, j;

    shmid = shmget(IPC_PRIVATE, SIZE*sizeof(int), IPC_CREAT|0777);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);
    if ((int)shmptr < 0) {
        perror("shmat");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            *(shmptr + i*SIZE + j) = 0;
        }
    }

    printf("Matrix initialized\n");

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (fork() == 0) {
                int value = rand() % 10;
                printf("Child %d setting (%d,%d) to %d\n", getpid(), i, j, value);
                sleep(1);
                *(shmptr + i*SIZE + j) = value;
                exit(0);
            }
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", *(shmptr + i*SIZE + j));
        }
        printf("\n");
    }

    return 0;
}