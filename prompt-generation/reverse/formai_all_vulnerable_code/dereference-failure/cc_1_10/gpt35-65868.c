//FormAI DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024 // Defining shared memory size

int main() {
    int pid, shmid;
    char *shm;
    char buffer[SHM_SIZE];
    key_t key = 12345; // Initializing key for shared memory

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); // Creating shared memory segment

    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0); // Attaching shared memory segment to the process

    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    pid = fork(); // Forking a new process

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { // Child process
        printf("Enter a message to send to the parent process: ");
        fgets(buffer, SHM_SIZE, stdin); // Reading user input

        strncpy(shm, buffer, SHM_SIZE); // Copying message to shared memory

        shmdt(shm); // Detaching shared memory segment

        exit(0);
    } else { // Parent process
        wait(NULL); // Waiting for child process to finish

        printf("Message received from child process: %s", shm); // Printing received message

        shmdt(shm); // Detaching shared memory segment
        shmctl(shmid, IPC_RMID, NULL); // Removing shared memory segment

        exit(0);
    }

    return 0;
}