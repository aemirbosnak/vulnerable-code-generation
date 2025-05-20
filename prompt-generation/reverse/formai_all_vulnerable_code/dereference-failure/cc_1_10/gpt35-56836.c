//FormAI DATASET v1.0 Category: Interprocess communication ; Style: futuristic
/* Welcome to the interstellar communication system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define MAX_LEN 100

int main()
{
    int shmid;
    key_t key = 1234;
    char *shm;
    char buffer[MAX_LEN];
    pid_t pid;
    
    // Create a shared memory segment
    if ((shmid = shmget(key, MAX_LEN, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget failed");
        exit(1);
    }
    
    // Attach to the shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
    {
        perror("shmat failed");
        exit(1);
    }
    
    printf("Welcome to the Intersellar Communication System!\n");
    printf("Enter the message you want to send to another system: ");
    fgets(buffer, MAX_LEN, stdin);
    
    pid = fork();
    
    if (pid < 0)
    {
        perror("fork failed");
        exit(1);
    }
    
    if (pid == 0)
    {
        // Child process
        printf("Connecting to remote system...\n");
        sleep(2);
        strcpy(shm, buffer);
        printf("Message sent to remote system!\n");
        exit(0);
    }
    else
    {
        // Parent process
        printf("Waiting for message acknowledgment from remote system...\n");
        wait(NULL);
        printf("Message acknowledged by remote system!\n");
        printf("Received message from remote system: %s", shm);
        printf("Thank you for using the Intersellar Communication System!\n");
        
        // Detach from the shared memory segment
        if (shmdt(shm) == -1)
        {
            perror("shmdt failed");
            exit(1);
        }
        
        // Remove the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1)
        {
            perror("shmctl failed");
            exit(1);
        }
    }
    
    return 0;
}