//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MESSAGE_SIZE 1024
#define MESSAGE_BUFFER "Messager's Quiver"

struct message {
    char *data;
    size_t size;
};

void *message_queue_create(void) {
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, MESSAGE_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        return NULL;
    }
    return shmat(shmid, NULL, 0);
}

void *message_queue_send(void *queue, const char *message) {
    struct message *msg = (struct message *)queue;
    size_t size = strlen(message) + 1;
    msg->data = (char *)realloc(msg->data, size);
    if (msg->data == NULL) {
        perror("realloc");
        return NULL;
    }
    strcpy(msg->data, message);
    msg->size = size;
    return msg;
}

const char *message_queue_receive(void *queue) {
    struct message *msg = (struct message *)queue;
    if (msg->size == 0) {
        return NULL;
    }
    return msg->data;
}

void message_queue_destroy(void *queue) {
    shmctl(IPC_PRIVATE, IPC_RMID, NULL);
}

int main(void) {
    void *queue = message_queue_create();
    if (queue == NULL) {
        perror("message_queue_create");
        return 1;
    }

    // Send some messages
    char *messages[] = {"Hail, good sir!", "How doth thy day fare?", "Pray tell, what is thy bidding?"};
    for (size_t i = 0; i < sizeof(messages) / sizeof(char *); i++) {
        message_queue_send(queue, messages[i]);
    }

    // Receive some messages
    char *received_messages[] = {"Tis a fair day, anon.", "Methinks 'tis a grand day for a joust.", "Prithee, how doth thy venture fare?"};
    for (size_t i = 0; i < sizeof(received_messages) / sizeof(char *); i++) {
        char *message = message_queue_receive(queue);
        if (message == NULL) {
            break;
        }
        printf("Received message: %s\n", message);
        free(message);
    }

    // Clean up
    message_queue_destroy(queue);

    return 0;
}