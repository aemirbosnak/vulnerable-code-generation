//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    // Attach to shared memory segment
    shm = (char *)shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        printf("Error attaching to shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        // Child process writes to shared memory
        sleep(1);
        sprintf(shm, "Hello from child process (%d)!", getpid());
    } else {
        // Parent process reads from shared memory
        sleep(2);
        printf("Shared memory content: %s\n", shm);
    }

    // Detach from shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error detaching from shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    return 0;
}