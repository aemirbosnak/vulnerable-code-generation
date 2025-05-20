//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHMSIZE 100

void *childProcess(void *arg);
void *parentProcess(void *arg);

int main()
{
    key_t key;
    int shmid;
    char *shmaddr;
    pthread_t thread1, thread2;

    // Creating a shared memory segment
    key = ftok("sharedmemory", 'a');
    shmid = shmget(key, SHMSIZE, IPC_CREAT | IPC_EXCL | 0666);

    if (shmid < 0)
    {
        printf("Shared memory already exists, connecting to it...\n");

        // If shared memory segment already exists, try to connect to it
        shmid = shmget(key, SHMSIZE, 0666);

        if (shmid < 0)
        {
            perror("Error connecting to shared memory");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("Shared memory created with id: %d\n", shmid);
    }

    // Attaching shared memory to process address space
    shmaddr = shmat(shmid, NULL, 0);

    if (shmaddr == (char *) -1)
    {
        perror("Error attaching shared memory");
        exit(EXIT_FAILURE);
    }

    printf("Address space attached to shared memory at address: %p\n", shmaddr);

    // Initializing shared memory segment
    memset(shmaddr, 0, SHMSIZE);

    // Creating threads
    pthread_create(&thread1, NULL, childProcess, (void *) shmaddr);
    pthread_create(&thread2, NULL, parentProcess, (void *) shmaddr);

    // Waiting for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Detaching shared memory segment
    shmdt(shmaddr);

    // Deleting shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

void *childProcess(void *arg)
{
    char *shmaddr = (char *) arg;

    // Writing message to shared memory
    strcpy(shmaddr, "Hello from child process!");

    printf("Child process wrote message to shared memory: %s\n", shmaddr);

    pthread_exit(NULL);
}

void *parentProcess(void *arg)
{
    char *shmaddr = (char *) arg;

    sleep(1);

    // Reading message from shared memory
    printf("Parent process read message from shared memory: %s\n", shmaddr);

    pthread_exit(NULL);
}