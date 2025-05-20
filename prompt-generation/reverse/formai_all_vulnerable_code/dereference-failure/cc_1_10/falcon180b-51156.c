//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SIZE 1024

int shmid;
char *shmaddr;

int main() {
    int pid;
    int status;

    key_t key = ftok("./shm", 65);
    shmid = shmget(key, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if ((int)shmaddr == -1) {
        perror("shmat");
        exit(1);
    }

    printf("Shared memory attached at %p\n", shmaddr);

    pid = fork();
    if (pid == 0) {
        for (int i = 0; i < SIZE; i++) {
            *(shmaddr + i) = i;
        }
        sleep(2);
        exit(0);
    } else {
        waitpid(pid, &status, 0);
        printf("Child exited with status %d\n", status);
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", *(shmaddr + i));
        }
        printf("\n");
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}