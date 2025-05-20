//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define MESSAGE_BUFFER_SIZE 1024

// Structure to hold the message and the sender's name
typedef struct {
    char message[MESSAGE_BUFFER_SIZE];
    char sender[20];
} message_t;

// Array to store the shared memory segments
static message_t messages[10];

// Shared memory segment for inter-process communication
static int shmid = -1;

// Function to create and attach to the shared memory segment
void create_shared_memory() {
    key_t key = IPC_PRIVATE;
    int shm_size = sizeof(message_t) * 10;
    shmid = shmget(key, shm_size, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }
}

// Function to write a message to the shared memory segment
void write_message(char* message, char* sender) {
    message_t* msg = (message_t*)mmap(NULL, sizeof(message_t), PROT_WRITE, MAP_SHARED, shmid, 0);
    if (msg == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
    strcpy(msg->message, message);
    strcpy(msg->sender, sender);
    munmap(msg, sizeof(message_t));
}

// Function to read a message from the shared memory segment
char* read_message() {
    message_t* msg = (message_t*)mmap(NULL, sizeof(message_t), PROT_READ, MAP_SHARED, shmid, 0);
    if (msg == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
    char* message = msg->message;
    char* sender = msg->sender;
    munmap(msg, sizeof(message_t));
    return message;
}

int main() {
    create_shared_memory();

    // Parent process
    if (fork() == 0) {
        char message[] = "Hello from the parent!";
        write_message(message, "Parent");
    }

    // Child process
    else {
        char message[MESSAGE_BUFFER_SIZE];
        read_message();
        printf("Received message from parent: %s\n", message);
    }

    return 0;
}