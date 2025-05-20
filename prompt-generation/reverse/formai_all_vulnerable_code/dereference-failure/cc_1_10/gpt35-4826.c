//FormAI DATASET v1.0 Category: Interprocess communication ; Style: all-encompassing
/* This program demonstrates an example of Interprocess communication in C. 
   This program creates two processes and one of the processes sends a message 
   to the other through shared memory. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 1234

int main(void)
{
    pid_t pid;
    int shm_id;
    int *shm_ptr;
    int status;

    /* Create shared memory segment */
    shm_id = shmget(SHM_KEY, sizeof(int), IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    /* Attach shared memory segment */
    shm_ptr = (int *) shmat(shm_id, NULL, 0);
    if (shm_ptr == (int *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    /* Fork a child process */
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* Child process */
        printf("Child process is writing to shared memory.\n");
        *shm_ptr = 42;
        exit(EXIT_SUCCESS);
    } else {
        /* Parent process */
        printf("Parent process is waiting for child to write to shared memory.\n");
        wait(&status);
        printf("Parent process read %d from shared memory.\n", *shm_ptr);
    }

    /* Detach shared memory segment */
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    /* Delete shared memory segment */
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}