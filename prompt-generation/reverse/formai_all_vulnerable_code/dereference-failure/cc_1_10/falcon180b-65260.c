//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY (1234)
#define SHM_SIZE (1024)

int main() {
    int shmid;
    void *shm;
    pid_t pid;
    char *shm_ptr;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process address space
    shm = shmat(shmid, NULL, 0);

    if (shm == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory contents
    shm_ptr = shm;
    strcpy(shm_ptr, "Hello, world!");

    // Fork child process
    pid = fork();

    if (pid == 0) {
        // Child process writes to shared memory
        shm_ptr += strlen("Hello, world!") + 1;
        strcpy(shm_ptr, "Child process says hi!");
    }
    else {
        // Parent process reads from shared memory
        wait(NULL);
        shm_ptr += strlen("Hello, world!") + 1;
        printf("Shared memory contents: %s\n", shm_ptr);
    }

    // Detach shared memory segment from process address space
    if (shmdt(shm) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment\n");
        exit(1);
    }

    return 0;
}