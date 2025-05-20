//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: introspective
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
    char *ptr;
    pid_t pid;

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error in shmget()\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error in shmat()\n");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        printf("Error in fork()\n");
        exit(1);
    }
    else if (pid > 0) {
        sleep(5);
        ptr = shmptr;
        for (int i = 0; i < SIZE; i++) {
            *ptr = i;
            ptr++;
        }
        printf("Data written by parent\n");
        exit(0);
    }
    else {
        sleep(10);
        ptr = shmptr;
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", *ptr);
            ptr++;
        }
        printf("\n");
        exit(0);
    }

    return 0;
}