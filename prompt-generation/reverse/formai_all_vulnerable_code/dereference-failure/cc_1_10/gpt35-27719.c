//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHMSZ 27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate shared memory key
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write message to shared memory
    memcpy(shm, "Hello World!", strlen("Hello World!"));

    // Read message from shared memory
    s = shm;
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    // Update shared memory message
    for (s = shm; *s != '\0'; s++) {
        *s = toupper(*s);
    }

    // Read updated message from shared memory
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    // Detach shared memory segment from process
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Deallocate shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}