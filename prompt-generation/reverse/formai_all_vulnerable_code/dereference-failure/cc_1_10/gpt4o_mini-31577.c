//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mqueue.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MSG_SIZE 256
#define QUEUE_NAME "/example_queue"

// Signal handler for clean exit
void signal_handler(int signo) {
    if (signo == SIGINT) {
        mq_unlink(QUEUE_NAME);
        printf("\nMessage queue deleted. Exiting...\n");
        exit(0);
    }
}

void sender() {
    mqd_t mq;
    char msg[MSG_SIZE];
    
    // Open the message queue
    mq = mq_open(QUEUE_NAME, O_WRONLY);
    if (mq == (mqd_t)-1) {
        perror("Sender: mq_open");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < 5; i++) {
        snprintf(msg, MSG_SIZE, "Message %d from sender", i);
        if (mq_send(mq, msg, strlen(msg) + 1, 0) == -1) {
            perror("Sender: mq_send");
        } else {
            printf("Sender sent: %s\n", msg);
        }
        sleep(1); // simulate work by sleeping
    }
    
    mq_close(mq);
}

void receiver() {
    mqd_t mq;
    char msg[MSG_SIZE];
    
    // Open the message queue
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("Receiver: mq_open");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 5; i++) {
        if (mq_receive(mq, msg, MSG_SIZE, NULL) == -1) {
            perror("Receiver: mq_receive");
            continue;
        }
        printf("Receiver received: %s\n", msg);
    }
    
    mq_close(mq);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Create message queue
    mq_unlink(QUEUE_NAME); // remove any existing queue
    mqd_t mq = mq_open(QUEUE_NAME, O_CREAT | O_EXCL | O_RDWR, 0644, NULL);
    if (mq == (mqd_t)-1) {
       perror("mq_open");
       exit(EXIT_FAILURE);
    }
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    
    // Child process
    if (pid == 0) {
        receiver();
    } else { // Parent process
        sender();
        wait(NULL); // Wait for child to finish
    }
    
    // Clean up message queue
    mq_unlink(QUEUE_NAME);
    return 0;
}