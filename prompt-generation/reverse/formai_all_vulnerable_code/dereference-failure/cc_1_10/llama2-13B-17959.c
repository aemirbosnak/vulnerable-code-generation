//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define SHM_KEY 1234

// Structure to hold the shared memory data
struct shared_data {
    char message[BUFFER_SIZE];
    int received;
};

// Function to create and attach to shared memory
void create_shm(void) {
    key_t key = SHM_KEY;
    int shmid = shmget(key, sizeof(struct shared_data), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    struct shared_data *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        exit(1);
    }
    // Initialize the shared memory data
    memset(shm, 0, sizeof(struct shared_data));
}

// Function to send a message from the parent process to the child process
void send_message(const char *message) {
    // Create a shared memory segment
    int shmid = shmget(SHM_KEY, strlen(message) + 1, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    // Write the message to the shared memory segment
    char *shm_message = shmat(shmid, NULL, 0);
    if (shm_message == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    strcpy(shm_message, message);
    // Signal the child process to read the message
    kill(getpid(), SIGUSR1);
}

// Function to read the message from the shared memory segment
void recv_message(void) {
    // Wait for the SIGUSR1 signal to indicate that there is a message available
    wait(NULL);
    // Read the message from the shared memory segment
    char *shm_message = shmat(SHM_KEY, NULL, 0);
    if (shm_message == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    // Print the received message
    printf("Received message: %s\n", shm_message);
}

int main(int argc, char *argv[]) {
    // Create the shared memory segment
    create_shm();

    // Fork the process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        // Child process
        recv_message();
        exit(0);
    } else {
        // Parent process
        send_message("Hello from the parent process!");
        wait(NULL);
    }
    return 0;
}