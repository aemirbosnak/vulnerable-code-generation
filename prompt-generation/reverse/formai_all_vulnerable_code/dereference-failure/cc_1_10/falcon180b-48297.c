//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SEM_KEY 1234
#define SEM_ID 9876
#define SHM_KEY 4321
#define SHM_ID 8765
#define SHM_SIZE 1024

int main()
{
    int shmid, semid;
    char *shm;
    struct sembuf sem_op;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char*)-1)
    {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    strcpy(shm, "Hello, world!");

    // Create semaphore set
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1)
    {
        printf("Error creating semaphore set\n");
        exit(1);
    }

    // Initialize semaphore set
    sem_op.sem_num = 0;
    sem_op.sem_op = 0;
    sem_op.sem_flg = SEM_UNDO;
    if (semctl(semid, 0, SETVAL, 1) == -1)
    {
        printf("Error initializing semaphore set\n");
        exit(1);
    }

    // Fork child process
    int pid = fork();
    if (pid == 0)
    {
        // Child process
        sleep(1);

        // Increment value in shared memory segment
        shm[0] = 'H';

        // Signal semaphore
        sem_op.sem_op = 1;
        if (semop(semid, &sem_op, 1) == -1)
        {
            printf("Error signaling semaphore\n");
            exit(1);
        }

        // Detach shared memory segment
        if (shmdt(shm) == -1)
        {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    }
    else
    {
        // Parent process
        sleep(2);

        // Decrement value in shared memory segment
        shm[0] = 'e';

        // Signal semaphore
        sem_op.sem_op = -1;
        if (semop(semid, &sem_op, 1) == -1)
        {
            printf("Error signaling semaphore\n");
            exit(1);
        }

        // Detach shared memory segment
        if (shmdt(shm) == -1)
        {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // Wait for child process to exit
        wait(NULL);
    }

    return 0;
}