//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <time.h>

#define SHM_SIZE 1024  // Shared memory size
#define MAX_HOARDERS 5 // Maximum number of hoarders

// Define the structure for shared data
struct SharedData {
    char message[SHM_SIZE];
    int current_hoarder;
};

// Function to simulate scavenger behavior
void scavenger(int shm_id) {
    // Attach to shared memory
    struct SharedData *data = (struct SharedData *)shmat(shm_id, NULL, 0);
    if (data == (void *)-1) {
        perror("Scavenger: shmat failed");
        exit(1);
    }

    // Scavenger process
    for (int i = 0; i < 10; i++) {
        // Simulate searching for supplies
        sleep(rand() % 3 + 1);
        sprintf(data->message, "Rescue supplies found by scavenger %d!", i);
        data->current_hoarder = i;

        // Notify other hoarders
        printf("Scavenger %d shares message: %s\n", i, data->message);
        sleep(rand() % 3 + 1);
    }

    // Detach from shared memory
    shmdt(data);
}

// Function to simulate hoarder behavior
void hoarder(int shm_id) {
    // Attach to shared memory
    struct SharedData *data = (struct SharedData *)shmat(shm_id, NULL, 0);
    if (data == (void *)-1) {
        perror("Hoarder: shmat failed");
        exit(1);
    }

    // Hoarder process
    while (1) {
        // Check for new messages
        if (strlen(data->message) > 0) {
            printf("Hoarder %d received message: %s\n", data->current_hoarder, data->message);
            memset(data->message, 0, SHM_SIZE); // Clear message after processing
            sleep(rand() % 3 + 1);
        }
        usleep(500000); // Sleep for half a second to prevent busy waiting
    }

    // Detach from shared memory
    shmdt(data);
}

int main() {
    srand(time(NULL));
    
    // Create shared memory
    int shm_id = shmget(IPC_PRIVATE, sizeof(struct SharedData), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("Main: shmget failed");
        exit(1);
    }

    // Initialize shared data
    struct SharedData *data = (struct SharedData *)shmat(shm_id, NULL, 0);
    if (data == (void *)-1) {
        perror("Main: shmat failed");
        exit(1);
    }
    memset(data->message, 0, SHM_SIZE);
    data->current_hoarder = 0;

    // Create scavenger process
    if (fork() == 0) {
        scavenger(shm_id);
        exit(0);
    }

    // Create hoarder processes
    for (int i = 0; i < MAX_HOARDERS; i++) {
        if (fork() == 0) {
            hoarder(shm_id);
            exit(0);
        }
    }

    // Parent process cleans up
    for (int i = 0; i < MAX_HOARDERS + 1; i++) {
        wait(NULL); // Wait for child processes to finish
    }

    // Cleanup shared memory
    shmdt(data);
    shmctl(shm_id, IPC_RMID, NULL); // Remove shared memory

    printf("\n\nIn this desolate world, all scavengers have finished their missions.\n");
    printf("The remaining hoarders now sift through the rubble in silence...\n");

    return 0;
}