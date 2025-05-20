//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: futuristic
// Welcome to the year 20XX! Interprocess communication just got a lot more... cybernetic.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>

// Introducing the "CyberComm" interprocess communication framework!
#define CYBER_COMM_KEY 123456 // Use a futuristic numeric key for intergalactic communication
#define CYBER_COMM_SIZE 1024 // Allocate a generous buffer for interstellar data exchange

// Prepare for warp speed data transfer!
int main() {
    // Let's create a shared memory segment, where processes can meet in the ether.
    int shmId = shmget(CYBER_COMM_KEY, CYBER_COMM_SIZE, IPC_CREAT | 0666);
    if (shmId < 0) {
        perror("Error creating shared memory segment. Aborting mission!");
        return EXIT_FAILURE;
    }

    // Time to fork a new process! Let's call it "Process B".
    pid_t pid = fork();
    if (pid < 0) {
        perror("Error forking process. No intergalactic travel for us today!");
        return EXIT_FAILURE;
    }

    // Great! Process B is ready. Let's attach it to the shared memory segment.
    void *sharedData = shmat(shmId, NULL, 0);
    if (sharedData == (void *)-1) {
        perror("Error attaching to shared memory segment. Intergalactic communication disrupted!");
        return EXIT_FAILURE;
    }

    // Now, let's imagine we're in a spaceship and want to send a message to another spaceship.
    // (In this case, Process B is our "other spaceship")
    if (pid == 0) { // Hey, we're in Process B!
        // Let's send a message: "Greetings from the future!"
        strcpy(sharedData, "Greetings from the future!");
        printf("Process B: Message sent. Prepare for intergalactic reception!\n");
    } else { // We're in the original process (Process A)
        // Wait for the message to arrive, like a galactic mail carrier.
        sleep(1); // Give Process B some time to prepare its message
        printf("Process A: Receiving message...\n");
        printf("%s\n", sharedData); // And voilà! The message is received!
    }

    // Mission accomplished! Time to clean up.
    shmdt(sharedData); // Detach from the shared memory segment
    shmctl(shmId, IPC_RMID, NULL); // Destroy the shared memory segment
    wait(NULL); // Wait for Process B to finish its interstellar journey
    return EXIT_SUCCESS;
}