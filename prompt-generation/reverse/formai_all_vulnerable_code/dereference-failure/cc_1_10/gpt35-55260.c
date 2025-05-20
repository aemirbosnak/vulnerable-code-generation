//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    pid_t pid;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678; // Set key for shared memory

    // Create shared memory  
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fork Child process
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }

    // Parent Process
    if (pid != 0) {
        printf("Parent Process: Writing to shared memory...\n");

        // Write message to shared memory
        strcpy(shm, "Hello from Parent!");

        // Wait for child to terminate
        wait(NULL);

        printf("Parent Process: Message received from Child: %s\n", shm);

        // Detach from shared memory
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Remove shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }

        printf("Parent Process: Done.\n");
        exit(0);
    }
    // Child Process
    else {
        printf("Child Process: Waiting for message...\n");

        // Wait for message from parent process
        while (*shm == '\0')
            sleep(1);

        printf("Child Process: Message received: %s\n", shm);

        // Reverse the message received
        int len = strlen(shm);
        for (int i = 0; i < len/2; i++) {
            char temp = shm[i];
            shm[i] = shm[len - i - 1];
            shm[len - i - 1] = temp;  
        }

        printf("Child Process: Reversed message: %s\n", shm);

        // Detach from shared memory
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        printf("Child Process: Done.\n");
        exit(0);
    }

    return 0;
}