//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MESSAGE_SIZE 1024
#define SHM_KEY 0x12345678

void *shm_ptr;

void create_shm(void) {
    key_t key = SHM_KEY;
    int shmid = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
}

void send_message(const char *message) {
    char *msg = (char *) shm_ptr;
    strcpy(msg, message);
}

void receive_message(char *message) {
    char *msg = (char *) shm_ptr;
    strcpy(message, msg);
}

int main() {
    create_shm();

    // Parent process
    send_message("Hello from parent!");

    // Child process
    char message[MESSAGE_SIZE];
    receive_message(message);
    printf("Received message from parent: %s\n", message);

    // Child process sends message back to parent
    send_message("Hello from child!");

    // Parent process receives message back from child
    receive_message(message);
    printf("Received message from child: %s\n", message);

    return 0;
}