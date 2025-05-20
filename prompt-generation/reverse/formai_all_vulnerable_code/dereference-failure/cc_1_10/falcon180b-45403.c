//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmptr;
    int i;

    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Error in shmget\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);
    if ((int) shmptr < 0) {
        printf("Error in shmat\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        shmptr[i] = i;
    }

    printf("Shared memory initialized\n");

    switch (fork()) {
        case -1:
            printf("Error in fork\n");
            exit(1);
        case 0:
            printf("Child process started\n");
            break;
        default:
            printf("Parent process started\n");
            break;
    }

    if (wait(NULL) < 0) {
        printf("Error in wait\n");
        exit(1);
    }

    printf("Interprocess communication completed\n");

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}