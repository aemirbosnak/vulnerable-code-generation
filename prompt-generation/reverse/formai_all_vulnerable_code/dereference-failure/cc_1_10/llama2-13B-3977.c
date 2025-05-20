//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

// Structure to hold the shared data
struct shared_data {
    int num1;
    int num2;
    int avg;
};

// Function to send data from parent to child process
void send_data(int num1, int num2) {
    struct shared_data data;
    data.num1 = num1;
    data.num2 = num2;
    data.avg = (num1 + num2) / 2;

    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, sizeof(struct shared_data), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the current process
    void *addr = shmat(shmid, NULL, 0);
    if (addr == (void *) -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    // Fill the shared data structure with the data to be sent
    memcpy(addr, &data, sizeof(struct shared_data));

    // Detach the shared memory segment from the current process
    shmdt(addr);
}

// Function to receive data in child process
void receive_data(int shmid) {
    struct shared_data *data = (struct shared_data *) shmat(shmid, NULL, 0);
    if (data == (struct shared_data *) -1) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    printf("Received data: num1 = %d, num2 = %d, avg = %d\n",
           data->num1, data->num2, data->avg);

    // Detach the shared memory segment from the current process
    shmdt(data);
}

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, sizeof(struct shared_data), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        exit(EXIT_FAILURE);
    }

    // Parent process sends data to child process
    if (pid > 0) {
        int num1 = 10, num2 = 20;
        send_data(num1, num2);
    }

    // Child process receives data from parent process
    else {
        receive_data(shmid);
    }

    // Wait for the child process to finish
    wait(NULL);

    return 0;
}