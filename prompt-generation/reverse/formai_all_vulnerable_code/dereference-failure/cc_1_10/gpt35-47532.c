//FormAI DATASET v1.0 Category: Interprocess communication ; Style: secure
// Example program demonstrating interprocess communication using shared memory in a secure way
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define KEY 9876
#define SIZE 1024

typedef struct {
    int data;
    bool written;
} shared_data_t;

int main() {
    int shmid, pid;
    shared_data_t *shared_data;
    
    // Create shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0600);
    if(shmid == -1) {
        perror("Error creating shared memory segment");
        exit(EXIT_FAILURE);
    }
    
    // Attach shared memory segment
    shared_data = (shared_data_t *) shmat(shmid, NULL, 0);
    if(shared_data == (shared_data_t *) -1) {
        perror("Error attaching shared memory segment");
        exit(EXIT_FAILURE);
    }
    
    // Parent process writes data to shared memory
    pid = fork();
    if(pid == -1) {
        perror("Error forking child process");
        exit(EXIT_FAILURE);
    } else if(pid == 0) {
        // Child process reads data from shared memory
        while(!shared_data->written) {
            sleep(1);
        }
        printf("Child process read %d from shared memory\n", shared_data->data);
        
        // Detach shared memory segment
        if(shmdt(shared_data) == -1) {
            perror("Error detaching shared memory segment");
            exit(EXIT_FAILURE);
        }
        
        exit(EXIT_SUCCESS);
    } else {
        shared_data->data = 42;
        shared_data->written = true;
        printf("Parent process wrote %d to shared memory\n", shared_data->data);
        
        // Wait for child process to finish
        wait(NULL);
        
        // Remove shared memory segment
        if(shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("Error removing shared memory segment");
            exit(EXIT_FAILURE);
        }
        
        // Detach shared memory segment
        if(shmdt(shared_data) == -1) {
            perror("Error detaching shared memory segment");
            exit(EXIT_FAILURE);
        }
        
        exit(EXIT_SUCCESS);
    }
}