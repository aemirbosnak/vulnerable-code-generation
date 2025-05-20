//FormAI DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

#define SHM_KEY 4567

typedef struct data {
    int num;
    double price;
} data;

int main() {
    pid_t pid;
    int shmid, status;
    data *data_ptr;
    srand(time(0));

    // Create shared memory
    shmid = shmget(SHM_KEY, sizeof(data), IPC_CREAT | 0666);
    if(shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory to process
    data_ptr = (data*) shmat(shmid, NULL, 0);
    if(data_ptr == (void*)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Fork child process
    pid = fork();
    if(pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0) { // Child process
        printf("Child process executing...\n");
        int num = (rand() % (100 - 1 + 1)) + 1;
        double price = (double)(rand() % (10000 - 1 + 1)) + 1.0;
        data_ptr->num = num;
        data_ptr->price = price;
        printf("Child process wrote values to shared memory: {num: %d, price: %.2f}\n", num, price);
        exit(EXIT_SUCCESS);
    }
    else { // Parent process
        wait(&status);
        printf("Parent process executing...\n");
        printf("Parent process read values from shared memory: {num: %d, price: %.2f}\n", data_ptr->num, data_ptr->price);

        // Detach shared memory from process
        if(shmdt(data_ptr) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        // Remove shared memory
        if(shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}