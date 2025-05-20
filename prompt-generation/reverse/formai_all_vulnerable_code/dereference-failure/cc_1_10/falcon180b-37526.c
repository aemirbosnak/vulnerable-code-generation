//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmptr;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = (char *)shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    strcpy(shmptr, "Hello, World!");

    // Fork child process
    pid_t pid = fork();
    if (pid == 0) {
        sleep(1);

        // Child process writes to shared memory
        strcat(shmptr, " from the child!");
    } else {
        sleep(2);

        // Parent process reads from shared memory
        char buf[SHM_SIZE];
        memcpy(buf, shmptr, SHM_SIZE);
        printf("Shared memory content: %s\n", buf);
    }

    return 0;
}