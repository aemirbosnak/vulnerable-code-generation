//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define SHM_SIZE 1024  // Size of shared memory
#define MAX_MESSAGE_LENGTH 256

void producer(char *shared_memory) {
    char message[MAX_MESSAGE_LENGTH];
    printf("Producer: Enter a message (type 'exit' to quit): \n");

    while (1) {
        printf("Producer> ");
        fgets(message, MAX_MESSAGE_LENGTH, stdin);
        
        // Remove newline character from the message
        message[strcspn(message, "\n")] = 0;

        // Check for exit condition
        if (strcmp(message, "exit") == 0) {
            break;
        }

        // Write to shared memory
        strcpy(shared_memory, message);
        printf("Producer: Written to shared memory: %s\n", shared_memory);
        sleep(1);  // Simulate some delay
    }
}

void consumer(char *shared_memory) {
    char last_message[MAX_MESSAGE_LENGTH] = "";

    printf("Consumer: Waiting for messages... (type 'exit' to quit)\n");

    while (1) {
        // Read from shared memory
        if (strcmp(shared_memory, last_message) != 0) {
            strcpy(last_message, shared_memory);
            if (strcmp(last_message, "exit") == 0) {
                printf("Consumer: Received exit signal, stopping...\n");
                break;
            }
            printf("Consumer: Read from shared memory: %s\n", last_message);
        }
        sleep(1);  // Simulate some delay
    }
}

int main() {
    int shm_id;
    char *shared_memory;

    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Fork a new process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process - Consumer
        consumer(shared_memory);
        exit(0);
    } else {
        // Parent process - Producer
        producer(shared_memory);
        
        // Wait for child process to finish
        wait(NULL);
    }

    // Detach and remove shared memory segment
    shmdt(shared_memory);
    shmctl(shm_id, IPC_RMID, NULL);
    
    printf("Main: Cleanup complete, exiting.\n");
    
    return 0;
}