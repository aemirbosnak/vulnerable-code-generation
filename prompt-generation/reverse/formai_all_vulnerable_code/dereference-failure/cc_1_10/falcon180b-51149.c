//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main()
{
    int shmid;
    key_t key;
    char *shm;

    // Create a shared memory segment
    key = ftok(".", 65);
    shmid = shmget(key, SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to the shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1)
    {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize the shared memory segment
    memset(shm, 0, SIZE);

    // Fork a child process
    int pid = fork();
    if (pid == -1)
    {
        printf("Error forking\n");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process writes to shared memory segment
        strcpy(shm, "Child process writes to shared memory segment");
        sleep(1);
        printf("Child process completed\n");
    }
    else
    {
        // Parent process reads from shared memory segment
        strcpy(shm, "Parent process reads from shared memory segment");
        sleep(1);
        printf("Parent process completed\n");
    }

    // Detach from the shared memory segment
    if (shmdt(shm) == -1)
    {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        printf("Error deleting shared memory segment\n");
        exit(1);
    }

    return 0;
}