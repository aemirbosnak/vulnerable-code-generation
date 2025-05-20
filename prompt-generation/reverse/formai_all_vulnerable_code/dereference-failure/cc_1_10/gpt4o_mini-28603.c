//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

#define SHM_SIZE 1024  // Size of shared memory
#define PERMISSION 0666 // Permissions for the shared memory

void write_data(int shmid) {
    char *data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    printf("Writer Process: Writing to shared memory...\n");
    char message[] = "Hello from Writer!";
    strncpy(data, message, sizeof(message));
    printf("Writer Process: Data written: %s\n", data);
    
    // Detach from shared memory
    shmdt(data);
}

void read_data(int shmid) {
    char *data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    printf("Reader Process: Reading from shared memory...\n");
    printf("Reader Process: Data read: %s\n", data);

    // Detach from shared memory
    shmdt(data);
}

void cleanup(int shmid) {
    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);
    printf("Cleanup: Shared memory segment destroyed.\n");
}

int main() {
    key_t key = ftok("shmfile", 65); // Create unique key
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Creating shared memory segment
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | PERMISSION);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    printf("Main: Shared memory segment created with ID: %d\n", shmid);

    // Forking process
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    
    if (pid == 0) {
        // Child Process (Writer)
        write_data(shmid);
        exit(0);
    } else {
        // Parent Process (Reader)
        sleep(2); // Ensure writer runs before reader
        read_data(shmid);
        cleanup(shmid);
    }

    return 0;
}