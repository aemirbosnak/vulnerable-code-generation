//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

void *shm_ptr;

void create_shm(void) {
    key_t key = SHM_KEY;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }
    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
}

void write_to_shm(const char *message) {
    char *ptr = shm_ptr;
    size_t len = strlen(message);
    memcpy(ptr, message, len + 1);
}

void read_from_shm(char *buffer, size_t size) {
    char *ptr = shm_ptr;
    memcpy(buffer, ptr, size);
}

int main() {
    create_shm();

    // Parent process
    write_to_shm("Hello from parent!");

    // Child process
    int status;
    wait(&status);

    // Read from shared memory
    char buffer[1024];
    read_from_shm(buffer, sizeof(buffer));
    printf("Received message from child: %s\n", buffer);

    return 0;
}