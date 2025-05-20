//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
/*
 * This program demonstrates how to use interprocess communication (IPC) to send
 * messages between processes using shared memory in Linux.
 *
 * Author: Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(void)
{
    int shmid;
    key_t key;
    char *shm;
    char *s;

    /* Generate a key for the shared memory segment */
    if ((key = ftok("/dev/null", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    /* Create the shared memory segment */
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    /* Attach the shared memory segment */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /* Write a message to the shared memory segment */
    s = shm;
    for (char* p = "Hello, world!"; *p != 0; p++)
        *s++ = *p;
    *s = 0;

    /* Print out the message from the shared memory segment */
    printf("%s\n", shm);

    /* Detach the shared memory segment */
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    /* Delete the shared memory segment */
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}