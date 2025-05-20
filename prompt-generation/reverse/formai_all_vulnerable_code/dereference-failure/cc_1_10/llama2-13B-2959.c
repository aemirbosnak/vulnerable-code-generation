//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_MESSAGE_SIZE 1024

// Structure to hold message data
typedef struct {
    char message[MAX_MESSAGE_SIZE];
    int sender;
} message_t;

// Function to send message to another process
void send_message(int pid, char *message) {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, sizeof(message_t), IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Write message to shared memory
    message_t *msg = (message_t *)shmat(shmid, NULL, 0);
    strcpy(msg->message, message);
    msg->sender = pid;
    shmdt(msg);
}

// Function to receive message from another process
void recv_message(int pid) {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, sizeof(message_t), IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Read message from shared memory
    message_t *msg = (message_t *)shmat(shmid, NULL, 0);
    printf("Received message from process %d: %s\n", msg->sender, msg->message);
    shmdt(msg);
}

int main() {
    // Fork two processes
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(1);
    }
    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(1);
    }

    // Parent process sends message to child process
    if (pid1 == 0) {
        char message[] = "Hello from parent!";
        send_message(pid2, message);
    }

    // Child process receives message from parent process
    if (pid2 == 0) {
        recv_message(pid1);
    }

    // Wait for child process to finish
    wait(NULL);

    return 0;
}