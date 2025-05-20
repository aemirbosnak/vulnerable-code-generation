//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int shmid;
char *shmaddr;

void init_shm() {
    key_t key = ftok("shm_file", 65);
    int shmid = shmget(key, SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }
    shmaddr = shmat(shmid, 0, 0);
    if (shmaddr == (char *) -1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }
    memset(shmaddr, 0, SIZE);
}

void read_shm() {
    char *shmaddr = (char *) shmat(shmid, 0, 0);
    if (shmaddr == (char *) -1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }
    printf("Shared memory content: %s\n", shmaddr);
    shmdt(shmaddr);
}

void write_shm() {
    char *shmaddr = (char *) shmat(shmid, 0, 0);
    if (shmaddr == (char *) -1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }
    strcpy(shmaddr, "Hello, world!");
    shmdt(shmaddr);
}

int main() {
    int pid;
    int status;

    init_shm();

    pid = fork();
    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    } else if (pid == 0) {
        write_shm();
        exit(0);
    } else {
        wait(&status);
        read_shm();
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}