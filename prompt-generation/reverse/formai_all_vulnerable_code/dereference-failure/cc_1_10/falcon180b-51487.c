//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    void *shmaddr;
    int *shmptr;
    int status;

    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);

    if (shmaddr == (void *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    shmptr = (int *) shmaddr;

    for (int i = 0; i < SIZE; i++) {
        *shmptr++ = i;
    }

    int pid = fork();

    if (pid == 0) {
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", *shmptr++);
        }
        exit(0);
    } else {
        wait(&status);
    }

    return 0;
}