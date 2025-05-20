//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHARED_MEMORY_SIZE 1024 // in bytes

// Create a shared memory segment
int create_shared_memory(key_t key) {
    int shm_id = shmget(key, SHARED_MEMORY_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    return shm_id;
}

// Attach to a shared memory segment
void *attach_to_shared_memory(int shm_id) {
    void *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    return shm_ptr;
}

// Detach from a shared memory segment
void detach_from_shared_memory(void *shm_ptr) {
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
}

// Remove a shared memory segment
void remove_shared_memory(int shm_id) {
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }
}

// Write data to shared memory
void write_to_shared_memory(void *shm_ptr, char *data) {
    strcpy(shm_ptr, data);
}

// Read data from shared memory
char *read_from_shared_memory(void *shm_ptr) {
    return (char *)shm_ptr;
}

int main() {
    // Generate a unique key for the shared memory segment
    key_t key = ftok(".", 's');

    // Create a shared memory segment
    int shm_id = create_shared_memory(key);

    // Attach to the shared memory segment
    void *shm_ptr = attach_to_shared_memory(shm_id);

    // Write data to shared memory
    char *data = "Hello, world!";
    write_to_shared_memory(shm_ptr, data);

    // Read data from shared memory
    char *read_data = read_from_shared_memory(shm_ptr);
    printf("Read data from shared memory: %s\n", read_data);

    // Detach from the shared memory segment
    detach_from_shared_memory(shm_ptr);

    // Remove the shared memory segment
    remove_shared_memory(shm_id);

    return EXIT_SUCCESS;
}