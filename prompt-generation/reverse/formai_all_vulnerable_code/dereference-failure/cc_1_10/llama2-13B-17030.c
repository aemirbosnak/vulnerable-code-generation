//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE 1024

void *shm_create(void) {
    int shmid;
    key_t key = SHM_KEY;
    size_t size = SHM_SIZE;
    void *shm = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    shmid = shmget(key, size, IPC_PRIVATE | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    return shm;
}

void shm_send(void *shm, char *message) {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_PRIVATE | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    char *shm_ptr = shm;
    char *message_ptr = message;
    while (*message_ptr != '\0') {
        *(shm_ptr++) = *(message_ptr++);
    }
    shm_ptr -= strlen(message);
    return;
}

void shm_receive(void *shm, char *message) {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_PRIVATE | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    char *shm_ptr = shm;
    char *message_ptr = message;
    while (*shm_ptr != '\0') {
        *(message_ptr++) = *(shm_ptr++);
    }
    return;
}

int main() {
    void *shm = shm_create();
    char message[] = "Hello, world!";
    shm_send(shm, message);
    char received_message[1024];
    shm_receive(shm, received_message);
    printf("Received message: %s\n", received_message);
    return 0;
}