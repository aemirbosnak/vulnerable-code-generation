//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SEM_KEY 1234
#define SEM_ID 0
#define SHM_KEY 5678
#define SHM_ID 0
#define SHM_SIZE 1024

int semid, shmid;
char *shm;

void init_sem() {
    int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error: Failed to create semaphore\n");
        exit(1);
    }
    union semun {
        int val;
        struct semid_ds *buf;
        ushort *array;
    } argument;
    argument.val = 1;
    if (semctl(semid, SEM_ID, SETVAL, argument) == -1) {
        printf("Error: Failed to set semaphore value\n");
        exit(1);
    }
}

void init_shm() {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: Failed to create shared memory\n");
        exit(1);
    }
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error: Failed to attach shared memory\n");
        exit(1);
    }
    memset(shm, 0, SHM_SIZE);
}

void write_to_shm(int pid) {
    sprintf(shm + strlen(shm), "Child process %d wrote to shared memory\n", pid);
}

void read_from_shm(int pid) {
    char buf[SHM_SIZE];
    memcpy(buf, shm, SHM_SIZE);
    printf("Child process %d read from shared memory: %s", pid, buf);
}

int main() {
    int pid;
    init_sem();
    init_shm();
    pid = fork();
    if (pid == 0) {
        sleep(1);
        write_to_shm(getpid());
        exit(0);
    } else {
        wait(NULL);
        read_from_shm(pid);
        exit(0);
    }
}