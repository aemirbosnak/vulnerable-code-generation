//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_KEY 0xDEADBEEF
#define SHM_SIZE 1024

int main(int argc, char **argv) {
    // Create a shared memory segment
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        return 1;
    }

    // Write some data to the shared memory
    char *message = "Hello from process 1!";
    strcpy(shm, message);

    // Use mlock to prevent the data from being swapped out
    mlock(shm, SHM_SIZE);

    // Fork a new process
    pid_t pid = fork();
    if (pid == 0) {
        // In the new process, read the data from the shared memory
        char *shm_data = shm;
        printf("Received message: %s\n", shm_data);

        // Use munlock to unlock the data
        munlock(shm, SHM_SIZE);

        // Exit the new process
        exit(0);
    } else {
        // In the parent process, wait for the new process to finish
        wait(NULL);
    }

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}