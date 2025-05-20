//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct {
    long mtype;
    int data;
} mymsg_t;

int main() {
    // Create a message queue key.
    key_t key = ftok(".", 'a');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a message queue using the key.
    int msqid = msgget(key, IPC_CREAT | IPC_EXCL | 0600);
    if (msqid == -1) {
        if (errno == EEXIST) {
            printf("Message queue already exists.\n");
            msqid = msgget(key, 0);
            if (msqid == -1) {
                perror("msgget");
                exit(EXIT_FAILURE);
            }
        } else {
            perror("msgget");
            exit(EXIT_FAILURE);
        }
    }

    // Send a message to the message queue.
    mymsg_t msg;
    msg.mtype = 1;
    msg.data = 10;
    if (msgsnd(msqid, &msg, sizeof(msg), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the message queue.
    if (msgrcv(msqid, &msg, sizeof(msg), 1, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    // Print the received message.
    printf("Received message: %ld, %d\n", msg.mtype, msg.data);

    // Remove the message queue.
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}