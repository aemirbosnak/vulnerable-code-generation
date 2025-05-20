//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    int shmid;
    char *shm_data;

    // Create a shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(char), IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the shared memory segment
    shm_data = (char*)shmat(shmid, NULL, 0);
    if (shm_data == (char*)-1)
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Create a child process to read from the shared memory segment
    pid_t pid = fork();
    if (pid == 0)
    {
        // Child process to read from shared memory segment
        printf("Child process reading from shared memory segment\n");
        while (1)
        {
            // Read data from the shared memory segment
            char data = shm_data[0];
            printf("Data read: %c\n", data);

            // Sleep for a random amount of time
            sleep(rand() % 10);
        }
    }

    // Create a child process to write to the shared memory segment
    pid = fork();
    if (pid == 0)
    {
        // Child process to write to shared memory segment
        printf("Child process writing to shared memory segment\n");
        while (1)
        {
            // Write data to the shared memory segment
            char data = 'A';
            shm_data[0] = data;

            // Sleep for a random amount of time
            sleep(rand() % 10);
        }
    }

    // Wait for the child processes to finish
    int status;
    wait(&status);
    wait(&status);

    // Unmap the shared memory segment
    shmdt(shm_data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}