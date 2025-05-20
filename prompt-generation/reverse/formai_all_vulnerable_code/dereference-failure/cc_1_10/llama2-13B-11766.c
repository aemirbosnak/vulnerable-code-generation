//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024
#define SHM_KEY 0xdeadbeef

typedef struct {
    char message[MESSAGE_SIZE];
    int length;
} message_t;

void* shm_create(key_t key, size_t size) {
    int shmid = shmget(key, size, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }
    return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
}

int shm_send(int shmid, const char* message, int length) {
    message_t* message_ptr = shm_create(SHM_KEY, sizeof(message_t));
    memcpy(message_ptr->message, message, length);
    message_ptr->length = length;
    return shmdt(message_ptr);
}

char* shm_recv(int shmid) {
    message_t* message_ptr = shm_create(SHM_KEY, sizeof(message_t));
    return message_ptr->message;
}

int main() {
    int shmid1 = shmget(SHM_KEY, sizeof(message_t), IPC_CREAT | 0666);
    if (shmid1 < 0) {
        perror("shmget() failed");
        exit(EXIT_FAILURE);
    }

    // Parent process
    char message[] = "Hello, world!";
    int length = strlen(message);
    shm_send(shmid1, message, length);

    // Child process
    char* message_ptr = shm_recv(shmid1);
    printf("Received message: %s\n", message_ptr);

    return 0;
}