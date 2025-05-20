//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>

#define BUFSIZE 1024

volatile sig_atomic_t flag = 0;

void sig_handler(int sig_num) {
    signal(SIGUSR1, sig_handler);
    flag = 1;
}

int main(int argc, char *argv[]) {
    struct stat sb;
    char buf[BUFSIZE];
    bool done_reading = false;
    int fd;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &sb) == -1 || !S_ISREG(sb.st_mode)) {
        fprintf(stderr, "%s is not a file\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        fprintf(stderr, "Failed to open %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Install signal handler
    signal(SIGUSR1, sig_handler);

    while (!done_reading) {
        ssize_t bytes_read = read(fd, buf, sizeof(buf));
        if (bytes_read == -1) {
            fprintf(stderr, "Failed to read from file %s: %s\n", argv[1], strerror(errno));
            exit(EXIT_FAILURE);
        } else if (bytes_read == 0) {
            done_reading = true;
            break;
        } else {
            // Async code starts here
            printf("Read %ld bytes from file %s\n", bytes_read, argv[1]);
            printf("Contents of buffer: %.*s\n", (int)bytes_read, buf);

            // Wait for SIGUSR1 signal
            while (!flag) {
                sleep(1);
            }

            // Reset flag for next read
            flag = 0;
        }
    }

    if (close(fd) == -1) {
        fprintf(stderr, "Failed to close file %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}