//FormAI DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024
#define KEY 9876

int main() {
    
    int shmid;
    int *num;
    char* message;
    int switchVal;
    int val;
    
    // Creating shared memory segment
    shmid = shmget(KEY, SHM_SIZE, 0666|IPC_CREAT);
    if(shmid == -1) {
        perror("Error in shmget");
        exit(EXIT_FAILURE);
    }
    
    // Attached shared memory segment to process address space
    num = (int*) shmat(shmid, NULL, 0);
    if(num == (int*) -1) {
        perror("Error in shmat");
        exit(EXIT_FAILURE);
    }
    
    // User input
    while(1) {
        printf("Enter 1 to write to shared memory, 2 to read from shared memory, or 3 to exit: ");
        scanf("%d", &switchVal);
        
        if (switchVal == 3) {
            break;
        } else if (switchVal == 1) {
            printf("Enter an integer to write to shared memory: ");
            scanf("%d", &val);
            
            // Writing to shared memory
            *num = val;
            printf("Wrote %d to shared memory\n", val);
            
        } else if (switchVal == 2) {
            
            // Reading from shared memory
            int output = *num;
            printf("Read %d from shared memory\n", output);
            
        } else {
            printf("Invalid input\n");
        }
    }
    
    // Detach from shared memory segment
    if (shmdt(num) == -1) {
        perror("Error in shmdt");
        exit(EXIT_FAILURE);
    }
    
    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Error in shmctl");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}