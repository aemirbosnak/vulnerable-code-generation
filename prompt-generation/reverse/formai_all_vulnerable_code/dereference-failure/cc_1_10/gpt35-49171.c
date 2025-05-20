//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    key_t key; 
    int shmid;
    char *shm, *s;

    key = 9876;

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) { 
        perror("shmget"); 
        exit(1); 
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) { // Attach to the shared memory segment
        perror("shmat"); 
        exit(1); 
    }

    s = shm;

    // Write data to shared memory segment
    for (char c = 'a'; c <= 'z'; c++)
        *s++ = c;

    *s = '\0';

    // Wait for the other process to read from shared memory
    while (*shm != '*') 
        sleep(1); 

    // Read data from shared memory and print to console
    for (s = shm; *s != '\0'; s++)
        putchar(*s);

    putchar('\n');

    // Detach from the shared memory segment
    shmdt(shm);

    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}