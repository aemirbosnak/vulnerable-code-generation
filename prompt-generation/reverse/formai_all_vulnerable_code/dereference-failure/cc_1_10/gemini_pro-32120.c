//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Create a shared memory segment with a key and a size
int create_shared_memory(key_t key, size_t size) {
    int shm_id = shmget(key, size, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    return shm_id;
}

// Attach a shared memory segment to the current process
void *attach_shared_memory(int shm_id) {
    void *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    return shm_ptr;
}

// Detach a shared memory segment from the current process
void detach_shared_memory(void *shm_ptr) {
    if (shmdt(shm_ptr) < 0) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
}

// Destroy a shared memory segment
void destroy_shared_memory(int shm_id) {
    if (shmctl(shm_id, IPC_RMID, NULL) < 0) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Create a shared memory segment with a key and a size
    key_t key = ftok("shared_memory.c", 'A');
    int shm_id = create_shared_memory(key, 1024);

    // Attach the shared memory segment to the current process
    void *shm_ptr = attach_shared_memory(shm_id);

    // Write a message to the shared memory segment
    strcpy(shm_ptr, "Hello, world!");

    // Detach the shared memory segment from the current process
    detach_shared_memory(shm_ptr);

    // Fork a child process
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process
        
        // Attach the shared memory segment to the child process
        shm_ptr = attach_shared_memory(shm_id);

        // Read the message from the shared memory segment
        printf("Child process: %s\n", shm_ptr);

        // Detach the shared memory segment from the child process
        detach_shared_memory(shm_ptr);
    } else {
        // Parent process
        
        // Wait for the child process to finish
        wait(NULL);

        // Destroy the shared memory segment
        destroy_shared_memory(shm_id);
    }

    return EXIT_SUCCESS;
}