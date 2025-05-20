//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo"
#define BUFFER_SIZE 100

void create_fifo() {
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    printf("FIFO %s created.\n", FIFO_NAME);
}

void write_to_fifo() {
    int fd;
    char buffer[BUFFER_SIZE];

    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 5; i++) {
        snprintf(buffer, sizeof(buffer), "Message %d from the server!\n", i + 1);
        write(fd, buffer, strlen(buffer) + 1);
        printf("Server: sent %s", buffer);
        sleep(1); // Simulate some delay
    }

    close(fd);
    printf("Server: finished sending messages.\n");
}

void read_from_fifo() {
    int fd;
    char buffer[BUFFER_SIZE];

    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (read(fd, buffer, sizeof(buffer)) > 0) {
        printf("Client: received %s", buffer);
    }

    close(fd);
    printf("Client: done reading messages.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server/client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        create_fifo();
        write_to_fifo();
    } else if (strcmp(argv[1], "client") == 0) {
        sleep(1); // Wait for the server to create the FIFO
        read_from_fifo();
    } else {
        fprintf(stderr, "Invalid argument. Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}