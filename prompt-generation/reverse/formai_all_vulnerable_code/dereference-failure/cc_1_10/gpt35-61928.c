//FormAI DATASET v1.0 Category: Interprocess communication ; Style: irregular
// Ahoy mateys! Are ye looking for a unique example program on Interprocess Communication in C? Well, shiver me timbers, I've got just the thing for ye!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // Aye, set the size of our shared memory

int main()
{
    pid_t pid;  // Declare our pirate captain pid
    int shmid, status;  // Declare the IDs of our shared memory and process status respectively
    char *shm, *s;  // Declare our shared memory pointer and a temp pointer

    // Step 1: Create our shared memory segment
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("Arrr, could not create shared memory");
        exit(1);
    }

    // Step 2: Attach to the shared memory
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("Arrr, could not attach to shared memory");
        exit(1);
    }

    // Step 3: Set the default value of our shared memory to ' '
    for (s = shm; *s != NULL; s++)
        *s = ' ';

    // Step 4: Fork a child process
    if ((pid = fork()) < 0) {
        perror("Arrr, could not create child process");
        exit(1);
    }

    // Step 5: In the child process, write to the shared memory and exit
    else if (pid == 0) {
        printf("ARRR, Ye be an example message to the parent process!\n");
        for (s = shm; *s != NULL; s++)
            *s = 'A' + ((*s - 'A' + 1) % 26);
        exit(0);  // Ye be free, child process!
    }

    // Step 6: In the parent process, wait for child process to finish writing
    else {
        wait(&status);  // This here be where we wait, arrr!
        printf("Message received from child process: ");
        for (s = shm; *s != NULL; s++)
            putchar(*s);
        printf("\n");
    }

    // Step 7: Detach and remove our shared memory
    if (shmdt(shm) < 0) {
        perror("Arrr, could not detach shared memory");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        perror("Arrr, could not remove shared memory");
        exit(1);
    }

    return 0;  // Arrr, we be finished ye mateys!
}