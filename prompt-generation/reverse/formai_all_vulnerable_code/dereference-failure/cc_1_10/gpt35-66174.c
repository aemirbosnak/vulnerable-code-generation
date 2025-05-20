//FormAI DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define TIMEOUT 5

void handle_error(char* message) {
    printf("Error: %s", message);
    exit(1);
}

void set_non_blocking(int sock_fd) {
    int flags = fcntl(sock_fd, F_GETFL, 0);
    if (flags == -1) {
        handle_error("Failed to set non-blocking");
    }
    if (fcntl(sock_fd, F_SETFL, flags | O_NONBLOCK) == -1){
        handle_error("Failed to set non-blocking");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        handle_error("Expected one argument: IP address");
    }

    int start_port = 1;
    int end_port = 65535;

    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    printf("Scanning ports on %s\n", argv[1]);
    for (int port = start_port; port <= end_port; port++) {
        int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (sock_fd == -1) {
            handle_error("Failed to create socket");
        }
        set_non_blocking(sock_fd);

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock_fd, &read_fds);

        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        if (connect(sock_fd, (struct sockaddr *)&target, sizeof target) == -1) {
            if (errno != EINPROGRESS) {
                close(sock_fd);
                continue;
            }
            int ret = select(sock_fd + 1, NULL, &read_fds, NULL, &timeout);
            if (ret == -1) {
                close(sock_fd);
                continue;
            } else if (ret == 0) {
                close(sock_fd);
                continue;
            } else {
                int error;
                socklen_t error_size = sizeof(error);
                getsockopt(sock_fd, SOL_SOCKET, SO_ERROR, &error, &error_size);
                if (error != 0) {
                    close(sock_fd);
                    continue;
                }
            }
        }

        close(sock_fd);

        printf("Port %d is open!\n", port);
    }

    printf("Scan complete!\n");

    return 0;
}