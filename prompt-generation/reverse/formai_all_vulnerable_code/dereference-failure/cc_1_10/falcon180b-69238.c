//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 1024
#define MAX_QUEUE 10

// Message structure
typedef struct {
    long mtype;
    char mtext[MAX_MSG_SIZE];
} message;

int main() {
    int msgid;
    key_t key = ftok("./", 65);
    int msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        printf("Error creating message queue: %s\n", strerror(errno));
        exit(1);
    }
    printf("Message queue created with ID: %d\n", msqid);

    // Send message
    message msg = {1, "Hello, world!"};
    if (msgsnd(msqid, &msg, sizeof(msg.mtext), 0) == -1) {
        printf("Error sending message: %s\n", strerror(errno));
        exit(1);
    }
    printf("Message sent\n");

    // Receive message
    message received_msg;
    if (msgrcv(msqid, &received_msg, MAX_MSG_SIZE, 1, 0) == -1) {
        printf("Error receiving message: %s\n", strerror(errno));
        exit(1);
    }
    printf("Received message: %s\n", received_msg.mtext);

    if (msgctl(msqid, IPC_RMID, 0) == -1) {
        printf("Error removing message queue: %s\n", strerror(errno));
        exit(1);
    }
    printf("Message queue removed\n");
    return 0;
}