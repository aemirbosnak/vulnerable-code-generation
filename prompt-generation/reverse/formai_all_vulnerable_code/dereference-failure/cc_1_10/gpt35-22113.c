//FormAI DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a key for shared memory
    key = ftok(".", 'S');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment
    shm = (char *) shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write data to the shared memory segment
    s = shm;
    for (char c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = 0;

    // Wait for the other process to read the data
    while (*shm != '*') {
        sleep(1);
    }

    printf("Data read by other process: %s\n", shm);

    // Detach the shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}