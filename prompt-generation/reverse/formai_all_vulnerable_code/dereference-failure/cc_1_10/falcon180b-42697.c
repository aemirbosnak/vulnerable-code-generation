//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    void *shmaddr;
    pid_t childpid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Fork child process
    childpid = fork();
    if (childpid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (childpid == 0) {
        // Child process writes to shared memory
        char *message = "Hello, world!";
        strcpy(shmaddr, message);
        printf("Child process wrote to shared memory\n");
    } else {
        // Parent process reads from shared memory
        char buffer[SHM_SIZE];
        memcpy(buffer, shmaddr, SHM_SIZE);
        printf("Parent process read from shared memory: %s\n", buffer);
    }

    // Detach from shared memory segment
    if (shmdt(shmaddr) == -1) {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment\n");
        exit(1);
    }

    return 0;
}