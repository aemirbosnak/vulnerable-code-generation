//FormAI DATASET v1.0 Category: Interprocess communication ; Style: real-life
/*
This program demonstrates interprocess communication 
between parent and child processes using shared memory
Parent process generates an array of random numbers and stores it in shared memory
Child process calculates the sum of the numbers in shared memory and returns the result
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

#define ARRAY_SIZE 100 // size of the array

int main()
{
    int shmid; // shared memory segment id
    int *shm_array; // pointer to shared memory array
    int sum = 0; // sum of the array
    int i;

    // fork a child process
    pid_t pid = fork();

    // error handling
    if (pid < 0)
    {
        fprintf(stderr, "Failed to fork the process\n");
        exit(1);
    }
    else if (pid == 0) // child process
    {
        // get the shared memory segment id created by parent process
        shmid = shmget(IPC_PRIVATE, ARRAY_SIZE * sizeof(int), IPC_CREAT | 0666);

        if (shmid < 0)
        {
            fprintf(stderr, "Failed to get shared memory segment id\n");
            exit(1);
        }

        // attach shared memory segment to child process memory space
        shm_array = (int *)shmat(shmid, NULL, 0);

        // calculate the sum of the numbers in the array
        for (i = 0; i < ARRAY_SIZE; i++)
        {
            sum += shm_array[i];
        }

        printf("Sum of the array is %d\n", sum);

        // detach shared memory segment from child process memory space
        shmdt(shm_array);

        // destroy the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);

        exit(0);
    }
    else // parent process
    {
        // initialize random number generator
        srand(time(NULL));

        // get the shared memory segment id
        shmid = shmget(IPC_PRIVATE, ARRAY_SIZE * sizeof(int), IPC_CREAT | 0666);

        if (shmid < 0)
        {
            fprintf(stderr, "Failed to get shared memory segment id\n");
            exit(1);
        }

        // attach shared memory segment to parent process memory space
        shm_array = (int *)shmat(shmid, NULL, 0);

        // generate random numbers and store it in shared memory
        for (i = 0; i < ARRAY_SIZE; i++)
        {
            shm_array[i] = rand() % 100;
            printf("%d ", shm_array[i]);
        }
        printf("\n");

        // detach shared memory segment from parent process memory space
        shmdt(shm_array);

        // wait for child process to finish
        wait(NULL);

        // destroy the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);

        exit(0);
    }
}