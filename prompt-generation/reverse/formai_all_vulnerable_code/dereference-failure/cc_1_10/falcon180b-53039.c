//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    key_t key;
    char *shmaddr;
    int i;

    // generate unique key
    key = 9876;

    // attach to shared memory segment
    shmid = shmget(key, SIZE*sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // get address of shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char*)-1) {
        perror("shmat");
        exit(1);
    }

    // initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        ((int*)shmaddr)[i] = 0;
    }

    // print shared memory segment
    printf("Shared memory segment:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", ((int*)shmaddr)[i]);
    }
    printf("\n");

    // detach from shared memory segment
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}