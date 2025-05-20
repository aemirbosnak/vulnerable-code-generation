//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#define MSG_SIZE 1024

typedef struct {
    char *message;
    size_t length;
} message_t;

void *mmap_msg(void *addr, size_t length) {
    return mmap(addr, length, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
}

void *recv_msg(int fd) {
    void *addr = mmap_msg(NULL, MSG_SIZE);
    size_t length = read(fd, addr, MSG_SIZE);
    return addr;
}

void send_msg(int fd, const char *message, size_t length) {
    void *addr = mmap_msg(NULL, length);
    memcpy(addr, message, length);
    write(fd, addr, length);
}

int main() {
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);

    // Parent process
    printf("Parent process created\n");

    // Child process
    if (fork() == 0) {
        close(p1[1]);
        close(p2[0]);

        char *message = "Hello, world!";
        send_msg(p1[0], message, strlen(message));

        // Block here until the parent process sends a message
        while (1) {
            char *addr = recv_msg(p2[0]);
            printf("Received message: %s\n", addr);
        }
    } else {
        close(p1[0]);
        close(p2[1]);

        // Parent process
        printf("Parent process created\n");

        char *message = "Hello, world!";
        send_msg(p2[1], message, strlen(message));
    }

    return 0;
}