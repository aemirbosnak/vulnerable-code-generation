//Gemma-7B DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_Q_NAME "my_msg_queue"
#define MSG_MAX_SIZE 1024

struct msg_st {
    long msg_id;
    char data[MSG_MAX_SIZE];
    struct msg_st* next;
};

typedef struct msg_st msg_st;

int main() {
    int msg_id;
    key_t key;
    msg_st* head = NULL;
    struct msg_st* tail = NULL;

    // Create a message queue
    key = ftok(MSG_Q_NAME, 0);
    if (msg_id = msgget(key, IPC_CREAT) < 0) {
        perror("Error creating message queue");
        exit(1);
    }

    // Send a message
    char message[] = "Hello, world!";
    msg_st* new_msg = malloc(sizeof(msg_st));
    new_msg->msg_id = msg_id;
    strcpy(new_msg->data, message);
    new_msg->next = NULL;

    if (msgsnd(msg_id, new_msg, sizeof(new_msg), 0) < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Receive a message
    msg_st* received_msg = (msg_st*) msgrcv(msg_id, NULL, 0, 0, 0);

    if (received_msg) {
        printf("Received message: %s\n", received_msg->data);
        free(received_msg);
    }

    // Destroy the message queue
    msgctl(msg_id, IPC_RMID, NULL);

    return 0;
}