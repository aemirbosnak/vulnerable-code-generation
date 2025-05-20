//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;

    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: shmget failed.\n");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        printf("Error: shmat failed.\n");
        exit(1);
    }

    strcpy(shm, "Hello, world!");

    printf("Parent process has written 'Hello, world!' to shared memory.\n");

    int pid = fork();

    if (pid == 0) { // Child process
        char *child_shm = shmat(shmid, NULL, 0);
        if (child_shm == (void *) -1) {
            printf("Error: shmat failed.\n");
            exit(1);
        }

        printf("Child process has read '%s' from shared memory.\n", child_shm);

        sleep(2);

        strcpy(child_shm, "Hello from child!");

        printf("Child process has written 'Hello from child!' to shared memory.\n");

        exit(0);
    } else { // Parent process
        wait(NULL);

        char *parent_shm = shmat(shmid, NULL, 0);
        if (parent_shm == (void *) -1) {
            printf("Error: shmat failed.\n");
            exit(1);
        }

        printf("Parent process has read '%s' from shared memory.\n", parent_shm);

        exit(0);
    }
}