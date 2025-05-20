//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define SIZE 100

int main() {
    int shmid, i;
    char *shmptr;
    pid_t pid;
    char *message = "Hello, Interprocess Communication!";

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        fprintf(stderr, "Unable to create shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        fprintf(stderr, "Unable to attach shared memory segment: %s\n", strerror(errno));
        exit(2);
    }

    // Initialize shared memory segment with message
    strcpy(shmptr, message);

    // Fork child process
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Unable to fork process: %s\n", strerror(errno));
        exit(3);
    } else if (pid == 0) {
        // Child process writes to shared memory segment
        for (i = 0; i < strlen(message); i++) {
            shmptr[i] = toupper(shmptr[i]);
        }
        printf("Child process modified message: %s\n", shmptr);
    } else {
        // Parent process reads from shared memory segment
        wait(NULL);
        printf("Parent process received message: %s\n", shmptr);
    }

    return 0;
}