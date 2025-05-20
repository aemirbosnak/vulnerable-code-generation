//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shmid;
    void *shmptr;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shmptr = shmat(shmid, 0, 0);
    if (shmptr == (void*) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    char *msg = (char*) shmptr;
    strcpy(msg, "Hello, world!");

    // Create child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        sleep(2);

        // Access shared memory
        char *child_msg = (char*) shmptr;
        printf("Child: %s\n", child_msg);

        // Detach shared memory segment
        if (shmdt(shmptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process
        sleep(1);

        // Modify shared memory
        char *parent_msg = (char*) shmptr;
        strcat(parent_msg, " from parent!");

        // Detach shared memory segment
        if (shmdt(shmptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Wait for child process to exit
        waitpid(pid, NULL, 0);
    }

    return 0;
}