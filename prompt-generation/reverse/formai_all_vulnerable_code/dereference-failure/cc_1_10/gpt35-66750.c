//FormAI DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_KEY 5678 // Shared memory key

// Shared memory structure to hold data
struct shared_memory {
    int client_pid;
    char message[100];
    int flag;
};

int main() {
    pid_t pid;
    int shmid;
    struct shared_memory *shared_mem;

    shmid = shmget(SHM_KEY, sizeof(struct shared_memory), 0666 | IPC_CREAT); // Create shared memory segment
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    shared_mem = shmat(shmid, NULL, 0); // Attach shared memory segment
    if (shared_mem == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fork child process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child process
        while (1) {
            if (shared_mem->flag == 1 && shared_mem->client_pid != getpid()) { // Check for incoming message from client
                printf("Received message: %s\n", shared_mem->message);
                shared_mem->flag = 0; // Reset flag
            }
        }
    } else { // Parent process
        int client_pid;
        char message[100];

        printf("Enter the client PID: ");
        scanf("%d", &client_pid);
        shared_mem->client_pid = client_pid;

        while (1) {
            printf("Enter message to send to client: ");
            scanf("%s", message);
            strcpy(shared_mem->message, message);
            shared_mem->flag = 1; // Set flag to indicate message ready to send

            kill(client_pid, SIGUSR1); // Send signal to client to read message

            wait(NULL); // Wait for child process to receive message
        }
    }

    shmdt(shared_mem); // Detach shared memory segment

    return 0;
}