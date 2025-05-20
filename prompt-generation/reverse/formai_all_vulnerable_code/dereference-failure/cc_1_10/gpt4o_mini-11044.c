//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mqueue.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define QUEUE_NAME "/msg_queue"
#define MAX_MSG_SIZE 256
#define MAX_MSG_COUNT 10

void cleanup() {
    mq_unlink(QUEUE_NAME);
    exit(0);
}

void sigint_handler(int sig) {
    printf("Interrupt signal received. Cleaning up...\n");
    cleanup();
}

void producer() {
    mqd_t mq;
    char msg[MAX_MSG_SIZE];
    int count = 0;

    if ((mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, NULL)) == (mqd_t)-1) {
        perror("Producer: mq_open");
        exit(1);
    }

    while (count < MAX_MSG_COUNT) {
        snprintf(msg, sizeof(msg), "Message %d from Producer", count + 1);
        if (mq_send(mq, msg, strlen(msg) + 1, 0) == -1) {
            perror("Producer: mq_send");
            break;
        }
        printf("Producer sent: %s\n", msg);
        count++;
        sleep(1);
    }

    mq_close(mq);
    cleanup();
}

void consumer(int id) {
    mqd_t mq;
    char msg[MAX_MSG_SIZE];

    if ((mq = mq_open(QUEUE_NAME, O_RDONLY)) == (mqd_t)-1) {
        perror("Consumer: mq_open");
        exit(1);
    }

    while (1) {
        ssize_t bytes_read = mq_receive(mq, msg, sizeof(msg), NULL);
        if (bytes_read >= 0) {
            printf("Consumer %d received: %s\n", id, msg);
        } else {
            perror("Consumer: mq_receive");
            break;
        }
        sleep(1);
    }

    mq_close(mq);
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, sigint_handler);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <number_of_consumers>\n", argv[0]);
        exit(1);
    }

    int num_consumers = atoi(argv[1]);
    if (num_consumers <= 0) {
        fprintf(stderr, "The number of consumers must be a positive integer.\n");
        exit(1);
    }

    // Start the producer
    if (fork() == 0) {
        producer();
    }

    // Start consumers
    for (int i = 0; i < num_consumers; i++) {
        if (fork() == 0) {
            consumer(i + 1);
        }
    }

    // Wait for the children to finish (optional)
    for (int i = 0; i < num_consumers; i++) {
        wait(NULL);
    }

    cleanup();
    return 0;
}