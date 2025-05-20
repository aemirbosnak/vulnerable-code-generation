//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmaddr;
    char *shmptr;
    pid_t pid;
    int i;

    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(char), IPC_CREAT | 0777);
    if (shmid == -1) {
        printf("Error in shmget\n");
        exit(0);
    }

    shmaddr = (char *)shmat(shmid, 0, 0);
    if (shmaddr == (char *)-1) {
        printf("Error in shmat\n");
        exit(0);
    }

    for (i = 0; i < SIZE; i++) {
        shmptr = shmaddr + i;
        *shmptr = 'A' + i;
    }

    printf("Shared memory attached at %p\n", shmaddr);
    printf("Shared memory contents: ");
    for (i = 0; i < SIZE; i++) {
        printf("%c ", *(shmaddr + i));
    }
    printf("\n");

    pid = fork();
    if (pid == 0) {
        shmptr = (char *)shmat(shmid, 0, 0);
        if (shmptr == (char *)-1) {
            printf("Error in shmat\n");
            exit(0);
        }

        printf("Child process attached to shared memory\n");
        printf("Shared memory contents: ");
        for (i = 0; i < SIZE; i++) {
            printf("%c ", *(shmaddr + i));
        }
        printf("\n");

        for (i = 0; i < SIZE; i++) {
            *(shmptr + i) = 'a' + i;
        }

        printf("Child process modified shared memory\n");
        printf("Shared memory contents: ");
        for (i = 0; i < SIZE; i++) {
            printf("%c ", *(shmptr + i));
        }
        printf("\n");

        exit(0);
    } else {
        sleep(2);
        printf("Parent process waiting for child to modify shared memory\n");
        wait(NULL);
        printf("Parent process detached from shared memory\n");
    }

    return 0;
}