//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>

#define MSG_SIZE 1024

typedef struct {
    char message[MSG_SIZE];
} message_t;

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, sizeof(message_t), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Attach to the shared memory segment
    message_t *message = mmap(NULL, sizeof(message_t), PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (message == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Set the message
    strcpy(message->message, "Hello, world!");

    // Create a pipe for interprocess communication
    int fd[2];
    pipe(fd);

    // Set up the message queue
    if (msgrcv(shmid, &message, MSG_SIZE, 0) < 0) {
        perror("msgrcv() failed");
        return 1;
    }

    // Write the message to the pipe
    if (write(fd[1], message, MSG_SIZE) < 0) {
        perror("write() failed");
        return 1;
    }

    // Wait for the message to be read
    if (read(fd[0], message, MSG_SIZE) < 0) {
        perror("read() failed");
        return 1;
    }

    // Print the received message
    printf("Received message: %s\n", message->message);

    // Clean up
    munmap(message, sizeof(message_t));
    close(shmid);
    close(fd[0]);
    close(fd[1]);

    return 0;
}