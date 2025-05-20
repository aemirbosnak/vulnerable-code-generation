//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024
#define SEM_KEY 0x5678
#define SEM_VALUE 1

int shmid;
char *shm;
int semid;
int sem;

void init_shm() {
    int shm_fd = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_fd == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }
    shmid = shmget(SHM_KEY, SHM_SIZE, 0644);
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }
    memset(shm, 0, SHM_SIZE);
}

void init_sem() {
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }
    sem = semget(SEM_KEY, 1, 0644);
    if (sem == -1) {
        printf("Error attaching semaphore\n");
        exit(1);
    }
    if (semctl(sem, 0, SETVAL, SEM_VALUE) == -1) {
        printf("Error setting semaphore value\n");
        exit(1);
    }
}

void write_to_shm(char *str) {
    int i = 0;
    while (shm[i]!= '\0') {
        i++;
    }
    strcpy(&shm[i], str);
}

char *read_from_shm() {
    char *msg = shm;
    while (msg[0]!= '\0') {
        msg++;
    }
    return msg;
}

int main() {
    init_shm();
    init_sem();

    pid_t pid = fork();
    if (pid == 0) {
        sleep(2);
        write_to_shm("Hello from child process!");
        printf("Child process wrote to shared memory\n");
        exit(0);
    } else {
        sleep(1);
        char *msg = read_from_shm();
        printf("Parent process read from shared memory: %s\n", msg);
        exit(0);
    }

    return 0;
}