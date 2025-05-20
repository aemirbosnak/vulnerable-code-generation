//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(int argc, char *argv[]) {
    int shmid;
    char *shm;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0600);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    memset(shm, 0, SHM_SIZE);

    // Fork child process
    pid = fork();
    if (pid == 0) {
        // Child process writes to shared memory
        int i = 0;
        while (i < SHM_SIZE) {
            shm[i] = i;
            i++;
        }
        exit(0);
    } else {
        // Parent process reads from shared memory
        wait(NULL);
        for (int i = 0; i < SHM_SIZE; i++) {
            printf("%c", shm[i]);
        }
        exit(0);
    }
}