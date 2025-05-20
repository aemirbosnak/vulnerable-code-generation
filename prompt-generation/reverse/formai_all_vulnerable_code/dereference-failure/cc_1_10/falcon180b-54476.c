//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    // create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // initialize shared memory
    for (int i = 0; i < SHM_SIZE; i++) {
        shm[i] = 0;
    }

    // fork child process
    pid = fork();
    if (pid == 0) {
        // child process
        for (int i = 0; i < SHM_SIZE; i++) {
            shm[i] = i;
        }
        sleep(2);
    } else {
        // parent process
        for (int i = 0; i < SHM_SIZE; i++) {
            shm[i] = 0;
        }
        sleep(1);
    }

    // detach from shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}