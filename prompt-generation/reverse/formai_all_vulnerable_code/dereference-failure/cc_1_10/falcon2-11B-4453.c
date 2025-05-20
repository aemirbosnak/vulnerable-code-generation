//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Message structure
struct Message {
    int id;
    char message[100];
};

// Function to send a message to a queue
int sendMessage(int queue_id, struct Message* message) {
    return msgrcv(queue_id, (struct mq_msg *)message, 100, 0, IPC_NOWAIT);
}

// Function to receive a message from a queue
int receiveMessage(int queue_id, struct Message* message) {
    return msgrcv(queue_id, (struct mq_msg *)message, 100, 0, IPC_NOWAIT);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <queue_id> <message>\n", argv[0]);
        return 1;
    }

    int queue_id = atoi(argv[1]);
    struct Message message;
    strcpy(message.message, argv[2]);

    // Create a new message queue
    int queue_fd = msgget(queue_id, IPC_CREAT | 0666);
    if (queue_fd == -1) {
        perror("msgget");
        return 1;
    }

    // Send the message to the queue
    if (sendMessage(queue_fd, &message) == -1) {
        perror("msgrcv");
        return 1;
    }

    // Receive the message from the queue
    struct Message received_message;
    if (receiveMessage(queue_fd, &received_message) == -1) {
        perror("msgrcv");
        return 1;
    }

    // Print the received message
    printf("Received message: %s\n", received_message.message);

    // Close the message queue
    if (msgctl(queue_fd, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    return 0;
}