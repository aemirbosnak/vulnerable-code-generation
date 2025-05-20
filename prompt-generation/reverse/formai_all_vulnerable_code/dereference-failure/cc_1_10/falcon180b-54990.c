//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100

int shmid;
char *shmaddr;
char *shmptr;

int main() {
    int i;
    pid_t pid;
    int status;
    char *ptr;

    // Create shared memory segment
    if ((shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0777)) == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    if ((shmaddr = shmat(shmid, NULL, 0)) == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i) = '\0';
    }

    // Fork child process
    if ((pid = fork()) == 0) {
        // Child process
        for (i = 0; i < SIZE; i++) {
            *(shmptr + i) = 'A';
        }
        printf("Child process completed\n");
        exit(0);
    } else {
        // Parent process
        wait(&status);
        printf("Child process terminated\n");
    }

    // Detach shared memory segment from process
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