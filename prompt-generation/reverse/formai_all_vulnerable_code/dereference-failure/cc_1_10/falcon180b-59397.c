//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define MAX_SIZE 100
#define KEY 12345
#define SEM_KEY 54321

int main() {
    int shmid, semid;
    char *shmptr;
    struct msgbuf {
        long mtype;
        char mtext[MAX_SIZE];
    } msg;
    int semid_shm = semget(SEM_KEY, 1, 0666 | IPC_CREAT);

    if (semid_shm == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    if ((shmid = shmget(KEY, MAX_SIZE, 0666 | IPC_CREAT)) == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    if ((shmptr = shmat(shmid, 0, 0)) == (char *) -1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }

    memset(shmptr, 0, MAX_SIZE);

    if (fork() == 0) {
        while (1) {
            sleep(1);
            sprintf(shmptr, "Child process is running\n");
        }
    } else {
        while (1) {
            sleep(1);
            if (msgrcv(semid_shm, &msg, MAX_SIZE, 0, 0) == -1) {
                printf("Error receiving message\n");
                exit(1);
            }
            printf("Received message: %s\n", msg.mtext);
        }
    }

    return 0;
}