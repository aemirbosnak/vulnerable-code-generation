//FormAI DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE     128

void child_process(char *shared_memory)
{
    printf("Child process started...\n");
    
    // Write data to shared memory
    snprintf(shared_memory, SHM_SIZE, "Hello from child process!");
    
    printf("Child process finished...\n");
}

void parent_process(char *shared_memory)
{
    printf("Parent process started...\n");
    
    // Wait for child process to finish
    int status;
    wait(&status);
    
    // Print data from shared memory
    printf("Received from child process: %s\n", shared_memory);
    
    printf("Parent process finished...\n");
}

int main()
{
    key_t key = ftok(".", 's');
    if(key == -1) {
        perror("ftok failed");
        exit(EXIT_FAILURE);
    }
    
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if(shmid == -1) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }
    
    char *shared_memory = shmat(shmid, NULL, 0);
    if(shared_memory == (void*) -1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }
    
    // Initialize shared memory
    memset(shared_memory, 0, SHM_SIZE);
    
    // Create child process
    pid_t pid = fork();
    if(pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    
    if(pid == 0) {
        // Child process
        child_process(shared_memory);
    }
    else {
        // Parent process
        parent_process(shared_memory);
    }
    
    // Detach and remove shared memory
    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}