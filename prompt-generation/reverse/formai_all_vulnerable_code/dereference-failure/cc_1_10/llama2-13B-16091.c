//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

#define MESSAGE_SIZE 1024
#define SHM_KEY 0x12345678

typedef struct {
    char message[MESSAGE_SIZE];
    int sender;
} message_t;

int main() {
    key_t shm_key = SHM_KEY;
    int shmid = shmget(shm_key, sizeof(message_t), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Create a shared memory object
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Set up the message structure
    message_t *msg = shm;
    msg->sender = 1; // sender process id

    // Send the message
    kill(msg->sender, SIGUSR1);

    // Receive the message
    wait(NULL);

    // Print the received message
    printf("Received message: %s\n", msg->message);

    // Clean up
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}