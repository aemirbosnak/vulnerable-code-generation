//FormAI DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

// Define constants
#define SHM_SIZE 1024
#define SHM_KEY 1234
#define MSG_LEN 100

int main() {
    // Declare variables
    int shmid;
    char *shm_ptr;
    char message[MSG_LEN] = "Hello from Process 1!";
    
    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    
    // Attach to shared memory segment
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    
    // Write message to shared memory segment
    strncpy(shm_ptr, message, strlen(message));
    
    // Detach from shared memory segment
    shmdt(shm_ptr);
    
    // Wait for Process 2 to read message
    sleep(5);
    
    // Re-attach to shared memory segment
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    
    // Read message from shared memory segment
    printf("Process 2 says: %s\n", shm_ptr);
    
    // Detach from shared memory segment and delete it
    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}