//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {

    // Generate a key for shared memory segment
    key_t key = ftok("/home/user/shared_memory", 1);

    // Create a shared memory segment
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    // Attach to shared memory segment
    char *shm = (char*) shmat(shmid, NULL, 0);

    // Set the message in shared memory segment
    sprintf(shm, "Hello from process 1");

    // Detach from shared memory segment
    shmdt(shm);

    // Fork a new process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process

        // Attach to shared memory segment
        char *shm = (char*) shmat(shmid, NULL, 0);

        // Wait for message from process 1
        while (shm[0] == '\0') {
            sleep(1);
        }

        // Print the message from process 1
        printf("Message from process 1: %s\n", shm);

        // Set the message in shared memory segment
        sprintf(shm, "Hello from process 2");

        // Detach from shared memory segment
        shmdt(shm);
    } else if (pid > 0) {
        // Parent process

        // Attach to shared memory segment
        char *shm = (char*) shmat(shmid, NULL, 0);

        // Wait for message from process 2
        while (shm[0] == '\0') {
            sleep(1);
        }

        // Print the message from process 2
        printf("Message from process 2: %s\n", shm);

        // Detach from shared memory segment
        shmdt(shm);

        // Remove the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    } else {
        // Error forking new process
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}