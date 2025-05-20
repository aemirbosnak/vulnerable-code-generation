//FormAI DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int shmid, pid;
    char *shmaddr;
    key_t key;

    // Generate unique key for shared memory
    if ((key = ftok(".", 'a')) < 0) {
        perror("ftok");
        exit(1);
    }

    // Create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to local address space
    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fork child process
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { // Child process
        char *message = "Hello, parent!";
        strncpy(shmaddr, message, SHM_SIZE);
        exit(0);
    } else { // Parent process
        wait(NULL);
        printf("Message from child: %s\n", shmaddr);
    }

    // Detach and remove shared memory segment
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}