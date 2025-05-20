//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
/* Hello everyone! I am a happy interprocess communication program. 
   My goal is to transmit messages between two processes using shared memory.
   Let's get started! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 1234; // Unique key for shared memory segment
    int shmid;
    char *message; // Message to be passed between processes
    char *shm; // Pointer to shared memory segment
    
    // Create shared memory segment
    if((shmid = shmget(key, 1024, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    
    // Attach shared memory segment to process address space
    if((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    
    // Write a happy message to shared memory
    message = "Hello, world! I am a happy interprocess communication program!";
    memcpy(shm, message, strlen(message));
    printf("Wrote message to shared memory: %s\n", message);
    
    // Detach shared memory segment from process address space
    if(shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }
    
    // Wait for other process to read the shared memory
    sleep(5);
    
    // Reattach shared memory segment to process address space
    if((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    
    // Read the message from shared memory
    message = shm;
    printf("Read message from shared memory: %s\n", message);
    
    // Detach shared memory segment from process address space
    if(shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }
    
    // Delete the shared memory segment
    if(shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    
    printf("Program completed successfully! Goodbye!\n");
    
    return 0;
}