//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>

#define BUFFER_SIZE 1024

void* shared_mem;

void init_shared_mem(void) {
    key_t key = IPC_PRIVATE;
    shared_mem = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    if(shared_mem == MAP_FAILED) {
        perror("mmap() failed");
        exit(1);
    }
}

void* send_message(const char* message) {
    char* buffer = (char*)shared_mem;
    strcpy(buffer, message);
    mprotect(buffer, BUFFER_SIZE, PROT_READ | PROT_WRITE);
    return buffer;
}

char* receive_message(void) {
    char* buffer = (char*)shared_mem;
    mprotect(buffer, BUFFER_SIZE, PROT_READ);
    return buffer;
}

int main() {
    init_shared_mem();

    // Parent process
    char* message = "Hello, child!";
    void* buffer = send_message(message);
    printf("Parent: Sent message: %s\n", buffer);

    // Child process
    char* received_message = receive_message();
    printf("Child: Received message: %s\n", received_message);

    // Child process sends message back to parent
    message = "Hello, parent!";
    buffer = send_message(message);
    printf("Child: Sent message: %s\n", buffer);

    // Parent process receives message from child
    received_message = receive_message();
    printf("Parent: Received message: %s\n", received_message);

    return 0;
}