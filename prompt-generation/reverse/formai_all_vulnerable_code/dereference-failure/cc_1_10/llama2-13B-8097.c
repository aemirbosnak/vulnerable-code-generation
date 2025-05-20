//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MESSAGE_SIZE 1024

void* shared_mem;

void create_shared_mem(void) {
    key_t key = IPC_PRIVATE;
    shared_mem = mmap(NULL, MESSAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
}

void send_message(const char* message) {
    size_t message_len = strlen(message);
    char* message_ptr = shared_mem;
    memcpy(message_ptr, message, message_len);
    message_ptr += message_len;
    *(char*)message_ptr = '\0';
}

char* receive_message(void) {
    char* message_ptr = shared_mem;
    char* result = NULL;
    while (*message_ptr != '\0') {
        result = message_ptr;
        message_ptr += strcspn(message_ptr, "\n");
    }
    return result;
}

int main() {
    create_shared_mem();

    // Parent process
    send_message("Hello, child!");

    // Child process
    char* message = receive_message();
    printf("Received message: %s\n", message);

    return 0;
}