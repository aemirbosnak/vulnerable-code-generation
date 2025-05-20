//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10
#define MAX_MESSAGE_SIZE 100

// Message structure
typedef struct {
    long mtype;
    char mtext[MAX_MESSAGE_SIZE];
} message;

int main() {
    int msqid;
    key_t key;
    struct msgbuf {
        long mtype;
        char mtext[MAX_MESSAGE_SIZE];
    } msg;
    int i;

    // Create a unique key
    key = ftok(".", 'a');

    // Get a message queue identifier
    msqid = msgget(key, 0644 | IPC_CREAT);

    // Check if the message queue was successfully created
    if (msqid == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }

    printf("Message queue created with ID: %d\n", msqid);

    // Initialize the message queue
    for (i = 0; i < MAX_QUEUE_SIZE; i++) {
        sprintf(msg.mtext, "Message %d", i);
        msg.mtype = i;

        // Send the message to the queue
        if (msgsnd(msqid, &msg, strlen(msg.mtext), 0) == -1) {
            printf("Error sending message\n");
            exit(1);
        }
    }

    // Receive messages from the queue
    for (i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (msgrcv(msqid, &msg, MAX_MESSAGE_SIZE, i, 0) == -1) {
            printf("Error receiving message\n");
            exit(1);
        }

        printf("Received message: %s\n", msg.mtext);
    }

    // Remove the message queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        printf("Error removing message queue\n");
        exit(1);
    }

    printf("Message queue removed\n");

    return 0;
}