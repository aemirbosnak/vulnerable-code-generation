//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024

void *shm_create(void)
{
    int shmid = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    void *shm = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    return shm;
}

void shm_write(void *shm, char *message)
{
    char *ptr = shm;
    while (*message != '\0') {
        *ptr++ = *message++;
    }
    *ptr = '\0';
}

char *shm_read(void *shm)
{
    char *ptr = shm;
    char message[BUFFER_SIZE];
    memset(message, 0, BUFFER_SIZE);

    while (*ptr != '\0') {
        message[strcspn(ptr, "\n")] = '\0';
        ptr += strlen(message) + 1;
    }

    return message;
}

int main()
{
    void *shm = shm_create();
    char *message = "Hello, world!";
    shm_write(shm, message);

    // Fork a new process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char *message = shm_read(shm);
        printf("Received message: %s\n", message);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}