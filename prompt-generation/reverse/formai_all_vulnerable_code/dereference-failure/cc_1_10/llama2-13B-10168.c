//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

// Structure to store data shared between processes
struct shared_data {
    char message[100];
    int value;
};

// Function to create a shared memory object
void create_shm(void) {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }
    printf("Created shared memory object %d\n", shm_id);
}

// Function to attach to an existing shared memory object
void attach_shm(void) {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_PRIVATE);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }
    printf("Attached to shared memory object %d\n", shm_id);
}

// Function to write data to shared memory
void write_to_shm(struct shared_data *data) {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_PRIVATE);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }
    char *shm_addr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    memcpy(shm_addr, data, sizeof(struct shared_data));
    munmap(shm_addr, SHM_SIZE);
}

// Function to read data from shared memory
struct shared_data *read_from_shm(void) {
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_PRIVATE);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }
    char *shm_addr = mmap(NULL, SHM_SIZE, PROT_READ, MAP_SHARED, shm_id, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    struct shared_data *data = (struct shared_data *)shm_addr;
    munmap(shm_addr, SHM_SIZE);
    return data;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(1);
    }

    // Create shared memory object
    create_shm();

    // Write data to shared memory
    struct shared_data data = {
        .message = "Hello from process 1!",
        .value = 42,
    };
    write_to_shm(&data);

    // Fork a new process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        // Child process
        struct shared_data *data = read_from_shm();
        printf("Received message: %s\n", data->message);
        printf("Received value: %d\n", data->value);
        exit(0);
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}