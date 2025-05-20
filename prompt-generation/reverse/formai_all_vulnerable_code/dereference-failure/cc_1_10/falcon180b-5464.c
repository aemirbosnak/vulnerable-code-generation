//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>

#define TRUE 1
#define FALSE 0
#define SEM_ID_KEY 1234
#define SEM_KEY_COUNT 5
#define SEM_KEY_LOCK 0
#define SEM_KEY_UNLOCK 1
#define SEM_KEY_WAIT 2
#define SEM_KEY_POST 3
#define SEM_KEY_CNT 4

int semid;
int sem_key[SEM_KEY_COUNT];

void init_sem(int id)
{
    semid = id;
    for (int i = 0; i < SEM_KEY_COUNT; i++)
    {
        sem_key[i] = semget(id, 1, 0777 | IPC_CREAT);
    }
}

void close_sem()
{
    for (int i = 0; i < SEM_KEY_COUNT; i++)
    {
        semctl(semid, sem_key[i], IPC_RMID);
    }
}

int main()
{
    int shmid;
    int *shm_ptr;
    int pid;
    int status;

    shmid = shmget(IPC_PRIVATE, sizeof(int), 0777 | IPC_CREAT);
    shm_ptr = shmat(shmid, NULL, 0);

    *shm_ptr = 0;

    pid = fork();
    if (pid == 0)
    {
        while (*shm_ptr == 0)
        {
            sleep(1);
        }

        *shm_ptr = 1;
        printf("Child process unlocked the lock\n");
    }
    else
    {
        while (*shm_ptr == 0)
        {
            sleep(1);
        }

        *shm_ptr = 0;
        printf("Parent process locked the lock\n");
    }

    wait(&status);
    close_sem();
    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}