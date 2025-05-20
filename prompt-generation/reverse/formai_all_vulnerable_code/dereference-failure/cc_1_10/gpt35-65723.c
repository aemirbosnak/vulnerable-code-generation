//FormAI DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024 /* Size of shared memory segment */

int main(int argc, char *argv[]) {
    
    /* Initializing variables */
    int pid, shmid, status;
    char *shmaddr;
    key_t key;
    
    /* Creating shared memory segment identified by key */
    key = ftok(".", 's');
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    
    if (shmid == -1) {
        perror("shmget error");
        exit(EXIT_FAILURE);
    }
    
    /* Forking a child process */
    pid = fork();
    
    if (pid == -1) {
        perror("fork error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* Child process */
        
        /* Attaching shared memory segment */
        shmaddr = shmat(shmid, NULL, 0);
        
        if (shmaddr == (char *) -1) {
            perror("shmat error");
            exit(EXIT_FAILURE);
        }
        
        /* Writing to shared memory */
        int i;
        int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (i = 0; i < 10; i++) {
            sprintf(shmaddr, "%d", data[i]);
            shmaddr += sizeof(int);
        }
        
        /* Detaching shared memory segment */
        shmdt(shmaddr);
        
        exit(EXIT_SUCCESS);
    } else {
        /* Parent process */
        
        /* Waiting for child process to finish */
        waitpid(pid, &status, 0);
        
        /* Attaching shared memory segment */
        shmaddr = shmat(shmid, NULL, 0);
        
        if (shmaddr == (char *) -1) {
            perror("shmat error");
            exit(EXIT_FAILURE);
        }
        
        /* Reading from shared memory */
        int i;
        int data[10];
        for (i = 0; i < 10; i++) {
            data[i] = atoi(shmaddr);
            shmaddr += sizeof(int);
        }
        
        /* Detaching shared memory segment */
        shmdt(shmaddr);
        
        /* Printing the data */
        printf("Data received from child process:\n");
        printf("[ ");
        for (i = 0; i < 10; i++) {
            printf("%d ", data[i]);
        }
        printf("]\n");
        
        /* Deleting shared memory segment */
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl error");
            exit(EXIT_FAILURE);
        }
        
        exit(EXIT_SUCCESS);
    }
}