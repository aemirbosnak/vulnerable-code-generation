//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 100 // Maximum size of message
#define QUEUE_KEY 1234 // Key for message queue
#define MESSAGE_TYPE 1 // Type of message

struct msgbuf {
    long mtype; // Message type
    char mtext[MAX_MSG_SIZE]; // Message text
};

// Function to create message queue
int create_queue() {
    int msgid;
    key_t key = ftok(".", QUEUE_KEY); // Create key for message queue
    if ((msgid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }
    return msgid;
}

// Function to send message
void send_message(int msgid, char* message) {
    struct msgbuf msg;
    strcpy(msg.mtext, message);
    msg.mtype = MESSAGE_TYPE;
    if (msgsnd(msgid, &msg, strlen(message), 0) == -1) {
        printf("Error sending message\n");
        exit(1);
    }
}

// Function to receive message
char* receive_message(int msgid) {
    struct msgbuf msg;
    char* message = NULL;
    if (msgrcv(msgid, &msg, MAX_MSG_SIZE, MESSAGE_TYPE, 0) == -1) {
        printf("Error receiving message\n");
        exit(1);
    }
    message = msg.mtext;
    return message;
}

int main() {
    int msgid = create_queue();
    char* message = "Hello, world!";
    send_message(msgid, message);
    char* received_message = receive_message(msgid);
    printf("Received message: %s\n", received_message);
    free(received_message);
    return 0;
}