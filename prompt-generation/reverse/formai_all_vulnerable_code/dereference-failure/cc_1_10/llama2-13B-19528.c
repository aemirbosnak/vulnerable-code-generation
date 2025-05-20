//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_KEY 0xDEADBEEF
#define SHM_SIZE 1024

int main(void) {
    // Create a shared memory segment
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *)(-1)) {
        perror("shmat");
        return 1;
    }

    // Write some data to the shared memory
    char *data = "Hello, world!";
    strcpy(shm, data);

    // Create a new process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    // In the new process, read the data from the shared memory
    if (pid > 0) {
        // Read the data from the shared memory
        char *shm_data = shm;
        printf("Received message: %s\n", shm_data);
    } else {
        // In the new process, write some more data to the shared memory
        char *more_data = "This is some additional data!";
        strcpy(shm, more_data);
    }

    // Wait for the new process to finish
    wait(NULL);

    // Detach from the shared memory segment
    shmdt(shm);

    return 0;
}