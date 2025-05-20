//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MESSAGE_SIZE 1024

typedef struct {
    char message[MESSAGE_SIZE];
    int sender;
} message_t;

int main() {
    key_t key = IPC_PRIVATE;
    int shmid = shmget(IPC_PRIVATE, sizeof(message_t), IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Create a shared memory segment
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        return 1;
    }

    // Initialize the shared memory with some data
    message_t *msg = shm;
    strcpy(msg->message, "Hello from parent process!");
    msg->sender = getpid();

    // Fork a child process to receive the message
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char *message = msg->message;
        printf("Received message from parent: %s\n", message);
        // Do some scientific calculations using the received message
        double sum = 0;
        for (int i = 0; i < strlen(message); i++) {
            sum += message[i] - '0';
        }
        printf("Sum of message digits: %f\n", sum);
    } else {
        // Parent process
        wait(NULL);
    }

    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}