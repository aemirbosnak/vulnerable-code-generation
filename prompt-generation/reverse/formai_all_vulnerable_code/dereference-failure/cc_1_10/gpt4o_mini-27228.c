//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024  // Size of the shared memory

void producer(char *shm_addr) {
    // Producer process writes data to shared memory
    char message[50];
    for(int i = 0; i < 5; i++) {
        snprintf(message, sizeof(message), "Message %d from Producer", i + 1);
        strncpy(shm_addr, message, SHM_SIZE);
        printf("Producer: Written '%s' to shared memory.\n", message);
        sleep(1);  // Simulating work by sleeping
    }
    shm_addr[0] = '\0';  // Indicating end of messages
}

void consumer(char *shm_addr) {
    // Consumer process reads data from shared memory
    char message[50];
    while (1) {
        if (strlen(shm_addr) > 0) {
            snprintf(message, sizeof(message), "%s", shm_addr);
            printf("Consumer: Read '%s' from shared memory.\n", message);
            sleep(1);  // Simulating work by sleeping
        } else {
            printf("Consumer: No more messages to read. Exiting.\n");
            break;
        }
    }
}

int main() {
    int shmid;
    char *shm_addr;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    // Attach shared memory
    shm_addr = (char *)shmat(shmid, NULL, 0);
    if (shm_addr == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Fork a process to act as a producer
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process - Producer
        producer(shm_addr);
        exit(0);
    } else {
        // Parent process - Consumer
        consumer(shm_addr);
        // Wait for the producer to finish
        wait(NULL);
    }

    // Detach and delete shared memory
    if (shmdt(shm_addr) == -1) {
        perror("shmdt failed");
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl failed");
    }

    return 0;
}