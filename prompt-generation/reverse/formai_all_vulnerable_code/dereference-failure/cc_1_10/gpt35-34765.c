//FormAI DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

#define SHMKEY 123456
#define BUFSIZE 256

typedef struct {
    pid_t pid;
    char message[BUFSIZE];
} shared_data;

int shm_id = -1;

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("Received SIGINT signal. Terminating...\n");
        if (shm_id != -1) {
            shmctl(shm_id, IPC_RMID, NULL);
        }
        exit(0);
    }
}

int main() {
    signal(SIGINT, signal_handler);
    
    // Create shared memory
    shm_id = shmget(SHMKEY, sizeof(shared_data), IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }
    printf("Created shared memory segment with ID %d\n", shm_id);
    
    // Attach to shared memory
    shared_data *data = shmat(shm_id, NULL, 0);
    if (data == (shared_data*)-1) {
        perror("shmat");
        exit(1);
    }
    printf("Attached to shared memory at address %p\n", data);
    
    // Wait for message from other process
    while (1) {
        if (data->pid != 0) {
            printf("Received message from process with PID %d: %s\n", data->pid, data->message);
            data->pid = 0;
        }
    }
    
    // Detach from shared memory
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }
    
    // Delete shared memory
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    
    return 0;
}