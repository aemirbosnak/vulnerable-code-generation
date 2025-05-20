//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 //Shared memory segment size

struct shared_mem {
    int num1;
    int num2;
    int sum;
};

int main() {
    key_t key = ftok("/tmp", 'z'); //Create a unique key using file path and a character

    if (key == -1) {
        perror("ftok failed"); //If key creation fails, print error and terminate
        exit(1);
    }

    int shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT); //Create shared memory segment using key

    if (shmid == -1) {
        perror("shmget failed"); //If shared memory segment creation fails, print error and terminate
        exit(1);
    }

    struct shared_mem *shared_memory = shmat(shmid, (void *)0, 0); //Attach the shared memory segment to process address space

    if (shared_memory == (void *)-1) {
        perror("shmat failed"); //If attachment to process address space fails, print error and terminate
        exit(1);
    }

    shared_memory->num1 = 10; //Write data to shared memory
    shared_memory->num2 = 20;

    pid_t pid = fork(); //Create a child process to read data from shared memory

    if (pid == -1) {
        perror("fork failed"); //If process creation fails, print error and terminate
        exit(1);
    }

    if (pid == 0) { //Child process reads data from shared memory and calculates sum
        shared_memory->sum = shared_memory->num1 + shared_memory->num2;
        printf("Sum = %d\n", shared_memory->sum);
        shmdt(shared_memory); //Detach shared memory segment from process address space
        exit(0);
    } else { //Parent process waits for child process to complete and then cleans up shared memory segment
        wait(NULL);
        if (shmctl(shmid, IPC_RMID, NULL) == -1) { //Delete shared memory segment
            perror("shmctl failed"); //If deletion fails, print error
        }
    }

    return 0;
}