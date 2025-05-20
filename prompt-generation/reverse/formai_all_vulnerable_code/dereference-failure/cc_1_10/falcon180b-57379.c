//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shm;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0777);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    for (int i = 0; i < SIZE; i++) {
        shm[i] = 0;
    }

    // Fork child process
    int pid = fork();
    if (pid == 0) {
        // Child process
        for (int i = 0; i < SIZE; i++) {
            shm[i] = i;
        }
    } else {
        // Parent process
        wait(NULL);
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", shm[i]);
        }
    }

    // Detach from shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment\n");
        exit(1);
    }

    return 0;
}