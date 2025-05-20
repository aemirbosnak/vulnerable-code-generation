//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHARE_SIZE 1024

// Structure to store shared data
struct share_data {
    char message[SHARE_SIZE];
};

// Function to send message to other process
void send_message(int shmid) {
    char *message = "SURPRISE! You've got a message!";
    char *ptr = (char *)shmat(shmid, NULL, 0);
    strcpy(ptr, message);
    shmdt(ptr);
}

// Function to receive message from other process
void recv_message(int shmid) {
    char *message = (char *)shmat(shmid, NULL, 0);
    printf("Received message: %s\n", message);
    shmdt(message);
}

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, SHARE_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Fork a new process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    // In parent process, send a message to child process
    if (pid > 0) {
        send_message(shmid);
    }

    // In child process, receive message from parent process
    if (pid == 0) {
        recv_message(shmid);
    }

    // Wait for child process to finish
    wait(NULL);

    // Print a success message
    printf("Interprocess communication successful!\n");

    // Destroy shared memory segment
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}