//FormAI DATASET v1.0 Category: Interprocess communication ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main()
{
    pid_t pid;
    int shmid;
    char *data;
    char *msg = "Hello from child process!";
    int status;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    data = shmat(shmid, NULL, 0);
    if (data == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Create child process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process - write data to shared memory
        strcpy(data, msg);
        printf("Child process wrote message to shared memory: %s\n", data);
        exit(0);
    } else {
        // Parent process - wait for child to finish
        wait(&status);
        printf("Parent process received message from shared memory: %s\n", data);

        // Detach shared memory segment
        if (shmdt(data) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Deallocate shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}