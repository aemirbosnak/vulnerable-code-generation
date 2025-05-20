//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <semaphore.h>

#define MESSAGE_SIZE 1024
#define BUFFER_SIZE 4096

typedef struct {
    char message[MESSAGE_SIZE];
    int length;
} message_t;

sem_t sem;

void* shm_create(key_t key, size_t size) {
    void* shm = shmget(key, size, IPC_CREAT | 0644);
    if (shm == NULL) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    return shm;
}

void* shm_write(void* shm, const char* message, int length) {
    message_t* data = shm;
    memset(data->message, 0, MESSAGE_SIZE);
    strncpy(data->message, message, length);
    data->length = length;
    return shm;
}

char* shm_read(void* shm, int length) {
    message_t* data = shm;
    if (length > data->length) {
        length = data->length;
    }
    return data->message;
}

int main() {
    sem_init(&sem, 0, 1);

    // Create shared memory
    void* shm = shm_create(IPC_PRIVATE, BUFFER_SIZE);
    if (shm == NULL) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Write message to shared memory
    char message[] = "Hello, world!";
    int length = strlen(message);
    shm_write(shm, message, length);

    // Wait for reader to finish
    sem_wait(&sem);

    // Read message from shared memory
    char* message_read = shm_read(shm, length);
    printf("Received message: %s\n", message_read);

    // Release shared memory
    shmctl(shm, IPC_RMID, 0);

    return 0;
}