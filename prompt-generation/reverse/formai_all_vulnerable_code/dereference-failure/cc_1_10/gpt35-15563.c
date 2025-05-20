//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

// Grateful Greetings!
// Welcome to my Interprocess Communication example program.
// In this example, we will use shared memory to communicate 
// between two processes: a sender and a receiver.

#define SHM_SIZE 512   // Shared memory size
#define SHM_KEY 12345  // Shared memory key

int main() {
    // First, we create a shared memory segment.
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget error");
        exit(1);
    }

    // Now we attach the shared memory segment to the sender process.
    char *message = (char *) shmat(shmid, NULL, 0);
    if (message == (char *) -1) {
        perror("shmat error");
        exit(1);
    }

    // Let's get some input from the user.
    printf("Enter a message to send: ");
    fgets(message, SHM_SIZE, stdin);

    // Remove newline character from the message.
    message[strcspn(message, "\n")] = 0;

    // Detach the shared memory segment.
    if (shmdt(message) == -1) {
        perror("shmdt error");
        exit(1);
    }

    // Now we fork a new process to be the receiver.
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork error");
        exit(1);

    // The receiver process.
    } else if (pid == 0) {
        // We attach the shared memory segment to the receiver process.
        char *message = (char *) shmat(shmid, NULL, 0);
        if (message == (char *) -1) {
            perror("shmat error");
            exit(1);
        }

        // Print the received message.
        printf("Received message: %s\n", message);

        // Detach the shared memory segment.
        if (shmdt(message) == -1) {
            perror("shmdt error");
            exit(1);
        }

        // Finally, we remove the shared memory segment.
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl error");
            exit(1);
        }

    // The sender process.
    } else {
        // Wait for the receiver process to finish.
        wait(NULL);

        printf("Message sent successfully!\n");
    }

    return 0;
}