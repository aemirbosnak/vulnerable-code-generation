//FormAI DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100

int main(){
    int status;
    long int i, loop, temp, *shmPtr;
    int shmId;
    pid_t pid;
    
    // Shared memory creation
    shmId = shmget(IPC_PRIVATE, SHSIZE, IPC_CREAT | 0666);
    if (shmId < 0){
        perror("shmget error");
        exit(EXIT_FAILURE);
    }
    
    // Allocate shared memory
    shmPtr = (long int*)shmat(shmId, NULL, 0);
    if (*shmPtr == -1){
        perror("shmat error");
        exit(EXIT_FAILURE);
    }
    
    // Start of the parent process. Fork a child.
    pid = fork();
    
    // Parent process
    if (pid > 0){
        printf("Parent process: Child process started with PID %d\n", pid);
        wait(NULL);
        printf("Parent process: Child process finished with PID %d\n", pid);
        printf("\nResult in shared memory: ");
        for (i = 0; i < SHSIZE; i++){
            printf("%ld ", shmPtr[i]);
        }
        printf("\n");
        
        // Detach and remove shared memory.
        shmdt(shmPtr);
        shmctl(shmId, IPC_RMID, 0);
    }
    // Child process
    else if (pid == 0){
        printf("Child process: Generating Fibonacci sequence...\n");
        shmPtr[0] = 0;
        shmPtr[1] = 1;
        for (i = 2; i < SHSIZE; i++){
            shmPtr[i] = shmPtr[i-1] + shmPtr[i-2];
        }
        printf("Child process: Fibonacci sequence generated...\n");
        exit(EXIT_SUCCESS);
    }
    // Error in forking
    else {
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}