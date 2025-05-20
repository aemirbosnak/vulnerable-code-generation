//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: distributed
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MESSAGE_SIZE 1024

void *sender(void *arg) {
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0666);
    char *message = malloc(MESSAGE_SIZE);
    strcpy(message, "Hello from sender!");
    shmat(shmid, message, 0);
    printf("Sending message...\n");
    kill(1, SIGUSR1);
    wait(NULL);
    return NULL;
}

void *receiver(void *arg) {
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0666);
    char *message = malloc(MESSAGE_SIZE);
    shmat(shmid, message, 0);
    printf("Received message: %s\n", message);
    free(message);
    return NULL;
}

int main() {
    pid_t pid_sender, pid_receiver;
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0666);

    // Create the sender process
    pid_sender = fork();
    if (pid_sender < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid_sender == 0) {
        // Sender process
        sender(NULL);
    } else {
        // Receiver process
        pid_receiver = fork();
        if (pid_receiver < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid_receiver == 0) {
            receiver(NULL);
        }
        wait(NULL);
    }

    shmctl(shmid, IPC_RMID, 0);
    return 0;
}