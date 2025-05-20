//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main() {
    int shm_id;
    char *shm_ptr;
    pid_t pid;

    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, SIZE, 0666 | IPC_CREAT);
    if (shm_id == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    memset(shm_ptr, 0, SIZE);

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process started\n");
        sleep(1);
        shm_ptr[0] = 'C';
    } else {
        // Parent process
        printf("Parent process started\n");
        sleep(2);
        shm_ptr[0] = 'P';
    }

    // Detach shared memory segment
    if (shmdt(shm_ptr) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment\n");
        exit(1);
    }

    return 0;
}