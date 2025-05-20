//FormAI DATASET v1.0 Category: Interprocess communication ; Style: unmistakable
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int pid;
    int shmid;
    char *shm;
    char message[SHM_SIZE];

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    // Attach shared memory to parent process
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }

    // Fork child process
    pid = fork();
    if (pid < 0) {
        printf("Error forking process\n");
        exit(1);
    }

    // Child process writes message to shared memory
    if (pid == 0) {
        sprintf(message, "Hello from Child Process\n");
        for (int i = 0; i < SHM_SIZE; i++) {
            shm[i] = message[i];
        }
        exit(0);
    }

    // Wait for child process to finish
    wait(NULL);

    // Read message from shared memory written by child process
    printf("Message from Child Process: ");
    for (int i = 0; i < SHM_SIZE; i++) {
        putchar(shm[i]);
    }

    // Detach and remove shared memory
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}