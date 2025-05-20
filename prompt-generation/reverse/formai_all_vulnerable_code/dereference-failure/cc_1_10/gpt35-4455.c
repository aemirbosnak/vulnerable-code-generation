//FormAI DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

#define SHM_SIZE 4

int main(int argc, char **argv) {
    int shmid, pid, *shared_mem;
    key_t key;

    // Generate a unique key
    key = ftok("./", 's');

    // Creae shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    // Error handling for shared memory
    if(shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory to parent process
    shared_mem = (int *)shmat(shmid, NULL, 0);

    // Error handling for shared memory attachment
    if(shared_mem == (int *)-1) {
        perror("shmat");
        exit(1);
    }

    // Fork a child process
    pid = fork();

    // Error handling for fork
    if(pid < 0) {
        perror("fork");
        exit(1);
    }

    // Child process writes to shared memory segment
    else if(pid == 0) {
        printf("Enter a number: ");
        scanf("%d", shared_mem);
    }

    // Parent process reads from shared memory segment
    else {
        // Wait for child process to finish writing
        wait(NULL);
        printf("The number entered is: %d\n", *shared_mem);
    }

    // Detach shared memory segment from parent process
    shmdt(shared_mem);

    // Delete shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}