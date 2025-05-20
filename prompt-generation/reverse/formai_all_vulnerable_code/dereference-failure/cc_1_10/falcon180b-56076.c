//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 50

int main() {
    int shmid;
    char *shmptr;
    pid_t pid;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(char), IPC_CREAT | 0777);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 0;
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process writes to shared memory segment
        for (i = 0; i < SIZE; i++) {
            shmptr[i] = i;
        }
        printf("Child process wrote to shared memory segment\n");
    } else {
        // Parent process reads from shared memory segment
        for (i = 0; i < SIZE; i++) {
            printf("Parent process read from shared memory segment: %d\n", shmptr[i]);
        }
    }

    // Detach shared memory segment from process
    if (shmdt(shmptr) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error destroying shared memory segment\n");
        exit(1);
    }

    return 0;
}