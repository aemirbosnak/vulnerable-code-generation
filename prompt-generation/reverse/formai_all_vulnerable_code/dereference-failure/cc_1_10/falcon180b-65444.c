//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SIZE 10

int main() {
    int shmid;
    int *shmptr;
    pid_t childpid;
    shmid = shmget(IPC_PRIVATE, SIZE*sizeof(int), IPC_CREAT|0666);
    if(shmid == -1) {
        perror("shmget");
        exit(1);
    }
    shmptr = (int*)shmat(shmid, (void*)0, 0);
    if(shmptr == (int*)-1) {
        perror("shmat");
        exit(1);
    }
    for(int i = 0; i < SIZE; i++) {
        shmptr[i] = i;
    }
    childpid = fork();
    if(childpid == -1) {
        perror("fork");
        exit(1);
    } else if(childpid == 0) {
        for(int i = 0; i < SIZE; i++) {
            shmptr[i] += 10;
        }
        printf("Child: ");
        for(int i = 0; i < SIZE; i++) {
            printf("%d ", shmptr[i]);
        }
        printf("\n");
        shmdt(shmptr);
        exit(0);
    } else {
        wait(NULL);
        printf("Parent: ");
        for(int i = 0; i < SIZE; i++) {
            printf("%d ", shmptr[i]);
        }
        printf("\n");
        shmdt(shmptr);
        shmctl(shmid, IPC_RMID, NULL);
        exit(0);
    }
    return 0;
}