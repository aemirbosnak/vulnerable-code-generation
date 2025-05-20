//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024 // Size of shared memory
#define MSG_SIZE 100  // Max size of the message
#define PERMISSIONS 0666 // Shared memory permissions

// Function prototypes
void producer(char* shm_ptr);
void consumer(char* shm_ptr);

int main() {
    int shm_id;
    char *shm_ptr;

    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, SHM_SIZE, PERMISSIONS);
    if (shm_id < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to our process' address space
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process (Consumer)
        consumer(shm_ptr);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process (Producer)
        producer(shm_ptr);
        
        // Wait for child process to terminate
        wait(NULL);
        
        // Detach and remove shared memory segment
        shmdt(shm_ptr);
        shmctl(shm_id, IPC_RMID, NULL);
        printf("Producer has exited.\n");
    }

    return 0;
}

void producer(char* shm_ptr) {
    char message[MSG_SIZE];

    for (int i = 0; i < 5; i++) {
        printf("Producer: Enter a message: ");
        fgets(message, MSG_SIZE, stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline character
        strncpy(shm_ptr, message, MSG_SIZE);
        printf("Producer: Message written to shared memory: %s\n", shm_ptr);
        sleep(1); // Simulate work
    }

    // Indicate end of communication
    strncpy(shm_ptr, "END", MSG_SIZE);
}

void consumer(char* shm_ptr) {
    char message[MSG_SIZE];

    while (1) {
        strncpy(message, shm_ptr, MSG_SIZE);
        
        if (strncmp(message, "END", 3) == 0) {
            printf("Consumer: End of communication.\n");
            break;
        }
        
        printf("Consumer: Message read from shared memory: %s\n", message);
        sleep(1); // Simulate work
    }
}