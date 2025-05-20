//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <sys/mman.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MESSAGE_SIZE 1024

void* shm_region;

int main() {
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0600);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    shm_region = shmat(shmid, NULL, 0);
    if (shm_region == (void*) -1) {
        perror("shmat");
        return 1;
    }

    char message[MESSAGE_SIZE];
    strcpy(message, "Hello from child process!");
    size_t message_len = strlen(message);

    // Write message to shared memory
    memcpy(shm_region, message, message_len);

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char* shm_ptr = shm_region;
        printf("Received message: %s\n", shm_ptr);
        // Do something with the message
        // ...
        exit(0);
    } else {
        // Parent process
        wait(NULL);
    }

    // Clean up
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}