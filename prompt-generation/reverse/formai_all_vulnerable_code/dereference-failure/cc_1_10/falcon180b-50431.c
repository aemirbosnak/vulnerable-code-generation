//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    void *shmaddr;
    pid_t pid;

    // Create shared memory segment
    if ((shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    if ((shmaddr = shmat(shmid, NULL, 0)) == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    memset(shmaddr, 0, SHM_SIZE);

    // Fork child process
    if ((pid = fork()) == 0) {
        // Child process writes to shared memory segment
        sprintf(shmaddr, "Hello, world!");
    } else {
        // Parent process reads from shared memory segment
        wait(NULL);
        printf("Shared memory segment contains: %s\n", (char *) shmaddr);
    }

    // Detach shared memory segment
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}