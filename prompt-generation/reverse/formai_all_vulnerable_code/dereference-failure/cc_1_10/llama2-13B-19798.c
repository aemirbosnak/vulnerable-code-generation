//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024
#define MESSAGE_SIZE 256

void* shared_mem;
int shmid;

void create_shared_mem() {
    key_t key = IPC_PRIVATE;
    shared_mem = shmat(shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0600), NULL, 0);
}

void send_message(const char* message) {
    int len = strlen(message);
    char* buffer = (char*)shared_mem;
    buffer[0] = len;
    memcpy(buffer + 1, message, len + 1);
}

char* receive_message() {
    char* buffer = (char*)shared_mem;
    int len = buffer[0];
    char* message = malloc(len + 1);
    memcpy(message, buffer + 1, len);
    message[len] = '\0';
    return message;
}

int main() {
    create_shared_mem();

    // Parent process
    char message[] = "Hello, child!";
    send_message(message);

    // Child process
    char* received_message = receive_message();
    printf("Received message: %s\n", received_message);

    // Send a message back to the parent
    char* message2 = "Hello, parent!";
    send_message(message2);

    // Receive the message from the parent
    received_message = receive_message();
    printf("Received message2: %s\n", received_message);

    return 0;
}