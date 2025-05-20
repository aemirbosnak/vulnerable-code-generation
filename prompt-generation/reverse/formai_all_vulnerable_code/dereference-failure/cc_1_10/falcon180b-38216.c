//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int fd, shmid;
    char *shm_ptr;
    pid_t child_pid;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory to process address space
    shm_ptr = shmat(shmid, 0, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    memset(shm_ptr, 0, SHM_SIZE);

    // Fork a child process
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        for (int i = 0; i < SHM_SIZE; i++) {
            *(shm_ptr + i) = i;
        }
        printf("Child: Shared memory initialized.\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent: Shared memory initialized.\n");
    }

    return 0;
}