//FormAI DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

// key value for shared memory
#define SHM_KEY 0x1234

// size of shared buffer
#define SHM_SIZE 1024

int main() {
    int shmid;

    // create shared memory
    if ((shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory
    char* shared_buffer = shmat(shmid, NULL, 0);
    
    // check for errors in attaching shared memory 
    if (shared_buffer == (char*) -1) {
        perror("shmat");
        exit(1);
    }

    // initialize shared buffer
    memset(shared_buffer, 0, SHM_SIZE);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    
    // child process
    if (pid == 0) {
        // read from shared buffer
        printf("Child Process Reading from Shared Memory: %s\n", shared_buffer);
        exit(0);
    } 
    
    // parent process
    else {
        // write to shared buffer
        strncpy(shared_buffer, "Hello from Parent Process\n", SHM_SIZE);
        printf("Parent Process Wrote to Shared Memory\n");
    }

    // detach shared memory
    if (shmdt(shared_buffer) == -1) {
        perror("shmdt");
        exit(1);
    }

    // delete shared memory
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}