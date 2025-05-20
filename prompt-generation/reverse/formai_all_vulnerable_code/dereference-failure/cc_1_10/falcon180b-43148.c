//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    key_t key;
    int i;

    key = ftok("shmfile", 65);
    shmid = shmget(key, SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);

    if (shmptr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 'A' + i;
    }

    printf("Shared memory segment created.\n");

    sleep(5);

    for (i = 0; i < SIZE; i++) {
        printf("%c ", shmptr[i]);
    }

    printf("\n");

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}