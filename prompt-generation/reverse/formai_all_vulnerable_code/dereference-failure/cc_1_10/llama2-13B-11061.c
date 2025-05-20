//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define MESSAGE_SIZE 1024

void *shm_create(void)
{
    key_t key = SHM_KEY;
    size_t size = MESSAGE_SIZE;
    int shmid = shmget(key, size, IPC_CREAT | 0644);

    if (shmid == -1) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    void *shm = shmat(shmid, NULL, 0);
    if (shm == NULL) {
        perror("shmat() failed");
        exit(EXIT_FAILURE);
    }

    return shm;
}

void shm_send(void *shm, const char *message)
{
    size_t message_len = strlen(message);
    char *ptr = shm;

    for (size_t i = 0; i < message_len; i++) {
        *(ptr++) = message[i];
    }
}

void *shm_recv(void *shm)
{
    char *ptr = shm;
    size_t message_len = strlen(ptr);
    char *message = malloc(message_len + 1);

    for (size_t i = 0; i < message_len; i++) {
        message[i] = *(ptr++) ;
    }

    message[message_len] = '\0';
    return message;
}

int main(void)
{
    pid_t pid = getpid();
    printf("Hello from %d\n", pid);

    void *shm = shm_create();
    shm_send(shm, "Hello from parent process");

    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process
        void *message = shm_recv(shm);
        printf("Received message from parent process: %s\n", message);
        free(message);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}