//FormAI DATASET v1.0 Category: Interprocess communication ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    int shmid;
    key_t key;
    char *shm;
    pid_t pid;
    
    // generate a key for shared memory segment
    key = ftok("ipc_example", 'R');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }
    
    // create shared memory segment
    shmid = shmget(key, BUFFER_SIZE, 0666|IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    
    // attach shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char*)-1) {
        perror("shmat");
        exit(1);
    }
    
    // fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // child process writes to shared memory
        printf("Enter a message: ");
        fgets(shm, BUFFER_SIZE, stdin);
        printf("Child process wrote message to shared memory: %s\n", shm);
        exit(0);
    } else {
        // parent process waits for child to finish writing to shared memory
        wait(NULL);
        printf("Parent process read message from shared memory: %s", shm);
        
        // detach shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }
        
        // remove shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
        
        exit(0);
    }
}