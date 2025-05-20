//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmaddr;
    key_t key;
    int i;
    pid_t pid;

    // Create a shared memory segment
    key = ftok("shm_key", 65); // ftok returns a key based on the filename and a project id
    if ((shmid = shmget(key, SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize the shared memory with a string
    strcpy(shmaddr, "Hello, world!");

    // Fork a child process
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1); // Allow time for parent to complete initialization
        for (i = 0; i < SIZE; i++) {
            shmaddr[i] = 'x'; // Modify the shared memory
        }
        exit(0);
    } else {
        // Parent process
        sleep(2); // Allow time for child to modify shared memory
        printf("Shared memory contains: %s\n", shmaddr);
        exit(0);
    }
}