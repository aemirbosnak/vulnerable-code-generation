//FormAI DATASET v1.0 Category: Interprocess communication ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
    // Create a shared memory segment
    key_t key = ftok("ipc_example", 'R');
    int shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);
    if(shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the segment to the process' virtual address space
    char *data = shmat(shmid, (void *)0, 0);
    if(data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Write to the shared memory segment
    printf("Enter a message: ");
    fgets(data, SHM_SIZE, stdin);

    // Start a child process to read from the shared memory segment
    pid_t pid = fork();
    if(pid == -1) {
        perror("fork");
        exit(1);
    }

    if(pid == 0) {
        // Child process reads from the shared memory segment
        printf("Child process reading from shared memory segment...\n");
        printf("Message received: %s", data);

        // Detach the segment from the child process' virtual address space
        if(shmdt(data) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Release the shared memory segment
        if(shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }

        exit(0);
    } else {
        // Parent process waits for the child to finish
        int status;
        waitpid(pid, &status, 0);

        // Detach the segment from the parent process' virtual address space
        if(shmdt(data) == -1) {
            perror("shmdt");
            exit(1);
        }
    }

    return 0;
}