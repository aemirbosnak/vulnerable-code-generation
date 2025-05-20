//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MESSAGE_SIZE 1024

// Structure to hold message data
typedef struct {
    char message[MESSAGE_SIZE];
} message_t;

// Function to send message to other process
void send_message(int shmid, const char* message) {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shm = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget");
        return;
    }

    // Attach shared memory segment to current process
    if (shmat(shm, NULL, 0) == -1) {
        perror("shmat");
        return;
    }

    // Fill message data into shared memory
    message_t* msg = (message_t*)shmat;
    strcpy(msg->message, message);

    // Detach shared memory segment from current process
    if (shmdt(shm) == -1) {
        perror("shmdt");
        return;
    }
}

// Function to receive message from other process
void receive_message(int shmid) {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shm = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget");
        return;
    }

    // Attach shared memory segment to current process
    if (shmat(shm, NULL, 0) == -1) {
        perror("shmat");
        return;
    }

    // Read message data from shared memory
    message_t* msg = (message_t*)shmat;
    printf("Received message: %s\n", msg->message);

    // Detach shared memory segment from current process
    if (shmdt(shm) == -1) {
        perror("shmdt");
        return;
    }
}

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shm = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget");
        return 1;
    }

    // Attach shared memory segment to current process
    if (shmat(shm, NULL, 0) == -1) {
        perror("shmat");
        return 1;
    }

    // Create a pipe for communication
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork a new process to receive messages
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        close(fd[0]);
        receive_message(shm);
    } else {
        // Parent process
        close(fd[1]);
        send_message(shm, "Hello from parent!");
    }

    // Detach shared memory segment from current process
    if (shmdt(shm) == -1) {
        perror("shmdt");
        return 1;
    }

    return 0;
}