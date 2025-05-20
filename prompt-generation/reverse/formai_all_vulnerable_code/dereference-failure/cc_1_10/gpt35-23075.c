//FormAI DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    // Set up the shared memory segment
    if ((key = ftok("bananas", 'R')) == -1) { // get the key
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) { // create the shared memory segment
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) { // attach the shared memory segment
        perror("shmat");
        exit(1);
    }

    // Write to the shared memory segment
    strncpy(shm, "Hello, shared world!", SHM_SIZE);

    // Read from the shared memory segment
    s = shm;
    s += strlen("Hello, shared world!");
    *s = '\0'; // null terminate the string

    printf("%s\n", shm); // print out the message

    // Detach the shared memory segment
    shmdt(shm);

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}