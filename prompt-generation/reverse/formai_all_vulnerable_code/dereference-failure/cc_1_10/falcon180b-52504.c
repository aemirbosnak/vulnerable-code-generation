//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 10

int main(int argc, char *argv[]) {
    int shmid;
    void *shmaddr;
    int i;
    pid_t pid;
    char *str = "Hello, world!";

    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);

    if (shmaddr == (void *) -1) {
        fprintf(stderr, "shmat failed\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        *(char *) (shmaddr + i) = str[i];
    }

    printf("Parent process: %s\n", str);

    pid = fork();

    if (pid == 0) {
        sleep(1);
        str[0] = 'H';
        str[1] = 'i';
        printf("Child process: %s\n", str);
    } else {
        wait(NULL);
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}