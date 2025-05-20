//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid, i;
    char *shmaddr;

    key_t key = ftok("shmfile", 65); // unique key for shared memory

    shmid = shmget(key, SIZE, 0666 | IPC_CREAT); // create shared memory segment

    if (shmid < 0) {
        printf("Error in creating shared memory segment\n");
        exit(0);
    }

    shmaddr = shmat(shmid, NULL, 0); // attach shared memory segment

    if (shmaddr == (char *)-1) {
        printf("Error in attaching shared memory segment\n");
        exit(0);
    }

    printf("Shared memory attached at: %x\n", shmaddr);

    for (i = 0; i < SIZE; i++) {
        shmaddr[i] = 'A'; // initialize shared memory with 'A'
    }

    printf("Shared memory initialized with 'A'\n");

    sleep(5); // wait for child process to access shared memory

    for (i = 0; i < SIZE; i++) {
        if (shmaddr[i] == 'B') {
            printf("Shared memory accessed by child process\n");
            exit(0);
        }
    }

    printf("Shared memory not accessed by child process\n");

    shmdt(shmaddr); // detach shared memory segment
    shmctl(shmid, IPC_RMID, NULL); // remove shared memory segment

    return 0;
}