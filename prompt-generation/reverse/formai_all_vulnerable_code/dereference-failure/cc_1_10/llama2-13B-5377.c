//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <fcntl.h>

#define SHM_KEY 0xdeadbeef
#define MSG_SIZE 1024

typedef struct {
    char message[MSG_SIZE];
    int sender;
} message_t;

int main() {
    // Create a shared memory segment
    int shmid = shmget(SHM_KEY, sizeof(message_t), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Attach to the shared memory segment
    message_t *msg = mmap(NULL, sizeof(message_t), PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (msg == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Set up the message buffer
    char *buffer = msg->message;
    memset(buffer, 0, MSG_SIZE);

    // Create a pipe for communication
    int pipefd[2];
    pipe(pipefd);

    // Fork a child process to handle incoming messages
    pid_t child = fork();
    if (child < 0) {
        perror("fork() failed");
        return 1;
    }
    if (child == 0) {
        // Child process
        close(pipefd[0]);
        read(pipefd[1], buffer, MSG_SIZE);
        printf("Received message: %s\n", buffer);
        exit(0);
    } else {
        // Parent process
        close(pipefd[1]);

        // Loop indefinitely to handle incoming messages
        while (1) {
            // Write a message to the shared memory segment
            strcpy(buffer, "Hello, world!");
            write(pipefd[0], buffer, MSG_SIZE);

            // Sleep for a short period of time to avoid overloading the pipe
            sleep(1);
        }
    }

    return 0;
}