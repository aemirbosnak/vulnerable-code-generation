//FormAI DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <signal.h>

// Define signal handlers
void signal_handler(int signal_number);
void clean_up();

// Define shared memory struct
struct shared_memory {
    int data_ready_flag;
    char message[100];
};

// Declare global variables
int shared_memory_id;
struct shared_memory *shared_memory_ptr;

int main() {
    // Set signal handlers
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    
    // Create shared memory
    key_t key = ftok("shared_memory_key", 'R');
    shared_memory_id = shmget(key, sizeof(struct shared_memory), 0666 | IPC_CREAT);
    if (shared_memory_id < 0) {
        perror("Error creating shared memory");
        exit(1);
    }
    
    // Attach to shared memory
    shared_memory_ptr = (struct shared_memory *) shmat(shared_memory_id, NULL, 0);
    if ((void *) shared_memory_ptr == (void *) -1) {
        perror("Error attaching to shared memory");
        exit(1);
    }
    
    // Set data_ready_flag to 0
    shared_memory_ptr->data_ready_flag = 0;
    
    // Loop to read messages from user input and write to shared memory
    char input_message[100];
    printf("Type a message (ctrl+c to exit):\n");
    while (1) {
        fgets(input_message, 100, stdin);
        input_message[strcspn(input_message, "\n")] = 0; // remove newline character
        memcpy(shared_memory_ptr->message, input_message, strlen(input_message) + 1);
        shared_memory_ptr->data_ready_flag = 1;
        printf("Sent message: %s\n", input_message);
    }
    
    return 0;
}

// Signal handler to clean up shared memory
void signal_handler(int signal_number) {
    if (signal_number == SIGINT || signal_number == SIGTERM) {
        printf("\nExiting...\n");
        clean_up();
        exit(0);
    }
}

// Clean up shared memory
void clean_up() {
    shmdt((void *) shared_memory_ptr);
    shmctl(shared_memory_id, IPC_RMID, NULL);
}