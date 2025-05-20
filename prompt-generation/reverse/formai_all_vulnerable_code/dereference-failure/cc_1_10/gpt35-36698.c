//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    char* shared_mem;
    int shm_id;

    // Create the shared memory segment
    shm_id = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shm_id < 0) {
        printf("Error creating shared memory segment!\n");
        exit(1);
    }

    // Attach to shared memory segment
    shared_mem = shmat(shm_id, NULL, 0);
    if (shared_mem == (char*)-1) {
        printf("Error attaching to shared memory segment!\n");
        exit(1);
    }

    // Write data to shared memory
    strcpy(shared_mem, "Hello World!");

    // Fork a child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process reads from shared memory
        printf("Child process reads from shared memory: %s\n", shared_mem);
        exit(0);
    } else if (pid > 0) {
        // Parent process waits for child to finish
        wait(NULL);

        // Detach from shared memory segment
        shmdt(shared_mem);

        // Delete the shared memory segment
        shmctl(shm_id, IPC_RMID, NULL);
    } else {
        // Forking failed
        printf("Error forking child process!\n");
        exit(1);
    }

    return 0;
}