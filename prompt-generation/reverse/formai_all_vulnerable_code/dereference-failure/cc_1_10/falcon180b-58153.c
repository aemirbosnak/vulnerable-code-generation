//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

int main() {
    int shmid, i;
    int *shmaddr;
    pid_t pid;
    char input[100];

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void*)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory with default values
    for (i = 0; i < SIZE; i++) {
        *(shmaddr + i) = 0;
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    // Parent process writes to shared memory
    if (pid > 0) {
        printf("Parent process\n");
        while (1) {
            printf("Enter a number to write to shared memory: ");
            scanf("%d", &i);
            *(shmaddr + i) = i;
        }
    }

    // Child process reads from shared memory
    else {
        printf("Child process\n");
        while (1) {
            printf("Shared memory contents:\n");
            for (i = 0; i < SIZE; i++) {
                printf("%d ", *(shmaddr + i));
            }
            printf("\n");
            sleep(1);
        }
    }

    return 0;
}