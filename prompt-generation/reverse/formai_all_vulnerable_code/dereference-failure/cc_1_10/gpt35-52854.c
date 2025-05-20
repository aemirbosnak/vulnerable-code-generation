//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdbool.h>
#include <aio.h>

volatile sig_atomic_t stop;

void handler(int signum)
{
    stop = true;
}

int main(int argc, char *argv[])
{
    // Setup signal handler
    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_handler = handler;
    if (sigaction(SIGINT, &action, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Open file for reading
    int fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Setup aio control block
    struct aiocb aio;
    memset(&aio, 0, sizeof(struct aiocb));
    aio.aio_fildes = fd;
    aio.aio_offset = 0;
    aio.aio_buf = malloc(1024);
    aio.aio_nbytes = 1024;

    // Read the file asynchronously
    while (!stop) {
        if (aio_read(&aio) == -1) {
            perror("aio_read");
            exit(EXIT_FAILURE);
        }

        // Wait for the read to complete
        while (aio_error(&aio) == EINPROGRESS) {}

        // Handle read error
        if (aio_error(&aio) != 0) {
            perror("aio_error");
            exit(EXIT_FAILURE);
        }

        // Process the data
        int bytes_read = aio_return(&aio);
        printf("%.*s", bytes_read, (char*)aio.aio_buf);

        // Reset aio control block
        aio.aio_offset += bytes_read;
        aio.aio_nbytes = 1024;

        // Check if we reached the end of file
        if (bytes_read < 1024) {
            break;
        }
    }

    // Cleanup
    free(aio.aio_buf);
    close(fd);

    return EXIT_SUCCESS;
}