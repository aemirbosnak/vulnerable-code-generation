//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

// Structure for shared memory
struct shared_memory {
    int count;
    char buffer[BUFFER_SIZE];
};

int main() {
    int shmid = 0;
    key_t key = ftok("shm_example.c", 65);
    struct shared_memory *shm = NULL;

    // Create shared memory
    if ((shmid = shmget(key, sizeof(struct shared_memory), IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    if ((shm = shmat(shmid, NULL, 0)) == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    shm->count = 0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        shm->buffer[i] = '\0';
    }

    // Fork child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        for (int i = 0; i < 10; i++) {
            sprintf(shm->buffer, "Child wrote: %d\n", i);
            shm->count++;
        }
        exit(0);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);

        for (int i = 0; i < shm->count; i++) {
            printf("Parent read: %s", shm->buffer[i]);
        }
    } else {
        // Error forking
        perror("fork");
        exit(1);
    }

    return 0;
}