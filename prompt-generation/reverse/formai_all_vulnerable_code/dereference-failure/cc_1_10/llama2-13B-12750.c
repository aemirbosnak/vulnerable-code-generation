//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MSG_SIZE 1024

struct message {
    char data[MSG_SIZE];
    int len;
};

int main() {
    key_t key = IPC_PRIVATE;
    int shmid = shmget(IPC_PRIVATE, sizeof(struct message), IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Create a shared memory object
    struct message *shm = mmap(NULL, sizeof(struct message), PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Set up the message buffer
    char *msg = "Hello, world!";
    shm->len = strlen(msg);
    memcpy(shm->data, msg, shm->len);

    // Create a pipe for communication
    int fd[2];
    pipe(fd);

    // Set up the message sender
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        close(fd[0]);
        write(fd[1], shm->data, shm->len);
        exit(0);
    } else {
        // Parent process
        close(fd[1]);

        // Read from the pipe
        char buffer[MSG_SIZE];
        read(fd[0], buffer, MSG_SIZE);

        // Print the received message
        printf("Received message: %s\n", buffer);

        // Unmap the shared memory
        munmap(shm, sizeof(struct message));
        shmctl(shmid, IPC_RMID, 0);
    }

    return 0;
}