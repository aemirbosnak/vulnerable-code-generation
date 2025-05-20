//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

#define SHM_SIZE 128

int main()
{
    // Shared Memory Segment Initialization
    int shmid;
    key_t key;
    char* shm;
    int* shared_value;

    key = ftok("shared_mem_example", 'a');
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    if (shmid < 0)
    {
        printf("Error creating shared memory segment! Error code: %d\n", errno);
        exit(1);
    }
    printf("Shared memory segment created successfully!\n");

    // Attach to the Shared Memory Segment
    shm = shmat(shmid, NULL, 0);

    if (shm == (char*)-1)
    {
        printf("Could not attach to shared memory segment! Error code: %d\n", errno);
        exit(1);
    }
    printf("Attached to shared memory segment successfully!\n");

    shared_value = (int*)shm;
    *shared_value = 0;

    // Forking a Child Process
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Error forking child process!\n");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child Process

        printf("Child process running...\n");

        printf("Enter an integer value to add to the shared memory segment: ");
        int value;
        scanf("%d", &value);

        *shared_value += value;
        printf("%d added to the shared memory segment.\n", value);

        printf("Child process terminating...\n");
        exit(0);
    }
    else
    {
        // Parent Process

        printf("Parent process running...\n");

        printf("Enter an integer value to add to the shared memory segment: ");
        int value;
        scanf("%d", &value);

        *shared_value += value;
        printf("%d added to the shared memory segment.\n", value);

        wait(NULL);

        printf("The shared value is: %d\n", *shared_value);

        // Detach from the Shared Memory Segment
        shmdt(shm);

        // Remove the Shared Memory Segment
        shmctl(shmid, IPC_RMID, NULL);

        printf("Parent process terminating...\n");
        exit(0);
    }
}