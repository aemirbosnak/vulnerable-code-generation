//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

volatile static int running;

void signal_handler(int sig)
{
    running = 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    int fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        printf("File could not be opened: %d\n", errno);
        return -1;
    }

    printf("Opened file %s.\n", argv[1]);

    char read_buf[1024];
    char write_buf[1024];
    size_t nbytes;
    ssize_t bytes_read;

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        printf("Cannot set signal handler: %d\n", errno);
        close(fd);
        return -1;
    }

    running = 1;
    while (running) {
        memset(read_buf, 0, sizeof(read_buf));
        memset(write_buf, 0, sizeof(write_buf));

        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(fd, &rfds);

        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        int retval = select(fd + 1, &rfds, NULL, NULL, &timeout);
        if (retval == -1) {
            printf("Error occurred: %d\n", errno);
            running = 0;
            break;
        } else if (retval > 0 && FD_ISSET(fd, &rfds)) {
            bytes_read = read(fd, read_buf, sizeof(read_buf));
            if (bytes_read < 0) {
                printf("Error occurred: %d\n", errno);
                running = 0;
                break;
            } else if (bytes_read > 0) {
                printf("%s\n", read_buf);
            }
        }

        nbytes = read(STDIN_FILENO, write_buf, sizeof(write_buf));
        if (nbytes < 0) {
            printf("Error occurred: %d\n", errno);
            running = 0;
            break;
        } else if (nbytes > 0) {
            ssize_t bytes_written = write(fd, write_buf, nbytes);
            if (bytes_written < 0) {
                printf("Error occurred: %d\n", errno);
                running = 0;
                break;
            }
        }
    }

    close(fd);

    return 0;
}