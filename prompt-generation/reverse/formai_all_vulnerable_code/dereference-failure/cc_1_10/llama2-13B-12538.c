//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024

// Structure to hold data shared between processes
struct data {
    char message[MAX_BUFFER_SIZE];
    int count;
};

// Function to create a shared memory segment
int create_shm(int shmid) {
    key_t key = IPC_PRIVATE;
    int shm = shmget(key, sizeof(struct data), IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget");
        return 1;
    }
    return shm;
}

// Function to attach to a shared memory segment
int attach_shm(int shmid) {
    key_t key = IPC_PRIVATE;
    struct data *shm = shmat(shmid, NULL, 0);
    if (shm == NULL) {
        perror("shmat");
        return 1;
    }
    return 0;
}

// Function to detach from a shared memory segment
int detach_shm(int shmid) {
    key_t key = IPC_PRIVATE;
    if (shmdt(shmid) == -1) {
        perror("shmdt");
        return 1;
    }
    return 0;
}

// Function to send data from one process to another
int send_data(int shmid, char *message, int count) {
    key_t key = IPC_PRIVATE;
    struct data *shm = shmat(shmid, NULL, 0);
    if (shm == NULL) {
        perror("shmat");
        return 1;
    }
    strcpy(shm->message, message);
    shm->count = count;
    shmdt(shmid);
    return 0;
}

// Function to receive data in another process
int recv_data(int shmid, char *message, int count) {
    key_t key = IPC_PRIVATE;
    struct data *shm = shmat(shmid, NULL, 0);
    if (shm == NULL) {
        perror("shmat");
        return 1;
    }
    strcpy(message, shm->message);
    shm->count = count;
    shmdt(shmid);
    return 0;
}

int main() {
    // Create a shared memory segment
    int shmid = create_shm(1);
    if (shmid == -1) {
        perror("create_shm");
        return 1;
    }

    // Fork multiple processes to communicate
    int p1 = fork();
    int p2 = fork();
    int p3 = fork();

    // Parent process
    if (p1 == 0) {
        char message[] = "Hello from P1!";
        send_data(shmid, message, strlen(message));
        wait(NULL);
    }

    // Child process 1
    if (p2 == 0) {
        char message[] = "Hello from P2!";
        recv_data(shmid, message, strlen(message));
        printf("Received message from P1: %s\n", message);
        wait(NULL);
    }

    // Child process 2
    if (p3 == 0) {
        char message[] = "Hello from P3!";
        send_data(shmid, message, strlen(message));
        wait(NULL);
    }

    // Detach from shared memory segment
    detach_shm(shmid);

    return 0;
}