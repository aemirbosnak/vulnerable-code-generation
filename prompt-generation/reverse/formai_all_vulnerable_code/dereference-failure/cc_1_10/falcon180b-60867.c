//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main()
{
    int shmid;
    char *shmptr;
    int i;

    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0777);

    if (shmid == -1)
    {
        printf("shmget failed\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);

    if ((long) shmptr == -1)
    {
        printf("shmat failed\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++)
    {
        shmptr[i] = i;
    }

    printf("Shared memory created successfully\n");

    sleep(10);

    for (i = 0; i < SIZE; i++)
    {
        printf("Value of element %d is %d\n", i, shmptr[i]);
    }

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}