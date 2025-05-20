//FormAI DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    // Create shared memory segment
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Attach to shared memory
    char *shared_mem = (char *) shmat(shmid, NULL, 0);

    if (shared_mem == (char *) -1) {
        perror("shmat");
        return 1;
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // This is the child process

        // Write message to shared memory
        sprintf(shared_mem, "Hello from child!");

        // Exit child process
        exit(0);
    } else {
        // This is the parent process

        // Wait for child process to complete
        wait(NULL);

        // Read message from shared memory
        char message[SHM_SIZE];
        strcpy(message, shared_mem);

        // Print the message
        printf("Received message from child: %s\n", message);

        // Detach from shared memory
        shmdt(shared_mem);

        // Remove shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}