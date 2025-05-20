//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_NAME "my_shared_mem"
#define SHM_SIZE 1024

void *shm_addr;

void create_shm(void) {
    key_t key = IPC_PRIVATE;
    int shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    shm_addr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
}

void write_to_shm(const char *msg) {
    char *ptr = shm_addr;
    for (int i = 0; msg[i] != '\0'; i++) {
        *ptr++ = msg[i];
    }
}

void read_from_shm(char *msg) {
    char *ptr = shm_addr;
    for (int i = 0; i < SHM_SIZE; i++) {
        msg[i] = *ptr++;
    }
}

int main() {
    create_shm();

    // Parent process
    write_to_shm("Hello, child!");

    // Child process
    char msg[SHM_SIZE];
    read_from_shm(msg);
    printf("Received message: %s\n", msg);

    return 0;
}