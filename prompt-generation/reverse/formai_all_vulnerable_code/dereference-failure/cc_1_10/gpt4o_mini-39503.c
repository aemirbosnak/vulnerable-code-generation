//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024
#define MESSAGE_SIZE 256

void producer(char *shm_addr) {
    char message[MESSAGE_SIZE];
    
    printf("Producer: Enter messages to send (type 'exit' to quit):\n");
    
    while (1) {
        memset(message, 0, MESSAGE_SIZE);
        printf("Producer: ");
        fgets(message, MESSAGE_SIZE, stdin);
        
        // Remove newline character if present
        message[strcspn(message, "\n")] = 0;

        // Exit condition
        if (strcmp(message, "exit") == 0) {
            break;
        }

        // Write to shared memory
        strcpy(shm_addr, message);
        printf("Producer: Message sent to consumer: '%s'\n", shm_addr);
        
        // Simulate work
        sleep(1);
    }

    // Indicate that the producer is done
    strcpy(shm_addr, "exit");
}

void consumer(char *shm_addr) {
    char message[MESSAGE_SIZE];
    
    while (1) {
        // Read from shared memory
        memset(message, 0, MESSAGE_SIZE);
        strcpy(message, shm_addr);
        
        // Exit condition
        if (strcmp(message, "exit") == 0) {
            break;
        }

        printf("Consumer: Message received from producer: '%s'\n", message);
        
        // Simulate work
        sleep(1);
    }
}

int main() {
    // Shared memory ID and address
    int shmid;
    char *shm_addr;

    // Create unique key for shared memory
    key_t key = ftok("shmfile", 65);
    
    // Create shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }
    
    // Attach to shared memory
    shm_addr = shmat(shmid, NULL, 0);
    if (shm_addr == (char *)(-1)) {
        perror("shmat failed");
        exit(1);
    }

    // Create the producer and consumer processes
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        // Parent process (producer)
        producer(shm_addr);
        wait(NULL); // Wait for the consumer to finish
    } else {
        // Child process (consumer)
        consumer(shm_addr);
    }

    // Detach from shared memory
    shmdt(shm_addr);
    
    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}