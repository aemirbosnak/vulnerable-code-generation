//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 8192

void handle_error(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <local_port> <remote_address>:<remote_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    in_port_t local_port = atoi(argv[1]);

    char *remote_address = strtok(argv[2], ":");
    uint16_t remote_port = atoi(strtok(NULL, ""));

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        handle_error("socket");
    }

    struct sockaddr_in local_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(local_port)
    };
    if (bind(sock_fd, (struct sockaddr *) &local_addr, sizeof(local_addr)) == -1) {
        handle_error("bind");
    }

    struct sockaddr_in remote_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(remote_address),
        .sin_port = htons(remote_port)
    };

    if (connect(sock_fd, (struct sockaddr *) &remote_addr, sizeof(remote_addr)) == -1) {
        handle_error("connect");
    }

    char buffer[BUFFER_SIZE];

    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
        FD_SET(sock_fd, &read_fds);

        if (select(sock_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
            handle_error("select");
        }

        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            ssize_t bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (bytes_read == -1) {
                handle_error("read(STDIN_FILENO)");
            }

            ssize_t bytes_written = write(sock_fd, buffer, bytes_read);
            if (bytes_written == -1) {
                handle_error("write(sock_fd)");
            }
        }

        if (FD_ISSET(sock_fd, &read_fds)) {
            ssize_t bytes_read = read(sock_fd, buffer, BUFFER_SIZE);
            if (bytes_read == -1) {
                handle_error("read(sock_fd)");
            }

            ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
            if (bytes_written == -1) {
                handle_error("write(STDOUT_FILENO)");
            }
        }
    }

    close(sock_fd);

    return 0;
}