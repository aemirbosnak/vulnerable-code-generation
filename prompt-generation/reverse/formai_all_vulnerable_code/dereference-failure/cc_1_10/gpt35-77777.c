//FormAI DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

#define SHSIZE 100

int main(){
    int shmid;
    key_t key;
    char *shm, *s;

    key = 9876;

    shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);

    if (shmid < 0){
        perror("Error in shmget.");
        return 1;
    }

    shm = shmat(shmid, NULL, 0);

    if (shm == (char *) -1){
        perror("Error in shmat.");
        return 1;
    }

    // Message to be sent
    sprintf(shm, "Hello there!");

    int pid = fork();

    if(pid == 0){
        char *child_message;
        child_message = (char *) calloc(sizeof(char), SHSIZE);

        // Waiting for parent message
        while(*shm == ' ');

        for(s = shm; *s != '\0'; s++)
            putchar(*s);
        putchar('\n');

        sprintf(child_message, "Hi parent, this is your child process.");
        strcpy(shm, child_message);

        // Detaching shared memory
        shmdt(shm);
        exit(0);

    }

    else {
        int status;
        waitpid(pid, &status, 0);
        printf("Message received: %s\n",shm);
        // Detaching and removing shared memory
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}