//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 2048
#define MAX_MESS_LENGTH 100

void survivor(int *shm_ptr) {
    char message[MAX_MESS_LENGTH];

    while (1) {
        // Read message from shared memory
        if (shm_ptr[0] != 0) {
            printf("Survivor, receiving message: %s\n", (char *)(shm_ptr + 1));
            shm_ptr[0] = 0; // Reset message indicator
        }

        // Compose a new message
        printf("Survivor, send your message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0'; // Remove newline character
        
        if (strcmp(message, "exit") == 0) {
            break; // Exit if the command is given
        }

        // Write to shared memory
        strcpy((char *)(shm_ptr + 1), message);
        shm_ptr[0] = 1; // Set message indicator
        usleep(500000); // Simulate thinking and changing location
    }
}

void soldier(int *shm_ptr) {
    while (1) {
        // Check for incoming messages
        if (shm_ptr[0] != 0) {
            printf("Soldier, received message: %s\n", (char *)(shm_ptr + 1));
            shm_ptr[0] = 0; // Reset message indicator
        }

        // Soldier keeps scanning the area and doing tasks
        printf("Soldier scanning for threats...\n");
        usleep(1000000); // Simulate soldier scanning
    }
}

int main() {
    int shmid;
    int *shm_ptr;

    // Create a shared memory segment
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to our process's address space
    shm_ptr = (int *)shmat(shmid, NULL, 0);
    if (shm_ptr == (int *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    shm_ptr[0] = 0; // Message indicator

    // Fork a process for soldier
    if (fork() == 0) {
        // Child Process - Soldier
        soldier(shm_ptr);
        exit(0);
    }

    // Parent Process - Survivor
    survivor(shm_ptr);

    // Cleanup: Detach and delete shared memory
    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);

    // Wait for the soldier to exit
    wait(NULL);
    printf("Survivor has exited, soldier has been freed.\n");

    return 0;
}