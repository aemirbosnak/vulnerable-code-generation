//FormAI DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024 /* size for shared memory segment */

int main(void) {
    pid_t pid;
    key_t key;
    char *shm;
    char message[SHM_SIZE];
    
    /* create a new key for the shared memory segment */
    if ((key = ftok(".", 'S')) == -1) {
        perror("ftok");
        exit(1);
    }
    
    /* create the shared memory segment */
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    
    /* attach the shared memory segment to the process's address space */
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    
    /* fork a child process */
    pid = fork();
    
    if (pid < 0) { /* error occurred */
        perror("fork");
        exit(1);
    } else if (pid == 0) { /* child process */
        printf("Enter a message: ");
        fgets(message, SHM_SIZE, stdin);
        strncpy(shm, message, SHM_SIZE);
    } else { /* parent process */
        wait(NULL);
        printf("Received message: %s\n", shm);
        
        /* detach and remove the shared memory segment */
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }
    
    return 0;
}