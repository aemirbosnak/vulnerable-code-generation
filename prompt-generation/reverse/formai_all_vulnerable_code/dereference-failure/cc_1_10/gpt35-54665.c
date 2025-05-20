//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int i, shmid, status;
    key_t key;
    char *shm, *s;

    // Create a key for shared memory
    key = ftok("prog.c", 'R');

    // Allocate a shared memory segment
    shmid = shmget(key, 1024, 0666|IPC_CREAT);

    // Attach the shared memory segment to the process
    shm = shmat(shmid, 0, 0);

    // Write data to the shared memory segment
    s = (char *) shm;
    strcpy(s, "Hello, world!");

    // Fork a child process
    pid_t pid = fork();

    // Child process
    if (pid == 0) {
        // Sleep for 5 seconds
        sleep(5);

        // Read data from the shared memory segment
        s = (char *) shm;
        printf("%s\n", s);

        // Detach the shared memory segment from the process
        shmdt(shm);

        // Exit the child process
        exit(0);
    }

    // Parent process
    else if (pid > 0) {
        // Wait for the child process to complete
        waitpid(pid, &status, 0);

        // Detach the shared memory segment from the process
        shmdt(shm);

        // Deallocate the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    // Error creating child process
    else {
        fprintf(stderr, "Failed to create child process\n");
        exit(1);
    }

    return 0;
}