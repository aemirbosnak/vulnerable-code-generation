//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024
#define SHM_KEY 0xDEADBEEF

typedef struct {
    char message[MESSAGE_SIZE];
    int length;
} message_t;

void *shm_create(void) {
    int shmid = shmget(SHM_KEY, sizeof(message_t), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(1);
    }
    return shmat(shmid, NULL, 0);
}

void shm_send(int fd, const char *message) {
    message_t *msg = (message_t *)shmat(fd, NULL, 0);
    strcpy(msg->message, message);
    msg->length = strlen(message);
}

void shm_recv(int fd, char *buffer, int size) {
    message_t *msg = (message_t *)shmat(fd, NULL, 0);
    memcpy(buffer, msg->message, msg->length);
}

int main(void) {
    int shmid = shmget(SHM_KEY, sizeof(message_t), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(1);
    }

    // Create the shared memory
    char *shm = shmat(shmid, NULL, 0);
    if (!shm) {
        perror("shmat() failed");
        exit(1);
    }

    // Create the pipes
    int fd[2];
    pipe(fd);

    // Create the parent and child processes
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        close(fd[0]);
        shm_send(fd[1], "Hello, world!");
        wait(NULL);
    } else {
        // Parent process
        close(fd[1]);
        char buffer[MESSAGE_SIZE];
        shm_recv(fd[0], buffer, sizeof(buffer));
        printf("Received message: %s\n", buffer);
    }

    // Clean up
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}