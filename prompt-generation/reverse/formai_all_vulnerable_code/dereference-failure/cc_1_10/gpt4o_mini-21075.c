//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 1024

void create_fifo() {
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
}

void client_process() {
    int fd;
    char input[BUFFER_SIZE];

    printf("Client: Enter a string: ");
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    // Open FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Writing input string to FIFO
    write(fd, input, strlen(input) + 1);
    close(fd);
}

void server_process() {
    int fd;
    char received[BUFFER_SIZE];
    int length;

    // Open FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read from FIFO
    while (read(fd, received, BUFFER_SIZE) > 0) {
        length = strlen(received);
        printf("Server: Received string: \"%s\" with length: %d\n", received, length);
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server|client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create FIFO
    create_fifo();

    if (strcmp(argv[1], "client") == 0) {
        client_process();
    } else if (strcmp(argv[1], "server") == 0) {
        server_process();
    } else {
        fprintf(stderr, "Invalid argument. Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    // Clean up FIFO
    unlink(FIFO_NAME);
    return 0;
}