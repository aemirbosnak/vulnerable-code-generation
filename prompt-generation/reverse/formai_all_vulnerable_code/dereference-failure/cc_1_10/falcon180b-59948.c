//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main() {
    int shmid;
    void *shm;
    char *ptr;

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Error in shmget\n");
        exit(1);
    }

    shm = shmat(shmid, (void *)0, 0);

    if (shm == (void *)-1) {
        printf("Error in shmat\n");
        exit(1);
    }

    ptr = shm;

    printf("Shared memory attached at %p\n", ptr);

    sleep(5);

    for (int i = 0; i < SIZE; i++) {
        *(ptr + i) = i;
    }

    printf("Data written to shared memory\n");

    sleep(5);

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *(ptr + i));
    }

    printf("\n");

    shmdt(shm);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}