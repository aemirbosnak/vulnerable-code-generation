//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SHM_NAME "irregular_ipc"
#define MESSAGE_SIZE 1024

// Structure to store message data
typedef struct {
    char name[10];
    int age;
} message_t;

// Function to send message
void send_message(int shmid, char *message) {
    // Create a shared memory segment
    key_t key = ftok(SHM_NAME, 'A');
    int shm = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the current process
    if (shmat(shm, NULL, 0) == -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    // Write the message to the shared memory segment
    char *shm_ptr = (char *)shmat;
    memcpy(shm_ptr, message, MESSAGE_SIZE);

    // Detach the shared memory segment from the current process
    if (shmdt(shm) == -1) {
        perror("shmdt() failed");
        exit(EXIT_FAILURE);
    }
}

// Function to receive message
void receive_message(int shmid) {
    // Create a shared memory segment
    key_t key = ftok(SHM_NAME, 'A');
    int shm = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the current process
    if (shmat(shm, NULL, 0) == -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    // Read the message from the shared memory segment
    char *shm_ptr = (char *)shmat;
    message_t message;
    memcpy(&message, shm_ptr, MESSAGE_SIZE);

    // Print the received message
    printf("Received message: %s %d\n", message.name, message.age);

    // Detach the shared memory segment from the current process
    if (shmdt(shm) == -1) {
        perror("shmdt() failed");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Create a shared memory segment
    key_t key = ftok(SHM_NAME, 'A');
    int shm = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the current process
    if (shmat(shm, NULL, 0) == -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    // Create a message
    message_t message = {"Alice", 25};

    // Send the message to another process
    int pid = fork();
    if (pid == 0) {
        send_message(shm, "Hello from child process!");
        exit(EXIT_SUCCESS);
    } else {
        receive_message(shm);
    }

    // Detach the shared memory segment from the current process
    if (shmdt(shm) == -1) {
        perror("shmdt() failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}