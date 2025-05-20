//FormAI DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <signal.h>

#define SHM_NAME "/my_shared_memory"
#define SHM_SIZE 4096

int h_shmem;

void handle_signal(int signal) {
    if (signal == SIGINT) { // Catch the interrupt signal
        printf("Terminating...\n");
        // close the shared memory
        if (munmap(NULL, SHM_SIZE) == -1) {
            perror("Error closing shared memory");
            exit(EXIT_FAILURE);
        }
        if (shm_unlink(SHM_NAME) == -1) {
            perror("Error unlinking shared memory");
            exit(EXIT_FAILURE);
        }
        printf("Shared memory closed successfully\n");
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char *argv[]) {

    struct sigaction sa;
    // Initialize the handler function for SIGINT signal
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error initializing signal handler");
        exit(EXIT_FAILURE);
    }

    char *shm_ptr; // pointer to shared memory
    // Create the shared memory segment
    h_shmem = shm_open(SHM_NAME, O_CREAT | O_RDWR, S_IRWXU);
    if (h_shmem == -1) {
        perror("Error creating shared memory segment");
        exit(EXIT_FAILURE);
    }

    // Set shared memory segment size
    if (ftruncate(h_shmem, SHM_SIZE) == -1) {
        perror("Error setting shared memory size");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory segment to process address space
    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, h_shmem, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("Error mapping shared memory");
        exit(EXIT_FAILURE);
    }

    // Wait for data in shared memory
    while (1) {
        sleep(1); // wait for 1 second
        if (strlen(shm_ptr) > 0) {
            printf("Received data: %s\n", shm_ptr);
            memset(shm_ptr, 0, SHM_SIZE); // clear the shared memory
        }
    }

    return 0;
}