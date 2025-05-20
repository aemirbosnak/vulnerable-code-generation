//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define MSG_SIZE 256
#define SHM_KEY 1234

void romeo_process() {
    int shmid = shmget(SHM_KEY, MSG_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Romeo: Failed to get shared memory");
        exit(1);
    }

    char *shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("Romeo: Failed to attach shared memory");
        exit(1);
    }

    const char *msg = "Oh, Juliet! My heart is bound to you.";
    printf("Romeo writes: %s\n", msg);
    strncpy(shm_ptr, msg, MSG_SIZE);
    shm_ptr[MSG_SIZE - 1] = '\0'; // Ensure null termination

    // Wait for Juliet to read
    while (shm_ptr[0] != '\0') {
        sleep(1);
    }

    shmdt(shm_ptr);
}

void juliet_process() {
    int shmid = shmget(SHM_KEY, MSG_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Juliet: Failed to get shared memory");
        exit(1);
    }

    char *shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("Juliet: Failed to attach shared memory");
        exit(1);
    }

    // Wait for Romeo's message
    while (shm_ptr[0] == '\0') {
        sleep(1);
    }

    printf("Juliet reads: %s\n", shm_ptr);
    const char *response = "My love, Romeo! How shall we be together?";
    strncpy(shm_ptr, response, MSG_SIZE);
    shm_ptr[MSG_SIZE - 1] = '\0'; // Ensure null termination

    // Signal that Juliet has sent a response
    sleep(1);
    shmdt(shm_ptr);
}

void cleanup_memory() {
    int shmid = shmget(SHM_KEY, MSG_SIZE, IPC_CREAT | 0666);
    shmctl(shmid, IPC_RMID, NULL);
}

int main() {
    int pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process: Juliet
        sleep(1); // Ensure Romeo runs first to send message
        juliet_process();
    } else {
        // Parent process: Romeo
        romeo_process();
        wait(NULL); // Wait for Juliet
        cleanup_memory(); // Clean up shared memory
    }

    return 0;
}