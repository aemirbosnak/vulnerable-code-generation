//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>

typedef struct shared_memory_segment {
    int value;
    char message[100];
} shared_memory_segment;

int main(int argc, char *argv[]) {
    // Declare the shared memory segment.
    shared_memory_segment *shared_memory = NULL;

    // Get the shared memory segment ID.
    key_t shared_memory_id = ftok("/tmp", 1234);
    if (shared_memory_id == -1) {
        perror("ftok");
        return 1;
    }

    // Create the shared memory segment.
    int shared_memory_segment_id = shmget(shared_memory_id, sizeof(shared_memory_segment), IPC_CREAT | 0666);
    if (shared_memory_segment_id == -1) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory segment to the current process.
    shared_memory = (shared_memory_segment *)shmat(shared_memory_segment_id, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat");
        return 1;
    }

    // Initialize the shared memory segment.
    shared_memory->value = 0;
    strcpy(shared_memory->message, "Hello, world!");

    // Print the initial value of the shared memory segment.
    printf("Initial value of the shared memory segment: %d\n", shared_memory->value);

    // Print the initial message of the shared memory segment.
    printf("Initial message of the shared memory segment: %s\n", shared_memory->message);

    // Update the value and message of the shared memory segment.
    shared_memory->value = 1;
    strcpy(shared_memory->message, "Goodbye, world!");

    // Print the updated value of the shared memory segment.
    printf("Updated value of the shared memory segment: %d\n", shared_memory->value);

    // Print the updated message of the shared memory segment.
    printf("Updated message of the shared memory segment: %s\n", shared_memory->message);

    // Detach the shared memory segment from the current process.
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        return 1;
    }

    // Delete the shared memory segment.
    if (shmctl(shared_memory_segment_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return 1;
    }

    return 0;
}