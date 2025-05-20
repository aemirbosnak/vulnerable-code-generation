//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmaddr;

    // Create a shared memory segment
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666); 
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to this process
    shmaddr = shmat(shmid, NULL, 0);
    if (*shmaddr == -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    printf("The shared memory segment's ID is %d\n", shmid);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        char message[SHM_SIZE];
        printf("Enter a message to send to the parent process: ");
        fgets(message, SHM_SIZE, stdin);

        // Write the message to shared memory
        strcpy(shmaddr, message);

        printf("Child process has written the message '%s' to shared memory\n", message);

        // Detach the shared memory segment from this process
        if (shmdt(shmaddr) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        wait(NULL);

        printf("Parent process has received the message '%s' from shared memory\n", shmaddr);

        // Detach the shared memory segment from this process
        if (shmdt(shmaddr) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        // Delete the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }

        printf("Parent process has deleted the shared memory segment and exited.\n");
        exit(EXIT_SUCCESS);
    }
}