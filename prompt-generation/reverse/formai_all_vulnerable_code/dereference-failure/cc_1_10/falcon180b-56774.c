//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid, i;
    char *shm;

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0600);

    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);

    if (shm == (void *)-1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        shm[i] = 'A' + i;
    }

    printf("Shared memory segment created and initialized\n");

    sleep(10);

    for (i = 0; i < SIZE; i++) {
        if (shm[i]!= 'A' + i) {
            printf("Error: shared memory segment corrupted\n");
            exit(1);
        }
    }

    printf("Shared memory segment is intact\n");

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}