//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void *shm_create(void)
{
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0644);

    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    printf("Shm ID: %d\n", shmid);

    return shmat(shmid, NULL, 0);
}

void shm_send(int shmid, char *message)
{
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *shm_ptr = shmat(shmid, NULL, 0);
    strcpy(shm_ptr, message);
    shmdt(shm_ptr);
}

void *shm_recv(int shmid)
{
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *shm_ptr = shmat(shmid, NULL, 0);
    printf("Received message: %s\n", shm_ptr);
    shmdt(shm_ptr);

    return shm_ptr;
}

int main()
{
    int shmid1, shmid2;
    char message[BUFFER_SIZE];

    // Create shared memory
    shmid1 = shm_create();
    if (shmid1 == -1) {
        perror("shmcreate");
        exit(EXIT_FAILURE);
    }

    // Send message from parent to child
    strcpy(message, "Hello, child!");
    shm_send(shmid1, message);

    // Fork child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        shmid2 = shm_recv(shmid1);
        printf("Received message: %s\n", shmid2);
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}