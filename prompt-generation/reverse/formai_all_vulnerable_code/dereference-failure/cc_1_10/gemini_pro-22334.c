//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Message queue structure
struct msg_buffer {
    long mtype;   // Message type
    char mtext[100];  // Message text
};

// Create a message queue
int create_message_queue(key_t key) {
    int msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid < 0) {
        perror("Failed to create message queue");
        exit(EXIT_FAILURE);
    }
    return msgid;
}

// Send a message to a message queue
void send_message(int msgid, long mtype, char *message) {
    struct msg_buffer msg;
    msg.mtype = mtype;
    strcpy(msg.mtext, message);
    if (msgsnd(msgid, &msg, sizeof(msg.mtext), 0) < 0) {
        perror("Failed to send message");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from a message queue
void receive_message(int msgid, long mtype, char *buffer) {
    struct msg_buffer msg;
    if (msgrcv(msgid, &msg, sizeof(msg.mtext), mtype, 0) < 0) {
        perror("Failed to receive message");
        exit(EXIT_FAILURE);
    }
    strcpy(buffer, msg.mtext);
}

// Main function
int main() {
    // Create a unique key for the message queue
    key_t key = ftok(".", 'a');

    // Create a message queue
    int msgid = create_message_queue(key);

    // Send a message to the message queue
    send_message(msgid, 1, "Hello from process 1");

    // Receive a message from the message queue
    char buffer[100];
    receive_message(msgid, 1, buffer);

    // Print the received message
    printf("Received message: %s\n", buffer);

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) < 0) {
        perror("Failed to remove message queue");
        exit(EXIT_FAILURE);
    }

    return 0;
}