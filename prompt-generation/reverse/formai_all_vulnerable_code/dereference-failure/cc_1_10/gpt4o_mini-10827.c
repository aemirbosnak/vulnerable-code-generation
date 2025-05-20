//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define QUEUE_NAME  "/example_mq"
#define MAX_MSG_SIZE 256
#define MAX_MESSAGES 10

void sender() {
    mqd_t mq;
    char buffer[MAX_MSG_SIZE];

    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, NULL);
    if (mq == (mqd_t)-1) {
        perror("Sender: mq_open failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 5; ++i) {
        snprintf(buffer, sizeof(buffer), "Message %d", i + 1);
        if (mq_send(mq, buffer, strlen(buffer) + 1, 0) == -1) {
            perror("Sender: mq_send failed");
            mq_close(mq);
            exit(EXIT_FAILURE);
        }
        printf("Sender: Sent: %s\n", buffer);
        sleep(1);  // Simulate some delay
    }
    
    mq_close(mq);
}

void receiver() {
    mqd_t mq;
    char buffer[MAX_MSG_SIZE];

    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("Receiver: mq_open failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 5; ++i) {
        if (mq_receive(mq, buffer, MAX_MSG_SIZE, NULL) == -1) {
            perror("Receiver: mq_receive failed");
            mq_close(mq);
            exit(EXIT_FAILURE);
        }
        printf("Receiver: Received: %s\n", buffer);
    }

    mq_close(mq);
    mq_unlink(QUEUE_NAME); // Clean up the message queue
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <sender|receiver>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "sender") == 0) {
        sender();
    } else if (strcmp(argv[1], "receiver") == 0) {
        receiver();
    } else {
        fprintf(stderr, "Invalid argument: %s. Use 'sender' or 'receiver'.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}