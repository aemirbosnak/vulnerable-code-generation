//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm_ptr;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // Attach to shared memory segment
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        printf("Error attaching to shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory
    strcpy(shm_ptr, "Hello, world!");

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking child process.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1);
        shm_ptr[0] = 'c';
        printf("Child process modified shared memory.\n");
        exit(0);
    } else {
        // Parent process
        sleep(2);
        printf("Parent process reading shared memory: %s\n", shm_ptr);
        exit(0);
    }

    return 0;
}