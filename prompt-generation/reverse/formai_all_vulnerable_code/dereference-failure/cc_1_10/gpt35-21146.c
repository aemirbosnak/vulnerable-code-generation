//FormAI DATASET v1.0 Category: Interprocess communication ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(void) {
    pid_t pid;
    key_t key;
    int shmid;
    char *shm, *s;

    // Create a new shared memory segment with read and write permissions
    key = ftok(".", 'c');
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to our address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fork a new process to communicate with
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process: write a message to the shared memory segment
        sprintf(shm, "Hello, World!");
        exit(0);
    } else {
        // Parent process: wait for the child to finish
        wait(NULL);
        printf("Parent process received message: ");
        
        // Read the message from the shared memory segment and print it
        for (s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');
        
        // Detach and remove the shared memory segment
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
        exit(0);
    }
}