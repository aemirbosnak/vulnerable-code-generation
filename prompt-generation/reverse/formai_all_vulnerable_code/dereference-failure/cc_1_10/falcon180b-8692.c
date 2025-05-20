//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 1000

struct msgbuf {
    long mtype;
    char mtext[MAX_SIZE];
};

int main() {
    int msgid, msqid;
    struct msgbuf *msg;
    key_t key;

    // Create a new message queue
    key = ftok(".", 'a');
    if ((msqid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(1);
    }

    // Create a new message
    msg = (struct msgbuf *) malloc(sizeof(struct msgbuf));
    if (msg == NULL) {
        perror("malloc");
        exit(1);
    }
    msg->mtype = 1;
    strcpy(msg->mtext, "Hello, world!");

    // Send the message
    if (msgsnd(msqid, msg, sizeof(struct msgbuf), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    // Receive the message
    if ((msgid = msgget(key, 0666)) == -1) {
        perror("msgget");
        exit(1);
    }
    if ((msg = (struct msgbuf *) msgrcv(msgid, (void *) 0, MAX_SIZE, 1, 0)) == NULL) {
        perror("msgrcv");
        exit(1);
    }

    printf("Received message: %s\n", msg->mtext);

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}