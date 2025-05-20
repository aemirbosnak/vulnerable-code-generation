//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_SIZE 4096
#define MSG_SIZE 1024

typedef struct {
    char name[16];
    char message[MSG_SIZE];
} shared_data_t;

shared_data_t *shm;

void create_shm(void) {
    shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
}

void send_message(const char *name, const char *message) {
    char *ptr = shm->name;
    memcpy(ptr, name, strlen(name) + 1);
    ptr += strlen(name) + 1;
    memcpy(ptr, message, strlen(message) + 1);
}

char *receive_message(void) {
    char *ptr = shm->message;
    return ptr;
}

int main(void) {
    create_shm();

    // Parent process
    send_message("Parent", "Hello, Child!");

    // Child process
    char *message = receive_message();
    printf("Received message from Parent: %s\n", message);

    // Child process
    send_message("Child", "Hello, Parent!");

    // Parent process
    message = receive_message();
    printf("Received message from Child: %s\n", message);

    // Clean up
    munmap(shm, SHM_SIZE);
    return 0;
}