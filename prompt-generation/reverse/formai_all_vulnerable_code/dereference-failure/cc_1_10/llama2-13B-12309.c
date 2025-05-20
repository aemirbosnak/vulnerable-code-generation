//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <utime.h>

#define MAX_NAME_LEN 20
#define MAX_MESSAGE_LEN 100

struct message {
    char name[MAX_NAME_LEN];
    char message[MAX_MESSAGE_LEN];
};

int main() {
    // Create a shared memory segment
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, sizeof(struct message), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    struct message *msg = mmap(NULL, sizeof(struct message), PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (msg == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Set up the message
    strcpy(msg->name, "Happy");
    strcpy(msg->message, "Hello, world!");

    // Send the message to other processes
    for (int i = 0; i < 5; i++) {
        // Fork a new process
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            return 1;
        }
        if (pid == 0) {
            // Child process
            char *message = msg->message;
            char *name = msg->name;
            printf("Received message from %s: %s\n", name, message);
            sleep(1);
            // Send a response back to the parent process
            char *response = "Hello, parent!";
            write(STDOUT_FILENO, response, strlen(response));
            exit(0);
        } else {
            // Parent process
            wait(NULL);
        }
    }

    // Unmap the shared memory segment
    munmap(msg, sizeof(struct message));

    return 0;
}