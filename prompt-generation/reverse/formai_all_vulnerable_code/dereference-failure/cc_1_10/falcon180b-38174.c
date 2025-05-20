//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid, i;
    char *shmaddr;
    key_t key = 1234;

    // create shared memory segment
    shmid = shmget(key, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // attach to shared memory segment
    shmaddr = shmat(shmid, (void *)0, 0);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmaddr + i * sizeof(int)) = i;
    }

    // fork child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // child process
        for (i = 0; i < SIZE; i++) {
            *(shmaddr + i * sizeof(int)) = i * 2;
        }
        exit(0);
    } else {
        // parent process
        wait(NULL);
        for (i = 0; i < SIZE; i++) {
            printf("%d\n", *(shmaddr + i * sizeof(int)));
        }
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}