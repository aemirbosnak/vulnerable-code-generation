//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 128

void run_server() {
    int fd;
    const char *messages[] = {
        "Hello from the server!",
        "How are you today?",
        "Interprocess communication is fun!",
        "Goodbye from the server!"
    };
    int msg_count = sizeof(messages) / sizeof(messages[0]);

    // Create the FIFO
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Open the FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write messages to the FIFO
    for (int i = 0; i < msg_count; i++) {
        write(fd, messages[i], strlen(messages[i]) + 1); // Include null terminator
        sleep(1); // Sleep for a second before sending the next message
    }

    // Close the FIFO
    close(fd);
}

void run_client() {
    int fd;
    char buffer[BUFFER_SIZE];

    // Open the FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read messages from the FIFO
    while (read(fd, buffer, sizeof(buffer)) > 0) {
        printf("Received: %s\n", buffer);
    }

    // Close the FIFO
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [server|client]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        run_server();
    } else if (strcmp(argv[1], "client") == 0) {
        run_client();
    } else {
        fprintf(stderr, "Invalid argument. Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    // Clean up and remove FIFO
    unlink(FIFO_NAME);
    return 0;
}