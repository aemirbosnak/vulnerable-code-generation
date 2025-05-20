//FormAI DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    pid_t pid;
    int shmid;
    char *shm;
    char message[SHM_SIZE];
    
    // Create shared memory segment
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0644)) < 0) {
        perror("shmget");
        exit(1);
    }
    
    // Attach shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    
    // Fork a child process
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    
    // Child process
    if (pid == 0) {
        printf("Child process is running...\n");
        
        // Write message to shared memory
        strcpy(shm, "Hello from child process!");
        
        // Exit child process
        exit(0);
    }
    // Parent process
    else {
        printf("Parent process is running...\n");
        
        // Wait for child process to finish
        wait(NULL);
        
        // Print message from shared memory
        printf("Message from child process: %s\n", shm);
        
        // Detach and remove shared memory segment
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }
    
    return 0;
}