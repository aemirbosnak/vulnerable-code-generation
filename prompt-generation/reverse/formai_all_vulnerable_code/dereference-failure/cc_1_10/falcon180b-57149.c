//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 100

typedef struct {
    int fd;
    char buffer[MAX_SIZE];
} MessageQueue;

int create_queue() {
    int fd = mkfifo("message_queue", 0666);
    if (fd == -1) {
        printf("Error creating message queue: %s\n", strerror(errno));
        exit(1);
    }
    return fd;
}

int send_message(int fd, char* message) {
    int len = strlen(message);
    int written = write(fd, message, len);
    if (written!= len) {
        printf("Error sending message: %s\n", strerror(errno));
        exit(1);
    }
    return 0;
}

int receive_message(int fd, char* buffer) {
    int len = read(fd, buffer, MAX_SIZE);
    if (len == -1) {
        printf("Error receiving message: %s\n", strerror(errno));
        exit(1);
    }
    buffer[len] = '\0';
    return len;
}

int main() {
    int fd = create_queue();
    char buffer[MAX_SIZE];

    while (1) {
        int len = receive_message(fd, buffer);
        printf("Received message: %s\n", buffer);
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }

    close(fd);
    return 0;
}