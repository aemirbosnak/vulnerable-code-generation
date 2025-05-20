//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define SHM_NAME "my_shm"
#define SHM_SIZE 1024

void *shm_addr;

void create_shm(void) {
    key_t key = IPC_PRIVATE;
    shm_addr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
}

void *send_message(const char *message) {
    size_t message_len = strlen(message);
    char *shm_ptr = shm_addr;
    memcpy(shm_ptr, message, message_len);
    shm_ptr += message_len;
    return shm_ptr;
}

char *receive_message(void) {
    char *shm_ptr = shm_addr;
    size_t message_len = strlen(shm_ptr);
    char *message = malloc(message_len + 1);
    memcpy(message, shm_ptr, message_len);
    message[message_len] = '\0';
    return message;
}

int main() {
    create_shm();

    // Parent process
    char *message = "Hello, child!";
    char *shm_ptr = send_message(message);
    printf("Parent: Sent message: %s\n", message);

    // Child process
    char *child_message = receive_message();
    printf("Child: Received message: %s\n", child_message);

    // Wait for child to finish
    wait(NULL);

    return 0;
}