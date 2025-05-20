//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    int i;

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT|0777);
    if (shmid < 0) {
        printf("Error in shmget()\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        printf("Error in shmat()\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 'A' + i;
    }

    if (fork() == 0) {
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            shmptr[i] = shmptr[i] + 1;
        }
        printf("Child process has modified the shared memory segment.\n");
    } else {
        sleep(2);
        for (i = 0; i < SIZE; i++) {
            if (shmptr[i]!= 'A' + i) {
                printf("Shared memory segment has been modified by child process.\n");
            }
        }
    }

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}