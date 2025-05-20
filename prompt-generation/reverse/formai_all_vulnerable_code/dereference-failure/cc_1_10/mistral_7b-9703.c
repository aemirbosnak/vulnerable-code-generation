//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_NAME1 "producer_consumer1"
#define FIFO_NAME2 "producer_consumer2"

pid_t pid1, pid2;
int fd1, fd2;

void producer(char *message) {
    mkfifo(FIFO_NAME1, 0666);
    fd1 = open(FIFO_NAME1, O_WRONLY);

    write(fd1, message, strlen(message) + 1);
    printf("Producer: Message sent to consumer1\n");

    close(fd1);
    remove(FIFO_NAME1);
}

void consumer1(char *message) {
    mkfifo(FIFO_NAME1, 0666);
    mkfifo(FIFO_NAME2, 0666);

    fd1 = open(FIFO_NAME1, O_RDONLY);
    fd2 = open(FIFO_NAME2, O_WRONLY);

    read(fd1, message, strlen(message) + 1);
    printf("Consumer1: Received message: %s\n", message);

    write(fd2, message, strlen(message) + 1);

    printf("Consumer1: Sent message to consumer2\n");

    close(fd1);
    close(fd2);
    remove(FIFO_NAME1);
    remove(FIFO_NAME2);
}

void consumer2(char *message) {
    mkfifo(FIFO_NAME2, 0666);

    fd2 = open(FIFO_NAME2, O_RDONLY);

    read(fd2, message, strlen(message) + 1);
    printf("Consumer2: Received message: %s\n", message);

    close(fd2);
    remove(FIFO_NAME2);
}

int main() {
    char message[100];

    strcpy(message, "Hello World!");

    pid1 = fork();
    if (pid1 > 0) {
        producer(message);
        wait(NULL);
        exit(0);
    }

    pid2 = fork();
    if (pid2 > 0) {
        consumer1(message);
        wait(NULL);
        exit(0);
    }

    consumer2(message);
    wait(NULL);
    wait(NULL);
    exit(0);
}