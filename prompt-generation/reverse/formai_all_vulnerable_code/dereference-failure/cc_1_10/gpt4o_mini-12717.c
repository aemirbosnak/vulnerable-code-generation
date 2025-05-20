//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SHAREDMEM_SIZE 256

// A simple function to write a message to shared memory
void write_to_shared_memory(char *shm_addr, const char *message) {
    strncpy(shm_addr, message, SHAREDMEM_SIZE);
    shm_addr[SHAREDMEM_SIZE - 1] = '\0';  // Ensure null-terminated
}

// A simple function to read a message from shared memory
void read_from_shared_memory(char *shm_addr) {
    printf("Message from shared memory: %s\n", shm_addr);
}

int main() {
    // Create a shared memory segment
    int shm_fd;
    char *shm_addr;

    // Use shm_open to create and open a new shared memory object
    shm_fd = shm_open("/my_shared_memory", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // Configure the size of shared memory segment
    if (ftruncate(shm_fd, SHAREDMEM_SIZE) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory segment to the process's address space
    shm_addr = mmap(0, SHAREDMEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Fork a new process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid > 0) {
        // Parent process
        const char *message = "Hello from the parent process!";
        write_to_shared_memory(shm_addr, message);
        printf("Parent process: message written to shared memory.\n");
        wait(NULL); // Wait for the child process to finish
    } else {
        // Child process
        sleep(1); // Ensure the parent writes first
        read_from_shared_memory(shm_addr);
        printf("Child process is exiting.\n");
    }

    // Cleanup: Unlink and close the shared memory
    if (shm_unlink("/my_shared_memory") == -1) {
        perror("shm_unlink");
        exit(EXIT_FAILURE);
    }

    munmap(shm_addr, SHAREDMEM_SIZE);
    close(shm_fd);

    return 0;
}