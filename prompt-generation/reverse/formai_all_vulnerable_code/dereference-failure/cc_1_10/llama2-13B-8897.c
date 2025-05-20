//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024
#define MESSAGE_SIZE 256

void* shared_mem;
int shmid;

void create_shared_mem() {
    key_t key = IPC_PRIVATE;
    shared_mem = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
    shmid = shmget(key, BUFFER_SIZE, IPC_PRIVATE | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }
}

void send_message(const char* message) {
    char* buffer = (char*)shared_mem;
    memcpy(buffer, message, MESSAGE_SIZE);
    buffer[MESSAGE_SIZE] = '\0';
}

char* receive_message() {
    char* buffer = (char*)shared_mem;
    return buffer;
}

int main() {
    create_shared_mem();

    // Parent process
    char message[] = "Hello, child!";
    send_message(message);

    // Child process
    char received_message[MESSAGE_SIZE];
    receive_message();
    printf("Received message: %s\n", received_message);

    return 0;
}