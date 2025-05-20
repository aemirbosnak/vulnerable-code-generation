//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
    int shmid, *shm, status;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = shmat(shmid, NULL, 0);
    if (shm == (int *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create child process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process writes to shared memory
        *shm = 42;
        sleep(1);
        exit(0);
    } else {
        // Parent process waits for child process to write to shared memory
        wait(&status);

        // Parent process reads from shared memory
        printf("Shared memory value: %d\n", *shm);

        // Detach shared memory segment from process
        shmdt(shm);

        // Destroy shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}