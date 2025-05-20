//FormAI DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;
    char message[SHM_SIZE];

    // generate a unique key for shared memory using ftok()
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(1);
    }

    // create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment to the process address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write to shared memory
    printf("Enter a message: ");
    fgets(message, SHM_SIZE, stdin);
    strncpy(shm, message, SHM_SIZE);

    // wait for reader process to read data from shared memory
    while (*shm != '*')
        sleep(1);

    // detach shared memory from process address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}