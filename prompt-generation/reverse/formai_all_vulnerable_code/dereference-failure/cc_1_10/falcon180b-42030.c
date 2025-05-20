//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024
#define KEY 1234

int main()
{
    int shmid;
    char *shmptr;
    char *ptr;

    // Create shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1)
    {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    ptr = shmptr;
    for (int i = 0; i < SIZE; i++)
    {
        *ptr++ = 'A';
    }

    // Detach from shared memory segment
    if (shmdt(shmptr) == -1)
    {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // Reattach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1)
    {
        printf("Error reattaching to shared memory segment\n");
        exit(1);
    }

    // Print contents of shared memory segment
    ptr = shmptr;
    printf("Shared memory segment contents:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%c", *ptr++);
    }

    // Detach from shared memory segment
    if (shmdt(shmptr) == -1)
    {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        printf("Error deleting shared memory segment\n");
        exit(1);
    }

    // End of program
    return 0;
}