//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10
#define SHM_KEY 5678

int main() {
    int shmid = -1;
    char *shmaddr = NULL;
    char *shmptr;
    int i;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SIZE * sizeof(char), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: shmget failed\n");
        exit(1);
    }

    // Attach shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        printf("Error: shmat failed\n");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SIZE; i++) {
        strcpy(shmaddr + i * sizeof(char), " ");
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error: fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process - write to shared memory
        shmptr = shmaddr;
        for (i = 0; i < SIZE; i++) {
            strcpy(shmptr + i * sizeof(char), "X");
        }
        sleep(2);
    } else {
        // Parent process - read from shared memory
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            printf("%c", shmaddr[i]);
        }
    }

    // Detach shared memory segment
    if (shmdt(shmaddr) == -1) {
        printf("Error: shmdt failed\n");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error: shmctl failed\n");
        exit(1);
    }

    return 0;
}