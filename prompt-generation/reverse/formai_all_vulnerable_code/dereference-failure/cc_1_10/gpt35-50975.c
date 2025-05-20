//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHMSIZE 100

int main()
{
    printf("Holy cow, we are going to learn about Interprocess Communication!\n");

    int shmid;
    key_t key;
    char *shm, *s;

    key = 1000; // Define a key for shared memory

    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666); // Create a shared memory segment
    if (shmid < 0) {
        perror("Err: shmget");
        exit(1); // Oh no, something went wrong
    }

    shm = shmat(shmid, NULL, 0); // Attach the memory segment to our data space
    if (shm == (char *) -1) {
        perror("Err: shmat");
        exit(1); // Oh no, something went wrong
    }

    // Let's write something to the shared memory
    printf("What message would you like to write to the shared memory?\n");
    fgets(shm, SHMSIZE, stdin);

    // Let's check if the message is there
    printf("Is the message [%s] in the shared memory? Let's find out!\n", shm);

    for (s = shm; *s != '\0'; s++)
        putchar(*s);

    *shm = '*'; // Terminate the message with a *

    // Detach the shared memory segment from our data space
    shmdt(shm);

    // Let's read the message from the shared memory from a different process
    pid_t pid = fork(); // Fork a child process
    if (pid < 0) {
        perror("Err: fork");
        exit(1); // Oh no, something went wrong
    } else if (pid == 0) { // We are in the child process
        char *shm_child;
        key_t key_child;

        key_child = 1000; // Use the same key as the parent process

        int shmid_child = shmget(key_child, SHMSIZE, 0666); //  Get the shared memory segment created by the parent process
        if (shmid_child < 0) {
            perror("Err: shmget in child process");
            exit(1); // Oh no, something went wrong
        }

        shm_child = shmat(shmid_child, NULL, 0); // Attach the memory segment to our data space
        if (shm_child == (char *) -1) {
            perror("Err: shmat in child process");
            exit(1); // Oh no, something went wrong
        }

        while (*shm_child != '*') // Read the message from the shared memory
            putchar(*shm_child++);

        putchar('\n');

        // Detach the shared memory segment from our data space
        shmdt(shm_child);

        // Delete the shared memory segment
        shmctl(shmid_child, IPC_RMID, NULL);

        exit(0); // Exit the child process
    } else { // We are in the parent process
        wait(NULL); // Wait for the child process to terminate

        // Delete the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);

        printf("Wow, interprocess communication is so cool! We shared a message!\n");
    }

    return 0;
}