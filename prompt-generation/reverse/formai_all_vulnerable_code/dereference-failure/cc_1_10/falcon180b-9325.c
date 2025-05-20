//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmptr;
    pid_t pid;

    // Create shared memory segment
    if ((shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    if ((shmptr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared data
    strcpy(shmptr, "Hello, world!");

    printf("Parent process (PID %d) wrote message to shared memory.\n", getpid());

    // Fork child process
    if ((pid = fork()) == 0) {
        // Child process
        sleep(1); // Allow parent process to finish writing message

        // Attach shared memory segment
        if ((shmptr = shmat(shmid, NULL, 0)) == (char *) -1) {
            perror("shmat");
            exit(1);
        }

        // Read message from shared memory
        printf("Child process (PID %d) read message from shared memory: %s\n", getpid(), shmptr);

        // Detach shared memory segment
        if (shmdt(shmptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process
        wait(NULL); // Wait for child process to finish

        // Detach shared memory segment
        if (shmdt(shmptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Remove shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }

        printf("Parent process (PID %d) removed shared memory segment.\n", getpid());
    }

    return 0;
}