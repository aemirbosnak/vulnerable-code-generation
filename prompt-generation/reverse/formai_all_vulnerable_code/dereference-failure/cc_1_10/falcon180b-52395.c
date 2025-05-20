//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complete
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
    void *shmaddr;
    char *shmptr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *)-1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    shmptr = (char *)shmaddr;
    for (int i = 0; i < SHM_SIZE; i++) {
        shmptr[i] = 0;
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process writes to shared memory
        for (int i = 0; i < SHM_SIZE; i++) {
            shmptr[i] = 'A' + i;
        }
        printf("Child process wrote to shared memory\n");
    } else {
        // Parent process reads from shared memory
        for (int i = 0; i < SHM_SIZE; i++) {
            printf("%c ", shmptr[i]);
        }
        printf("\n");
    }

    // Detach shared memory segment
    if (shmdt(shmaddr) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error deleting shared memory segment\n");
        exit(1);
    }

    return 0;
}