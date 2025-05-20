//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define MSG_SIZE 1024

typedef struct {
    char *message;
    int len;
} msg_t;

int main() {
    key_t key = SHM_KEY;
    int shmid = shmget(key, MSG_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Create a shared memory segment
    void *shm = mmap(NULL, MSG_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Set up a message buffer in the shared memory
    msg_t *msg = (msg_t *)shm;
    msg->message = "Hello, world!";
    msg->len = strlen(msg->message);

    // Create a pipe for communication
    int pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("pipe() failed");
        return 1;
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }
    if (pid > 0) {
        // Parent process
        close(pipefd[0]);
        printf("Parent: PID = %d, waiting for child\n", getpid());
        wait(NULL);
        return 0;
    }

    // Child process
    close(pipefd[1]);
    printf("Child: PID = %d, received message\n", getpid());

    // Read the message from the shared memory
    char *message = (char *)shm;
    int len = msg->len;
    read(pipefd[0], message, len);

    // Print the message
    printf("Child: Message received: %s\n", message);

    // Exit the child process
    exit(0);
}