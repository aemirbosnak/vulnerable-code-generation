//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmaddr;
    int i;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0777);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shmaddr = shmat(shmid, 0, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SIZE; i++) {
        shmaddr[i] = i;
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1); // Allow parent to finish initializing shared memory

        // Modify shared memory
        for (i = 0; i < SIZE; i++) {
            shmaddr[i] *= 2;
        }

        // Print modified shared memory
        for (i = 0; i < SIZE; i++) {
            printf("%d ", shmaddr[i]);
        }

        exit(0);
    } else {
        // Parent process
        wait(NULL); // Wait for child to finish

        // Print original shared memory
        for (i = 0; i < SIZE; i++) {
            printf("%d ", shmaddr[i]);
        }
    }

    return 0;
}