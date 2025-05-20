//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MESSAGE_SIZE 1024

// Structure to store message data
struct message {
    char *data;
    size_t length;
};

// Function to send message to other process
void send_message(int pid, char *message) {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Write message to shared memory
    struct message *msg = (struct message *)shmat(shmid, NULL, 0);
    msg->data = message;
    msg->length = strlen(message);

    // Send message to other process
    if (pid > 0) {
        // Use fork() to create a new process
        pid = fork();
        if (pid == 0) {
            // In child process, read message from shared memory
            msg = (struct message *)shmat(shmid, NULL, 0);
            printf("Received message: %s\n", msg->data);
        } else {
            // In parent process, wait for child process to finish
            wait(NULL);
        }
    }
}

// Function to receive message from other process
void receive_message(int pid) {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Read message from shared memory
    struct message *msg = (struct message *)shmat(shmid, NULL, 0);
    printf("Received message: %s\n", msg->data);

    // Free shared memory
    shmctl(shmid, IPC_RMID, NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Send message to other process
    char message[MESSAGE_SIZE];
    strcpy(message, argv[1]);
    send_message(getppid(), message);

    // Receive message from other process
    receive_message(getppid());

    return 0;
}