//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

#define SIZE 10

int main() {
    int shmid;
    key_t key;
    char *shm;
    int i;

    // Create shared memory
    key = ftok(".", 'a');
    shmid = shmget(key, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    // Attach shared memory
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SIZE; i++) {
        *(shm + i) = 0;
    }

    // Fork process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        for (i = 0; i < SIZE; i++) {
            *(shm + i) = i * 2;
        }
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        for (i = 0; i < SIZE; i++) {
            printf("%d ", *(shm + i));
        }
        printf("\n");
    }

    // Detach shared memory
    if (shmdt(shm) == -1) {
        printf("Error detaching shared memory\n");
        exit(1);
    }

    // Delete shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error deleting shared memory\n");
        exit(1);
    }

    return 0;
}