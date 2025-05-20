//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmptr;
    pid_t pid;

    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);

    if (shmptr == (char *) -1) {
        printf("Error attaching to shared memory\n");
        exit(1);
    }

    for (int i = 0; i < SIZE; i++) {
        *(shmptr + i) = i;
    }

    pid = fork();

    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    }

    if (pid == 0) {
        for (int i = 0; i < SIZE; i++) {
            *(shmptr + i) += 10;
        }
    } else {
        wait(NULL);
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", *(shmptr + i));
        }
        printf("\n");
    }

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}