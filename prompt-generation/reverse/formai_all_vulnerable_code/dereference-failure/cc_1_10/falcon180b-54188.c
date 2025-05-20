//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 1000

int shmid;
char *shmptr;

void child_process() {
    int i;
    for(i=0; i<SIZE; i++) {
        shmptr[i] = 'A' + i;
    }
    printf("Child process has written to shared memory\n");
    exit(0);
}

int main() {
    int i, status;
    pid_t pid;

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0777);
    if(shmid == -1) {
        printf("Error in shmget\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);
    if((int)shmptr == -1) {
        printf("Error in shmat\n");
        exit(2);
    }

    printf("Parent process has initialized shared memory\n");

    pid = fork();
    if(pid == -1) {
        printf("Error in fork\n");
        exit(3);
    } else if(pid == 0) {
        child_process();
    } else {
        wait(&status);
        printf("Parent process has received exit status of child process: %d\n", status);
    }

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}