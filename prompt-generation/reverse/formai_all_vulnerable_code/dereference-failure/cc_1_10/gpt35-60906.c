//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(void) {
    char message[SHM_SIZE];
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate a unique key
    if ((key = ftok("input.txt", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment 
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the segment to our data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Read a message from the user
    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);

    // Copy the message into the shared memory segment
    memcpy(shm, message, strlen(message)+1);
    printf("Message sent!\n");

    // Pass control to the receiver process
    printf("Waiting for receiver process...\n");
    sleep(5);

    // Print out the message received by the receiver process
    printf("Received message: ");
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    // Detach and remove the shared memory segment
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}