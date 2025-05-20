//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_NAME "my_shared_mem"
#define SHM_SIZE 1024

// Structure to store shared data
struct shared_data {
    int count;
    char message[100];
};

// Function to create and map shared memory
void *create_shm(void) {
    int shmid = shmget(SHM_NAME, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    void *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    return shm;
}

// Function to write to shared memory
void write_to_shm(void *shm, const char *message) {
    struct shared_data *data = shm;
    strcpy(data->message, message);
    data->count++;
}

// Function to read from shared memory
char *read_from_shm(void *shm) {
    struct shared_data *data = shm;
    return data->message;
}

int main() {
    // Create and map shared memory
    void *shm = create_shm();

    // Write to shared memory from parent process
    write_to_shm(shm, "Hello from parent!");

    // Fork child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process reads from shared memory
        char *message = read_from_shm(shm);
        printf("Received message from parent: %s\n", message);
    } else {
        // Parent process waits for child process to finish
        wait(NULL);
    }

    // Unmap and delete shared memory
    munmap(shm, SHM_SIZE);
    shmctl(shm, IPC_RMID, 0);

    return 0;
}