//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <string.h>

#define SHM_SIZE 1024  // Shared memory size
#define MAX_CLIENTS 5  // Maximum number of clients

typedef struct {
    char message[SHM_SIZE];
    int is_used;
} SharedMemorySegment;

// Function to handle interrupt signal
void handle_sigint(int sig) {
    printf("Interrupt signal received. Exiting...\n");
    exit(0);
}

void client_process(int client_id, SharedMemorySegment *shared_segment) {
    char send_message[SHM_SIZE];
    while (1) {
        printf("Client %d: Enter a message (or type 'exit' to quit): ", client_id);
        fgets(send_message, SHM_SIZE, stdin);
        send_message[strcspn(send_message, "\n")] = 0;  // Remove newline character
        
        if (strcmp(send_message, "exit") == 0) {
            printf("Client %d exiting...\n", client_id);
            break;
        }
        
        // Writing to shared memory
        while (shared_segment[client_id].is_used) {
            // Busy-waiting for the segment to become free
        }
        strncpy(shared_segment[client_id].message, send_message, SHM_SIZE);
        shared_segment[client_id].is_used = 1;  // Mark as used
        printf("Client %d sent: %s\n", client_id, shared_segment[client_id].message);
        
        // Wait for acknowledgment
        while (shared_segment[client_id].is_used) {
            // Busy-waiting for acknowledgment
        }
    }
}

void server_process(SharedMemorySegment *shared_segment) {
    while (1) {
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (shared_segment[i].is_used) {
                printf("Server received from Client %d: %s\n", i, shared_segment[i].message);
                // Acknowledge that message has been processed
                shared_segment[i].is_used = 0;
            }
        }
        // Add a brief sleep to reduce CPU usage
        usleep(100000);
    }
}

int main() {
    // Handle SIGINT to allow graceful shutdown
    signal(SIGINT, handle_sigint);

    int shmid;
    SharedMemorySegment *shared_segment;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(SharedMemorySegment) * MAX_CLIENTS, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    shared_segment = (SharedMemorySegment*) shmat(shmid, NULL, 0);
    if (shared_segment == (SharedMemorySegment*) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize the shared memory
    memset(shared_segment, 0, sizeof(SharedMemorySegment) * MAX_CLIENTS);

    pid_t pid;
    // Create a server process
    if ((pid = fork()) == 0) {
        // In the server process
        server_process(shared_segment);
        exit(0);
    }

    // Create client processes
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (fork() == 0) {
            // In the client process
            client_process(i, shared_segment);
            exit(0);
        }
    }

    // Wait for all children to finish
    for (int i = 0; i < MAX_CLIENTS + 1; i++) {
        wait(NULL);
    }

    // Detach and delete the shared memory
    shmdt(shared_segment);
    shmctl(shmid, IPC_RMID, NULL);
    
    printf("Shared memory segment deleted and main process exiting.\n");

    return 0;
}