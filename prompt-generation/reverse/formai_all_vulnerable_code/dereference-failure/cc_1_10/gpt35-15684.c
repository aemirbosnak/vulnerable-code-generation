//FormAI DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

#define SHM_SIZE 1024

void handler(int sig);

int main()
{
    int shmid;
    char *shm, *s;

    // Create a shared memory segment
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process's address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Setup signal handler to detach shared memory segment on termination
    signal(SIGINT, handler);

    // Read input from standard input and write to shared memory segment
    printf("Enter a message:\n");
    for (s = shm; (*s = getchar()) != '\n'; s++);

    *s = '\0'; // Terminate the string with a null character

    // Wait for a process to read the shared memory segment
    while (*shm != '*')
        sleep(1);

    // Detach the shared memory segment from the process's address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Destroy the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}

void handler(int sig)
{
    exit(0);
}