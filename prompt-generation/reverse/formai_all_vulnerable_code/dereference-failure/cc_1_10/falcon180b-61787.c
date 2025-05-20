//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100
#define KEY 5678

int main() {
    int shmid, i;
    char *shm;
    pid_t pid;

    shmid = shmget(KEY, SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        printf("Error in shmget\n");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        printf("Error in shmat\n");
        exit(2);
    }

    pid = fork();

    if (pid == 0) {
        for (i = 0; i < SIZE; i++) {
            shm[i] = 'A';
        }
        printf("Child: Sent string to shared memory\n");
    } else {
        sleep(2);
        for (i = 0; i < SIZE; i++) {
            if (shm[i]!= 'A') {
                printf("Parent: Received string from shared memory: %s\n", shm);
            } else {
                printf("Parent: String not received\n");
            }
        }
    }

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}