//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>

#define MAX_MESSAGE_SIZE 1024
#define SHM_KEY 0xdeadbeef

typedef struct {
    char *message;
    int length;
} message_t;

int shm_id = -1;
int shm_ptr = -1;

void create_shm() {
    key_t key = SHM_KEY;
    shm_id = shmget(key, sizeof(message_t), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget() failed");
        exit(1);
    }
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)(-1)) {
        perror("shmat() failed");
        exit(1);
    }
}

void send_message(const char *message) {
    message_t *msg = (message_t *)shm_ptr;
    msg->message = message;
    msg->length = strlen(message);
    if (msync(msg, sizeof(message_t), MS_ASYNC) == -1) {
        perror("msync() failed");
    }
}

void recv_message(char *message, int max_length) {
    message_t *msg = (message_t *)shm_ptr;
    if (msg->length > max_length) {
        fprintf(stderr, "Received message too long (%d > %d)\n", msg->length, max_length);
        msg->length = max_length;
    }
    strcpy(message, msg->message);
}

void sig_handler(int sig) {
    switch (sig) {
        case SIGUSR1:
            fprintf(stderr, "Received SIGUSR1 signal\n");
            break;
        case SIGINT:
            fprintf(stderr, "Received SIGINT signal\n");
            exit(0);
            break;
    }
}

int main() {
    create_shm();

    // Parent process
    if (fork() == 0) {
        char message[] = "Hello, world!";
        send_message(message);
        exit(0);
    } else {
        char message[MAX_MESSAGE_SIZE];
        recv_message(message, MAX_MESSAGE_SIZE);
        printf("Received message: %s\n", message);
        wait(NULL);
    }

    return 0;
}