//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define MSG_LEN 1024

// Structure to store message data
struct message {
    char name[50];
    char message[MSG_LEN];
};

// Create a shared memory segment
int shm_create(void) {
    int shmid;
    key_t key = SHM_KEY;
    size_t size = sizeof(struct message);
    int shm = shmget(key, size, IPC_CREAT | 0644);
    if (shm == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    shmid = shm;
    return shmid;
}

// Send message to another process
void send_message(int shmid, char *message) {
    char *shm_addr;
    size_t len = strlen(message) + 1;
    shm_addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    strcpy(shm_addr, message);
    munmap(shm_addr, len);
}

// Receive message from another process
char *recv_message(int shmid) {
    char *shm_addr;
    size_t len = sizeof(struct message);
    shm_addr = mmap(NULL, len, PROT_READ, MAP_SHARED, shmid, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    struct message *msg = (struct message *)shm_addr;
    char *message = msg->message;
    munmap(shm_addr, len);
    return message;
}

int main() {
    int shmid = shm_create();
    char message[] = "Hello from process 1!";
    send_message(shmid, message);
    char *recved_message = recv_message(shmid);
    printf("Received message: %s\n", recved_message);
    return 0;
}