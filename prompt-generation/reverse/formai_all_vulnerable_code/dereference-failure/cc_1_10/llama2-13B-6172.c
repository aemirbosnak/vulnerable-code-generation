//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define MESSAGE_SIZE 1024
#define SHM_KEY 0xdeadbeef

void* shared_mem;

void create_shared_mem(void) {
    key_t key = SHM_KEY;
    shared_mem = mmap(NULL, MESSAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
}

void send_message(const char* message) {
    char* dest = shared_mem + strlen(message);
    memcpy(dest, message, strlen(message));
}

char* receive_message(void) {
    char* src = shared_mem;
    char message[MESSAGE_SIZE];
    memcpy(message, src, MESSAGE_SIZE);
    return message;
}

int main(void) {
    create_shared_mem();

    // Parent process
    printf("Parent process creating shared memory...\n");
    send_message("Hello, child!");

    // Child process
    printf("Child process receiving message...\n");
    char* message = receive_message();
    printf("Received message: %s\n", message);

    // Child process sends a message back
    send_message("Hello, parent!");

    // Parent process receives the message
    message = receive_message();
    printf("Received message: %s\n", message);

    return 0;
}