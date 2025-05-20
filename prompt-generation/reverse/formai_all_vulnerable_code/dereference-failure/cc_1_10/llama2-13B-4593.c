//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define MSG_LEN 1024

typedef struct {
    char message[MSG_LEN];
} message_t;

int main(void) {
    key_t shm_key = SHM_KEY;
    int shmid = shmget(shm_key, sizeof(message_t), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Create a shared memory object
    message_t *shm = mmap(NULL, sizeof(message_t), PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Fill the shared memory with a message
    strcpy(shm->message, "Hello, world!");

    // Create a pipe for communication
    int fd[2];
    pipe(fd);

    // Fork a child process to read from the pipe
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }
    if (pid == 0) {
        // Child process reads from the pipe
        read(fd[0], shm->message, MSG_LEN);
        printf("Received message: %s\n", shm->message);
    } else {
        // Parent process writes to the pipe
        write(fd[1], "Hello, world!", strlen("Hello, world!"));
    }

    // Unmap the shared memory
    munmap(shm, sizeof(message_t));

    return 0;
}