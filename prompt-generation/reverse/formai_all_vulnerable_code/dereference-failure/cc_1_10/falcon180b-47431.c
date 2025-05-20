//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100
#define KEY 1234

int main() {
    int shmid;
    char *shmptr;
    int i;

    // Create shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i) = 0;
    }

    // Fork child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        sleep(2);

        // Modify shared memory segment
        for (i = 0; i < SIZE; i++) {
            *(shmptr + i) = i;
        }

        printf("Child process completed\n");
    } else {
        // Parent process
        sleep(1);

        // Print shared memory segment
        printf("Shared memory segment:\n");
        for (i = 0; i < SIZE; i++) {
            printf("%d ", *(shmptr + i));
        }
        printf("\n");

        // Detach shared memory segment
        if (shmdt(shmptr) == -1) {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment\n");
            exit(1);
        }
    }

    return 0;
}