//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#define SHM_SIZE 1024

// Function to handle the SIGINT signal
void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nSignal received! Exiting...\n");
        exit(0);
    }
}

int main() {
    // Set up signal handling for cleanup
    signal(SIGINT, signal_handler);
    
    // Create a shared memory segment
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT);
    char *str = (char*) shmat(shmid, NULL, 0);
    
    // Forking a new process
    pid_t id = fork();

    if (id == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (id > 0) {
        // Parent process: a writer
        printf("Parent (PID: %d) is writing to shared memory...\n", getpid());
        
        // Write data to shared memory
        while (1) {
            printf("Enter a message for the child (type 'exit' to end): ");
            fgets(str, SHM_SIZE, stdin);
            str[strcspn(str, "\n")] = 0; // Remove the newline character
            
            if (strcmp(str, "exit") == 0) {
                break; // Exit if the user types 'exit'
            }

            printf("Parent wrote: '%s'\n", str);
            sleep(1); // Simulate delay in writing
        }
        
        // Clean up shared memory
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
        printf("Parent exiting...\n");
    } 
    else {
        // Child process: a reader
        sleep(1); // Ensure parent writes first
        
        printf("Child (PID: %d) is reading from shared memory...\n", getpid());
        
        while (1) {
            printf("Child read: '%s'\n", str);
            if (strcmp(str, "exit") == 0) {
                break; // Exit if the parent signals to exit
            }
            sleep(1); // Simulate delay in reading
        }
        
        // Clean up after reading
        shmdt(str);
        printf("Child exiting...\n");
    }

    return 0;
}