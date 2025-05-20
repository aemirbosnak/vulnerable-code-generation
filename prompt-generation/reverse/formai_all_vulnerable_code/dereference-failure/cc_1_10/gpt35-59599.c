//FormAI DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

// Structure for message queue
struct message {
    long mtype;
    char mtext[50];
};

int main() {
    int id, pid;
    struct message message_buf;
    char message_text[50];

    // Create the message queue
    id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if (id < 0) {
        perror("Error creating message queue");
        exit(1);
    }

    // Fork process
    pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        exit(1);
    }

    // Child process
    if (pid == 0) {
        // Receive message from parent
        if (msgrcv(id, &message_buf, sizeof(struct message), 1, 0) < 0) {
            perror("Error receiving message");
            exit(1);
        }
        printf("Child received message: %s\n", message_buf.mtext);

        // Send message to parent
        sprintf(message_text, "Hello parent, this is child with PID %d", getpid());
        message_buf.mtype = 2;
        strcpy(message_buf.mtext, message_text);
        if (msgsnd(id, &message_buf, sizeof(struct message), 0) < 0) {
            perror("Error sending message");
            exit(1);
        }
    }
    
    // Parent process
    else {
        // Send message to child
        sprintf(message_text, "Hello child, this is parent with PID %d", getpid());
        message_buf.mtype = 1;
        strcpy(message_buf.mtext, message_text);
        if (msgsnd(id, &message_buf, sizeof(struct message), 0) < 0) {
            perror("Error sending message");
            exit(1);
        }

        // Receive message from child
        if (msgrcv(id, &message_buf, sizeof(struct message), 2, 0) < 0) {
            perror("Error receiving message");
            exit(1);
        }
        printf("Parent received message: %s\n", message_buf.mtext);
    }

    // Delete message queue
    msgctl(id, IPC_RMID, NULL);

    return 0;
}