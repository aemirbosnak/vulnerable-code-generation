//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_MSG_LEN 1024
#define SHM_NAME "my_shared_mem"

// Structure to hold the shared data
struct shared_data {
    char message[MAX_MSG_LEN];
    int counter;
};

// Function to create and attach to a shared memory segment
void create_shm(void) {
    int shmid;
    struct shared_data *shmd;

    // Create a new shared memory segment
    shmid = shmget(SHM_NAME, sizeof(struct shared_data), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Attach to the shared memory segment
    shmd = shmat(shmid, NULL, 0);
    if (shmd == (void *) -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    // Set up the shared data structure
    shmd->counter = 0;
    strcpy(shmd->message, "Hello, world!");
}

// Function to write to the shared memory segment
void write_shm(const char *message) {
    int shmid;
    struct shared_data *shmd;

    // Get the shared memory segment ID
    shmid = shmget(SHM_NAME, sizeof(struct shared_data), IPC_PRIVATE);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Attach to the shared memory segment
    shmd = shmat(shmid, NULL, 0);
    if (shmd == (void *) -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    // Write the message to the shared memory segment
    strcpy(shmd->message, message);
}

// Function to read from the shared memory segment
const char *read_shm(void) {
    int shmid;
    struct shared_data *shmd;

    // Get the shared memory segment ID
    shmid = shmget(SHM_NAME, sizeof(struct shared_data), IPC_PRIVATE);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Attach to the shared memory segment
    shmd = shmat(shmid, NULL, 0);
    if (shmd == (void *) -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    // Read the message from the shared memory segment
    return shmd->message;
}

int main(void) {
    // Create and attach to the shared memory segment
    create_shm();

    // Write a message to the shared memory segment
    write_shm("Hello, world!");

    // Read the message from the shared memory segment
    const char *message = read_shm();
    printf("Received message: %s\n", message);

    // Wait for the child process to finish
    wait(NULL);

    return 0;
}