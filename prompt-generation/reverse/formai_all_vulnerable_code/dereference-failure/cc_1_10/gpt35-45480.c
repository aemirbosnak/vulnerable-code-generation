//FormAI DATASET v1.0 Category: Interprocess communication ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;
    pid_t pid;
    
    //generate a unique key
    key = ftok(".", 'p');
    
    //create a shared memory segment
    shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    
    //attach it to our process
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    
    //fork a child process
    pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(1);
    } 
    
    //in child process
    else if (pid == 0) {
        printf("Child process writing to shared memory\n");
        s = shm;
        char *msg = "Hello from child process!";
        for (int i = 0; i < 26; i++) {
            *s++ = *msg++;
        }
        *s = '\0';
        exit(0);
    }
    
    //in parent process
    else {
        printf("Parent process reading from shared memory\n");
        wait(NULL);
        printf("Message from child process: %s\n", shm);
        
        //detach from shared memory
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }
        
        //delete the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }
    
    return 0;
}