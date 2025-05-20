//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

// Message queue identifier
#define MSG_QUEUE_ID IPC_PRIVATE

// Message structure
typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} message;

// Function to create message queue
int create_message_queue() {
    key_t key = ftok("message_queue.c",'m'); // Create key using file name and character'm'
    int msg_id = msgget(key, IPC_CREAT | IPC_EXCL | 0666); // Create message queue with exclusive access and read-write permission for all
    if (msg_id == -1) {
        printf("Error creating message queue\n");
        return FALSE;
    }
    return TRUE;
}

// Function to send message
int send_message(int msg_id, char* text) {
    message msg;
    strcpy(msg.mtext, text);
    msg.mtype = 1; // Message type is 1
    if (msgsnd(msg_id, &msg, strlen(text), 0) == -1) {
        printf("Error sending message\n");
        return FALSE;
    }
    return TRUE;
}

// Function to receive message
int receive_message(int msg_id, char* buffer) {
    message msg;
    if (msgrcv(msg_id, &msg, MAX_SIZE, 1, 0) == -1) {
        printf("Error receiving message\n");
        return FALSE;
    }
    strcpy(buffer, msg.mtext);
    return TRUE;
}

int main() {
    int msg_id;
    char buffer[MAX_SIZE];

    // Create message queue
    if (!create_message_queue()) {
        exit(1);
    }

    // Send message
    if (!send_message(msg_id, "Hail, noble knight! What news dost thou bring?")) {
        exit(2);
    }

    // Receive message
    if (!receive_message(msg_id, buffer)) {
        exit(3);
    }

    printf("Message received: %s\n", buffer);

    return 0;
}