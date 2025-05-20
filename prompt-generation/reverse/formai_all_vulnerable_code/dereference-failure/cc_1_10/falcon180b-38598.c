//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1000
#define SHM_KEY 1234

int main() {
    int shmid, fd;
    char *shm;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    for (int i = 0; i < SIZE; i++) {
        shm[i] = 'A';
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process writes to shared memory
        for (int i = 0; i < SIZE; i++) {
            shm[i] = 'B';
        }
        printf("Child process wrote to shared memory\n");
    } else {
        // Parent process reads from shared memory
        for (int i = 0; i < SIZE; i++) {
            printf("%c", shm[i]);
        }
        printf("\n");
    }

    // Detach shared memory segment from process
    if (shmdt(shm) == -1) {
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