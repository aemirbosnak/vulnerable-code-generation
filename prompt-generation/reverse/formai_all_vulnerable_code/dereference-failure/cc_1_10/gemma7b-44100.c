//Gemma-7B DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define IPC_KEY 1234
#define SHM_SIZE 1024

int main()
{
    int shmid, pid, i, data;
    char *shm_ptr;
    key_t key;

    // Create a shared memory segment
    key = IPC_KEY;
    shm_ptr = shmat(key, NULL, 0);

    // Attach the shared memory segment to the current process
    if (shm_ptr == NULL)
    {
        perror("Error attaching shared memory segment");
        exit(1);
    }

    // Get the process ID of the other process
    pid = fork();

    // If the process is the parent, send data to the child
    if (pid == 0)
    {
        // Send data to the child
        for (i = 0; i < SHM_SIZE; i++)
        {
            data = rand() % 10;
            shm_ptr[i] = data;
        }
    }

    // If the process is the child, receive data from the parent
    else
    {
        // Receive data from the parent
        for (i = 0; i < SHM_SIZE; i++)
        {
            data = shm_ptr[i];
            printf("Data from parent: %d\n", data);
        }
    }

    // Detach the shared memory segment from the current process
    shmdt(shm_ptr);

    return 0;
}