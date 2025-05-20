//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>

#define BUFSIZE 128

bool volatile isReading = false;

void handle_sigint(int sig) {
    isReading = false;
}

void read_file_async(char *filename) {
    int fd = open(filename, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return;
    }

    isReading = true;

    char buffer[BUFSIZE];
    memset(buffer, 0, BUFSIZE);

    while (isReading) {
        ssize_t bytes_read = read(fd, buffer, BUFSIZE - 1);

        if (bytes_read == -1 && errno != EAGAIN) {
            fprintf(stderr, "Error reading from file: %s\n", strerror(errno));
            break;
        } else if (bytes_read > 0) {
            printf("%.*s", (int)bytes_read, buffer);
        }

        usleep(100000);
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, handle_sigint);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    printf("Reading file asynchronously: %s\n", argv[1]);

    read_file_async(argv[1]);

    printf("Done.\n");

    return 0;
}