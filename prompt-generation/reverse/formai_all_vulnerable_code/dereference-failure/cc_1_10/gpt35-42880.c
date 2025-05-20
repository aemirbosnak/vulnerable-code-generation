//FormAI DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    /* Generate a unique key for shared memory */
    if ((key = ftok("ipc_prog", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    /* Create a shared memory segment with 1024 bytes */
    if ((shmid = shmget(key, 1024, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /* Attach the shared memory segment to our process's address space */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /* Let's write something to the shared memory segment */
    s = shm;
    for (char c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    /* Wait until the other process writes something to the shared memory segment */
    while (*shm != '*') {
        sleep(1);
    }

    /* Print whatever the other process has written to the shared memory segment */
    printf("Other process wrote: %s\n", shm);

    /* Detach the shared memory segment from our process's address space */
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