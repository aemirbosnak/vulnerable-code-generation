//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

// Structure to store data shared between processes
struct shared_data {
    char name[20];
    int age;
};

// Function to create a shared memory segment
void create_shm(void) {
    key_t key = SHM_KEY;
    size_t size = SHM_SIZE;
    int shmid = shmget(key, size, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    printf("Shared memory segment created with key %d and size %zu\n", key, size);
}

// Function to attach to an existing shared memory segment
void attach_shm(void) {
    key_t key = SHM_KEY;
    size_t size = SHM_SIZE;
    int shmid = shmget(key, size, 0);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    printf("Attached to shared memory segment with key %d and size %zu\n", key, size);
}

// Function to write data to shared memory
void write_shm(struct shared_data *data) {
    key_t key = SHM_KEY;
    size_t size = SHM_SIZE;
    int shmid = shmget(key, size, IPC_PRIVATE | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    char *shm_addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    memcpy(shm_addr, data, sizeof(struct shared_data));
    munmap(shm_addr, size);
}

// Function to read data from shared memory
struct shared_data *read_shm(void) {
    key_t key = SHM_KEY;
    size_t size = SHM_SIZE;
    int shmid = shmget(key, size, IPC_PRIVATE | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    char *shm_addr = mmap(NULL, size, PROT_READ, MAP_SHARED, shmid, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    struct shared_data *data = (struct shared_data *)shm_addr;
    munmap(shm_addr, size);
    return data;
}

int main(void) {
    // Create a shared memory segment
    create_shm();

    // Fork a new process to write data to shared memory
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        struct shared_data data = {"Alice", 25};
        write_shm(&data);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        wait(NULL);

        // Attach to the shared memory segment
        attach_shm();

        // Read data from shared memory
        struct shared_data *data = read_shm();
        printf("Read data from shared memory: %s %d\n", data->name, data->age);
    }
    return 0;
}