//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <fcntl.h>

#define SHM_NAME "random_shared_mem"
#define SHM_SIZE 4096

// Structure to store shared data
struct shared_data {
    char message[1024];
    int counter;
};

// Function to create and map shared memory
void create_shm(void) {
    int shm_fd;
    struct shared_data *shm_ptr;

    shm_fd = shmget(SHM_NAME, SHM_SIZE, IPC_CREAT | 0644);
    if (shm_fd == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }

    // Initialize shared data
    shm_ptr->message[0] = 'H';
    shm_ptr->message[1] = 'E';
    shm_ptr->message[2] = 'L';
    shm_ptr->message[3] = 'L';
    shm_ptr->counter = 0;
}

// Function to write to shared memory
void write_to_shm(const char *message) {
    int shm_fd;
    struct shared_data *shm_ptr;

    shm_fd = shmget(SHM_NAME, SHM_SIZE, IPC_PRIVATE | 0644);
    if (shm_fd == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }

    strcpy(shm_ptr->message, message);
    shm_ptr->counter++;
}

// Function to read from shared memory
char *read_from_shm(void) {
    int shm_fd;
    struct shared_data *shm_ptr;

    shm_fd = shmget(SHM_NAME, SHM_SIZE, IPC_PRIVATE | 0644);
    if (shm_fd == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }

    return shm_ptr->message;
}

int main(void) {
    // Create and map shared memory
    create_shm();

    // Write to shared memory
    write_to_shm("Hello, world!");

    // Read from shared memory
    char *message = read_from_shm();
    printf("Received message: %s\n", message);

    return 0;
}