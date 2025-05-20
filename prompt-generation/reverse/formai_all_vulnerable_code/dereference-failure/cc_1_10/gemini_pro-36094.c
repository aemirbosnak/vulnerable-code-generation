//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define the message structure
typedef struct {
    long mtype;
    char mtext[100];
} message;

// Create a message queue
int create_msg_queue() {
    // Create a unique key for the message queue
    key_t key = ftok(".", 'a');

    // Create the message queue
    int msgqid = msgget(key, IPC_CREAT | 0666);

    if (msgqid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    return msgqid;
}

// Send a message to the message queue
void send_msg(int msgqid, long mtype, char *mtext) {
    // Create a message
    message msg;
    msg.mtype = mtype;
    strcpy(msg.mtext, mtext);

    // Send the message
    int ret = msgsnd(msgqid, &msg, strlen(mtext) + 1, 0);

    if (ret == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from the message queue
void receive_msg(int msgqid, long mtype, char *mtext) {
    // Create a message
    message msg;

    // Receive the message
    int ret = msgrcv(msgqid, &msg, sizeof(mtext), mtype, 0);

    if (ret == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    // Copy the message text to the buffer
    strcpy(mtext, msg.mtext);
}

// Main function
int main() {
    // Create a message queue
    int msgqid = create_msg_queue();

    // Send a message to the message queue
    send_msg(msgqid, 1, "Hello from process 1!");

    // Receive a message from the message queue
    char mtext[100];
    receive_msg(msgqid, 1, mtext);

    // Print the received message
    printf("Received message: %s\n", mtext);

    // Clean up
    msgctl(msgqid, IPC_RMID, NULL);

    return 0;
}